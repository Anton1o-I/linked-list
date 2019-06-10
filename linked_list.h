#ifndef linked_list_h
#define linked_list_h

/**
 * appends a link to the end of the list
 */
struct block* append(struct block *head, int v);

/**
 * remove will remove the specified block by freeing the allocated space
 * and adjusting the pointers so that space is skipped.
 */
void remove_block(struct block *head, struct block *del_block);

/**
 * insert_before inserts a link before the link in the parameter insert_on
 */
struct block* insert_before(struct block *head, struct block *insert_on, int v);

/**
 * find_first finds and returns the first block with the specified value.
 */
struct block* find_first(struct block *head, int v);

/**
 * len gets length of linked list.
 */
int len(struct block *head);

/**
 * pop removes values from end of list.
 */
void pop(struct block *head);

/**
 * traverse prints the information for each block in the 
 * linked list.
 */
void
traverse(struct block *head);

#endif