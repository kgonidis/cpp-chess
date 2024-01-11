#define DEBUG
#include "engine.h"
#include "ui.hpp"

class PieceTexture
{
private:
    ui::Texture texture;
    ImVec2 size;
    ImVec2 target;
    const int PIECE_IMAGE_MAP[12] = {
        [k] = 0,
        [q] = 1,
        [b] = 2,
        [n] = 3,
        [r] = 4,
        [p] = 5,
        [K] = 6,
        [Q] = 7,
        [B] = 8,
        [N] = 9,
        [R] = 10,
        [P] = 11};

public:
    PieceTexture(const std::string &path) : texture(path),
                                            size(texture.GetWidth() / 6, texture.GetHeight() / 2),
                                            target(size.x / 4, size.y / 4)
    {
    }

    void SetTargetWidth(float width)
    {
        target.x = width;
        target.y = width * size.y / size.x;
    }

    ImVec2 GetTargetSize() const
    {
        return target;
    }

    void Draw(ImDrawList *draw_list, int piece, const ImVec2 &pos) const
    {
        int image = PIECE_IMAGE_MAP[piece];
        int x_off = size.x * (image % 6);
        int y_off = size.y * (int)(image / 6);
        ImVec2 min(pos.x, pos.y + target.y);
        ImVec2 max(pos.x + target.x, pos.y);
        draw_list->AddImage(
            (void *)(intptr_t)texture.GetID(),
            min,
            max,
            ImVec2(x_off / (float)texture.GetWidth(), y_off / (float)texture.GetHeight()),
            ImVec2((x_off + size.x) / (float)texture.GetWidth(), (y_off + size.y) / (float)texture.GetHeight()));
    }
};

class ChessBoard : public ui::ImGuiGLWindow
{
private:
    game_t game;
    std::unique_ptr<PieceTexture> pieces;
    pgn_db_t db;
    move_tree_t *move;

public:
    ChessBoard(unsigned int width, unsigned int height, const std::string &title, const std::string &pgn_file)
        : ui::ImGuiGLWindow(width, height, title),
          pieces(nullptr)
    {
        pgn_parse(&db, pgn_file.c_str());
        move = new move_tree_t({
            .state = game_t::FromStartingPosition().getState(),
        });
        auto mt = pgn_moves(&db, 0);
        // std::cout << *mt << std::endl;
        move->AddChild(mt);
    }

    bool OnPostInit() override
    {
        pieces = std::make_unique<PieceTexture>("assets/images/pieces.png");
        pieces->SetTargetWidth(75);
        auto m = move->value;
        game = m != nullptr ? game_t(m->state) : game_t::FromStartingPosition();
        return true;
    }

