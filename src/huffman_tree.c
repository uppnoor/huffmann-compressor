#include "huffman_tree.h"
#include <stdio.h>
#include <stdlib.h>

/**
* Creates a new HuffmanNode with the given character and frequency.
* Allocates memory and initializes the node's fields.
*
* @param character the character to store in the node
* @param frequency the frequency of the character
* @return a pointer to the newly created HuffmanNode
*/
static HuffmanNode* createNode(unsigned char character, int frequency)
{
    HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    if(!node)
    {
        fprintf(stderr, "Error: Could not allocate memory for HuffmanNode.\n");
        exit(EXIT_FAILURE);
    }

    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}