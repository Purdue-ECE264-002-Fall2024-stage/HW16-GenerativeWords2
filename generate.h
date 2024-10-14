#ifndef GENERATE_H
#define GENERATE_H

#define MAX_WORD_LENGTH 15
#define MAX_WORD_PAIRS 40000
#define MAX_NEXT_WORDS 10

// DON'T CHANGE BELOW THIS LINE

#include <stddef.h>
#include <stdio.h>

typedef struct {
    char word[MAX_WORD_LENGTH];
} Word;

typedef struct {
    Word word1;
    Word word2;
    Word next_words[MAX_NEXT_WORDS];
    int next_word_count;
} MarkovNode;

typedef struct {
    MarkovNode nodes[MAX_WORD_PAIRS];
    int node_count;
} MarkovModel;


/**
 * Trains the Markov chain model on the input text. Needs to be implemented
 * 
 * @param model The markov model.
 * @param file The input file used for training the model.
 */
void train_markov_model(MarkovModel* model, const char *filename);

/**
 * Generates text using the trained Markov chain model.
 * 
 * @param model The markov model.
 * @param num_words The number of words to generate.
 */
void generate_text(MarkovModel* model, size_t num_words);

/**
 * Frees the resources used by the Markov chain model if any. Needs to be implemented.
 * 
 * @param model The markov model to free.
 */
void free_markov_model(MarkovModel* model);

#endif 