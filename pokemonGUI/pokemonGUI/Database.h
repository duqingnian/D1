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



//void CheckConn()
//{
//	bool isOpenDB = false;
//	isOpenDB = connectDB();
//	if (isOpenDB)
//		cout << "Connected Successful" << endl;
//	else cout << "connection failed " << endl;
//}
