#include "huffman_tree.h"
#include <stdio.h>
#include <stdlib.h>

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