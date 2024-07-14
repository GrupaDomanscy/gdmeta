#include "TYPE_NAME_array.h"

#include <stdlib.h>

TYPEDEF_NAME InitializeTYPEDEF_NAME()
{
    TYPEDEF_NAME arr = malloc(sizeof(struct STRUCT_NAME));

    arr->length = 0;
    arr->capacity = 2;
    arr->items = malloc(sizeof(TYPE_NAME) * arr->capacity);

    return arr;
}

int GetLengthOfTYPEDEF_NAME(TYPEDEF_NAME arr)
{
    return arr->length;
}

TYPE_NAME GetItemFromTYPEDEF_NAME(TYPEDEF_NAME arr, int index)
{
    return arr->items[index];
}

void PushToTYPEDEF_NAME(TYPEDEF_NAME arr, TYPE_NAME item)
{
    if (arr->length + 1 > arr->capacity)
    {
        arr->capacity *= 2;
        arr->items = realloc(arr->items, sizeof(struct STRUCT_NAME) * arr->capacity);
    }

    arr->items[arr->length] = item;
    arr->length++;
}

void FreeTYPEDEF_NAME(TYPEDEF_NAME arr)
{
    free(arr->items);
    free(arr);
}
