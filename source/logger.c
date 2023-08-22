#include "logger.h"

#include <stdio.h>
#include <string.h>

void logInfo(char message[])
{
    char prefix[6] = "INFO";
    printf("[%s] %s", prefix, message);

}
