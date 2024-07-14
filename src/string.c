#include "string.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

String InititializeString() {
    String str = malloc(sizeof(struct String));

    str->capacity = 128 + 1;
    str->length = 0;
    str->src = malloc(sizeof(char) * str->capacity);
    str->src[0] = '\0';

    return str;
}

int GetAlignedSizeOfMemoryForStringLength(int length) {
    int alignedSize = 128;

    while (alignedSize <= length) {
        alignedSize *= 2;
    }

    return alignedSize + 1;
}

String InitializeStringFromCStr(char* cstr) {
    String str = malloc(sizeof(struct String));

    int cstrLength = strlen(cstr);

    str->capacity = GetAlignedSizeOfMemoryForStringLength(cstrLength); 
    str->length = cstrLength;
    str->src = malloc(sizeof(char) * str->capacity);
    strcpy(str->src, cstr);

    return str;
}

char* GetCStrFromString(String str) {
    return str->src;
}

void AppendCStrToString(String str, char* cstr) {
    int cstrLength = strlen(cstr);
    int newCapacity = GetAlignedSizeOfMemoryForStringLength(str->length + cstrLength);

    if (newCapacity != str->capacity) {
        str->src = realloc(str->src, sizeof(char) * newCapacity);
        str->capacity = newCapacity;
    }

    for (int i = 0; i < cstrLength; i++) {
        str->src[i + str->length] = cstr[i];
    }
}

REPLACE_CSTR_STATUS ReplaceCStrInsideString(String src, char* patternCStr, char* replaceWithCStr) {
    String pattern = InitializeStringFromCStr(patternCStr);
    String replaceWith = InitializeStringFromCStr(replaceWithCStr);

    char* occurencePtr = src->src;

    while ((occurencePtr = strstr(occurencePtr, GetCStrFromString(pattern))) != 0) {
        int lengthAfterReplace = src->length - pattern->length + replaceWith->length;

        if (lengthAfterReplace > src->length) {
            int capacityForReplacement = GetAlignedSizeOfMemoryForStringLength(lengthAfterReplace);

            if (capacityForReplacement != src->capacity)
                src->src = realloc(src->src, sizeof(char) * capacityForReplacement);
        }

        String endStr = InitializeStringFromCStr(occurencePtr + pattern->length);

        for (int i = 0; i < endStr->length; i++)
            occurencePtr[i + replaceWith->length] = endStr->src[i];

        for (int i = 0; i < replaceWith->length; i++)
            occurencePtr[i] = replaceWith->src[i];
        
        occurencePtr += replaceWith->length;

        src->length = lengthAfterReplace;
        src->src[src->length] = '\0';

        DeinitString(endStr);
    }
    
    DeinitString(pattern);
    DeinitString(replaceWith);
}

void DeinitString(String str) {
    free(str->src);
    free(str);
}
