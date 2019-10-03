#ifndef HUFFMAN_CODING_H_
#define HUFFMAN_CODING_H_

#define CODE_LENGTH 7

struct node
{
    char letter;
    int freq;
    char code[CODE_LENGTH + 1];
    struct node *left, *right;
};
typedef struct node node_t;

node_t character_count(char letter, char string[], int letter_position);
void bubble_sort(node_t characters[], int arraySize);
void code_assign(node_t characters[]);

/* Debugging Functions */
void character_output(node_t character);
void character_output_loop(node_t characters[], int arraySize);

#endif
