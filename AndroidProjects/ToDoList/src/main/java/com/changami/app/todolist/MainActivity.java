package com.changami.app.todolist;

import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;

import java.util.Date;


public class MainActivity extends ActionBarActivity {

    ListView listView;
    MyAdapter mAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mAdapter = new MyAdapter(this);

        // get Layout's list_view to listView
        listView = (ListView) findViewById(R.id.list_view);
        listView.setAdapter(mAdapter);

        // get Layout's add_button to addButton
        Button addButton = (Button) findViewById(R.id.add_button);
        addButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ListData listData = new ListData();

                EditText todoNameForm = (EditText) findViewById(R.id.todo_name_edit);
                String todoName = todoNameForm.getText().toString();
                if (todoName.length() == 0) return;
                listData.setTextData(todoName);

                listData.setAddingDateTime(new Date());

                mAdapter.insert(listData, 0);
                listView.setAdapter(mAdapter);
                // clearing input form
                todoNameForm.setText("");
            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
