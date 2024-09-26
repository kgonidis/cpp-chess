#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "types.h"

typedef struct attack_boards_s
{
    Bitboard pawn[2][64];
    Bitboard knight[64];
    Bitboard king[64];
    Bitboard bishop[64][512];
    Bitboard rook[64][4096];
    Bitboard masks[2][64];
    uint8_t initialized;
} attack_boards_t;

#ifdef __cplusplus

template <typename T>
class NodeTree
{
public:
    using ptr_t = std::shared_ptr<T>;
    using ptr_nt = std::shared_ptr<NodeTree<T>>;
    ptr_t value;
    NodeTree<T> *parent;
    ptr_nt main;
    ptr_nt next;
    std::vector<ptr_nt> children;

    NodeTree() : value(nullptr), parent(nullptr), next(nullptr) {}
    NodeTree(const T &m) : value(new T(m)), parent(nullptr), next(nullptr) {}
    NodeTree(const T &m, NodeTree<T> *p) : NodeTree(m) { parent = p; }

    class iterator
    {
    private:
        NodeTree<T> *mt;
        int index;

    public:
        iterator(NodeTree<T> *mt) : mt(mt), index(-1)
        {
            if (mt == nullptr || mt->value == nullptr)
                index = 0;
        }

        iterator &operator++()
        {
            index++;

            if (index >= (int)mt->children.size())
            {
                index = 0;
                mt = mt->main.get();
                if (mt == nullptr || mt->children.size() == 0)
                {
                    mt = nullptr;
                }
            }

            return *this;
        }

        iterator operator++(int)
        {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const iterator &rhs) const
        {
            return mt == rhs.mt && index == rhs.index;
        }

        bool operator!=(const iterator &rhs) const
        {
            return !(rhs == *this);
        }

        NodeTree<T> operator*() const
        {
            if (index > -1 && index < (int)mt->children.size())
                return *mt->children[index].get();
            return *mt;
        }

        NodeTree<T> *operator->() const
        {
            if (index > -1 && index < (int)mt->children.size())
                return mt->children[index].get();
            return mt;
        }
    };

    bool isAlternate() const
    {
        return parent != nullptr && parent->main != this;
    }

    NodeTree<T> *operator[](int index) const
    {
        int i;
        for (auto it = begin(), i = 0; it != end(); ++it, ++i)
            if (i == index)
                return *it;
        return nullptr;
    }

    bool operator==(const NodeTree<T> &mt) const
    {
        return *value == *mt.value;
    };

    ptr_nt AddChild(const T &m)
    {
        auto mt = std::make_shared<NodeTree<T>>(m, this);
        children.emplace_back(mt);
        if (next == nullptr)
            next = mt;
        if (main == nullptr)
            main = mt;
        return children.back();
    };

    ptr_nt AddChild(ptr_nt mt)
    {
        mt->parent = this;
        children.emplace_back(mt);
        if (next == nullptr)
            next = mt;
        if (main == nullptr)
            main = mt;
        return mt;
    };

    ptr_nt AddChild(NodeTree<T> &mt)
    {
        return AddChild(std::make_shared<NodeTree<T>>(mt));
    }

    void clear()
    {
        value = nullptr;
        children.clear();
        next = nullptr;
        main = nullptr;
    }

    NodeTree<T>::iterator begin()
    {
        return NodeTree<T>::iterator(this);
    }

    NodeTree<T>::iterator end()
    {
        return NodeTree<T>::iterator(nullptr);
    }

    // std::string Print(int move_number = 2, bool isMain = true) const
    // {
    //     std::string s = "";
    //     if (move_number % 2 == 0)
    //         s += std::to_string(move_number / 2) + ". ";

    //     s += value->ToString();
    //     bool alternate = false;
    //     if (isMain && this->parent != nullptr)
    //         for (auto *child : this->parent->children)
    //         {
    //             if (child == this)
    //                 continue;
    //             alternate = true;
    //             s += " (";
    //             if (child->value->GetSide() == BLACK)
    //                 s += std::to_string(move_number / 2) + "... ";
    //             s += child->Print(move_number, false);
    //             s += ") ";
    //         }

    //     if (main != nullptr)
    //     {
    //         s += " ";
    //         ++move_number;
    //         if (alternate && main->value->GetSide() == BLACK)
    //             s += std::to_string(move_number / 2) + "... ";
    //         s += main->Print(move_number);
    //     }

    //     return s;
    // }

    // friend std::ostream &operator<<(std::ostream &os, const NodeTree<T> &mt)
    // {
    //     os << mt.Print();
    //     return os;
    // }
};

typedef NodeTree<move_state_t> move_tree_t;
#else
typedef void *move_tree_t;
#endif

extern attack_boards_t ATTACK_BOARDS;

#ifdef __cplusplus
extern "C"
{
#endif

    void attack_boards_init();
    void get_bishop_attacks(Bitboard *bitboard, int square, Bitboard blockers);
    void get_rook_attacks(Bitboard *bitboard, int square, Bitboard blockers);
    void get_queen_attacks(Bitboard *bitboard, int square, Bitboard blockers);

    // void new_move_tree(move_tree_t *tree);
    // void new_move_tree_s(move_tree_t *tree, const move_state_t state);
    // void new_move_tree_sp(move_tree_t *tree, const move_state_t state, move_tree_t *parent);

    // move_state_t *move_tree_get(move_tree_t *tree);

    // void delete_move_tree(move_tree_t *tree);
    // void add_move_tree_child(move_tree_t *tree, const move_state_t state);
    // void add_move_tree_childp(move_tree_t *tree, move_tree_t *child);

#ifdef __cplusplus
}
#endif

#endif