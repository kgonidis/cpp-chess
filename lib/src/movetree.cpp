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

void movetree_t::deleteChildren()
{
    for (auto child : children)
    {
        child->deleteChildren();
        delete child;
    }
    children.clear();
}

move_node_t movetree_t::getData() const
{
    return data;
}

movetree_t *movetree_t::getParent() const
{
    return parent;
}

movetree_t *movetree_t::getNext() const
{
    if (children.size() == 0)
        return nullptr;
    return children[current_child];
}

std::vector<movetree_t *> movetree_t::getChildren() const
{
    return children;
}

size_t movetree_t::getTabs() const
{
    return tab_level;
}

void movetree_t::setLine()
{
    if (parent == nullptr)
        return;
    for (size_t i = 0; i < parent->children.size(); i++)
    {
        if (parent->children[i] == this)
        {
            parent->current_child = i;
            break;
        }
    }
    parent->setLine();
}

void movetree_t::setData(const move_node_t &data)
{
    this->data = data;
}

movetree_t *movetree_t::addChild(const move_node_t &data)
{
    size_t tab_level = this->children.size() == 0 ? this->tab_level : this->tab_level + 1;
    children.emplace_back(new movetree_t(data, this, tab_level));
    return children.back();
}