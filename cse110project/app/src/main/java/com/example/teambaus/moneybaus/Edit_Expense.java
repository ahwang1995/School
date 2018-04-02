package com.example.teambaus.moneybaus;

import android.app.AlertDialog;
import android.app.DialogFragment;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.content.Intent;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import java.io.File;
import java.text.DecimalFormat;
import java.text.SimpleDateFormat;
import java.util.HashMap;
import java.util.List;

/**
 * Created by Stefan on 11/23/15.
 */
public class Edit_Expense extends AppCompatActivity {

    private Expense e = (Expense) null;
    private int expenseIdx = -1;
    double origCost;
    String origCategory;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit__expense);

        Intent i = getIntent();
        int expenseId = -1;
        expenseId = i.getIntExtra("EXPENSE_ID", expenseId);
        expenseIdx = expenseId;

        Globals currentBudget = ((Globals) getApplicationContext());

        //using ID, get the expense that was selected
        //save the values in the expense that existed on load in the expense
        e = currentBudget.getCurrentBudget().expenseLinkedList.get(expenseId);


        EditText nameEditText = (EditText) findViewById(R.id.edit_expense_name);
        nameEditText.setText(e.getName());
        nameEditText.setBackgroundResource(R.drawable.button_border);

        List<String> categories  = currentBudget.getCurrentBudget().getCategories();//new ArrayList<String>();

        Spinner spinner = (Spinner)findViewById(R.id.edit_category_button);

        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
                android.R.layout.simple_spinner_dropdown_item, categories);
        spinner.setAdapter(adapter);

        //List<String> categories  = currentBudget.getCurrentBudget().getCategories();//new ArrayList<String>();

        EditText costEditText = (EditText) findViewById(R.id.edit_expense_amount);
        costEditText.setBackgroundResource(R.drawable.button_border);
        costEditText.setText(new DecimalFormat("#0.00").format(e.getCost()));
        origCost = e.getCost();
        origCategory = e.getCategory();

        //change the text of the button to string on load
        SimpleDateFormat dateFormat = new SimpleDateFormat("MM/dd/yy");
        Button b = (Button) findViewById(R.id.edit_expense_date_button);
        b.setText(dateFormat.format(e.getWhen()));
    }

    public void cancelButtonOnClick(View view) {
        //create intent to go back to enter_expense without saving any changes
        Intent createCancelButtonIntent = new Intent(this, Enter_Expense.class);
        startActivity(createCancelButtonIntent);
    }

    public void saveChangesButtonOnClick(View view) {
        //get name, check validity
        EditText editNameText = (EditText)findViewById(R.id.edit_expense_name);
        String editNameString = editNameText.getText().toString();

        //get category
        Spinner spinner = (Spinner)findViewById(R.id.edit_category_button);
        String newCategory = spinner.getSelectedItem().toString();

        final Globals currentBudget = ((Globals) getApplicationContext());
        //currentBudget.getCurrentBudget().moveExpense(e, newCategory);

        //check expense validity
        EditText editExpense = (EditText)findViewById(R.id.edit_expense_amount);

        double amount = 0.0;
        if (!editExpense.getText().toString().matches("(\\d+([.](\\d{2})?)?)|([.]\\d{2})")){
            Toast.makeText(Globals.getAppContext(), "Invalid expense format",
                    Toast.LENGTH_LONG).show();
            return;
        }

        amount = Double.parseDouble(editExpense.getText().toString());

        if (amount == 0.0){
            Toast.makeText(Globals.getAppContext(), "Expense of zero is invalid",
                    Toast.LENGTH_LONG).show();
            return;
        }
        //get date
        //change the values appropriately
        if(!newCategory.equals("")) {
            currentBudget.getCurrentBudget().editExp(origCost, amount, origCategory, newCategory);
            e.setCategory(newCategory);
        } else {
            currentBudget.getCurrentBudget().editExp(origCost, amount, origCategory, "Other");
            e.setCategory("Other");
        }
        e.setName(editNameString);
        e.setCost(amount);

        currentBudget.saveBudget(currentBudget.getCurrentBudget());
        final Intent newBudget = new Intent(this, Start.class);
        if (currentBudget.getCurrentBudget().totalMoney < 0){

            Toast.makeText(Globals.getAppContext(), "You have exceeded you're budget",
                    Toast.LENGTH_LONG).show();
            AlertDialog.Builder builder = new AlertDialog.Builder(this);
            builder.setTitle("Budget has ended");
            builder.setMessage("Do you want to create a new Budget?");

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

        Intent createCancelButtonIntent = new Intent(this, Enter_Expense.class);
        startActivity(createCancelButtonIntent);
    }

    public void deleteExpenseButtonOnClick(View view) {

        final Globals currentBudget = ((Globals) getApplicationContext());
        final Intent createDeleteButtonIntent = new Intent(this, Enter_Expense.class);
        AlertDialog.Builder builder = new AlertDialog.Builder(this);

        builder.setTitle("Delete");
        builder.setMessage("Are you sure?");

        builder.setPositiveButton("YES", new DialogInterface.OnClickListener() {

            public void onClick(DialogInterface dialog, int which) {
                currentBudget.getCurrentBudget().expenseLinkedList.remove(expenseIdx);
                startActivity(createDeleteButtonIntent);
                currentBudget.getCurrentBudget().editExp(origCost, 0, origCategory, origCategory);
                currentBudget.saveBudget(currentBudget.getCurrentBudget());
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

    public void editDateButtonOnClick(View v) {
        Intent i = getIntent();
        int expenseId = -1;
        expenseId = i.getIntExtra("EXPENSE_ID", expenseId);
        //get the String ID of the button that was clicked
        String buttonID = getResources().getResourceEntryName(v.getId());
        //create a bundle to pass to the DatePickerFragment, which will hold this id
        Bundle bundle = new Bundle();
        bundle.putString("button_ID",buttonID);
        bundle.putInt("expense_ID", expenseId);
        DialogFragment datePicker = new DatePickerFragment();
        datePicker.setArguments(bundle);
        datePicker.show(getFragmentManager(), "datePicker");
    }

}
