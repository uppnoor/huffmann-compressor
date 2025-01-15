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

PriorityQueue* createPriorityQueue(FrequencyTable* frequencyTable)
{
    for(int i = 0; i < 256; i++)
    {
        if(frequencyTable->frequencies[i] > 0)
        {
            HuffmanNode* node = createNode((unsigned char)i, frequencyTable->frequencies[i]);
            // Code to add node to a priority queue (implementation of a min heap)
        }
    }
}

HuffmanNode* buildHuffmanTree(FrequencyTable* frequency_table)
{

}
