#include <stdio.h>
#include "huffman_coding.h"

weight_t weight_count(char letter, char string[], int letterPosition)
{
    printf("HC Checkpoint 1; letter %c; string[] %s; letterPosition %d\n",
            letter, string, letterPosition);
    weight_t letterWeight;
    letterWeight.letter = letter;
    letterWeight.weight = 0;
    printf("HC Checkpoint 2; letterWeight %c %d\n",
            letterWeight.letter, letterWeight.weight);
    int i = letterPosition + 1;
    /* printf("HC Checkpoint 3; letterPosition %d; i %d\n",
            letterPosition, i); */
    while (string[i] != '\0')
    {
        /* printf("HC Checkpoint 4; string letter %c\n", string[i]); */
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
