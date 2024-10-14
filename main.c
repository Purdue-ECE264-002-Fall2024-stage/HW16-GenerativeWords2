#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "generate.h"

// Main function for testing
int main(int argc, char ** argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <number_words>\n", argv[0]);
        return 1;
    }

    srand((unsigned int) time(NULL));

    MarkovModel model;
    model.node_count = 0;
    train_markov_model(&model, argv[1]);

    // Output the transitions. Uncomment for debugging.
    for (int i = 0; i < model.node_count; i++) {
        MarkovNode node = model.nodes[i];
        Word word1 = node.word1;
        Word word2 = node.word2;
        Word *wordList = node.next_words;
        printf("%s %s -> ", word1.word, word2.word);

        for (int j = 0; j < node.next_word_count; j++) {
            printf("%s ", wordList[j].word);
        }
        printf("\n");
    }

    printf("Generated text:\n");
    generate_text(&model, atoi(argv[2]));

    free_markov_model(&model);

    return 0;
}