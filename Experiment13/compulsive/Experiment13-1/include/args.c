#include "args.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_usage() {
    printf("Usage: ./executable [command] [option] [value]\n");
    printf("Commands:\n");
    printf("  --help\t\t\tPrint this help message and exit\n");
    printf("  --save\t\t\tSave the data to file $filename\n");
    printf("  --search\t\t\tLoad the data from file $filename and search for id\n");
    printf("  --even\t\t\tLoad the data from file $filename and print the even score\n");
    printf("  --all\t\t\t\tLoad the data from file $filename and print all the data\n");
    printf("Options:\n");
    printf("  -f filename\t\t\tSpecify the filename\n");
}

void print_error(arg_condition condition, char* arg) {
    switch (condition) {
        case ARG_LESS:
            printf("Error: Argument %s is missing\n", arg);
            break;
        case ARG_NOT_FOUND:
            printf("Error: Argument %s is not found\n", arg);
            break;
        case ARG_WRONG_FORMAT:
            printf("Error: Argument %s is in wrong format\n", arg);
            break;
        default:
            break;
    }
    print_usage();
    _exit(1);
}

ARGS split_args(int argc, const char *argv[]) {
    if (argc < 2) print_error(ARG_LESS, "[command]");

    ARGS args = {0};
    if (strcmp(argv[1], "--help") == 0) args.command = COMMAND_HELP;
    else if (strcmp(argv[1], "--save") == 0) args.command = COMMAND_SAVE;
    else if (strcmp(argv[1], "--search") == 0) args.command = COMMAND_SEARCH;
    else if (strcmp(argv[1], "--even") == 0) args.command = COMMAND_EVEN;
    else if (strcmp(argv[1], "--all") == 0) args.command = COMMAND_ALL;
    else print_error(ARG_NOT_FOUND, (char*)argv[1]);

    if (args.command == COMMAND_HELP) return args;
    if (argc < 4) print_error(ARG_LESS, "[option]");
    if (strcmp(argv[2], "-f") == 0) args.filename = (char*)argv[3];
    else print_error(ARG_WRONG_FORMAT, "[option]");

    return args;
}