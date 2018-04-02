package com.example.teambaus.moneybaus;

import org.junit.Before;
import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.Assert.*;

import android.app.Activity;
import android.app.Instrumentation;
import android.content.Intent;
import android.support.test.espresso.action.ViewActions;
import android.support.test.espresso.matcher.ViewMatchers;
import android.support.test.internal.runner.junit3.JUnit38ClassRunner;
import android.support.test.rule.ActivityTestRule;
import android.support.test.runner.AndroidJUnit4;
import android.support.test.InstrumentationRegistry;
import android.test.ActivityInstrumentationTestCase2;
import android.test.suitebuilder.annotation.LargeTest;

import junit.framework.Assert;

import java.io.File;

import static android.support.test.espresso.Espresso.onView;
import static android.support.test.espresso.action.ViewActions.click;
import static android.support.test.espresso.action.ViewActions.closeSoftKeyboard;
import static android.support.test.espresso.action.ViewActions.typeText;
import static android.support.test.espresso.assertion.ViewAssertions.matches;
import static android.support.test.espresso.matcher.ViewMatchers.withId;
import static android.support.test.espresso.matcher.ViewMatchers.withText;

/*
 * SCENARIO: test creating budget, adding expense to budget, sorting expenses
 *
 * Given: There is no budget and I am on the Create Budget page
 * When: I enter a budget
 * Then: I am taken to the enter expense page
 * //REPEAT THE FOLLOW BLOCK THREE TIMES
 * When: I click on the text box labeled $0.00
 * Then: I can enter an expense amount
 * When: I click on the text box to the right of the expense entry box
 * Then: I can attach a name to the expense to indicate its purpose
 * When: I click on 'Spend'
 * Then: the expense is entered and shows up in the chart
 * //END BLOCK
 * When: I click on the 'Expense' button
 * Then: the expenses display, sorted by cost in increasing order
 * When: I click on the 'Name' button
 * Then: expenses are sorted in alphabetical order by label
 */

@RunWith(AndroidJUnit4.class)
@LargeTest
public class Scenario01EnterExpenseSort extends ActivityInstrumentationTestCase2<Start>{

    private Globals global = ((Globals)Globals.getAppContext().getApplicationContext());

    private Budget budget;

    public Scenario01EnterExpenseSort(){
        super(Start.class);
    }

    @Before
    /** Delete a budget if there is one to enable creating a new budget when the test starts*/
    public void setUp() throws Exception {
        super.setUp();
        injectInstrumentation(InstrumentationRegistry.getInstrumentation());

        File savedBudget = new File("/sdcard/save_object.ser");
        if( savedBudget.isFile() )
        {

            savedBudget.delete();
        }
        global.setCurrentBudget(new Budget());
        budget = global.getCurrentBudget();
    }


