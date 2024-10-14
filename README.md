# Markov Chain Text Generation (Two-Word N-Grams)

## Learning Goals
By completing this assignment, you will:
- Gain a deeper understanding of **Markov chains** and how they model sequential data.
- Learn how to extend a basic single-word **n-gram** Markov chain model to a two-word **n-gram** model.
- Practice implementing functions that manipulate data structures to train and generate text.
- Develop skills to read and process text input to create models for text generation.

## Background: N-Gram Markov Chains
A **Markov chain** models the probability of moving from one state to another in a sequence. In this assignment, the "states" are words, and we model the probability of a word sequence in text.

Previously, you worked with **single-word n-grams** (i.e., n = 1). Here, the sequence is made up of individual words. For example, given the text:

> The cat sat on the mat.

The model would predict the next word based on a single preceding word. If the input includes multiple occurrences of "sat", it tracks which words follow it and assigns probabilities based on frequency.

In this assignment, we’ll work with **two-word n-grams** (i.e., n = 2). Instead of modeling the next word from just one word, we’ll consider two-word sequences to predict what comes next. This captures more context and allows for more natural text generation. For example, given the same text as above:

> The cat, cat sat, sat on, on the, the mat.

We would predict the next word based on two preceding words, such as what follows "cat sat".

## N-gram Markov Chains: Why n = 2 is generally Better than n = 1

Using N-gram Markov chains with n = 2 (bigrams) generally improves performance compared to n = 1 (unigrams) for several reasons. Bigrams capture relationships between consecutive words, providing richer context and enhancing coherence in generated text. By considering the preceding word, bigrams help disambiguate words with multiple meanings, leading to more accurate predictions. Text generated with bigrams tends to be more fluent and natural, as it reflects common word pairings. Hopefully, this will be apparent in the text you guys generate when compared to the unigram markov chain from hw15.


## What You Need to Do

### Training Function
You are tasked with extending the training function from the single-word n-gram model to handle two-word n-grams. You’ll modify the training function to process **pairs of consecutive words** instead of single words.

- **Input**: A large block of text.
- **Output**: The MarkovModel data structure that holds all of the transitions.

### Example Walkthrough: Training Function
Let’s walk through an example of how to build the two-word Markov chain model. Consider the following input text:

> I am happy today because I am learning.

1. Start by splitting the text into pairs of consecutive words:

> I am, am happy, happy today, today because, because I, I am, am learning

2. Build the data structures based on these pairs:
- "I am": ["happy", "learning"]
- "am happy": ["today"]
- "happy today": ["because"]
- "today because": ["I"]
- "because I": ["am"]


3. This model then can be used to generate text. For example, starting with the pair "I am", the model could predict either "happy" or "learning" as the next word based on the training data.

## Data Structures for the Two-Word N-gram Markov Model

In our implementation of the two-word N-gram Markov chain model, we utilize several interconnected structures to efficiently manage and organize the data. These structs will be provided for you and must be used in your implementation.

### `Word`
This data structure represents a single word from the input text. The word is stored in a character array with a fixed length of `MAX_WORD_LENGTH`. This structure is essential because it simplifies handling individual words when building and manipulating the Markov model. In the context of the assignment, each word in the input text will be stored using this structure.

### `MarkovNode`
The `MarkovNode` structure represents a pair of consecutive words, or an "n-gram," in the input text and the potential words that follow this pair. It contains two `Word` elements, `word1` and `word2`, which store the two-word sequence. The `next_words` array stores the words that can follow this pair, with a limit of `MAX_NEXT_WORDS`. The `next_word_count` field keeps track of how many next words have been observed for this pair. This structure is crucial for representing the relationships between word pairs and their possible transitions in the Markov chain.

### `MarkovModel`
The `MarkovModel` structure holds the entire Markov chain for the input data. It contains an array of `MarkovNode` elements, each representing a unique two-word sequence (n-gram) along with its possible transitions. The `node_count` field keeps track of how many nodes (word pairs) have been added to the model, with a maximum capacity defined by `MAX_WORD_PAIRS`. This structure allows us to store and manage all the possible word transitions in the Markov chain.


### Data Connections

These structures are interconnected for data management within the N-gram model. The `MarkovModel` serves as the entry point, providing access to the linked list of `MarkovModelNode` structures, each containing two `Word` elements and its associated list of possible next words.

### Notes

The time complexity of generating words with this implementation is worse than it would be with a hashing implementation but also easier to do. You have the choice of whether you want to allocate memory statically or dynamically for this assignment. Static helper functions can be used. Checking the transition matrix output can help a lot with debugging.



## Instructions
1. Implement the provided `train_markov_model` function to handle two-word n-grams instead of single words.
2. Implement the `free_markov_model` function to successfully free all the potentially allocated memory.
3. Write more test cases to ensure your implementation works.
4. Submit generate.c to gradescope for grading.
