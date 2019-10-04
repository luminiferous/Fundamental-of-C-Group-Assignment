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

/* Huffman Coding Compression Functions */
int frequency_count(char letter, char string[], int letterPosition);
node_t create_node(char ch, char str[], int chPos, node_t *left, node_t *right);
void bubble_sort(node_t characters[], int arraySize);
void encoding(node_t characters[], int arraySize);

/* Debugging Functions */
node_t debug_frequency_count(char letter, char string[], int letter_position);
void character_output(node_t character);
void character_output_loop(node_t characters[], int arraySize);

#endif
