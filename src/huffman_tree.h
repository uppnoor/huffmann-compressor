#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include "frequency_table.h"

typedef struct Node
{
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

Node* buildHuffmanTree(const FrequencyTable *table);

#endif
