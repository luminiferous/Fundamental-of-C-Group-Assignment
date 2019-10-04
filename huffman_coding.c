#include <stdio.h>
#include "huffman_coding.h"

/* Functionality */
/* node_t create_node(char ch, int freq, char code[], node_t *left, node_t *right){} */

void bubble_sort(node_t characters[], int arraySize)
{
    int i, j;
    node_t temp;
    for (i = 0; i < arraySize - 1; i++)
    {
        for (j = 0; j < arraySize - 1; j++)
        {
            if (characters[j].freq > characters[j + 1].freq)
            {
                temp = characters[j];
                characters[j] = characters[j + 1];
                characters[j + 1] = temp;
            }
        }
    }
}

void encoding(node_t characters[], int arraySize)
{

}

/* Debugging Functions */
node_t character_count(char letter, char string[], int letterPosition)
{
    node_t letterFreq;
    letterFreq.letter = letter;
    letterFreq.freq = 1;
    int i = letterPosition + 1;
    while (string[i] != '\0')
    {
        if (letter == string[i])
        {
            letterFreq.freq++;
        }
        i++;
    }
    return letterFreq;
}

void character_output(node_t character)
{
    printf("Character: %c; Frequency: %d\n",
            character.letter, character.freq);
}

void character_output_loop(node_t characters[], int arraySize)
{
    int i;
    for (i = 0; i < arraySize; i++)
    {
        character_output(characters[i]);
    }
}
