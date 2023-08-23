#include "logger.h"

#include <stdio.h>
#include <string.h>

void logInfo(char message[])
{
    char prefix[6] = "INFO";
    printf("[%s] %s\n", prefix, message);
}

void logError(char message[])
{
    char prefix[6] = "ERROR";
    printf("[%s] %s\n", prefix, message);
}
