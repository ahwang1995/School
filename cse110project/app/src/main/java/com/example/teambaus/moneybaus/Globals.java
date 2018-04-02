package com.example.teambaus.moneybaus;

import android.app.Application;
import android.content.Context;
import android.content.res.Resources;
import android.util.TypedValue;
import java.io.*;

/**
 * Created by Stefan on 10/27/15.
 */
public class Globals extends Application {

    private Budget currentBudget;
    private static Context context;

    public void onCreate(){
        super.onCreate();

        File savedBudget = new File("/sdcard/save_object.ser");

        if( savedBudget.isFile() )
        {

            this.currentBudget = loadBudget(savedBudget);

        }
        else
        {

            this.currentBudget = new Budget();

        }



        Globals.context = getApplicationContext();
    }

    public Budget getCurrentBudget() {

        return currentBudget;

    }

    public void setCurrentBudget(Budget currentBudget) {

        this.currentBudget = currentBudget;

    }

    public void saveBudget(Budget b){
        try
        {
            ObjectOutputStream outstream = new ObjectOutputStream(new FileOutputStream(new File("/sdcard/save_object.ser"), false));
            outstream.writeObject(b);
            outstream.flush();
            outstream.close();
        }
        catch(Exception ex)
        {

        }
    }

    public Budget loadBudget(File f)
    {
        try
        {
            ObjectInputStream inputstream = new ObjectInputStream(new FileInputStream(f));
            Budget loadedBudget = (Budget)inputstream.readObject();
            return loadedBudget;
        }
        catch(Exception ex)
        {

        }
        return null;
    }

    public float dpToPx(float dp)
    {

        Resources r = getResources();
        float px = TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, dp, r.getDisplayMetrics());

        return px;

    }


    public static Context getAppContext(){
        return Globals.context;
    }

}
