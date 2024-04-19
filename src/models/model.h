#include "../include/include.h"

#ifndef _model_h
#define _model_h

// static sqlite3 *connection;
// static char *errorMessage = {'\0'};

// database functions
void create_connection();
void close_connection();

// entities (tables)
typedef struct
{
	char id[ID_SIZE];
	char name[NAME_SIZE];
	char status[BOOL_SIZE];
} VotingProcess;

typedef struct
{
	char id[ID_SIZE];
	char username[USER_NAME_SIZE];
	char has_voted[BOOL_SIZE];
	char pin[PIN_SIZE];
	char voting_processes[BOOL_SIZE];
} RegisteredVoters;

typedef struct
{
	char id[ID_SIZE];
	char username[NAME_SIZE];
	char name[NAME_SIZE];
	char voting_process[ID_SIZE];
} Candidate;

typedef struct
{
	char id[ID_SIZE];
	char voter_id[ID_SIZE];
	char candidate_id[ID_SIZE];
} Ballot;

typedef struct
{
	char id[ID_SIZE];
	char candidate_id[ID_SIZE];
	char count[COUNT_SIZE];
} Results;

#endif