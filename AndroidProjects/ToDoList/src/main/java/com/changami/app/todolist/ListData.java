package com.changami.app.todolist;

import java.text.SimpleDateFormat;
import java.util.Date;

public class ListData {

    private String textData_;
    private String addingDate;

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
}

