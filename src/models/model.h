#include <sqlite3.h>
#include <stdio.h>

#ifndef __model_h
#define __model_h

static const char *DATABASE_PATH = "../../bin/voting_system_db.db";

static sqlite3 *connection;
// static char *errorMessage = {'\0'};

void create_connection();
void close_connection();

#endif