#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "../doubly_linked/doubly_linked.h"
#include "unity/unity.h"

#define HEAD_BLOCK dib *h = block_new(10)

/**
 * tests that a new block is created with the specified value and NULL pointers
 * on both prev and next.
 */ 
void
test_block_new(void)
{
    dib *h = block_new(10);
    TEST_ASSERT_EQUAL_INT(10,h->value);
    TEST_ASSERT_NULL(h->prev);
    TEST_ASSERT_NULL(h->next);
    block_free(h);
}

void
test_append(void)
{
    HEAD_BLOCK;
    append(h,20);
    TEST_ASSERT_EQUAL_INT(20,h->next->value);
}

void
test_prepend(void)
{
    HEAD_BLOCK;
    prepend(h,20);
    TEST_ASSERT_EQUAL_INT(20, h->prev->value);
}

void
test_remove_block(void)
{
    HEAD_BLOCK;
    dib *t = append(h, 20);
    remove_block(t);
    TEST_ASSERT_NULL(h->next);
}

void
test_pop(void)
{
    HEAD_BLOCK;
    dib *t = append(h, 20);
    dib *n = append(h, 21);
    pop(h);
    TEST_ASSERT_NULL(t->next);
}

void
test_sum(void)
{
    HEAD_BLOCK;
    dib *t = append(h, 10);
    TEST_ASSERT_EQUAL_INT(20, sum(h));
}

void
test_count(void)
{
    HEAD_BLOCK;
    for(int i = 0; i<10; i++){
        append(h, i);
    }
    TEST_ASSERT_EQUAL_INT(11, len(h));
}

int
main(void)
{
	UNITY_BEGIN();

    RUN_TEST(test_block_new);
    RUN_TEST(test_append);
    RUN_TEST(test_prepend);
    RUN_TEST(test_remove_block);
    RUN_TEST(test_pop);
    RUN_TEST(test_count);
    RUN_TEST(test_sum);
    
    return UNITY_END();
}



