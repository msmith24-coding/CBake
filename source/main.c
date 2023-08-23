#include "utils/logger.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* Initialize the FILE pointer variable. */
    FILE* file = NULL;
    /* Opens the file for reading.  */
    file = fopen("CBakefile", "rb");

    /* Checks if the file does not exist. */
    if(file == NULL) {
        /* Return an error. */
        logError("Could not locate CBakefile. Does it exist or end with a .txt?");
        return 1;
    }

    /* Gets the file size. */
    fseek(file, 0, SEEK_END);
    unsigned long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    /* Allocate memory for storing the data in a char array. */
    char* content = (char*)malloc(fileSize + 1);

    /* Checks if it failed to read the contents. */
    if(content == NULL) {
        fclose(file);
        logError("Memory allocation error.");
        return 1;
    }

    size_t bytesRead = fread(content, 1, fileSize, file);
    
    if(bytesRead != fileSize) {
        fclose(file);
        free(content);
        logError("Failed to read file.");
        return 1;
    }

    content[fileSize] = '\0';

    fclose(file); // <-- Closes the file.
    free(content);

    return 0;
}
