package com.changami.app.todolist;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;
import com.changami.app.todolist.db.ListDataDao;
import com.changami.app.todolist.db.MySQLiteOpenHelper;

import java.util.List;

public class MyAdapter extends ArrayAdapter<ListData> {

    static SQLiteDatabase dataBase;
    static ListDataDao dao;

    private LayoutInflater mLayoutInflater;

    public MyAdapter(Context context) {
        super(context, android.R.layout.simple_list_item_1);
        mLayoutInflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);

        MySQLiteOpenHelper mHelper = new MySQLiteOpenHelper(context);
        dataBase = mHelper.getWritableDatabase();
        dao = new ListDataDao(dataBase);

        reloadDB(dao);
    }

    @Override
    public View getView(final int position, View convertView, final ViewGroup parent) {
        if (convertView == null) {
            convertView = mLayoutInflater.inflate(R.layout.list_item, null);
        }

        ListData item = getItem(position);
        // get the TextView to display item_label, and set value
        TextView itemLabel = (TextView) convertView.findViewById(R.id.item_label);
        itemLabel.setText(item.getTextData());
        // get the TextView to display item_time, and set value
        TextView itemTime = (TextView) convertView.findViewById(R.id.item_time);
        itemTime.setText(item.getAddingDateTime());
        // get the Button, and set ClickListener
        Button deleteButton = (Button) convertView.findViewById(R.id.delete_button);
        deleteButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ListView listView = (ListView) parent;
                MyAdapter adapter = (MyAdapter) listView.getAdapter();
                adapter.remove(getItem(position));
            }
        });

        return convertView;
    }

    /**
     * insert to DataBase and ListView
     *
     * @param listData ListData
     */
    public void insert(ListData listData) {
        dao.insert(listData);
        reloadDB(dao);
    }

    /**
     * remove from DataBase and ListView
     *
     * @param listData ListData
     */
    @Override
    public void remove(ListData listData) {
        dao.delete(listData.getId());
        reloadDB(dao);
    }

    public void reloadDB(ListDataDao dao) {
        clear();
        List<ListData> data = dao.selectAll();
        for (ListData item : data) {
            insert(item, 0);
        }
    }
}
