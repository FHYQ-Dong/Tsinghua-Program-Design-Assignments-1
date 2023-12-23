#pragma once
typedef enum {
    ARG_OK,
    ARG_LESS,
    ARG_NOT_FOUND,
    ARG_WRONG_FORMAT,
} arg_condition;

typedef enum {
    COMMAND_HELP,
    COMMAND_SAVE,
    COMMAND_SEARCH,
    COMMAND_EVEN,
    COMMAND_ALL
} command_type;

typedef struct {
    command_type command;
    char* filename;
} ARGS;

void print_usage();
void print_error(arg_condition condition, char* arg);
ARGS split_args(int argc, char const *argv[]);