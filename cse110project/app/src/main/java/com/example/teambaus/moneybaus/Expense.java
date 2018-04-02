package com.example.teambaus.moneybaus;

import java.util.Comparator;
import java.util.Date;
import java.io.Serializable;

/**
 * Class for individual Expenses. A Budget contains a list of Expenses.
 */
public class Expense implements Serializable{
    private String name;
    private String category;
    private Date when;
    private double cost;

    Expense(String name, String category, Date when, double cost) {
        this.name = name;
        this.category = category;
        this.when = when;
        this.cost = cost;
    }

    public String getName(){ return this.name; }
    public boolean setName (String inName) {
        boolean nameSet = false;
        this.name = inName;
        if(this.name.equals(name)) {
            nameSet = true;
        }
        return nameSet;
    }
    public String getCategory(){ return this.category; }
    public boolean setCategory(String inCategory) {
        boolean catSet = false;
        this.category = inCategory;
        if(this.category.equals(inCategory)) {
            catSet = true;
        }
        return catSet;
    }
    public Date getWhen(){ return this.when; }
    public boolean setWhen(Date date) {
        boolean dateSet = false;
        this.when = date;
        if(this.when.equals(date)) {
            dateSet = true;
        }
        return dateSet;
    }
    public double getCost(){ return this.cost; }
    public boolean setCost(double inCost) {
        boolean costSet = false;
        this.cost = inCost;
        if(this.cost == inCost) {
            costSet = true;
        }
        return costSet;
    }
}