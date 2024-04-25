#include "../include/include.h"

#ifndef _model_h
#define _model_h

// TODO: provide method for field validations before writing to db
// refer to the ../include/include.h for the appropriate character sizes

// database functions
void create_connection();
void close_connection();
void get_connection_error_message(char *);

// CRUD util
static int write_callback(void *NotUsed, int argc, char **argv, char **azColName);

// entities (tables)

// Voting process and its associated functions
typedef struct
{
	char *id;
	char *name;
	char *status;
} VotingProcess;

void print_voting_process(VotingProcess v);
int create_voting_process_model(char *voting_process_name);
void list_voting_process_models();
static int list_voting_process_callback(void *NotUsed, int argc, char **argv, char **azColName);

// Registered voter and its associated functions
typedef struct
{
	char *id;
	char *username;
	char *has_voted;
	char *pin;
	char *voting_processes;
} RegisteredVoters;

int create_registered_voter_model(int voting_process_id, char *username, char *pin);
void list_registered_voters_model(int voting_process_id);
void read_registered_voters_model(int voting_process_id, char *username);

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