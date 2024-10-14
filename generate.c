#include "generate.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void train_markov_model(MarkovModel* model, const char *filename) {
    // to do. Check Readme for more details
}

void free_markov_model(MarkovModel* model) {
    // to do. Check Readme for more details
}

void generate_text(MarkovModel* model, size_t num_words) {
    if (model->node_count == 0) {
        printf("No data to generate text from.\n");
        return;
    }

    // Starting with a random word pair
    int start_index = rand() % model->node_count;
    Word current_word1 = model->nodes[start_index].word1;
    Word current_word2 = model->nodes[start_index].word2;

    printf("%s %s", current_word1.word, current_word2.word);

    for (size_t i = 2; i < num_words; i++) {
        int node_index = find_word_pair(model, &current_word1, &current_word2);
        if (node_index == -1) {
            // If no matching pair, restart with a random pair
            start_index = rand() % model->node_count;
            current_word1 = model->nodes[start_index].word1;
            current_word2 = model->nodes[start_index].word2;
            printf(" %s %s", current_word1.word, current_word2.word);
            continue;
        }

        MarkovNode* node = &model->nodes[node_index];
        if (node->next_word_count == 0) break; // No next words to choose from, shouldn't happen if transition matrix made correctly

        int next_word_index = rand() % node->next_word_count;
        Word* next_word = &node->next_words[next_word_index];

        printf(" %s", next_word->word);

        // Move to the next word pair
        strcpy(current_word1.word, current_word2.word);
        strcpy(current_word2.word, next_word->word);
    }
    printf("\n");
}