    @Test
    public void testScenario01EnterExpenseSort() {

        getActivity();
        //* Given: There is no budget and I am on the Create Budget page
        //* When: I enter a budget
        onView(withId(R.id.spend_id)).perform(typeText("10000"), closeSoftKeyboard());
        onView(withId(R.id.createBudgetButton)).perform(click());
        //*Then: I am taken to the enter expense page

        /* When: I click on the text box labeled $0.00
         * Then: I can enter an expense amount */
        onView(withId(R.id.enter_expense_amount)).perform(typeText("1300"),closeSoftKeyboard());
        /* When: I click on the text box to the right of the expense entry box
         * Then: I can attach a name to the expense to indicate its purpose */
        onView(withId(R.id.enter_expense_label)).perform(typeText("October"),closeSoftKeyboard());
        /* When: I click on 'Spend'
         * Then: the expense is entered and shows up in the chart */
        onView(withId(R.id.enter_expense_button)).perform(click());

        System.out.println("Testing: budget should contain 1 item:\n");
        Assert.assertEquals(budget.expenseLinkedList.size(), 1);

        /* When: I click on the text box labeled $0.00
         * Then: I can enter an expense amount */
        onView(withId(R.id.enter_expense_amount)).perform(typeText("1200"), closeSoftKeyboard());
        /* When: I click on the text box to the right of the expense entry box
         * Then: I can attach a name to the expense to indicate its purpose */
        onView(withId(R.id.enter_expense_label)).perform(typeText("November"),closeSoftKeyboard());
        /* When: I click on 'Spend'
         * Then: the expense is entered and shows up in the chart */
        onView(withId(R.id.enter_expense_button)).perform(click());


        System.out.println("Testing: budget should contain 2 items:\n");
        Assert.assertEquals(budget.expenseLinkedList.size(), 2);

        /* When: I click on the text box labeled $0.00
         * Then: I can enter an expense amount */
        onView(withId(R.id.enter_expense_amount)).perform(typeText("1400"), closeSoftKeyboard());
        /* When: I click on the text box to the right of the expense entry box
         * Then: I can attach a name to the expense to indicate its purpose */
        onView(withId(R.id.enter_expense_label)).perform(typeText("December"),closeSoftKeyboard());
        /* When: I click on 'Spend'
         * Then: the expense is entered and shows up in the chart */
        onView(withId(R.id.enter_expense_button)).perform(click());

        System.out.println("Testing: budget should contain 3 items:\n");
        Assert.assertEquals(budget.expenseLinkedList.size(), 3);

        //When: I click on the 'Expense' button
        //Then: the expenses display, sorted by cost in increasing order
        onView(withId(R.id.cost_button)).perform(click());

        System.out.println("Testing sorting by cost\n");
        //expense costs should be 1200, 1300, 1400 and expense names should be November, October, December
        System.out.println("Testing: first budget element should have cost of 1200.00:\n");
        Assert.assertEquals(budget.expenseLinkedList.get(0).getCost(), 1200.0);
        System.out.println("Testing: second budget element should have cost of 1300.00:\n");
        Assert.assertEquals(budget.expenseLinkedList.get(1).getCost(), 1300.0);
        System.out.println("Testing: third budget element should have cost of 1400.00:\n");
        Assert.assertEquals(budget.expenseLinkedList.get(2).getCost(), 1400.0);

        System.out.println("Testing: first budget element should have name 'November':\n");
        Assert.assertEquals(budget.expenseLinkedList.get(0).getName(), "November");
        System.out.println("Testing: second budget element should have name 'October':\n");
        Assert.assertEquals(budget.expenseLinkedList.get(1).getName(), "October");
        System.out.println("Testing: third budget element should have name of 'December':\n");
        Assert.assertEquals(budget.expenseLinkedList.get(2).getName(), "December");


        //When: I click on the 'Name' button
        //Then: expenses are sorted in alphabetical order by label
        onView(withId(R.id.name_button)).perform(click());

        System.out.println("Testing sorting by name\n");
        //expense names should be December, November, October
        System.out.println("Testing: first budget element should have name 'December':\n");
        Assert.assertEquals(budget.expenseLinkedList.get(0).getName(), "December");
        System.out.println("Testing: second budget element should have name 'November':\n");
        Assert.assertEquals(budget.expenseLinkedList.get(1).getName(), "November");
        System.out.println("Testing: third budget element should have name of 'October':\n");
        Assert.assertEquals(budget.expenseLinkedList.get(2).getName(), "October");

        //expense cost should be 1400,1200,1300
        System.out.println("Testing: first budget element should have cost of 1400.00:\n");
        Assert.assertEquals(budget.expenseLinkedList.get(0).getCost(), 1400.0);
        System.out.println("Testing: second budget element should have cost of 1200.00:\n");
        Assert.assertEquals(budget.expenseLinkedList.get(1).getCost(), 1200.0);
        System.out.println("Testing: third budget element should have cost of 1300.00:\n");
        Assert.assertEquals(budget.expenseLinkedList.get(2).getCost(), 1300.0);

    }



}
