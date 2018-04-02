package com.example.teambaus.moneybaus;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.drawable.AnimationDrawable;
import android.graphics.drawable.Drawable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.InputType;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

public class Edit_Categories extends AppCompatActivity {

    Button.OnClickListener mReturnListener;
    Button.OnClickListener mDeleteListener;
    Button.OnClickListener mNewListener;
    private String mNewCategoryName = "";

    public void goToEnterExpense()
    {
        Intent returnIntent = new Intent(this, Enter_Expense.class);
        startActivity(returnIntent);
    }

    public void createNewCategort() {
        Globals currentBudget = ((Globals) getApplicationContext());
        currentBudget.getCurrentBudget().addCategory(mNewCategoryName);
        currentBudget.saveBudget(currentBudget.getCurrentBudget());
        fillContent();
    }

    public void displayNewCategoryPopup()
    {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("New Category Name:");

        final EditText newCategoryNameInput = new EditText(this);
        newCategoryNameInput.setInputType(InputType.TYPE_CLASS_TEXT | InputType.TYPE_TEXT_VARIATION_NORMAL);
        builder.setView(newCategoryNameInput);

        builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                mNewCategoryName = newCategoryNameInput.getText().toString();
                createNewCategort();
            }
        });
        builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                dialog.cancel();
            }
        });

        builder.show();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit__categories);


        mReturnListener = new Button.OnClickListener(){
            @Override
            public void onClick(View v) {
                goToEnterExpense();
            }
        };
        mDeleteListener = new Button.OnClickListener(){
            @Override
            public void onClick(View v) {

                Button button = (Button)v;
                String tag = (String)v.getTag();

                Globals currentBudget = ((Globals) getApplicationContext());
                currentBudget.getCurrentBudget().deleteCategory(tag);
                currentBudget.saveBudget(currentBudget.getCurrentBudget());
                fillContent();
            }
        };
        mNewListener = new Button.OnClickListener(){
            @Override
            public void onClick(View v) {
                displayNewCategoryPopup();
            }
        };
        fillContent();
    }
    
    private void fillContent() {
        LinearLayout my_root = (LinearLayout) findViewById(R.id.Edit_Categories_Root);

        my_root.removeAllViews();

        Globals currentBudget = ((Globals) getApplicationContext());
        List<String> categories = currentBudget.getCurrentBudget().getCategories();
        HashMap<String, Double> categoriesHash =
                currentBudget.getCurrentBudget().getCategoriesAndMoneySpent();

        for (String category : categories) {
            TextView category_name = new TextView(this);
            category_name.setText(category + "   ");
            category_name.setTextSize(17);
            category_name.setTextColor(Color.WHITE);
            category_name.setGravity(Gravity.CENTER);

            TextView categoryAmount = new TextView(this);
            categoryAmount.setText(((Double) categoriesHash.get(category)).toString() + "   ");
            categoryAmount.setTextSize(17);
            categoryAmount.setTextColor(Color.WHITE);
            categoryAmount.setGravity(Gravity.CENTER);

            Button deleteButton = new Button(this);
            deleteButton.setBackgroundColor(80000000);
            deleteButton.setTextColor(Color.WHITE);
            deleteButton.setText("Delete");
            deleteButton.setTag(category);
            deleteButton.setOnClickListener(mDeleteListener);

            LinearLayout A = new LinearLayout(this);
            A.setOrientation(LinearLayout.HORIZONTAL);
            A.addView(category_name);
            A.addView(categoryAmount);
            if (!category.equals("Other")) {
                A.addView(deleteButton);
            }
            my_root.addView(A);
        }

        Button returnButton = new Button(this);
        returnButton.setText("Return");
        returnButton.setBackgroundColor(80000000);
        returnButton.setTextColor(Color.WHITE);
        returnButton.setOnClickListener(mReturnListener);


        Button newCategoryButton = new Button(this);
        newCategoryButton.setText("New Category");
        newCategoryButton.setBackgroundColor(80000000);
        newCategoryButton.setTextColor(Color.WHITE);
        newCategoryButton.setOnClickListener(mNewListener);
        Drawable whitebord = getResources().getDrawable(R.drawable.white_border);
        returnButton.setTextSize(18);
        newCategoryButton.setTextSize(18);
        newCategoryButton.setLeft(20);
        returnButton.setBackground(whitebord);
        newCategoryButton.setBackground(whitebord);
        LinearLayout A = new LinearLayout(this);
        A.setOrientation(LinearLayout.HORIZONTAL);
        A.setTop(17);
        A.addView(returnButton);
        A.addView(newCategoryButton);
        my_root.addView(A);
    }

    protected void onRestart()
    {
        super.onRestart();

        fillContent();
    }

}
