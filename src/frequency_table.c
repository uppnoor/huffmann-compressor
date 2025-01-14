#include <stdio.h>
#include <stdlib.h>
#include "frequency_table.h"

/**
* Reads the contents of a file and generates a frequency table for the characters.
*
* @param fileName the name of the file to be read
*/
void readFile(const char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if(file == NULL)
    {
        perror("Error opening file");
        return;
    }

    char line[1024];
    printf("Contents of the file %s:\n", fileName);

    FrequencyTable *frequency_table = malloc(sizeof(FrequencyTable));
    if(frequency_table == NULL)
    {
        perror("Error allocating memory for FrequencyTable");
        fclose(file);
        return;
    }

    for(int i = 0; i < 256; i++)
    {
        frequency_table->frequencies[i] = 0;
    }

    while(fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
        generateFrequencyTable(frequency_table, line, sizeof(line));
    }

    fclose(file);
    printFrequencies(frequency_table, 256);
    free(frequency_table);
}

/**
* Generates a frequency table by calculating the occurrences of each character in a line.
*
* @param frequency_table a pointer to the FrequencyTable structure
* @param line a character array representing the line of text to analyze
* @param size_of_line the size of the line array
*/
void generateFrequencyTable(FrequencyTable *frequency_table, const char line[], int size_of_line)
{
    for(int i = 0; i < size_of_line && line[i] != '\0'; i++)
    {
        unsigned char asciiValue = (unsigned char)line[i];
        frequency_table->frequencies[asciiValue]++;
    }
}

/**
* Prints the frequencies of characters from the frequency table.
*
* @param frequency_table a pointer to the FrequencyTable structure
* @param size_of_table the size of the frequency table
*/
void printFrequencies(FrequencyTable *frequency_table, int size_of_table)
{
    for(int i = 0; i < size_of_table; i++)
    {
        if(frequency_table->frequencies[i] > 0)
        {
            printf("Character '%c' (ASCII %d): %d times\n", i, i, frequency_table->frequencies[i]);
        }
    }
}
