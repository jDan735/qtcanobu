#include <QString>

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

#include <iostream>
using namespace std;

class SQLite_Wrapper {
    public:
        void open(const char *name)
        {
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName(name);
            db.open();
        }

        void table()
        {
            QSqlQuery query;

            query.exec("CREATE TABLE results (" \
                       "Username TEXT," \
                       "User int," \
                       "Bot int," \
                       "Result INTEGER" \
                       ");");
        }

        void insert(QString username, int result, int user, int bot)
        {
            QString result_str = QString::number(result);
            QString user_str = QString::number(user);
            QString bot_str = QString::number(bot);
            QSqlQuery query;
            query.exec("INSERT INTO results VALUES ('" + username + "'," + user_str + ", " + bot_str + "," + result_str + ");");
        }

//        void insert(QString username, int result)
//        {
//            int rc;
//            QString sql_str;
//            const char *sql;
//            char *zErrMsg = 0;

//            QString result_str = QString::number(result);

//            sql_str = "INSERT INTO results VALUES ('" + username + "', " + result_str + ");";
//            sql = sql_str.toStdString().c_str();

//            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

//            if(rc != SQLITE_OK){
//                cout << "SQL error: " << zErrMsg << endl;
//                sqlite3_free(zErrMsg);
//            } else {
//                cout << "Records created successfully" << endl;
//            }
//        }

//        void show()
//        {
//            int rc;
//            string sql_str;
//            const char *sql;
//            char *zErrMsg = 0;

//            sql_str = "SELECT * FROM results";
//            sql = sql_str.c_str();

//            rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

//            if(rc != SQLITE_OK){
//                cout << "SQL error: " << zErrMsg << endl;
//                sqlite3_free(zErrMsg);
//            } else {
//                cout << "Select created successfully" << endl;
//            }

//            cout << "ban" << endl;
//        }

//        static int callback(void *NotUsed, int argc, char **argv, char **azColName)
//        {
//            for(int i = 0; i < argc; i++) {
//                cout << azColName[i] << " = " << argv[i] ? argv[i] : "NULL";
//                cout << "   ";
//            }

//            cout << endl;
//            return 0;
//        }

    private:
        QSqlDatabase db;
};
