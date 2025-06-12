// Not a LeetCode Problem

// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

// Given two arrays, arr[] and dep[], that represent the arrival and departure times of 
// trains respectively, the task is to find the minimum number of platforms required so
//  that no train waits.

// Java program to find minimum Platforms Required
// for Given Arrival and Departure Times

import java.util.Arrays;

class GfG {
    public int minPlatform(int[] arr, int[] dep) {
        Arrays.sort(arr);
        Arrays.sort(dep);
        int i = 0, j = 0, count = 0, maxCount = 0;
        while (i < arr.length) {
            if (arr[i] <= dep[j]) {
                count += 1;
                i++;
            } else {
                count--;
                j++;
            }
            maxCount = Math.max(count, maxCount);
        }
        return maxCount;
    }
}

public class minPlatformsRequired {
    public static void main(String[] args) {
        int[] arr = { 900, 940, 950, 1100, 1500, 1800 };
        int[] dep = { 910, 1200, 1120, 1130, 1900, 2000 };
        GFG gfg = new GfG();
        System.out.println(gfg.minPlatform(arr, dep));
    }
}