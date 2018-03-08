#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#define DB "Pokemon.sqlite"
#include "Database\sqlite3.h"

bool isOpenDB = false;
sqlite3 *dbFile;

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

void displayTable()
{


	char *zErrMsg = 0;
	int rc;
	const char *sql;
	const char* data = "Callback function called";

	sql = "SELECT * from ability";
	rc = sqlite3_exec(dbFile, sql, callback, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "operation done succesfully \n");
	}
	sqlite3_close(dbFile);
}

bool connectDB()
{
	if (sqlite3_open(DB, &dbFile) == SQLITE_OK)
	{
		isOpenDB = true;
		return true;
	}

	return false;
}

void DisonnectDB()
{
	if (isOpenDB == true)
	{
		sqlite3_close(dbFile);
	}
}

void CheckConn()
{
	bool isOpenDB = false;
	isOpenDB = connectDB();
	if (isOpenDB)
		cout << "Connected Successful" << endl;
	else cout << "connection failed " << endl;
}