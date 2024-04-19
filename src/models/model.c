#include "./model.h"

static sqlite3 *connection;
static char *error_message;

/**
 * create_connection
 *
 * initialize the database connection and exit on error
 */
void create_connection()
{
	int conn = sqlite3_open(DATABASE_PATH, &connection);
	if (conn)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(connection));
		exit(ERROR);
	}

	// for debugging
	// printf("Opened database successfully\n");
}

/**
 * close_connection
 *
 * Close connection
 */
void close_connection()
{
	sqlite3_close(connection);
}

/**
 * get_connection_error_message
 *
 * get the error message that the connection puts out
 */
void get_connection_error_message(char *error_message)
{
	strcpy(error_message, sqlite3_errmsg(connection));
}

static int write_callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	return 0;
}

/**
 * create_voting_process_model
 *
 * create a new record of a voting process by inserting a name
 */
int create_voting_process_model(char *voting_process_name)
{
	// INSERT INTO voting_processes(name) VALUES(?), voting_process_name

	char insert_sql[TITLE_SIZE];
	int insert_status = FAILURE;

	sprintf(insert_sql, "INSERT INTO voting_processes(name) VALUES('%s')\n",
			voting_process_name);

	int sqlite_result = sqlite3_exec(
		connection, insert_sql, write_callback, 0, &error_message);

	if (SQLITE_OK == sqlite_result)
	{
		insert_status = SUCCESS;
	}

	return insert_status;
}