    void OnLateUpdate(double deltaTime) override
    {

        auto io = ui::GetIO();
        bool showdemo = true;
        ui::ShowDemoWindow(&showdemo);

        ui::Begin("Moves");

        ui::BeginListBox("Moves");

        bool isLastAlternate = false;
        auto mt = pgn_moves(&db, 0);
        for (auto *move_tree : *mt)
        {
            auto m = move_tree->value;
            auto isAlternate = move_tree->isAlternate();
            auto move_num = m->state.full_move_number;
            auto move_side = m->state.side ^ 1;
            std::string move_text = "";
            int text_size = 50;

            if (isAlternate)
            {
                text_size = 100;
                if (move_side == WHITE)
                    ui::NewLine();
                move_text += "\t+ ";

                if (move_side == BLACK)
                    move_text += std::to_string(move_num) + "... ";
            }

            if (!isAlternate && isLastAlternate && move_side == BLACK)
                move_text += std::to_string(move_num) + "... ";

            if (move_side == WHITE)
            {
                move_text += std::to_string(move_num) + ". ";
                ui::SetNextItemAllowOverlap();
            }

            char san[10];
            move_to_san(&m->move, san);
            move_text += std::string(san);

            if (ui::Selectable(move_text.c_str(), move == move_tree, 0, ImVec2(text_size, 0)))
            {
                move = move_tree;
                game = game_t(m->state);
            }
            if (move_side == WHITE)
                ui::SameLine();
        }

        ui::EndListBox();

        if (ui::ButtonEx("Previous", ImVec2(100, 100), ImGuiButtonFlags_PressedOnClickRelease))
        {
            if (move->parent != nullptr)
            {
                move = move->parent;
                auto m = move->value;
                game = m != nullptr ? game_t(m->state) : game_t::FromStartingPosition();
            }
        }

        if (ui::ButtonEx("Next", ImVec2(100, 100), ImGuiButtonFlags_PressedOnClickRelease))
        {
            if (move->next != nullptr)
            {
                move = move->next;
                auto m = move->value;
                game = m != nullptr ? game_t(m->state) : game_t::FromStartingPosition();
            }
        }

        ui::End();

        ui::Begin("ChessBoard");

        auto pos = ui::GetCurrentWindow()->DC.CursorPos;
        auto draw_list = ui::GetWindowDrawList();
        auto target_size = pieces->GetTargetSize();

        static int selected = no_sq;
        static s_tree_t move_tree;

        // draw chess board with pieces
        for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {

                int square = row * 8 + col;
                int piece, side;

                ImVec2 min(pos.x + col * target_size.x, pos.y + row * target_size.y);
                ImVec2 max(pos.x + (col + 1) * target_size.x, pos.y + (row + 1) * target_size.y);
                ImU32 square_color = (row + col) % 2 == 0 ? IM_COL32(255, 206, 158, 255) : IM_COL32(209, 139, 71, 255);
                draw_list->AddRectFilled(min, max, square_color);

                bool held, hovered;
                bool pressed = ui::ButtonBehavior(
                    ImRect(min, max),
                    ui::GetID(CHAR_SQUARE_MAP[square]),
                    &hovered,
                    &held,
                    ImGuiButtonFlags_PressedOnRelease);

                if (pressed && move_tree.value != nullptr)
                {
                    auto it = std::find_if(move_tree.begin(), move_tree.end(), [&](s_tree_t *mt)
                                           { 
                                            auto move = mt->value->move;
                                            return (int)move.target == square; });
                    if (it != move_tree.end())
                    {
                        auto move = it->value->move;
                        game.makeMove(move);
                        move_tree.clear();
                        selected = no_sq;
                        break;
                    }
                }

                if (game.getPiece(square, piece, side))
                {
                    pieces->Draw(draw_list, piece, min);

                    if (pressed)
                    {
                        move_tree.clear();
                        if (selected == square)
                            selected = no_sq;
                        else
                        {
                            game.generateMoves(move_tree, side, piece, square);
                            selected = move_tree.children.size() > 0 ? square : no_sq;
                        }
                    }
                }
                else if (pressed)
                {
                    selected = no_sq;
                    move_tree.clear();
                }
            }
        }

        if (selected != no_sq)
        {
            int row = selected / 8;
            int col = selected % 8;
            ImVec2 min(pos.x + col * target_size.x, pos.y + row * target_size.y);
            ImVec2 max(pos.x + (col + 1) * target_size.x, pos.y + (row + 1) * target_size.y);
            // highlight border of square green
            draw_list->AddRect(min, max, IM_COL32(0, 255, 0, 255));
        }

        for (auto *mt : move_tree)
        {
            auto move = mt->value->move;
            int row = move.target / 8;
            int col = move.target % 8;
            ImVec2 min(pos.x + col * target_size.x, pos.y + row * target_size.y);
            ImVec2 max(pos.x + (col + 1) * target_size.x, pos.y + (row + 1) * target_size.y);
            // add grey circle in the middle of the square
            draw_list->AddCircleFilled(ImVec2((min.x + max.x) / 2, (min.y + max.y) / 2), target_size.x / 4, IM_COL32(128, 128, 128, 128));
        }
        ui::End();
    }
};

class SubTest
{
public:
    int x;
    SubTest(int x) : x(x) {}
};

class Test
{
public:
    std::vector<int *> v;
    SubTest tests[3];

    Test() : v(), tests{SubTest(0), SubTest(0), SubTest(0)} {}
};

int main(int argc, char **argv)
{
    auto g = game_t::FromStartingPosition();
    s_tree_t moves;
    g.generateMoves(moves, e2);

    for (auto *mt : moves)
    {
        auto m = mt->value;
        std::cout << m->move.target << std::endl;
    }

    // const char *f = argc > 1 ? argv[1] : "Vienna.pgn";
    // std::string filename = "assets/pgns/" + std::string(f);

    // ChessBoard board(1200, 780, "Test", filename);
    // board.Show();
}