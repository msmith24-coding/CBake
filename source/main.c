#include "utils/logger.h"
#include "lexer/lexer.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* Initialize the FILE pointer variable. */
    FILE *file = NULL;
    /* Opens the file for reading.  */
    file = fopen("CBakefile", "rb");

    /* Checks if the file does not exist. */
    if(file == NULL) {
        /* Return an error. */
        logError("Could not locate CBakefile. Does it exist or end with a .txt?");
        return 1;
    }

    makeTokens(file);

    fclose(file); // <-- Closes the file.

    return 0;
}
