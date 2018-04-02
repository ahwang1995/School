package com.example.teambaus.moneybaus;
import java.util.*;

/**
 * Created by Stefan on 11/17/15.
 */
public class ExpenseComparatorByDate implements Comparator<Expense> {

    public int compare(Expense e1, Expense e2) {
        //dates are guaranteed to be different
        return e1.getWhen().compareTo(e2.getWhen());
        //else go by date
    }
}
