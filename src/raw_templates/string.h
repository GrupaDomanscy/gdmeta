#ifndef LENGTH_AWARE_STRING_H_GD
#define LENGTH_AWARE_STRING_H_GD 

struct String {
    char* src;
    int capacity;
    int length;
};

typedef struct String* String;

String InititializeString();

String InitializeStringFromCStr(char* cstr);

char* GetCStrFromString(String str);

void AppendCStrToString(String str, char* cstr);

void ReplaceCStrInsideString(String src, char* patternCStr, char* replaceWithCStr);

void DeinitString(String str);

#endif
