package com.example.teambaus.moneybaus;


import android.app.DialogFragment;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import android.graphics.drawable.*;
import java.io.File;

public class Start extends AppCompatActivity {
//maybe can add Globals as field element?
EditText editText;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        File savedBudget = new File("/sdcard/save_object.ser");

        if( savedBudget.isFile() )
        {

            hasBudget();

        }

        editText = (EditText)findViewById(R.id.spend_id);
        setContentView(R.layout.activity_start);

        EditText spendID = (EditText)findViewById(R.id.spend_id);
        spendID.setBackgroundResource(R.drawable.button_border);

        GradientDrawable drawable = (GradientDrawable)spendID.getBackground();
        drawable.setColor(Color.WHITE);

        Button createButton = (Button)findViewById(R.id.createBudgetButton);
        createButton.setTransformationMethod(null);

        Globals currentBudget = ((Globals)getApplicationContext());

        //currentBudget.testDate("asdas");

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_start, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    public void hasBudget() {

        Intent hasBudgetIntent = new Intent(this, Enter_Expense.class);
        startActivity(hasBudgetIntent);

    }

    public void createBudgetButtonClicked(View v) {
        editText = (EditText)findViewById(R.id.spend_id);
        if(editText.getText().toString().length() == 0){
            //put in toast notification for empty string
            return;
        }
        String str_budgetAmount = editText.getText().toString();

        double budgetAmount = 0.0;
        if (!str_budgetAmount.matches("(\\d+([.](\\d{2})?)?)|([.]\\d{2})")){
            Toast.makeText(Globals.getAppContext(), "Invalid expense format",
                    Toast.LENGTH_LONG).show();
            return;
        }

        budgetAmount = Double.parseDouble(str_budgetAmount.toString());

        if (budgetAmount == 0.0){
            Toast.makeText(Globals.getAppContext(), "Expense of zero is invalid",
                    Toast.LENGTH_LONG).show();
            return;
        }


        Globals currentBudget = ((Globals)getApplicationContext());
        currentBudget.getCurrentBudget().setTotalAmount(budgetAmount);

        currentBudget.saveBudget(currentBudget.getCurrentBudget());

        Intent createBudgetButtonIntent = new Intent(this, Enter_Expense.class);
        startActivity(createBudgetButtonIntent);
    }

    public void showDatePickerDialog(View v) {
        //get the String ID of the button that was clicked
        String buttonID = getResources().getResourceEntryName(v.getId());
        //create a bundle to pass to the DatePickerFragment, which will hold this id
        Bundle bundle = new Bundle();
        bundle.putString("button_ID",buttonID);
        DialogFragment datePicker = new DatePickerFragment();
        datePicker.setArguments(bundle);
        datePicker.show(getFragmentManager(), "datePicker");
    }
}
