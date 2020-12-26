#include <iostream>
#include <sqlite3.h>

using namespace std;

class SQLite_Wrapper {
    public:
        void open_db(string name)
        {
            int rc = sqlite3_open("test.db", &db);

            if(rc) {
                cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
            } else {
                cout << "Opened database successfully" << endl;
            }
        }

        void create_table()
        {
            int rc;
            const char *sql;
            char *zErrMsg = 0;

            sql = "CREATE TABLE results (" \
                    "Username TEXT," \
                    "Result INTEGER" \
                  ");";

            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

            if(rc != SQLITE_OK){
                cout << "SQL error: " << zErrMsg << endl;
                sqlite3_free(zErrMsg);
            } else {
                cout << "Records created successfully" << endl;
            }
        }

        void insert_result(string username, string result)
        {
            int rc;
            string sql_str;
            const char *sql;
            char *zErrMsg = 0;

            sql_str = "INSERT INTO results VALUES ('" + username + "', " + result + ");";
            sql = sql_str.c_str();

            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

            if(rc != SQLITE_OK){
                cout << "SQL error: " << zErrMsg << endl;
                sqlite3_free(zErrMsg);
            } else {
                cout << "Records created successfully" << endl;
            }
        }

        void show_content()
        {
            int rc;
            string sql_str;
            const char *sql;
            char *zErrMsg = 0;

            sql_str = "SELECT * FROM results";
            sql = sql_str.c_str();

            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

            if(rc != SQLITE_OK){
                cout << "SQL error: " << zErrMsg << endl;
                sqlite3_free(zErrMsg);
            } else {
                cout << "Select created successfully" << endl;
            }

            cout << "ban" << endl;
        }

        static int callback(void *NotUsed, int argc, char **argv, char **azColName)
        {
            for(int i = 0; i < argc; i++) {
                cout << azColName[i] << " = " << argv[i] ? argv[i] : "NULL";
                cout << "   ";
            }

            cout << endl;
            return 0;
        }

    private:
        sqlite3 *db;
};
