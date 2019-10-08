#include <stdio.h>
#include "huffman_coding.h"

/* Functionality */
int frequency_count(char character, char string[], int letterPosition)
{
    int frequency = 1;
    int i = letterPosition + 1;
    while (string[i] != '\0')
    {
        if (character == string[i])
        {
            frequency++;
        }
        i++;
    }
    return frequency;
}

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

node_t create_node(char ch, int freq, node_t *left, node_t *right)
{
    node_t node;
    node.character = ch;
    node.freq = freq;
    node.left = left;
    node.right = right;
    return node;
}

void encoding(node_t characters[], int arraySize)
{

}

node_t build_tree(node_t characters[], int arraySize)
{
    int i, front = 0;
    node_t node, leftNode, rightNode;

    while (arraySize != 1)
    {
        bubble_sort(characters, arraySize);
        leftNode = characters[front];
        printf("Left Node\n");
        character_output(leftNode);
        printf("----------------------\n");
        rightNode = characters[front+1];
        printf("Right Node\n");
        character_output(rightNode);
        printf("----------------------\n");
        for (i = 2; i < arraySize; i++)
        {
            characters[i-2] = characters[i];
        }
        arraySize--;
        node = create_node(' ', leftNode.freq + rightNode.freq, &leftNode, &rightNode);
        characters[arraySize-1] = node;

        character_output_loop(characters, arraySize);
        printf("----------------------\n");
    }
    return node;
}

/* Debugging Functions */
node_t debug_frequency_count(char ch, char string[], int letterPosition)
{
    node_t letterFreq;
    letterFreq.character = ch;
    letterFreq.freq = 1;
    int i = letterPosition + 1;
    while (string[i] != '\0')
    {
        if (ch == string[i])
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
            character.character, character.freq);
}

void character_output_loop(node_t characters[], int arraySize)
{
    int i;
    for (i = 0; i < arraySize; i++)
    {
        character_output(characters[i]);
    }
}

void huffman_tree_output(node_t *node)
{
    printf("Node Letter: %c; Frequency: %d\n",
            node -> character, node -> freq);

    if (node -> left != NULL)
    {
        printf("Left\n");
        huffman_tree_output(node -> left);
    }
    if (node -> right != NULL)
    {
        printf("Right\n");
        huffman_tree_output(node -> right);
    }
}
