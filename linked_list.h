#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

/**
 * block contains the stored integer value and the
 * pointer to the next block in the list.
 */
struct block_int {
    int value;
    struct block_int *next;
};

/**
 * alias block struct 
 */ 
typedef struct block_int block;

/**
 * block_new allocates memory on heap for a new block and 
 * returns pointer to memory space.
 */
block* block_new(int v);

/**
 * block_free sets all bytes to 0 in allocated space and frees the memory address for reallocation.
 */
void block_free(block *b);

/**
 * appends a link to the end of the list
 */
block* append(block *head, int v);

/**
 * remove will remove the specified block by freeing the allocated space
 * and adjusting the pointers so that space is skipped.
 */
void remove_block(block *head, block *del_block);

/**
 * insert_before inserts a link before the link in the parameter insert_on
 */
block* insert_before(block *head, block *insert_on, int v);

/**
 * find_first finds and returns the first block with the specified value.
 */
block* find_first(block *head, int v);

/**
 * len gets length of linked list.
 */
int len(block *head);

/**
 * pop removes values from end of list.
 */
void pop(block *head);

/**
 * traverse prints the information for each block in the 
 * linked list.
 */
void
traverse(block *head);

#endif /* _LINKED_LIST_H */