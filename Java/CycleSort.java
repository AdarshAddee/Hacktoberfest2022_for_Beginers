package com.topics.algorithms.sortingAlgorithms;

import java.util.Arrays;

public class CycleSort {
    public static void main(String[] args) {
        int[] arr={3,5,-2,1,4};
        cycsort(arr);
        System.out.println(Arrays.toString(arr));

    }
    static void cycsort(int[] arr){ 
        int i = 0;
        while(i<arr.length){
            int correct = arr[i] - 1;
            if(arr[i] >0 && arr[i]!= arr[correct] ){
                swap(arr,i,correct);
            } else {
                i++;
            }
        }
    }
    static void swap(int[] arr,int first,int second){
        int temp = arr[first];
        arr[first]=arr[second];
        arr[second]=temp;
    }
}


