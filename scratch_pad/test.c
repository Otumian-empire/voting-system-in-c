#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include "../src/include/include.h"

#define ERROR -1
#define FAILURE 0
#define SUCCESS 1
// #define DATABASE_PATH "voting_system_db.db"
#define DATABASE_PATH "bin/voting_system_db.db"

sqlite3 *database_connection;
char *error_message;

int connect_database();
static int callback(void *NotUsed, int argc, char **argv, char **azColName);
void disconnect_database();
int insert_into_tb(char *voting_process_name);
void read_all_from_tb();

typedef char charptr[256];

typedef struct VotingProcess
{
	charptr id;
	charptr name;
	charptr status;

	int (*get_name_size)(struct VotingProcess *);

} VotingProcess;

int get_name_size(VotingProcess *v)
{
	return strlen(v->name);
}

/* void print_voting_process(VotingProcess voting_process)
{
	// printf("%-4s %-2.25s %14s\n\n", voting_process.id, voting_process.name, voting_process.status);
	printf("%-4s %-30s %-4s\n", voting_process.id, voting_process.name, voting_process.status);
} */

int main()
{

	struct VotingProcess process;
	process.get_name_size = get_name_size;

	// Allocate memory for strings
	// process.id = malloc(2 * sizeof(char));	   // For "1" and null terminator
	// process.name = malloc(7 * sizeof(char));   // For "Daniel" and null terminator
	// process.status = malloc(2 * sizeof(char)); // For "0" and null terminator

	strcpy(process.id, "1");
	strcpy(process.name, "Daniel martin seeing");
	strcpy(process.status, "0");

	int size_of_name = process.get_name_size(&process);
	printf("The size of %s is %d\n\n", process.name, size_of_name);

	/* free(process.id);
	free(process.name);
	free(process.status); */
	/* if (FAILURE == connect_database())
	{
		printf("Hello there!\n");
		printf("Sorry, database connection failed!\n");
		exit(0);
	}

	printf("Database connection opened\n"); */

	/*
		// Insert values into table
		char voting_process_name[25];
		printf("Enter voting process name: ");
		get_str_input(voting_process_name, sizeof(voting_process_name));

		printf("Name entered is: [%s]\n", voting_process_name);
		if (SUCCESS == insert_into_tb(voting_process_name))
		{
			printf("Done!!!\n");
		}
		else
		{
			// printf("Error occurred: %s\n", error_message);
			fprintf(stderr, "SQL error: %s\n", error_message);
			sqlite3_free(error_message);
		}
	*/

	// read all values
	/* read_all_from_tb();

	disconnect_database(); */

	return 0;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{

	// VotingProcess voting_process;
	// voting_process.id = argv[0];
	// // strcpy(voting_process.status, argv[2]);
	// voting_process.name = argv[1];
	// voting_process.status = argv[2];
	// printf("%s\n", argv[0]);
	// printf("%s\n", argv[1]);
	// printf("%s\n", argv[2]);

	// print_voting_process(voting_process);

	printf("\n");

	// argc      = column count = 3
	// argv      = values       = [ [1, "A", 0], [2, "B", 1], [3, "C", 0] ]
	// azColName = column names = [ [ id, name, status ], [ id, name, status ], [ id, name, status ]]
	/* for (int i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n"); */

	return 0;
}

int connect_database()
{
	// TODO: manually check that the database file exists before connecting to it
	int db_status = FAILURE;

	if (!sqlite3_open(DATABASE_PATH, &database_connection))
	{
		db_status = SUCCESS;
	}

	return db_status;
}

void disconnect_database()
{
	sqlite3_close(database_connection);
	printf("Database connection closed\n");
}

int insert_into_tb(char *voting_process_name)
{
	// INSERT INTO voting_processes(name) VALUES(?), voting_process_name

	char insert_sql[256];
	int insert_status = FAILURE;

	sprintf(insert_sql, "INSERT INTO voting_processes(name) VALUES('%s')\n",
			voting_process_name);

	if (SQLITE_OK == sqlite3_exec(
						 database_connection,
						 insert_sql,
						 callback,
						 0,
						 &error_message))
	{
		insert_status = SUCCESS;
	}

	return insert_status;
}

void read_all_from_tb()
{
	char *read_sql = "SELECT * FROM voting_processes";

	if (SQLITE_OK == sqlite3_exec(database_connection, read_sql, callback, 0, &error_message))
	{
		puts("data from select query");
		fprintf(stdout, "Data from table");
	}
	else
	{
		puts("couldn't insert into table");
		fprintf(stderr, "%s\n", error_message);
	}
}
