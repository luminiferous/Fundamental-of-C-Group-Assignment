#ifndef HUFFMAN_CODING_H_
#define HUFFMAN_CODING_H_

#define CODE_LENGTH 7

struct node
{
    char character;
    int freq;
    char code[CODE_LENGTH + 1];
    struct node *left, *right;
};
typedef struct node node_t;

struct list
{
    node_t *nodeptr;
    struct list *listptr;
};
typedef struct list list_t;

/* Huffman Coding Compression Functions */
int frequency_count(char letter, char string[], int letterPosition);
void bubble_sort(node_t characters[], int arraySize);
node_t create_node(char ch, int freq, node_t *left, node_t *right);
void encoding(node_t characters[], int arraySize);
node_t build_tree(node_t characters[], int arraySize);

/* Debugging Functions */
node_t debug_frequency_count(char ch, char string[], int letterPosition);
void character_output(node_t character);
void character_output_loop(node_t characters[], int arraySize);
void root_node_output(node_t rootNode);
void huffman_tree_output(node_t *node);

#endif
