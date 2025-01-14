#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include "frequency_table.h"

/**
* Represents a node in a Huffman Tree used for encoding and decoding.
* Each node contains a character, its frequency, and pointers to child nodes.
*/
typedef struct HuffmanNode
{
    char character;
    int frequency;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
} HuffmanNode;

HuffmanNode* buildHuffmanTree(FrequencyTable* freqTable);

#endif