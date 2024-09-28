#include "movetree.h"
#include <game.h>

movetree_t::movetree_t()
    : data({
          .state = game_t::FromStartingPosition().getState(),
      }),
      parent(nullptr), tab_level(0)
{
}

movetree_t::movetree_t(const move_node_t &data, movetree_t *parent, size_t tab_level)
    : data(data), parent(parent), tab_level(tab_level)
{
}

move_node_t movetree_t::getData() const
{
    return data;
}

movetree_t *movetree_t::getParent() const
{
    return parent;
}

std::vector<movetree_t *> movetree_t::getChildren() const
{
    return children;
}

movetree_t *movetree_t::addChild(const move_node_t &data)
{
    size_t tab_level = this->children.size() == 0 ? this->tab_level : this->tab_level + 1;
    children.emplace_back(new movetree_t(data, this, tab_level));
    return children.back();
}