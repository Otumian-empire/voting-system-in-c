#include "./model.h"

/**
 * Model will have a initialization (connection) and closing of the database
 *
 */

void create_connection()
{
	int conn = sqlite3_open(DATABASE_PATH, &connection);
	if (conn)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(connection));
	}
	else
	{
		fprintf(stderr, "Opened database successfully\n");
	}

	sqlite3_close(connection);
}

void close_connection()
{
}