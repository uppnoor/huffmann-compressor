#include <stdio.h>
#include <stdlib.h>
#include "frequency_table.h"

/**
* Reads the contents of a file and generates a frequency table for the characters.
* @param fileName the name of the file to be read
* @return Frequency table struct pointer.
*/
FrequencyTable* readFile(const char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if(file == NULL)
    {
        perror("Error opening file");
        return NULL;
    }

    char line[1024];
    printf("Contents of the file %s:\n", fileName);

    FrequencyTable *frequencyTable = malloc(sizeof(FrequencyTable));
    if(frequencyTable == NULL)
    {
        perror("Error allocating memory for FrequencyTable");
        fclose(file);
        return NULL;
    }

    for(int i = 0; i < 256; i++)
    {
        frequencyTable->frequencies[i] = 0;
    }

    while(fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
        generateFrequencyTable(frequencyTable, line, sizeof(line));
    }

    fclose(file);
    printFrequencies(frequencyTable, 256);
    return frequencyTable;
}

/**
* Generates a frequency table by calculating the occurrences of each character in a line.
*
* @param frequencyTable a pointer to the FrequencyTable structure
* @param line a character array representing the line of text to analyze
* @param size_of_line the size of the line array
*/
void generateFrequencyTable(FrequencyTable *frequencyTable, const char line[], int size_of_line)
{
    for(int i = 0; i < size_of_line && line[i] != '\0'; i++)
    {
        unsigned char asciiValue = (unsigned char)line[i];
        frequencyTable->frequencies[asciiValue]++;
    }
}

/**
* Prints the frequencies of characters from the frequency table.
*
* @param frequencyTable a pointer to the FrequencyTable structure
* @param size_of_table the size of the frequency table
*/
void printFrequencies(FrequencyTable *frequencyTable, int size_of_table)
{
    for(int i = 0; i < size_of_table; i++)
    {
        if(frequencyTable->frequencies[i] > 0)
        {
            printf("Character '%c' (ASCII %d): %d times\n", i, i, frequencyTable->frequencies[i]);
        }
    }
}
