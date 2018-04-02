package com.example.teambaus.moneybaus;

/**
 * Created by Kurona on 10/31/2015.
 */

import android.app.DatePickerDialog;
import android.app.Dialog;
import android.content.Context;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.DatePicker;
import android.app.DialogFragment;
import android.widget.Toast;

import com.example.teambaus.moneybaus.Globals;

import java.text.SimpleDateFormat;
import java.util.*;

import java.util.Calendar;

public class DatePickerFragment extends DialogFragment
    implements DatePickerDialog.OnDateSetListener{
    Context context;
    public DatePickerFragment() {

    }

    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState){
        //use the current date as picker's default values
        Calendar date = Calendar.getInstance();
        int year = date.get(Calendar.YEAR);
        int month = date.get(Calendar.MONTH);
        int day = date.get(Calendar.DAY_OF_MONTH);

        // Create new instance of DatePickerDialog & return
        return new DatePickerDialog(getActivity(), this, year, month, day);
    }



    public void onDateSet(DatePicker view, int year, int month, int day) {
        //Gets the Globals object so Budget methods can be called
        Globals currentBudget = ((Globals)getActivity().getApplicationContext());
        //Calendar object is called to turn year-month-day into Date object for storage
        Calendar date = Calendar.getInstance();
        //clear the calendar object to wipe out default values
        String buttonID = this.getArguments().getString("button_ID");
        date.clear();

        date.set(Calendar.YEAR, year);
        date.set(Calendar.MONTH, month);
        date.set(Calendar.DAY_OF_MONTH, day);
        //create date object, and then pass to Budget.setStartDate
        Date utilDate = date.getTime();
        boolean checkValidDate = false;
        String buttonText;
        SimpleDateFormat dateFormat = new SimpleDateFormat("MM/dd/yy");
        if(buttonID.equals("start_button_id")) {
            checkValidDate = currentBudget.getCurrentBudget().setStartDate(utilDate);
            Button dateButton = (Button) getActivity().findViewById(R.id.start_button_id);
            buttonText = dateFormat.format(currentBudget.getCurrentBudget().getStartDate());
            dateButton.setText(buttonText);
            /*Toast.makeText(Globals.getAppContext(), "Start date : " + month + "/" + day + "/" + year,
                    Toast.LENGTH_LONG).show();*/
        }
        else if(buttonID.equals("end_button_id")) {
            checkValidDate = currentBudget.getCurrentBudget().setFinishDate(utilDate);
            Button dateButton = (Button) getActivity().findViewById(R.id.end_button_id);
            buttonText = dateFormat.format(currentBudget.getCurrentBudget().getFinishDate());
            dateButton.setText(buttonText);
            /*Toast.makeText(Globals.getAppContext(), "Finish date : " + month + "/" + day + "/" + year,
                    Toast.LENGTH_LONG).show();*/
        }
        else if (buttonID.equals("edit_expense_date_button")) {
            int expenseId = this.getArguments().getInt("expense_ID");
            Expense e = currentBudget.getCurrentBudget().expenseLinkedList.get(expenseId);
            checkValidDate = e.setWhen(utilDate);
            Button dateButton = (Button) getActivity().findViewById(R.id.edit_expense_date_button);
            buttonText = dateFormat.format(e.getWhen());
            dateButton.setText(buttonText);
        }
        if(!checkValidDate){
            Toast.makeText(Globals.getAppContext(),"Invalid Date",Toast.LENGTH_LONG).show();
        }

    }
}
