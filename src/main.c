#include "templates/string_h.h"
#include "templates/string_c.h"
#include "templates/array_h.h"
#include "templates/array_c.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

char* charpointermin(char* a, char* b) {
    return (a < b) ? a : b;
}

int main(int argc, char** argv) {
    argc -= 1;
    argv += 1;

    if (argc - 1 < 0) {
        printf("Please provide a valid argument. See --help for help.\n");
        return 1;
    }

    if (strcmp(argv[0], "--help") == 0) {
        printf("GDMeta - metaprogramming helpers for C language\n");
        printf("\n");
        printf("\tstring.c\t- write string.c to stdout, file that contains solution for length-aware strings\n");
        printf("\tstring.h\t- write string.h to stdout, header file for string.c helper\n");
        printf("\tarray.h [TYPEDEF_NAME] [STRUCT_NAME] [INCLUDE_GUARD_NAME] [TYPE_NAME]\t- write custom array.h script to stdout\n");
        printf("\tarray.c [TYPEDEF_NAME] [STRUCT_NAME] [TYPE_NAME]\t- write custom array.c script to stdout\n");
    } else if (strcmp(argv[0], "string.h") == 0) {
        printf("%s", string_h_template);
    } else if (strcmp(argv[0], "string.c") == 0) {
        printf("%s", string_c_template);
    } else if (strcmp(argv[0], "array.h") == 0) {
        argc -= 1;
        argv += 1;

        if (argc != 4) {
            printf("For this argument you have to pass 4 arguments, you passed %d.\n", argc);
            printf("Usage: gdmeta array.h [TYPEDEF_NAME] [STRUCT_NAME] [INCLUDE_GUARD_NAME] [TYPE_NAME]\n");
            return 1;
        }

        String output = InitializeStringFromCStr(array_h_template);

        ReplaceCStrInsideString(output, "TYPEDEF_NAME", argv[0]);
        ReplaceCStrInsideString(output, "STRUCT_NAME", argv[1]);
        ReplaceCStrInsideString(output, "INCLUDE_GUARD_NAME_H", argv[2]);
        ReplaceCStrInsideString(output, "TYPE_NAME", argv[3]);

        printf("%s", GetCStrFromString(output));

        DeinitString(output);
    } else if (strcmp(argv[0], "array.c") == 0) {
        argc -= 1;
        argv += 1;

        if (argc != 3) {
            printf("For this argument you have to pass 3 arguments, you passed %d.\n", argc);
            printf("Usage: gdmeta array.c [TYPEDEF_NAME] [STRUCT_NAME] [TYPE_NAME]\n");
            return 1;
        }

        String output = InitializeStringFromCStr(array_c_template);

        ReplaceCStrInsideString(output, "TYPEDEF_NAME", argv[0]);
        ReplaceCStrInsideString(output, "STRUCT_NAME", argv[1]);
        ReplaceCStrInsideString(output, "TYPE_NAME", argv[2]);

        printf("%s", GetCStrFromString(output));

        DeinitString(output);
    } else {
        printf("Please provide a valid argument. See --help for help.\n");
        return 1;
    }

    return 0;
}
