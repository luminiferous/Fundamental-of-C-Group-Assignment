#include <stdio.h>
#include "huffman_coding.h"

/* Functionality */
weight_t weight_count(char letter, char string[], int letterPosition)
{
    weight_t letterWeight;
    letterWeight.letter = letter;
    letterWeight.weight = 1;
    int i = letterPosition + 1;
    while (string[i] != '\0')
    {
        if (letter == string[i])
        {
            letterWeight.weight++;
        }
        i++;
    }
    return letterWeight;
}

/* Debugging Functions */
void weight_output(weight_t* character)
{
    printf("Character: %c; Weight: %d\n",
            character -> letter, character -> weight);
}
