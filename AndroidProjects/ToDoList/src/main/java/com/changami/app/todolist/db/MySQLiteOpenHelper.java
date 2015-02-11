package com.changami.app.todolist.db;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class MySQLiteOpenHelper extends SQLiteOpenHelper {

    static final String DB = "sqlite_todo.db";
    static final int DB_VERSION = 1;
    static final String CREATE_TABLE = "create table todo_list ( _id integer primary key autoincrement, text_data text not null, adding_date text);";
    static final String DROP_TABLE = "drop table todo_list;";

    public MySQLiteOpenHelper(Context context) {
        super(context, DB, null, DB_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(CREATE_TABLE);
    }

    // if DB version is different, run this
    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL(DROP_TABLE);
        onCreate(db);
    }
}