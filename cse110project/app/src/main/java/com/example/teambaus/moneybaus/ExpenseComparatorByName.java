package com.example.teambaus.moneybaus;
import java.util.*;

/**
 * Created by Stefan on 11/17/15.
 */
public class ExpenseComparatorByName implements Comparator<Expense> {

    public int compare(Expense e1, Expense e2) {
        //if names are different
        if (e1.getName().compareTo(e2.getName()) != 0) {
            return e1.getName().compareTo(e2.getName());
        }
        //else use date
        return e1.getWhen().compareTo(e2.getWhen());
    }
}
