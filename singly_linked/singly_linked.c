#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "singly_linked.h"

#define BLOCK_SIZE sizeof(sib)
#define TEMP_BLOCK sib *temp = head


sib*
block_new(int v)
{
    sib *new = malloc(BLOCK_SIZE);
    if (!new) {
        return NULL;
    }
    memset(new, 0, BLOCK_SIZE);
    new->value = v;
    new->next = NULL;
    return new;
}


void
block_free(sib *b)
{
    memset(b, 0, BLOCK_SIZE);
    free(b);
    return;
}


sib* 
append(sib *head, int v)
{
    TEMP_BLOCK;
    while (temp->next) {
        temp = temp->next;
    }
    sib *new_block= block_new(v);
    temp->next = new_block;
    return new_block;
}

void 
remove_block(sib *head, sib *del_block)
{
    TEMP_BLOCK;
    if (temp == del_block){
        block_free(temp);
        return;
    }
    while (temp->next != del_block){
        temp = temp->next;
    }
    sib *block_delete = temp->next;
    temp->next = temp->next->next;
    block_free(block_delete);
    return;
}

sib* 
insert_before(sib *head, sib *insert_on, int v) 
{
    TEMP_BLOCK;
    while (1){
        if (temp->next == insert_on) {
            sib * new_block;
            new_block = block_new(v);
            new_block->next = temp->next;
            temp->next = new_block;
            return new_block;
        }
        temp = temp->next;
    }
}

sib* 
find_first(sib *head, int v)
{
    TEMP_BLOCK;
    while (1){
        if (temp->value == v) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int 
len(sib *head)
{
    int c = 1;
    TEMP_BLOCK;
    while (temp->next) {
            c += 1;
            temp = temp->next;
        }
    return c;
}

int
sum(sib *head)
{
    int s = 0;
    TEMP_BLOCK;
    while(temp->next){
        s += temp->value;
        temp = temp->next;
    } 
    return s;
}

void 
pop(sib *head)
{
    if (!head->next){
        return;
    }
    TEMP_BLOCK;
    while (temp->next->next){
        temp = temp->next;
    }
    block_free(temp->next);
    temp->next = NULL;
    return;
}

void
traverse(sib *head)
{
    TEMP_BLOCK;
    while(temp){
        printf("value:%d\n", temp->value);
        temp=temp->next;
    }
}
