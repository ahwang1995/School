package com.example.teambaus.moneybaus;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.drawable.GradientDrawable;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.text.format.DateUtils;
import android.view.View;
import android.view.ViewGroup.LayoutParams;
import android.widget.*;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import android.app.Application;
import java.util.*;
import java.text.*;
import android.database.*;


public class Enter_Expense extends AppCompatActivity {

    static int SORT_BY_CATEGORY = 0;
    static int SORT_BY_COST = 1;
    static int SORT_BY_NAME = 2;
    static int SORT_BY_DATE = 3;
    private int currentSortParameter = 3;

    private ArrayList<MediaPlayer> entrySoundPlayer = new ArrayList<MediaPlayer>();
    private Random randGen;
    private SimpleDateFormat dateFormat;

    public void goToEditCategories()
    {
        Intent createBudgetButtonIntent = new Intent(this, Edit_Categories.class);
        startActivity(createBudgetButtonIntent);
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_enter__expense);

        randGen = new Random();
        entrySoundPlayer.add(MediaPlayer.create(this, R.raw.cha_ching));
        entrySoundPlayer.add(MediaPlayer.create(this, R.raw.coin));
        entrySoundPlayer.add(MediaPlayer.create(this, R.raw.moneybags));

        //if(true)
         //   return;
        Globals currentBudget = ((Globals)getApplicationContext());

        //create dateformatter for strings
        dateFormat = new SimpleDateFormat("MM/dd/yy");

        TextView totalMoneyTextView = (TextView)findViewById(R.id.total_money_textview);
        NumberFormat cf = NumberFormat.getCurrencyInstance();
        totalMoneyTextView.setText(String.valueOf(cf.format(currentBudget.getCurrentBudget().getTotalMoney())));

        if(currentBudget.getCurrentBudget().getTotalMoney() < 0)
        {
            totalMoneyTextView.setTextColor(Color.RED);
        } else

        {
            totalMoneyTextView.setTextColor(Color.WHITE);
        }

        List<String> categories  = currentBudget.getCurrentBudget().getCategories();//new ArrayList<String>();
        categories.add("Edit Categories");

