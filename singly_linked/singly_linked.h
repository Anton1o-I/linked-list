#ifndef _SINGLY_LINKED_H
#define _SINGLY_LINKED_H

/**
 * node contains the stored integer value and the
 * pointer to the next node in the list.
 */
struct single_int_node
{
    int value;
    struct single_int_node *next;
};

/**
 * alias node struct 
 */
typedef struct single_int_node sib;

/**
 * node_new allocates memory on heap for a new node and 
 * returns pointer to memory space.
 */
sib *node_new(int v);

/**
 * node_free sets all bytes to 0 in allocated space and frees the memory address for reallocation.
 */
void node_free(sib *b);

/**
 * appends a link to the end of the list
 */
sib *append(sib *head, int v);

/**
 * remove will remove the specified node by freeing the allocated space
 * and adjusting the pointers so that space is skipped.
 */
void remove_node(sib *head, sib *del_node);

/**
 * insert_before inserts a link before the link in the parameter insert_on
 */
sib *insert_before(sib *head, sib *insert_on, int v);

/**
 * find_first finds and returns the first node with the specified value.
 */
sib *find_first(sib *head, int v);

/**
 * len gets length of linked list.
 */
int len(sib *head);

/**
 * sum gets the sum of the items in the linked list.
 */
int sum(sib *head);

/**
 * pop removes values from end of list.
 */
void pop(sib *head);

/**
 * traverse prints the information for each node in the 
 * linked list.
 */
void traverse(sib *head);

#endif /* _SINGLY_LINKED_H */