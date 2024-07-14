#ifndef INCLUDE_GUARD_NAME_H 
#define INCLUDE_GUARD_NAME_H 

struct STRUCT_NAME 
{
    TYPE_NAME* items;
    int length;
    int capacity;
};

typedef struct STRUCT_NAME* TYPEDEF_NAME;

TYPEDEF_NAME InitializeTYPEDEF_NAME();

int GetLengthOfTYPEDEF_NAME(TYPEDEF_NAME arr);

float GetItemFromTYPEDEF_NAME(TYPEDEF_NAME arr, int index);

void PushToTYPEDEF_NAME(TYPEDEF_NAME arr, TYPE_NAME item);

void FreeTYPEDEF_NAME();

#endif
