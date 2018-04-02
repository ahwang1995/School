package com.example.teambaus.moneybaus;

import android.content.Intent;
import android.app.AlertDialog;
import android.app.Application;

import java.io.File;
import java.io.Serializable;
import java.util.*;
import java.text.*;

import android.content.DialogInterface;
import android.content.Intent;
import android.database.*;
import android.view.View;
import android.widget.Toast;

/**
 * Created by Stefan on 10/27/15.
 */
public class Budget implements Serializable {

    double totalMoney;
    private Date finishDate;
    private Date startDate;
    HashMap<String,Double> categoriesAndMoneySpent=new HashMap<String,Double>();
    LinkedList<Expense> expenseLinkedList = new LinkedList<Expense>();
    private final String defaultCategory = "Other";

    public Budget(){
        Calendar date = Calendar.getInstance();
        this.totalMoney = 0;
        Date utilDate = date.getTime();
        this.startDate = utilDate;
        date.set(2100,11,25);
        utilDate = date.getTime();
        this.finishDate = utilDate;

        //setup default categories
        addCategory(defaultCategory);
        addCategory("Food");
        addCategory("Gas");
        addCategory("Rent");
    }
    public Budget(double amount, String finishDate){
        this.totalMoney = amount;
        this.startDate = new Date();
    }

    public boolean setStartDate(Date date) {
        Boolean bool = false;
        if(date.before(this.finishDate)) {
            this.startDate = date;
            bool = true;
        }
        return bool;
    }
    public Date getStartDate(){
        return this.startDate;
    }
    public boolean setFinishDate(Date date) {
        Boolean bool = false;
        if(date.after(this.startDate)) {
            this.finishDate = date;
            bool = true;
        }
        return bool;
    }
    public Date getFinishDate(){
        return this.finishDate;
    }
    public boolean setTotalAmount(double amount){
        Boolean boo1 = false;
        if(amount >= 0){
            this.totalMoney = amount;
            boo1 = true;
        }
        return boo1;
    }
    public double getTotalMoney() {

        return this.totalMoney;

    }



    /**
     * adds an expense to the linked list of expenses and updates the spending by category
     * @param amount - cost of the expense
     * @param category - category of the expense
     * @param name - name of the expense (can be left blank)
     */
    public void enterExpense(double amount, String category, String name)
    {
        totalMoney = totalMoney - amount;
        /*if (totalMoney < 0){

            Toast.makeText(Globals.getAppContext(), "You have exceeded you're budget",
                    Toast.LENGTH_LONG).show();
            AlertDialog.Builder builder = new AlertDialog.Builder(this);
            builder.setTitle("Budget has ended");
            builder.setMessage("Do you want to create a new Budget?");

            builder.setPositiveButton("YES", new DialogInterface.OnClickListener() {

                public void onClick(DialogInterface dialog, int which) {

                    dialog.dismiss();
                }

            });

            builder.setNegativeButton("NO", new DialogInterface.OnClickListener() {

                @Override
                public void onClick(DialogInterface dialog, int which) {
                    dialog.dismiss();
                }
            });


            AlertDialog alert = builder.create();
            alert.show();

        }*/

        //update the amount associated with category
        if(categoriesAndMoneySpent.containsKey(category))
        {
            categoriesAndMoneySpent.put(category, categoriesAndMoneySpent.get(category) + amount);
        } else {
            categoriesAndMoneySpent.put(category, amount);
        }

        //add expense to the list of expenses
        //assume variable when = now
        Date when = Calendar.getInstance().getTime();
        expenseLinkedList.add(new Expense(name, category, when, amount));
    }
    public void editExp(double originalcost, double edited,String originalCat, String category) {
        double amount = originalcost - edited;
        totalMoney = totalMoney + (amount);
        if(totalMoney < 0) {
            Toast.makeText(Globals.getAppContext(), "You have exceeded your budget",
                    Toast.LENGTH_LONG).show();
        }

        //update category amounts
        if(categoriesAndMoneySpent.containsKey(category))
        {
            categoriesAndMoneySpent.put(originalCat, categoriesAndMoneySpent.get(originalCat) - originalcost);
            categoriesAndMoneySpent.put(category, categoriesAndMoneySpent.get(category) + edited);
        } else {
            categoriesAndMoneySpent.put(originalCat, categoriesAndMoneySpent.get(originalCat) - originalcost);
            categoriesAndMoneySpent.put(category, edited);
        }
    }

    public HashMap<String, Double> getCategoriesAndMoneySpent()
    {
        return categoriesAndMoneySpent;
    }

    public List<String> getCategories()
    {
        List<String> categories = new ArrayList<String>();
        Iterator it = categoriesAndMoneySpent.entrySet().iterator();
        while (it.hasNext())
        {
            Map.Entry pair = (Map.Entry)it.next();
            categories.add((String)pair.getKey());
        }
        return categories;
    }

    public boolean addCategory(String categoryName) {
        if (!categoriesAndMoneySpent.containsValue(categoryName))
        {
            categoriesAndMoneySpent.put(categoryName, 0.);
            return true;
        }
        return false;
    }

    public boolean deleteCategory(String categoryName) {
        if(categoryName.equals(defaultCategory))
        {
            return false;
        }
        if (categoriesAndMoneySpent.containsKey(categoryName))
        {
            double amount = categoriesAndMoneySpent.get(categoryName);
            categoriesAndMoneySpent.put(defaultCategory, categoriesAndMoneySpent.get(defaultCategory) + amount);
            categoriesAndMoneySpent.remove(categoryName);
            for(Expense E: expenseLinkedList)
            {
                if(E.getCategory().equals(categoryName))
                    E.setCategory(defaultCategory);
            }
            return true;
        }
        return false;
    }
}
