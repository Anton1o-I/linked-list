#ifndef _DOUBLY_LINKED_H
#define _DOUBLY_LINKED_H

/**
 * dbl_int_node stores information for each node in a doubly
 * linked list.
 */
struct dbl_int_node
{
    int value;
    struct dbl_int_node *prev;
    struct dbl_int_node *next;
};

/**
 * dib aliases the dbl_int_node struct
 */
typedef struct dbl_int_node dib;

/**
 * node_new allocates space in the heap for a new doubly linked
 * node type and hydrates the value
 */
dib *node_new(int v);

/**
 * node_free sets the values in the space to 0 and
 *  frees the allocated memory for a specific node.
 */
void node_free(dib *b);

/**
 * append writes a new doubly linked node to the end of the list
 */
dib *append(dib *b, int v);

/**
 * prepend writes a new node to the beginning of the doubly linked list.
 */
dib *prepend(dib *b, int v);

/**
 * remove_node removes the specified node from the doubly linked list
 */
void remove_node(dib *b);

/**
 * pop removes the last node in the double linked list
 */
void pop(dib *b);

/**
 * insert_before adds a node before the specified node.
 */
dib *insert_before(dib *b, int v);

/**
 * insert_after adds a node before the specified node.
 */
dib *insert_after(dib *b, int v);

/**
 * traverse_back prints out the values from the specified node backwards.
 */
void traverse_back(dib *b);

/**
 * traverse_forward prints out the values from the specified node forwards.
 */
void traverse_forward(dib *b);

/**
 * forward_search finds the first item in the list that matches the given value, starting
 * at the head you provider and moving forward, returns NULL if node not found.
 */
dib *forward_search(dib *head, int v);

/**
 * backward_search finds the first item in the list that matches the given value,
 * starting at the tail and moving backwards, returns NULL if node not found.
 */
dib *backward_search(dib *tail, int v);

/**
 * len returns the length of the list when given any node in the list.
 */
int len(dib *b);

/**
 * sum returns the sum of the items in the list when given any node in the list.
 */
int sum(dib *b);

#endif /* _DOUBLE_LINKED_H */