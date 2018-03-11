#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#define DB "Pokemon.sqlite"
#include "Database\sqlite3.h"




using namespace std;
static int callback(void *data, int argc, char **argv, char **azColName) {
	int i;
	fprintf(stderr, "%s: ", (const char*)data);

	for (i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");
	return 0;
}
void runParamSQL(sqlite3 *db, const char *fn, const char *ln, const char *emailAdd, const char * pass)
{


	char *zErrMsg = 0;
	sqlite3_stmt *stmt;
	const char *pzTest;
	char *szSQL;

	// Insert data item into myTable
	szSQL = "insert into Player (FirstName, LastName, EmailAddress, Password) values (?,?,?,?)";

	int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

	if (rc == SQLITE_OK) {

		// bind the value 
		sqlite3_bind_text(stmt, 1, fn, strlen(fn), 0);
		sqlite3_bind_text(stmt, 2, ln, strlen(ln), 0);
		sqlite3_bind_text(stmt, 3, emailAdd, strlen(emailAdd), 0);
		sqlite3_bind_text(stmt, 4, pass, strlen(pass), 0);


		// commit 
		sqlite3_step(stmt);
		sqlite3_finalize(stmt);

	}
}

void sqlExecute(const char *sql)
{
	bool isOpenDB = false;
	sqlite3 *dbFile;
	char *zErrMsg = 0;
	int rc;

	//sql = "SELECT * from ability";
	const char* data = "Callback function called";

	if (sqlite3_open(DB, &dbFile) == SQLITE_OK)
	{
		
		rc = sqlite3_exec(dbFile, sql, callback, (void*)data, &zErrMsg);
		
	}
	else
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(dbFile);
	
}

