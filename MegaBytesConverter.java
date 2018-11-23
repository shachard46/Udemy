package com.company;

public class MegaBytesConverter {
    public static void printMegaBytesAndKiloBytes(int kiloBytes) {
        int megaBytes = kiloBytes / 1024;
        int kbRemaining = kiloBytes % 1024;
        System.out.println(kiloBytes + "KB = " + megaBytes + "MB and " + kbRemaining + "KB");
    }
}
