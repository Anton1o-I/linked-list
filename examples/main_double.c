#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "../doubly_linked/doubly_linked.h"

int main(){
    dib *h = block_new(2);
    dib *fs_result = append(h, 3);
    dib *bs_result = prepend(h, 1);
    append(h, 3);
    printf("Length of list - %d\n", len(h));
    traverse_forward(h);
    traverse_back(h);
    printf("Sum of List - %d\n",sum(h));
    pop(h);
    printf("Length after Delete: %d\n", len(h));
    dib *t = insert_after(h, 101);
    insert_before(t, 10);
    traverse_forward(h);
    printf("Forward Search - %p == %p\n", forward_search(h, 3), fs_result);
    printf("Backward Search - %p == %p\n", backward_search(h, 1), bs_result);
}