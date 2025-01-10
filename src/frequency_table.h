#ifndef FREQUENCY_TABLE_H
#define FREQUENCY_TABLE_H

typedef struct
{
    int frequencies[256];
} FrequencyTable;

void readFile(const char *fileName);
void generateFrequencyTable(FrequencyTable *frequency_table, const char line[], int size_of_line);
void printFrequencies(FrequencyTable *frequency_table, int size_of_table);

#endif // FREQUENCY_TABLE_H
