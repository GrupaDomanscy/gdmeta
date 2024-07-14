#ifndef LENGTH_AWARE_STRING_H_GD
#define LENGTH_AWARE_STRING_H_GD 

struct String {
    char* src;
    int capacity;
    int length;
};

typedef struct String* String;

typedef int REPLACE_CSTR_STATUS;
#define REPLACE_CSTR_SUCCESS 0
#define REPLACE_CSTR_NO_MATCHES -1

String InititializeString();

String InitializeStringFromCStr(char* cstr);

char* GetCStrFromString(String str);

void AppendCStrToString(String str, char* cstr);

REPLACE_CSTR_STATUS ReplaceCStrInsideString(String src, char* patternCStr, char* replaceWithCStr);

void DeinitString(String str);

#endif
