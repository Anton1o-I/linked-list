#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "../singly_linked/singly_linked.h"
#include "unity/unity.h"

#define HEAD_BLOCK sib *h = block_new(10)

/**
 * test_head_new tests whether a new block is created with 
 * the correct value and a NULL pointer to next.
 */ 
void
test_head_new(void)
{
    sib *h = block_new(10);
    TEST_ASSERT_NOT_NULL(h);
    TEST_ASSERT_EQUAL_INT(10, h->value);
    TEST_ASSERT_NULL(h->next);
    block_free(h);
}

/**
 * test_append tests whether a new block is appended 
 * to the list correctly.
 */ 
void
test_append(void)
{
    HEAD_BLOCK;
    sib *n = append(h, 1);
    TEST_ASSERT_NOT_NULL(h->next);
    TEST_ASSERT_NULL(n->next);
    TEST_ASSERT_EQUAL_INT(1, n->value);
    block_free(h);
    block_free(n);
}

/**
 * 
 */
void
test_len(void)
{
    HEAD_BLOCK;
    for (int i=0; i<10; i++){
        append(h, 1);
    }
    int list_len = len(h);
    TEST_ASSERT_EQUAL_INT(11, list_len);
}

/**
 * test_pop tests that the last value in list is removed.
 */ 
void
test_pop(void)
{
    HEAD_BLOCK;
    sib *two = append(h, 11);
    pop(h);
    TEST_ASSERT_EQUAL_INT(1, len(h));
    TEST_ASSERT_NULL(h->next);
}

/**
 * test_find_first tests to ensure that searching through
 * the linked list finds the correct block.
 */
void
test_find_first(void)
{
    HEAD_BLOCK;
    sib *two = append(h, 11);
    TEST_ASSERT_EQUAL_PTR(two, find_first(h, 11));
} 

/**
 * test_insert_before tests to ensure that a block is inserted in the right
 * location and the next pointers are all correct.
 */ 
void test_insert_before(void)
{
    HEAD_BLOCK;
    sib *two = append(h, 11);
    sib *before = insert_before(h, two, 13);
    TEST_ASSERT_EQUAL_PTR(h->next, before);
    TEST_ASSERT_EQUAL_PTR(before->next, two);
}


int
main(void)
{
	UNITY_BEGIN();

    RUN_TEST(test_head_new);
    RUN_TEST(test_append);
    RUN_TEST(test_len);
    RUN_TEST(test_pop);
    RUN_TEST(test_find_first);
    RUN_TEST(test_insert_before);

    return UNITY_END();
}



