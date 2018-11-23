package com.company;

public class BarkingDog {
    public static boolean bark(boolean barking, int hourOfDay){
        if (barking && ((hourOfDay > 22 && hourOfDay < 24) || (hourOfDay < 8 && hourOfDay > 0))){
            return true;
        } else{
            return false;
        }
    }
}
