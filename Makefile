cc ?= gcc
CFLAGS = -std=c99 -O3 -Wall
LDFLAgGS = 
EXAMPLES_DIR = examples
TEST_DIR = tests

.PHONY: run-example
run-example:
	$(CC) $(CFLAGS) -o $(EXAMPLES_DIR)/example $(EXAMPLES_DIR)/main.c linked_list.c
	./$(EXAMPLES_DIR)/example

.PHONY: test
test:
	$(CC) -o $(TEST_DIR)/tests $(TEST_DIR)/tests.c linked_list.c $(TEST_DIR)/unity/unity.c
	$(TEST_DIR)/tests
	rm -f $(TEST_DIR)/tests

.PHONY: clean
clean:
	rm -f $(EXAMPLES_DIR)/example
	rm -f $(TEST_DIR)/tests
