#ifndef HUFFMAN_CODING_H_
#define HUFFMAN_CODING_H_

struct weight
{
    char letter;
    int weight;
};
typedef struct weight weight_t;

weight_t weight_count(char letter, char string[], int letter_position);

/* Debugging Functions */
void weight_output(weight_t* character);

#endif
