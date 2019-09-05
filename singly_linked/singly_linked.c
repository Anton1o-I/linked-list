#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "singly_linked.h"

#define NODE_SIZE sizeof(sib)
#define TEMP_NODE sib *temp = head


sib*
node_new(int v)
{
    sib *new = malloc(NODE_SIZE);
    if (!new) {
        return NULL;
    }
    memset(new, 0, NODE_SIZE);
    new->value = v;
    new->next = NULL;
    return new;
}


void
node_free(sib *b)
{
    memset(b, 0, NODE_SIZE);
    free(b);
    return;
}


sib* 
append(sib *head, int v)
{
    TEMP_NODE;
    while (temp->next) {
        temp = temp->next;
    }
    sib *new_node= node_new(v);
    temp->next = new_node;
    return new_node;
}

void 
remove_node(sib *head, sib *del_node)
{
    TEMP_NODE;
    if (temp == del_node){
        node_free(temp);
        return;
    }
    while (temp->next != del_node){
        temp = temp->next;
    }
    sib *node_delete = temp->next;
    temp->next = temp->next->next;
    node_free(node_delete);
    return;
}

sib* 
insert_before(sib *head, sib *insert_on, int v) 
{
    TEMP_NODE;
    while (1){
        if (temp->next == insert_on) {
            sib * new_node;
            new_node = node_new(v);
            new_node->next = temp->next;
            temp->next = new_node;
            return new_node;
        }
        temp = temp->next;
    }
}

sib* 
find_first(sib *head, int v)
{
    TEMP_NODE;
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
    TEMP_NODE;
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
    TEMP_NODE;
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
    TEMP_NODE;
    while (temp->next->next){
        temp = temp->next;
    }
    node_free(temp->next);
    temp->next = NULL;
    return;
}

void
traverse(sib *head)
{
    TEMP_NODE;
    while(temp){
        printf("value:%d\n", temp->value);
        temp=temp->next;
    }
}
