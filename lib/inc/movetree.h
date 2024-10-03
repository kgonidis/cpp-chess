#ifndef MOVE_TREE_H
#define MOVE_TREE_H

#include "types.h"

#ifdef __cplusplus
#include <memory>
#include <vector>

/**
 * @brief Represents a node in a move tree for a chess game.
 */
class movetree_t
{
private:
    move_node_t data; ///< The data associated with this node.
    movetree_t *parent; ///< Pointer to the parent node.
    std::vector<movetree_t *> children; ///< Vector of pointers to child nodes.
    size_t tab_level; ///< The tab level for this node (used for formatting).
    size_t current_child; ///< Index of the current child node.

public:
    /**
     * @brief Default constructor.
     */
    movetree_t();

    /**
     * @brief Constructs a move tree node with given data and optional parent.
     * 
     * @param data The data for this node.
     * @param parent Pointer to the parent node (default is nullptr).
     * @param tab_level The tab level for this node (default is 0).
     */
    movetree_t(const move_node_t &data, movetree_t *parent = nullptr, size_t tab_level = 0);

    /**
     * @brief Destructor.
     */
    ~movetree_t();

    /**
     * @brief Gets the data associated with this node.
     * 
     * @return The data of this node.
     */
    move_node_t getData() const;

    /**
     * @brief Gets the parent node.
     * 
     * @return Pointer to the parent node.
     */
    movetree_t *getParent() const;

    /**
     * @brief Gets the next child node.
     * 
     * @return Pointer to the next child node.
     */
    movetree_t *getNext() const;

    /**
     * @brief Gets the children of this node.
     * 
     * @return Vector of pointers to child nodes.
     */
    std::vector<movetree_t *> getChildren() const;

    /**
     * @brief Gets the tab level of this node.
     * 
     * @return The tab level.
     */
    size_t getTabs() const;

    /**
     * @brief Sets this node as a line node.
     */
    void setLine();

    /**
     * @brief Sets the data for this node.
     * 
     * @param data The data to set.
     */
    void setData(const move_node_t &data);

    /**
     * @brief Adds a child node with given data.
     * 
     * @param data The data for the child node.
     * @return Pointer to the newly added child node.
     */
    movetree_t *addChild(const move_node_t &data);
};

#else

/**
 * @brief Represents a node in a move tree for a chess game (C version).
 */
typedef struct movetree_s
{
    move_node_t data; ///< The data associated with this node.
    struct movetree_s *parent; ///< Pointer to the parent node.
    struct movetree_s **children; ///< Array of pointers to child nodes.
    long tab_level; ///< The tab level for this node (used for formatting).
} movetree_t;

#endif // __cplusplus

#endif // MOVE_TREE_H