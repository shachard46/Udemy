package com.company;

public class DecimalComparator {
    public static boolean areEqualByThreeDecimalPlaces(double n1, double n2){
        if ((int)(n1 * 1000) == (int)(n2 * 1000)){
            return true;
        }
        return false;
    }
}
