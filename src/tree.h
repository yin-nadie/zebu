
#ifndef ZEBU_TREE_H_
#define ZEBU_TREE_H_

#include "node.h"

/*
 * Abstract Syntax Tree
 *
 * Not actually the tree, but a factory to produce new nodes that can
 * deallocate all them with a sigle call.
 */
struct zz_tree {
	/* Size of each node */
	size_t node_size;
	/* All nodes managed by this tree */
	struct zz_list nodes;
};

/*
 * Initialize tree 
 *
 * @tree a zz_tree
 * @node_size size of node; it must be at least sizeof(struct zz_node)
 */
void zz_tree_init(struct zz_tree *tree, size_t node_size);
/*
 * Destroy tree 
 *
 * @tree a zz_tree
 */
void zz_tree_destroy(struct zz_tree *tree);

/*
 * Create a node 
 *
 * @tree a zz_tree
 * @tok a token
 * @data payload
 * @return a new zz_node allocated by _tree_
 */
struct zz_node *zz_node(struct zz_tree *tree, const char *tok, struct zz_data data);
/*
 * Dereference---and potentially destroy---a node 
 *
 * @node a zz_node
 * @return node or __NULL__
 */
struct zz_node *zz_unref(struct zz_node *n);
/*
 * Copy a node 
 *
 * @tree a zz_tree
 * @node zz_node to copy
 * @return a new zz_node allocated by _tree_
 */
struct zz_node *zz_copy(struct zz_tree *tree, struct zz_node *node);
/*
 * Copy a node and all its children recursively 
 *
 * @tree a zz_tree
 * @node zz_node to copy
 * @return a new zz_node allocated by _tree_
 */
struct zz_node *zz_copy_recursive(struct zz_tree *tree, struct zz_node *node);

#endif         // ZEBU_TREE_H_
