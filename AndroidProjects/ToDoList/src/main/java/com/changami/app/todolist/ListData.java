package com.changami.app.todolist;

import java.text.SimpleDateFormat;
import java.util.Date;

public class ListData {

    private int _id;
    private String textData_;
    private String addingDate;

    public int getId() {
        return _id;
    }

    public void setId(int _id) {
        this._id = _id;
    }

    public void setTextData(String text) {
        textData_ = text;
    }

    public String getTextData() {
        return textData_;
    }

    public String getAddingDateTime() {
        return addingDate;
    }

    public void setAddingDateTime(Date addingDateTime) {
        SimpleDateFormat formatter = new SimpleDateFormat("yyyy.MM.dd G 'at' HH:mm:ss z");
        this.addingDate = formatter.format(addingDateTime);
    }

    public void setAddingDateTime(String formattedAddingDateTime) {
        this.addingDate = formattedAddingDateTime;
    }
}

