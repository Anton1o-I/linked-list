#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

/**
 * block contains the stored integer value and the
 * pointer to the next block in the list.
 */
struct single_int_block {
    int value;
    struct single_int_block *next;
};

/**
 * alias block struct 
 */ 
typedef struct single_int_block sib;

/**
 * block_new allocates memory on heap for a new block and 
 * returns pointer to memory space.
 */
sib* block_new(int v);

/**
 * block_free sets all bytes to 0 in allocated space and frees the memory address for reallocation.
 */
void block_free(sib *b);

/**
 * appends a link to the end of the list
 */
sib* append(sib *head, int v);

/**
 * remove will remove the specified block by freeing the allocated space
 * and adjusting the pointers so that space is skipped.
 */
void remove_block(sib *head, sib *del_block);

/**
 * insert_before inserts a link before the link in the parameter insert_on
 */
sib* insert_before(sib *head, sib *insert_on, int v);

/**
 * find_first finds and returns the first block with the specified value.
 */
sib* find_first(sib *head, int v);

/**
 * len gets length of linked list.
 */
int len(sib *head);

/**
 * pop removes values from end of list.
 */
void pop(sib *head);

/**
 * traverse prints the information for each block in the 
 * linked list.
 */
void
traverse(sib *head);

#endif /* _LINKED_LIST_H */