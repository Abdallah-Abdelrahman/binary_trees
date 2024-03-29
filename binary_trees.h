#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

/*----------- HEADERS ------------*/
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stddef.h>

/*----------- MACROS ------------*/
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define QUEUE_SIZE 500
#define SWAP(x, y)\
{\
	x->n ^= y->n;\
	y->n ^= x->n;\
	x->n ^= y->n;\
}
/* Initialize a queue */
#define QUEUE(ptr, size)\
	{0, 0, NULL};\
	ptr.queue = calloc(sizeof(binary_tree_t), size)


/*----------- STRUCTS ------------*/
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

/**
 * struct Queue_s - Queue data structure
 *
 * @front: front of the queue
 * @rear: back of the queue
 * @queue: arrey of struct binary_tree_s
 */
struct Queue_s
{
	int front, rear;
	struct binary_tree_s **queue;
};

/*----------- ALIASES ------------*/
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;
typedef struct Queue_s queue_t;

/*----------- PROTOTYPES ------------*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
avl_t *sorted_array_to_avl(int *array, size_t size);
int binary_tree_is_heap(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
heap_t *array_to_heap(int *array, size_t size);
int heap_extract(heap_t **root);
int *heap_to_sorted_array(heap_t *heap, size_t *size);

/*----------- HELPERS ------------*/
void binary_tree_print(const binary_tree_t *tree);
size_t _pow(int base, int exp);
bst_t *get_root(bst_t *node);
bst_t *inorder_successor(binary_tree_t *node);
bst_t *min_node(bst_t *tree);
void repair_balance(avl_t *tree);
avl_t *build_avl(avl_t **tree, avl_t *p, int *array, int first, int last);

#endif /* _BINARY_TREES_H_ */
