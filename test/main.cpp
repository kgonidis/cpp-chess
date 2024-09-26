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

public:
    ChessBoard(unsigned int width, unsigned int height, const std::string &title)
        : ui::ImGuiGLWindow(width, height, title),
          pieces(nullptr)
    {
    }

    bool OnPostInit() override
    {
        pieces = std::make_unique<PieceTexture>("assets/images/pieces.png");
        pieces->SetTargetWidth(75);
        game = game_t::FromStartingPosition();
        return true;
    }

    void OnLateUpdate(double deltaTime) override
    {

        auto io = ui::GetIO();
        bool showdemo = true;
        ui::ShowDemoWindow(&showdemo);

        ui::Begin("ChessBoard");

        auto pos = ui::GetCurrentWindow()->DC.CursorPos;
        auto draw_list = ui::GetWindowDrawList();
        auto target_size = pieces->GetTargetSize();

        static move_t *selected = nullptr;

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

                if (pressed)
                {
                    if (selected != nullptr)
                    {
                        selected->target = square;
                        selected->promotion = no_piece;
                        game.makeMove(*selected);
                        delete selected;
                        selected = nullptr;
                    }
                    else if (game.getPiece(square, piece, side) && game.generateMoves(square).size() > 0)
                    {
                        selected = new move_t();
                        selected->source = square;
                        selected->piece = piece;
                    }
                }

                if (game.getPiece(square, piece, side))
                {
                    pieces->Draw(draw_list, piece, min);
                }
            }
        }

        if (selected != nullptr)
        {
            int row = selected->source / 8;
            int col = selected->source % 8;
            ImVec2 min(pos.x + col * target_size.x, pos.y + row * target_size.y);
            ImVec2 max(pos.x + (col + 1) * target_size.x, pos.y + (row + 1) * target_size.y);
            // highlight border of square green
            draw_list->AddRect(min, max, IM_COL32(0, 255, 0, 255));

            auto moves = game.generateMoves(selected->source);
            for (auto &move : moves)
            {
                int row = move.target / 8;
                int col = move.target % 8;
                ImVec2 min(pos.x + col * target_size.x, pos.y + row * target_size.y);
                ImVec2 max(pos.x + (col + 1) * target_size.x, pos.y + (row + 1) * target_size.y);
                // add grey circle in the middle of the square
                draw_list->AddCircleFilled(ImVec2((min.x + max.x) / 2, (min.y + max.y) / 2), target_size.x / 4, IM_COL32(128, 128, 128, 128));
            }
        }

        if (game.isCheckmated())
        {
            ui::OpenPopup("Checkmate");
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
    // const char *f = argc > 1 ? argv[1] : "Vienna.pgn";
    // std::string filename = "assets/pgns/" + std::string(f);

    ChessBoard board(1200, 780, "Test");
    board.Show();
}