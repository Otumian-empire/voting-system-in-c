#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef _include_h
#define _include_h

int get_int_input();
void get_str_input(char *input, size_t size);
int validate_input(int input, int start, int end);
void exit_with_error_message(char *error_message);
void clear_buffer();

#endif
