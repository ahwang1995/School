package com.example.teambaus.moneybaus;

import java.util.*;

/**
 * Created by Stefan on 11/15/15.
 */
public class ExpenseComparatorByCategory implements Comparator<Expense>{

    public int compare(Expense e1, Expense e2) {

        //compare by category
        if (e1.getCategory().compareTo(e2.getCategory()) != 0) {
            return e1.getCategory().compareTo(e2.getCategory());
        }
        //use date as fallback
        return e1.getWhen().compareTo(e2.getWhen());
    }

}
