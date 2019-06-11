cc ?= gcc
CFLAGS = -std=c99 -O3 -Wall
LDFLAgGS = 
EXAMPLES_DIR = examples
TEST_DIR = tests

.PHONY: run-examples
run-examples:
	$(CC) $(CFLAGS) -o $(EXAMPLES_DIR)/example_single $(EXAMPLES_DIR)/main_single.c singly_linked/singly_linked.c
	./$(EXAMPLES_DIR)/example_single
	$(CC) $(CFLAGS) -o $(EXAMPLES_DIR)/example_double $(EXAMPLES_DIR)/main_double.c doubly_linked/doubly_linked.c
	./$(EXAMPLES_DIR)/example_double

.PHONY: tests
tests:
	$(CC) -o $(TEST_DIR)/singly_tests $(TEST_DIR)/singly_tests.c singly_linked/singly_linked.c $(TEST_DIR)/unity/unity.c
	$(TEST_DIR)/singly_tests
	$(CC) -o $(TEST_DIR)/doubly_tests $(TEST_DIR)/doubly_tests.c doubly_linked/doubly_linked.c $(TEST_DIR)/unity/unity.c
	$(TEST_DIR)/doubly_tests
	rm -f $(TEST_DIR)/singly_tests
	rm -f $(TEST_DIR)/doubly_tests


.PHONY: clean
clean:
	rm -f $(EXAMPLES_DIR)/example_single
	rm -rf $(EXAMPLES_DIR)/example_double
	rm -f $(TEST_DIR)/tests
