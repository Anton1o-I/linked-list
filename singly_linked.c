#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "singly_linked.h"

#define BLOCK_SIZE sizeof(block)
#define TEMP_BLOCK block *temp; temp = head


block*
block_new(int v)
{
    block *new = malloc(BLOCK_SIZE);
    if (!new) {
        return NULL;
    }
    memset(new, 0, BLOCK_SIZE);
    new->value = v;
    new->next = NULL;
    return new;
}


void
block_free(block *b)
{
    memset(b, 0, BLOCK_SIZE);
    free(b);
    return;
}


block* 
append(block *head, int v)
{
    TEMP_BLOCK;
    while (temp->next) {
        temp = temp->next;
    }
    block *new_block= block_new(v);
    temp->next = new_block;
    return new_block;
}

void 
remove_block(block *head, block *del_block)
{
    TEMP_BLOCK;
    if (temp == del_block){
        block_free(temp);
        return;
    }
    while (temp->next != del_block){
        temp = temp->next;
    }
    block *block_delete = temp->next;
    temp->next = temp->next->next;
    block_free(block_delete);
    return;
}

block* 
insert_before(block *head, block *insert_on, int v) 
{
    TEMP_BLOCK;
    while (1){
        if (temp->next == insert_on) {
            block * new_block;
            new_block = block_new(v);
            new_block->next = temp->next;
            temp->next = new_block;
            return new_block;
        }
        temp = temp->next;
    }
}

block* 
find_first(block *head, int v)
{
    TEMP_BLOCK;
    while (1){
        if (temp->value == v) {
            return temp;
        }
        temp = temp->next;
    }
}

int 
len(block *head)
{
    int c = 1;
    TEMP_BLOCK;
    while (temp->next) {
            c += 1;
            temp = temp->next;
        }
    return c;
}

void 
pop(block *head)
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

void
traverse(block *head)
{
    TEMP_BLOCK;
    while(temp){
        printf("value:%d\n", temp->value);
        temp=temp->next;
    }
}
