package com.changami.app.todolist.db;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import com.changami.app.todolist.ListData;

import java.util.ArrayList;
import java.util.List;

public class ListDataDao {

    private static final String TABLE_NAME = "todo_list";
    private static final String COLUMN_ID = "_id";
    private static final String COLUMN_TODO_NAME = "text_data";
    private static final String COLUMN_ADDING_TIME = "adding_date";
    private static final String[] COLUMNS = {COLUMN_ID, COLUMN_TODO_NAME, COLUMN_ADDING_TIME};

    private SQLiteDatabase db;

    public ListDataDao(SQLiteDatabase db) {
        this.db = db;
    }

    /**
     * get all data
     *
     * @return List<ListData>
     */
    public List<ListData> selectAll() {
        List<ListData> entityList = new ArrayList<ListData>();
        Cursor cursor = db.query(
                TABLE_NAME,
                COLUMNS,
                null,
                null,
                null,
                null,
                COLUMN_ID);

        while (cursor.moveToNext()) {
            ListData entity = new ListData();
            entity.setId(cursor.getInt(0));
            entity.setTextData(cursor.getString(1));
            entity.setAddingDateTime(cursor.getString(2));
            entityList.add(entity);
        }

        return entityList;
    }

    /**
     * insert data to DB
     *
     * @param entity ListData
     * @return long
     */
    public long insert(ListData entity) {
        ContentValues values = new ContentValues();
        values.put(COLUMN_TODO_NAME, entity.getTextData());
        values.put(COLUMN_ADDING_TIME, entity.getAddingDateTime());
        return db.insert(TABLE_NAME, null, values);
    }

    /**
     * update data to DB
     *
     * @param entity ListData
     * @return int
     */
    public int update(ListData entity) {
        ContentValues values = new ContentValues();
        values.put(COLUMN_TODO_NAME, entity.getTextData());
        values.put(COLUMN_ADDING_TIME, entity.getAddingDateTime());
        String where = COLUMN_ID + "=" + entity.getId();
        return db.update(TABLE_NAME, values, where, null);
    }

    /**
     * delete data from DB
     *
     * @param _id int
     * @return int
     */
    public int delete(int _id) {
        String where = COLUMN_ID + "=" + _id;
        return db.delete(TABLE_NAME, where, null);
    }
}
