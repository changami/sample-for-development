package com.changami.app.todolist;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;

public class MyAdapter extends ArrayAdapter<ListData> {

    private LayoutInflater mLayoutInflater;

    public MyAdapter(Context context) {
        super(context, android.R.layout.simple_list_item_1);
        mLayoutInflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
    }

    @Override
    public View getView(final int position, View convertView, final ViewGroup parent) {
        if (convertView == null) {
            convertView = mLayoutInflater.inflate(R.layout.list_item, null);
        }

        ListData item = getItem(position);
        // get the TextView, and set input String
        TextView itemLabel = (TextView) convertView.findViewById(R.id.item_label);
        itemLabel.setText(item.getTextData());
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
}
