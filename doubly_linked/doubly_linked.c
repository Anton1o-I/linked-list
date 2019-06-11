#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "doubly_linked.h"

#define BLOCK_SIZE sizeof(dib)
#define TEMP_BLOCK dib *temp = b 

dib*
block_new(int v)
{
    dib *new = malloc(BLOCK_SIZE);
    if(!new){
        return NULL;
    }
    memset(new, 0, BLOCK_SIZE);
    new->value = v;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

void
block_free(dib *b)
{
    memset(b, 0, BLOCK_SIZE);
    free(b);
    return;
}

dib*
append(dib *b, int v)
{
    TEMP_BLOCK;
    while(temp->next){
        temp = temp->next;
    }
    dib *new = block_new(v);
    temp->next = new;
    new->prev = temp;
    return new;
}

dib*
prepend(dib *b, int v)
{
    TEMP_BLOCK;
    while(temp->prev)
    {
        temp = temp->prev;
    }
    dib *new = block_new(v);
    temp->prev = new;
    new->next = temp;
    return new; 
}

void
remove_block(dib *b)
{
    if (b->next && !b->prev){
        b->next->prev = NULL;
    } 
    if (b->next && b->prev){
        b->next->prev = b->prev;
        b->prev->next = b->next;
    }
    if (!b->next && b->prev){
        b->prev->next = NULL;
    }
    block_free(b);
    return;
}

void
pop(dib *b)
{
    if (!b->next){
        return;
    }
    TEMP_BLOCK;
    while(temp->next->next){
        temp = temp->next;
    }
    remove_block(temp->next);
    temp->next = NULL;
    return;
}

dib*
insert_before(dib *b, int v)
{
    dib *new = block_new(v);
    new->prev = b->prev;
    new->next = b;
    b->prev = new;
    return new;
}

dib*
insert_after(dib *b, int v)
{
    dib *new = block_new(v);
    new->prev = b;
    new->next = b->next;
    b->next = new;
    return new;
}

void
traverse_back(dib *b)
{
    TEMP_BLOCK;
    printf("%d, ", temp->value);
    while(temp->prev){
        temp=temp->prev;
        printf("%d, ", temp->value);
    }
    printf("\n");
    return;
}

void
traverse_forward(dib *b)
{
    TEMP_BLOCK;
    printf("%d, ", temp->value);
    while(temp->next){
        temp=temp->next;
        printf("%d, ", temp->value);
    }
    printf("\n");
    return;
}

dib*
forward_search(dib *head, int v)
{
    dib *temp = head;
    while(temp){
        if(temp->value == v){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

dib*
backward_search(dib *tail, int v)
{
    dib *temp = tail;
    while(temp){
        if(temp->value == v){
            return temp;
        }
        temp = temp->prev;
    }
    return NULL;
}

int
len(dib *b)
{
    dib *ftemp = b;
    dib *btemp = b;
    int c = 1;
    while(ftemp->next){
        c+=1;
        ftemp = ftemp->next;
    }
    while(btemp->prev){
        c+=1;
        btemp = btemp->prev;
    }
    return c;
}

int
sum(dib *b)
{
    dib *ftemp = b;
    dib *btemp = b;
    int s = b->value;
    while(ftemp->next){
        ftemp=ftemp->next;
        s+=ftemp->value;

    }
    while(btemp->prev){
        btemp = btemp->prev;
        s+=btemp->value;
    }
    return s;
}



