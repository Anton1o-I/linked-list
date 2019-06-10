#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct block{
    int value;
    struct block *next;
};

#define BLOCK_SIZE sizeof(struct block)
#define TEMP_BLOCK struct block *temp; temp = head

/**
 * create allocates memory on heap for a new block and 
 * returns pointer to memory space.
 */
struct block*
block_new(int v)
{
    struct block *new = malloc(BLOCK_SIZE);
    if (!new) {
        return NULL;
    }
    memset(new, 0, BLOCK_SIZE);
    new->value = v;
    new->next = NULL;
    return new;
}

/**
 * block_free sets all bytes to 0 in allocated space and frees the memory address for reallocation.
 */
void
block_free(struct block *b)
{
    memset(b, 0, BLOCK_SIZE);
    free(b);
    return;
}

/**
 * appends a link to the end of the list
 */
struct block* 
append(struct block *head, int v)
{
    TEMP_BLOCK;
    while (temp->next) {
        temp = temp->next;
    }
    struct block *new_block= block_new(v);
    temp->next = new_block;
    return new_block;
}

/**
 * insert_before inserts a link before the link in the parameter insert_on
 */
struct block* 
insert_before(struct block *head, struct block *insert_on, int v) 
{
    TEMP_BLOCK;
    while (1){
        if (temp->next == insert_on) {
            struct block * new_block;
            new_block = block_new(v);
            new_block->next = temp->next;
            temp->next = new_block;
            return new_block;
        }
        temp = temp->next;
    }
}

/**
 * find_first finds and returns the first block with the specified value.
 */
struct block* 
find_first(struct block *head, int v)
{
    TEMP_BLOCK;
    while (1){
        if (temp->value == v) {
            return temp;
        }
        temp = temp->next;
    }
}

/**
 * len gets length of linked list.
 */
int 
len(struct block *head)
{
    int c = 1;
    TEMP_BLOCK;
    while (temp->next) {
            c += 1;
            temp = temp->next;
        }
    return c;
}

/**
 * delete will delete the specified block by freeing the allocated space
 * and adjusting the pointers so that space is skipped.
 */
void 
remove_block(struct block *head, struct block *del_block)
{
    TEMP_BLOCK;
    if (temp == del_block){
        block_free(temp);
        return;
    }
    while (temp->next != del_block){
        temp = temp->next;
    }
    struct block *block_delete = temp->next;
    temp->next = temp->next->next;
    block_free(block_delete);
    return;
}

/**
 * pop removes values from end of list.
 */
void 
pop(struct block *head)
{
    if (!head->next){
        return;
    }
    TEMP_BLOCK;
    while (temp->next->next){
        temp = temp->next;
    }
    if (!temp->next->next){
        block_free(temp->next);
        temp->next = NULL;
        return;
    }
}

/**
 * traverse prints the information for each block in the 
 * linked list.
 */
void
traverse(struct block *head)
{
    TEMP_BLOCK;
    while(temp){
        printf("value:%d\n", temp->value);
        temp=temp->next;
    }
}

int main()
{
    struct block *head = block_new(1);
    struct block *second = append(head, 2);
    struct block *third = append(head, 3);
    traverse(head);
    remove_block(head, second);
    printf("%d\n", len(head));
    struct block *fourth = append(head, 4);
    printf("%d\n", len(head));
    pop(head);
    printf("%d\n", len(head));
    insert_before(head, third, 5);
    traverse(head);
    return 0;
}