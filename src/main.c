#include <stdio.h>
#include "frequency_table.h"
#include "huffman_tree.h"


int main(void)
{
    FrequencyTable *frequencyTable = readFile("input.txt");

    // Testing to see if frequency table is accessible.
    for(int i = 0; i < 256; i++)
    {
        printf("%d", frequencyTable->frequencies[i]);
    }

    return 0;
}
