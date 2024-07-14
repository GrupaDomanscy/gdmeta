# GDMeta

Metaprogramming helpers for C language.

## Contents
1. [String helper](#string-helper)
2. [Template for arrays](#template-for-arrays)

## String helper

### Structs
**`struct String`**

A struct that represents a dynamically allocated string with adjustable capacity.

*Members*:

    char* src:
        A pointer to the character array (string) managed by this struct.
    int length:
        The current length of the string stored in src.
    int capacity:
        The total allocated capacity for the character array, including space for the null-terminator.

### Functions
**`String InitializeString()`**

Allocates and initializes a new empty String. The capacity of the new String is aligned as per GetAlignedSizeOfMemoryForStringLength.

*Returns*: 

    A new String with length set to 0 and src initialized to an empty string.

<hr />

**`int GetAlignedSizeOfMemoryForStringLength(int length)`**

Calculates the required capacity for a string of a given length, ensuring the capacity is a power of two greater than or equal to 128, plus one for the null-terminator.

*Parameters*:

    int length:
        The desired length of the string.

*Returns*:

    The aligned size of memory required to store the string plus one for the null-terminator.

<hr />

**`String InitializeStringFromCStr(char* cstr)`**

Initializes a new String from a given C-string (char*). The capacity of the new String is aligned as per GetAlignedSizeOfMemoryForStringLength.

*Parameters*:

    char* cstr:
        The C-string to initialize the String with.

*Returns*:

    A new String containing the given C-string.

<hr />

**`char* GetCStrFromString(String str)`**

Retrieves the C-string (char*) from the given String. It does not allocate anything, it only passes the internal pointer that is contained within the struct.

*Parameters*:

    String str:
        The String from which to retrieve the C-string.

*Returns*:

    The C-string managed by the String.

**`void AppendCStrToString(String str, char* cstr)`**

Appends a given C-string (char*) to the end of a String, resizing the String if necessary.

*Parameters*:

    String str:
        The String to which the C-string will be appended.
    char* cstr:
        The C-string to append to the String.

<hr />

**`void ReplaceCStrInsideString(String src, char* patternCStr, char* replaceWithCStr)`**

Replaces all occurrences of a pattern C-string inside a String with another C-string. The function adjusts the size of the String as needed.

*Parameters*:

    String src:
        The String in which to replace the pattern.
    char* patternCStr:
        The pattern C-string to be replaced.
    char* replaceWithCStr:
        The C-string to replace the pattern with.

<hr />

**`void DeinitString(String str)`**

Deinitializes a String, freeing its allocated memory.

*Parameters*:

    String str:
        The String to deinitialize.

### Notes:

    String is a typedef for a pointer to struct String (typedef struct String* String).
    Error handling: Proper error handling for malloc and realloc failures is not present.

## Template for arrays

### Structs
**`struct STRUCT_NAME`**

A struct that represents a dynamically allocated array with adjustable capacity.

*Members*:

    TYPE_NAME* items:
        A pointer to the array of items managed by this struct.
    int length:
        The current number of items stored in the array.
    int capacity:
        The total allocated capacity for the array.

### Functions
**`TYPEDEF_NAME InitializeTYPEDEF_NAME()`**

Allocates and initializes a new empty array of type TYPEDEF_NAME. The initial capacity of the array is set to 2.

*Returns*:

    A new `TYPEDEF_NAME` with length set to 0 and an allocated initial capacity of 2.

<hr />

**`int GetLengthOfTYPEDEF_NAME(TYPEDEF_NAME arr)`**

Retrieves the current length of the array.

*Parameters*:

    TYPEDEF_NAME arr:
        The array from which the length is to be retrieved.

*Returns*:

    The current length of the array.

<hr />

**`TYPE_NAME GetItemFromTYPEDEF_NAME(TYPEDEF_NAME arr, int index)`**

Gets the item at the specified index from the array.

*Parameters*:

    TYPEDEF_NAME arr:
        The array from which the item is to be retrieved.
    int index:
        The index of the item to be retrieved.

*Returns*:

    The item at the specified index.

<hr />

**`void PushToTYPEDEF_NAME(TYPEDEF_NAME arr, TYPE_NAME item)`**

Adds a new item to the end of the array. If the array's current length exceeds its capacity, the capacity is doubled.

*Parameters*:

    TYPEDEF_NAME arr:
        The array to which the item is to be added.
    TYPE_NAME item:
        The item to be added to the array.

<hr />

**`void FreeTYPEDEF_NAME(TYPEDEF_NAME arr)`**

Frees the memory allocated for the array, including its items.

*Parameters*:

    TYPEDEF_NAME arr:
        The array to be freed.

<hr />