        Spinner spinner = (Spinner)findViewById(R.id.catigory_picker);
        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parentView, View selectedItemView, int position, long id) {
                Spinner spinner = (Spinner)findViewById(R.id.catigory_picker);
                String selectedItem = spinner.getSelectedItem().toString();
                if(selectedItem.equals("Edit Categories"))
                {
                    spinner.setSelection(0);
                    goToEditCategories();
                }
            }
            @Override
            public void onNothingSelected(AdapterView<?> parentView) {}

        });

        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
                android.R.layout.simple_spinner_dropdown_item, categories);
        //adapter.setDropDownViewResource(R.layout.activity_enter__expense);
        spinner.setAdapter(adapter);
        updateBudget(currentBudget.getCurrentBudget());

        final Button chartButton = (Button)findViewById(R.id.chartButton);
        final Button enterExpenseButton = (Button)findViewById(R.id.enter_expense_button);
        final Button nameButton = (Button)findViewById(R.id.name_button);
        final Button costButton = (Button)findViewById(R.id.cost_button);
        final Button categoryButton = (Button)findViewById(R.id.category_button);
        final Button dateButton = (Button)findViewById(R.id.date_button);

        chartButton.setTransformationMethod(null);
        enterExpenseButton.setTransformationMethod(null);
        nameButton.setTransformationMethod(null);
        costButton.setTransformationMethod(null);
        categoryButton.setTransformationMethod(null);
        dateButton.setTransformationMethod(null);

        EditText enterExpense = (EditText)findViewById(R.id.enter_expense_amount);
        enterExpense.setBackgroundResource(R.drawable.button_border);

        GradientDrawable drawableEnterExpense = (GradientDrawable)enterExpense.getBackground();
        drawableEnterExpense.setColor(Color.WHITE);

        EditText enterExpenseLabel = (EditText)findViewById(R.id.enter_expense_label);
        enterExpenseLabel.setBackgroundResource(R.drawable.button_border);

        GradientDrawable drawableEnterExpenseLabel = (GradientDrawable)enterExpenseLabel.getBackground();
        drawableEnterExpenseLabel.setColor(Color.WHITE);

    }


    //add all expenses
    protected void listExpenses(Budget budget){
        Iterator it = budget.expenseLinkedList.iterator();
        int i = 0;

        Globals currentBudget = ((Globals)getApplicationContext());

        final Button nameButton = (Button)findViewById(R.id.name_button);
        final Button costButton = (Button)findViewById(R.id.cost_button);
        final Button categoryButton = (Button)findViewById(R.id.category_button);
        final Button dateButton = (Button)findViewById(R.id.date_button);

        //for length of the array, get ids and set the text to zero
        LinearLayout name_column = (LinearLayout) findViewById(R.id.name_column_inner);
        LinearLayout cost_column = (LinearLayout) findViewById(R.id.cost_column_inner);
        LinearLayout category_column = (LinearLayout) findViewById(R.id.category_column_inner);
        LinearLayout date_column = (LinearLayout) findViewById(R.id.date_column_inner);

        name_column.removeAllViews();
        cost_column.removeAllViews();
        category_column.removeAllViews();
        date_column.removeAllViews();

        for (Expense expense : budget.expenseLinkedList ){
            String cat = expense.getCategory();
            String name = expense.getName();
            if ("".equals(name)){
                name = "untitled";
            }
            Date when = expense.getWhen();
            Double cost = expense.getCost();

            TextView name_textview = new TextView(this);
            name_textview.setText(name);
            name_textview.setId(i);
            LinearLayout.LayoutParams nameLayout = new LinearLayout.LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
            nameLayout.setMargins((int) currentBudget.dpToPx(30), 0, 0, 0);
            name_textview.setLayoutParams(nameLayout);
            name_textview.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    expenseClick(v);
                }
            });
            name_column.addView(name_textview);


            TextView cost_textview = new TextView(this);
            cost_textview.setText(new DecimalFormat("#0.00").format(cost));
            //cost_textview.setText("" + cost); //TOOD: make sure formatting is pretty
            cost_textview.setId(i);
            LinearLayout.LayoutParams costLayout = new LinearLayout.LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
            costLayout.setMargins((int) currentBudget.dpToPx(30), 0, 0, 0);
            cost_textview.setLayoutParams(costLayout);
            cost_textview.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    expenseClick(v);
                }
            });
            cost_column.addView(cost_textview);

            TextView category_textview = new TextView(this);
            category_textview.setText(cat);
            category_textview.setId(i);
            LinearLayout.LayoutParams categoryLayout = new LinearLayout.LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
            categoryLayout.setMargins((int) currentBudget.dpToPx(30), 0, 0, 0);
            category_textview.setLayoutParams(categoryLayout);
            category_textview.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    expenseClick(v);
                }
            });
            category_column.addView(category_textview);

            TextView date_textview = new TextView(this);
            long now = System.currentTimeMillis();
            date_textview.setText(dateFormat.format(when));
            date_textview.setId(i);
            LinearLayout.LayoutParams dateLayout = new LinearLayout.LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
            dateLayout.setMargins((int) currentBudget.dpToPx(30), 0, 0, 0);
            date_textview.setLayoutParams(dateLayout);
            date_textview.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    expenseClick(v);
                }
            });
            date_column.addView(date_textview);

            i++;
        }
    }

    /* sort the budget and update the display */
    protected void updateBudget(Budget budget) {
        sortBudget(budget, currentSortParameter);
        listExpenses(budget);
    }

    /* enter an expense or display error messages if input is bad */
    public void Enter_Expense(View v)
    {

        //get expense amount and do error handling if invalid
        EditText edit = (EditText)findViewById(R.id.enter_expense_amount);

        double amount = 0.0;
        if (!edit.getText().toString().matches("(\\d+([.](\\d{2})?)?)|([.]\\d{2})")){
            Toast.makeText(Globals.getAppContext(), "Invalid expense format",
                    Toast.LENGTH_LONG).show();
            return;
        }

        if(!entrySoundPlayer.isEmpty()) {
            entrySoundPlayer.get(randGen.nextInt(entrySoundPlayer.size())).start();
        }

        amount = Double.parseDouble(edit.getText().toString());

        if (amount == 0.0){
            Toast.makeText(Globals.getAppContext(), "Expense of zero is invalid",
                    Toast.LENGTH_LONG).show();
            return;
        }

        //get expense label. NOTE THAT the empty string is valid
        EditText edit2 = (EditText)findViewById(R.id.enter_expense_label);
        String expenseLabel = edit2.getText().toString();

        //get category of expense
        Spinner spinner = (Spinner)findViewById(R.id.catigory_picker);
        String selectedItem = spinner.getSelectedItem().toString();

        final Globals currentBudget = ((Globals) getApplicationContext());

        if(!selectedItem.equals("")) {
            currentBudget.getCurrentBudget().enterExpense(amount, selectedItem, expenseLabel);
        } else {
            currentBudget.getCurrentBudget().enterExpense(amount, "Other", expenseLabel);
        }

        if( currentBudget.getCurrentBudget().expenseLinkedList.size() == 1 )
        {

            final Button dateButton = (Button)findViewById(R.id.date_button);
            dateButton.setTextColor(Color.WHITE);

        }

        //sort the budget with the added item included and redisplay it

        updateBudget(currentBudget.getCurrentBudget());
        currentBudget.saveBudget(currentBudget.getCurrentBudget());

        TextView totalMoneyTextView = (TextView)findViewById(R.id.total_money_textview);

        NumberFormat cf = NumberFormat.getCurrencyInstance();
        totalMoneyTextView.setText(String.valueOf(cf.format(currentBudget.getCurrentBudget().getTotalMoney())));

        if(currentBudget.getCurrentBudget().getTotalMoney() < 0)
        {
            totalMoneyTextView.setTextColor(Color.RED);
        } else

        {
            totalMoneyTextView.setTextColor(Color.WHITE);
        }

        //clear fields after successful entry
        edit.setText("");
        edit2.setText("");
        final Intent newBudget = new Intent(this, Start.class);
        if (currentBudget.getCurrentBudget().totalMoney < 0){

            //Toast.makeText(Globals.getAppContext(), "You have exceeded your budget",
            //        Toast.LENGTH_LONG).show();
            AlertDialog.Builder builder = new AlertDialog.Builder(this);
            builder.setTitle("You have exceeded your budget!");
            builder.setMessage("Do you want to create a new budget?");

            builder.setPositiveButton("YES", new DialogInterface.OnClickListener() {

                public void onClick(DialogInterface dialog, int which) {
                    File savedBudget = new File("/sdcard/save_object.ser");

                    if( savedBudget.isFile() )
                    {
                        savedBudget.delete();
                    }
                    currentBudget.setCurrentBudget(new Budget());
                    startActivity(newBudget);
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

        }
    }


    /* when one of the header buttons for the table is pressed, sort the budget
     * according to the parameter on the label (e.g. date, cost)
     */
    public void tableButtonClick(View view){

        Globals currentBudget = ((Globals)getApplicationContext());
        Budget budget  = currentBudget.getCurrentBudget();
        int expenses = budget.expenseLinkedList.size();

        final Button nameButton = (Button)findViewById(R.id.name_button);
        final Button costButton = (Button)findViewById(R.id.cost_button);
        final Button categoryButton = (Button)findViewById(R.id.category_button);
        final Button dateButton = (Button)findViewById(R.id.date_button);


        switch(view.getId()){
            case R.id.category_button:
                sortBudget(budget, SORT_BY_CATEGORY);
                currentSortParameter = SORT_BY_CATEGORY;
                if( expenses > 0 ) {

                    nameButton.setTextColor(Color.BLACK);
                    costButton.setTextColor(Color.BLACK);
                    categoryButton.setTextColor(Color.WHITE);
                    dateButton.setTextColor(Color.BLACK);
                }

                break;
            case R.id.cost_button:
                sortBudget(budget, SORT_BY_COST);
                currentSortParameter = SORT_BY_COST;
                if( expenses > 0 ) {
                nameButton.setTextColor(Color.BLACK);
                costButton.setTextColor(Color.WHITE);
                categoryButton.setTextColor(Color.BLACK);
                dateButton.setTextColor(Color.BLACK);}
                break;
            case R.id.date_button:
                sortBudget(budget, SORT_BY_DATE);
                currentSortParameter = SORT_BY_DATE;
                if( expenses > 0 ) {
                nameButton.setTextColor(Color.BLACK);
                costButton.setTextColor(Color.BLACK);
                categoryButton.setTextColor(Color.BLACK);
                dateButton.setTextColor(Color.WHITE);}
                break;
            case R.id.name_button:
                sortBudget(budget, SORT_BY_NAME);
                currentSortParameter = SORT_BY_NAME;
                if( expenses > 0 ) {
                nameButton.setTextColor(Color.WHITE);
                costButton.setTextColor(Color.BLACK);
                categoryButton.setTextColor(Color.BLACK);
                dateButton.setTextColor(Color.BLACK);}
        }

        updateBudget(budget);

    }

    /* sorts the budget based on a passed parameter
     */
    private void sortBudget(Budget budget, int how){
        if (how == SORT_BY_CATEGORY){
            Collections.sort(budget.expenseLinkedList, new ExpenseComparatorByCategory());
        }
        if (how == SORT_BY_NAME){
            Collections.sort(budget.expenseLinkedList, new ExpenseComparatorByName());
        }
        if (how == SORT_BY_COST){
            Collections.sort(budget.expenseLinkedList, new ExpenseComparatorByCost());
        }
        if (how == SORT_BY_DATE){
            Collections.sort(budget.expenseLinkedList, new ExpenseComparatorByDate());
        }
    }

    public void chartButtonClick(View view){
        Intent createChartButtonIntent = new Intent(this, Baus_Chart.class);
        startActivity(createChartButtonIntent);
    }

    /* creates a new intent to edit a particular expense */
    public void expenseClick(View view) {
        Intent expenseSelectIntent = new Intent(this, Edit_Expense.class);

        expenseSelectIntent.putExtra("EXPENSE_ID", view.getId());
        startActivity(expenseSelectIntent);

    }

}
