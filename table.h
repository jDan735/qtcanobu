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

        QSqlQuery select()
        {
            QSqlQuery query;
            query.exec("SELECT * FROM results");

            return query;
        }

        void clean()
        {
            QSqlQuery query;
            query.exec("DELETE FROM results");
        }

    private:
        QSqlDatabase db;
};
