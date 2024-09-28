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

public:
    movetree_t();
    movetree_t(const move_node_t &data, movetree_t *parent = nullptr, size_t tab_level = 0);
    move_node_t getData() const;
    movetree_t *getParent() const;
    std::vector<movetree_t *> getChildren() const;
    movetree_t *addChild(const move_node_t &data);
};
#else
typedef struct movetree_s movetree_t;
#endif // __cplusplus

#endif // MOVE_TREE_H
