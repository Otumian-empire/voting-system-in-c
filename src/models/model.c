#include "./model.h"

static sqlite3 *connection;

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
 * Close connection and exit when an error occurs or anything of that sort
 */
void close_connection()
{
	sqlite3_close(connection);
	exit(ERROR);
}