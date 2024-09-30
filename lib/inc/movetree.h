#ifndef MOVE_TREE_H
#define MOVE_TREE_H

#include "types.h"

#ifdef __cplusplus
#include <memory>
#include <vector>

class movetree_t
{
private:
    move_node_t data;
    movetree_t *parent;
    std::vector<movetree_t *> children;
    size_t tab_level;
    size_t current_child;

public:
    movetree_t();
    movetree_t(const move_node_t &data, movetree_t *parent = nullptr, size_t tab_level = 0);

    move_node_t getData() const;
    movetree_t *getParent() const;
    movetree_t *getNext() const;
    std::vector<movetree_t *> getChildren() const;
    size_t getTabs() const;

    void setLine();
    void setData(const move_node_t &data);
    movetree_t *addChild(const move_node_t &data);
};
#else
typedef struct movetree_s{
    move_node_t data;
    struct movetree_s *parent;
    struct movetree_s **children;
    long tab_level;
} movetree_t;
#endif // __cplusplus

#endif // MOVE_TREE_H
