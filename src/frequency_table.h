#ifndef FREQUENCY_TABLE_H
#define FREQUENCY_TABLE_H

/**
 * Represents a frequency table that holds the frequencies of the chars used in text file.
 * The chars are added and incremented by their ASCII index in the array.
 */
typedef struct
{
    int frequencies[256];
} FrequencyTable;

FrequencyTable* readFile(const char *fileName);
void generateFrequencyTable(FrequencyTable *frequency_table, const char line[], int size_of_line);
void printFrequencies(FrequencyTable *frequency_table, int size_of_table);

#endif // FREQUENCY_TABLE_H
