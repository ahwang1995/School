package com.example.teambaus.moneybaus;

import android.graphics.Color;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.Toast;

import com.github.mikephil.charting.charts.PieChart;
import com.github.mikephil.charting.components.Legend;
import com.github.mikephil.charting.data.Entry;
import com.github.mikephil.charting.data.PieData;
import com.github.mikephil.charting.data.PieDataSet;
import com.github.mikephil.charting.formatter.PercentFormatter;
import com.github.mikephil.charting.highlight.Highlight;
import com.github.mikephil.charting.listener.OnChartValueSelectedListener;
import com.github.mikephil.charting.utils.ColorTemplate;

import java.util.ArrayList;
import java.util.HashMap;

public class Baus_Chart extends AppCompatActivity {
    //change xml to relative layout
    private RelativeLayout pieChartLayout;
    private PieChart pieChart;
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_baus__chart);
        pieChartLayout = (RelativeLayout)findViewById(R.id.pieChartLayout);
        pieChart = (PieChart)findViewById(R.id.piechart);
        //pieChartLayout.addView(pieChart, ViewGroup.LayoutParams.MATCH_PARENT);
        //pieChartLayout.setBackgroundColor(Color.LTGRAY);


        pieChart.setUsePercentValues(true);
        pieChart.setDescription("Baus Pie");

        pieChart.setDrawHoleEnabled(true);
        pieChart.setHoleColorTransparent(true);
        pieChart.setHoleRadius(7);
        pieChart.setTransparentCircleRadius(10);

        pieChart.setRotationAngle(0);
        pieChart.setRotationEnabled(true);

        pieChart.setOnChartValueSelectedListener(new OnChartValueSelectedListener() {
            @Override
            public void onValueSelected(Entry entry, int i, Highlight highlight) {
                if (entry == null) {
                    return;
                }
                /*Toast.makeText(Baus_Chart.this, xData[entry.getXIndex()] + "=" + entry.getVal() + "%"
                        , Toast.LENGTH_SHORT).show();*/
            }

            @Override
            public void onNothingSelected() {

            }
        });
        addData();

        Legend l = pieChart.getLegend();
        l.setPosition(Legend.LegendPosition.RIGHT_OF_CHART);
        l.setXEntrySpace(7);
        l.setYEntrySpace(5);

        /*Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });*/
    }
    private void addData(){
        Globals currentBudget = ((Globals) getApplicationContext());
        HashMap<String,Double> categoryMap = currentBudget.getCurrentBudget()
                .getCategoriesAndMoneySpent();
        String[] xData = categoryMap.keySet().toArray(new String[categoryMap.size()]);
        Float[] yData = new Float[categoryMap.size()];
        int index = 0;
        for(String Sindex : xData) {
            double dValue = categoryMap.get(Sindex);
            float fValue = (float)dValue;
            yData[index] = fValue;
            index++;
        }
        ArrayList<Entry> yVals = new ArrayList<Entry>();
        for(int i = 0; i<yData.length;i++){
            yVals.add(new Entry(yData[i],i));
        }
        ArrayList<String> xVals = new ArrayList<String>();
        for(int i = 0; i<xData.length;i++){
            xVals.add(xData[i]);
        }
        PieDataSet pieDataSet = new PieDataSet(yVals,"Categories");
        pieDataSet.setSliceSpace(3);
        pieDataSet.setSelectionShift(5);

        ArrayList<Integer> colors = new ArrayList<Integer>();
        for(int c : ColorTemplate.VORDIPLOM_COLORS){
            colors.add(c);
        }
        for(int c : ColorTemplate.JOYFUL_COLORS){
            colors.add(c);
        }
        for(int c : ColorTemplate.COLORFUL_COLORS){
            colors.add(c);
        }
        for(int c : ColorTemplate.LIBERTY_COLORS){
            colors.add(c);
        }
        for(int c : ColorTemplate.PASTEL_COLORS){
            colors.add(c);
        }
        colors.add(ColorTemplate.getHoloBlue());
        pieDataSet.setColors(colors);

        PieData pieData = new PieData(xVals,pieDataSet);
        pieData.setValueFormatter(new PercentFormatter());
        pieData.setValueTextSize(11f);
        pieData.setValueTextColor(Color.GRAY);

        pieChart.setData(pieData);
        pieChart.highlightValues(null);
        pieChart.invalidate();


    }

}
