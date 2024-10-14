CC = gcc
CFLAGS = -std=c11 -g -Wall -Wshadow --pedantic -Wvla -Werror
EXEC = wordgen

SRC_DIR = .
TEST_DIR = textFiles
SRCS = main.c generate.c
OBJS = $(SRCS:%.c=%.o)
GENERATED_WORDS = 100

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

testall: $(EXEC)
	@for file in $(TEST_DIR)/*.txt; do \
		# Running test on $$file"; \
		./$(EXEC) $$file $(GENERATED_WORDS); \
	done

test1: $(EXEC)
	# Running test on Jekyll Hyde
	./$(EXEC) $(TEST_DIR)/JekyllHyde.txt $(GENERATED_WORDS)

test2: $(EXEC)
	# Running test on Heart of Darkness
	./$(EXEC) $(TEST_DIR)/HeartOfDarkness.txt $(GENERATED_WORDS)

test3: $(EXEC)
	# Running test on Eepy Hollow
	./$(EXEC) $(TEST_DIR)/EepyHollow.txt $(GENERATED_WORDS)

test4: $(EXEC)
	# Running test on The Time Machine
	./$(EXEC) $(TEST_DIR)/TimeMachine.txt $(GENERATED_WORDS)

test5: $(EXEC)
	# Running test on Modest Proposal
	./$(EXEC) $(TEST_DIR)/ModestProposal.txt $(GENERATED_WORDS)

transition: $(EXEC)
	# Correct Test transition matrix:
	# the the -> a b c d e f h i j k 
	# the the, -> a b a b a 
	./$(EXEC) $(TEST_DIR)/EasyTest.txt $(GENERATED_WORDS)

memcheck:
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC) $(TEST_DIR)/TimeMachine.txt $(GENERATED_WORDS)

clean: 
	rm -f wordgen *.o output?? *~