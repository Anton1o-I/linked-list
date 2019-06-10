#include <stdio.h>

#include "../singly_linked.h"


int main(){
    sib *h = block_new(10);
    printf("Head Node - value: %d - next: %p\n", h->value, h->next);
    sib *n = append(h,5);
    traverse(h); /* prints out all values in the linked list */
    sib *t = append(h, 101);
    printf("length of list before removing block: %d\n", len(h));
    remove_block(h, n);
    printf("length of list after removing block: %d\n", len(h));
    insert_before(h, t, 2);
    traverse(h);
    printf("Address of block with value 101: %p == address of t: %p\n", 
        find_first(h, 101), (void*)t);
    return 0;
}