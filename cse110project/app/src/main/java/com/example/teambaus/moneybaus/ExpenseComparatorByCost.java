package com.example.teambaus.moneybaus;
import java.util.*;

/**
 * Created by Stefan on 11/16/15.
 */
public class ExpenseComparatorByCost implements Comparator<Expense> {

    public int compare(Expense e1, Expense e2) {
        //if costs are different
        if (e1.getCost() != e2.getCost()) {
            return (int) (100 * (e1.getCost() - e2.getCost()));
        }
        //else use date
        return e1.getWhen().compareTo(e2.getWhen());
    }
}