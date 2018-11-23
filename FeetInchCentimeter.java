package com.company;

public class FeetInchCentimeter {

    public static double calcFeetAndInchesToCentimeters(double inches, double feet) {
        double centimeter = -1;
        if (inches >= 0 && inches <= 12 && feet >= 0) {
            centimeter = 2.54 * inches + 12 * 12.54 * feet;
        }
        return centimeter;
    }
    public static double calcFeetAndInchesToCentimeters(double inches) {
        double feet = -1;
        if (inches >= 0) {
            feet = 12 * inches;
        }
        return feet;
    }
}
