#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *find_needle(const char *const *haystack, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        if (strcmp(haystack[i], "needle") == 0)
        {
            char *result = malloc(100);  // Allocate memory for the result string
            sprintf(result, "found the needle at position %lu", i); // Format the result string
            return result;
        }
    }

    return NULL; // Needle not found
}