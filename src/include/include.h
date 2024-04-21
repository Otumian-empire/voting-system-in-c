#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <string.h>

#ifndef _include_h
#define _include_h

// the min and max expected value for the start app options
#define UI_START_APP_OPTION_START 1
#define UI_START_APP_OPTION_END 8

#define UI_START_APP_OPTION_ERR_MESSAGE                 \
	"invalid start option entered. expected: [%d, %d]", \
		UI_START_APP_OPTION_START, UI_START_APP_OPTION_END

#define UI_INPUT_PROMPT "$ "

// define constants for the switch statement
#define VOTING_PROCESS 1
#define ADD_VOTER 2
#define ADD_CANDIDATE 3
#define VOTE 4
#define VIEW_VOTERS_RESULT 5
#define END_VOTING_PROCESS 6
#define VIEW_VOTING_RESULTS 7
#define VIEW_LIST_VOTING_PROCESSES 8

// error, failure and success codes
#define ERROR -1
#define FAILURE 0
#define SUCCESS 1

// table character lengths
#define ID_SIZE 5
#define BOOL_SIZE 2
#define USER_NAME_SIZE 11
#define PIN_SIZE 6
#define NAME_SIZE 26
#define COUNT_SIZE 7
#define TITLE_SIZE 256
#define MAX_ROW_SIZE 1000

// status for a record
#define PROCESS_STATUS_TRUE "1"
#define PROCESS_STATUS_FALSE "0"
#define PROCESS_STATUS_DONE "Done"
#define PROCESS_STATUS_ON_GOING "On going"

// database file path
#define DATABASE_PATH "bin/voting_system_db.db"

// util functions
int get_int_input();
void get_str_input(char *input, size_t size);
int validate_input(int input, int start, int end);
void exit_with_error_message(char *error_message);
void clear_buffer();

#endif
