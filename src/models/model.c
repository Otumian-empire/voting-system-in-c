#include "./model.h"

// TODO: check if the username already exists: create a function for it
// TODO: check if the voting process exists: create a function for it
// TODO: hash the pin before inserting

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

/**
 * write_callback
 *
 * - a method that does nothing but is passed when writing
 * - writing can be creating, updating and deleting
 */
int write_callback(void *NotUsed, int argc, char **argv, char **azColName)
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

/**
 * print_voting_process
 *
 * prints the content of a voting process
 */
void print_voting_process(VotingProcess v)
{
	printf("%-4s %-30s %-4s\n", v.id, v.name,
		   SUCCESS == strcmp(PROCESS_STATUS_TRUE, v.status)
			   ? PROCESS_STATUS_DONE
			   : PROCESS_STATUS_ON_GOING);
}

/**
 * list_voting_process_models
 *
 * prints a format list of voting processes
 */
void list_voting_process_models()
{
	// SELECT id, name, status FROM voting_processes
	char *read_sql = "SELECT * FROM voting_processes";

	if (SQLITE_OK != sqlite3_exec(
						 connection,
						 read_sql,
						 list_voting_process_callback,
						 0,
						 &error_message))

	{
		printf("couldn't read from table\n");
		fprintf(stderr, "%s\n", error_message);
	}
}

/**
 * list_voting_process_callback
 *
 * callback used for printing voting process
 */
int list_voting_process_callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	VotingProcess voting_process = {argv[0], argv[1], argv[2]};
	print_voting_process(voting_process);

	return 0;
}

/**
 * create_registered_voter_model
 */
int create_registered_voter_model(int voting_process_id, char *username, char *pin)
{
	// check if the username already exists
	// check if the voting process exists
	// these comments above are tied to the to-dos are the top

	// INSERT INTO registered_voters(username, pin, voting_process_id) VALUES(?,?,?),
	// username, pin, voting_process_id

	char insert_sql[TITLE_SIZE];
	int insert_status = FAILURE;

	sprintf(insert_sql,
			"INSERT INTO registered_voters(username, pin, voting_process_id) VALUES('%s', '%s', '%d')\n",
			username, pin, voting_process_id);

	int sqlite_result = sqlite3_exec(
		connection, insert_sql, write_callback, 0, &error_message);

	if (SQLITE_OK == sqlite_result)
	{
		insert_status = SUCCESS;
	}

	return insert_status;
}

void print_registered_voter(RegisteredVoter r)
{
	char *has_voted_str = SUCCESS == strcmp(PROCESS_STATUS_TRUE, r.has_voted)
							  ? PROCESS_STATUS_VOTED
							  : PROCESS_STATUS_HAS_NOT_VOTED;

	printf("%-4s %-15s %-15s %-25s\n", r.id, r.username, r.voting_processes,
		   has_voted_str);
}

/**
 * list_registered_voters_callback
 *
 * callback used for printing registered voter
 */
int list_registered_voters_callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	RegisteredVoter registered_voter = {argv[0], argv[1], argv[2], argv[3], argv[4]};
	print_registered_voter(registered_voter);

	return 0;
}

/**
 * list_registered_voters_model
 */
void list_registered_voters_model(int voting_process_id)
{
	// SELECT id, name, status FROM voting_processes
	char *read_sql = "SELECT * FROM registered_voters";

	if (SQLITE_OK != sqlite3_exec(
						 connection,
						 read_sql,
						 list_registered_voters_callback,
						 0,
						 &error_message))

	{
		printf("couldn't read from table\n");
		fprintf(stderr, "%s\n", error_message);
	}
}