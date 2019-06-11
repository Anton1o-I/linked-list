#ifndef _DOUBLY_LINKED_H
#define _DOUBLY_LINKED_H

/**
 * dbl_int_block stores information for each block in a doubly
 * linked list.
 */
struct dbl_int_block
{
    int value;
    struct dbl_int_block *prev;
    struct dbl_int_block *next;
};

/**
 * dib aliases the dbl_int_block struct
 */
typedef struct dbl_int_block dib;

/**
 * block_new allocates space in the heap for a new doubly linked
 * block type and hydrates the value
 */
dib *block_new(int v);

/**
 * block_free sets the values in the space to 0 and
 *  frees the allocated memory for a specific block.
 */
void block_free(dib *b);

/**
 * append writes a new doubly linked block to the end of the list
 */
dib *append(dib *b, int v);

/**
 * prepend writes a new block to the beginning of the doubly linked list.
 */
dib *prepend(dib *b, int v);

/**
 * remove_block removes the specified block from the doubly linked list
 */
void remove_block(dib *b);

/**
 * pop removes the last block in the double linked list
 */
void pop(dib *b);

/**
 * insert_before adds a block before the specified block.
 */
dib *insert_before(dib *b, int v);

/**
 * insert_after adds a block before the specified block.
 */
dib *insert_after(dib *b, int v);

/**
 * traverse_back prints out the values from the specified block backwards.
 */
void traverse_back(dib *b);

/**
 * traverse_forward prints out the values from the specified block forwards.
 */
void traverse_forward(dib *b);

/**
 * forward_search finds the first item in the list that matches the given value, starting
 * at the head you provider and moving forward, returns NULL if block not found.
 */
dib *forward_search(dib *head, int v);

/**
 * backward_search finds the first item in the list that matches the given value,
 * starting at the tail and moving backwards, returns NULL if block not found.
 */
dib *backward_search(dib *tail, int v);

/**
 * len returns the length of the list when given any block in the list.
 */
int len(dib *b);

/**
 * sum returns the sum of the items in the list when given any block in the list.
 */
int sum(dib *b);

#endif /* _DOUBLE_LINKED_H */