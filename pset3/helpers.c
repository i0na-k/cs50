/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int start = 0;
    int end = n-1;
    bool found = false;
    // TODO: implement a searching algorithm
    
    //Return false if n is not positive
    if (n < 1 || end > n){
    return false;
    }
    
    while (found==false){
        int middle = (start + end) / 2;
    
        if (value==values[middle]){
            printf("Value Found!\n");
            break;
            return true;
        }
    
        
        else if(values[middle] < value){
            found = false;
            start = middle+1;
        }
        
        else{
            found = false;
            end = middle -1;
        }
    }
    
    return true;
}

/**
 * Sorts array of n values.
 */

void sort(int values[], int n)
{
    int tmp = 0;
    int count;
    // TODO: implement an O(n^2) sorting algorithm
    
    do
    {
    count = 0;
    for (int i = 0; i < n-1; i++){
            if(values[i] > values[i+1]){
                tmp = values[i];
                values[i] = values [i+1];
                values[i+1] = tmp;
            count ++;
                                        
        
                                    }
                                }
    }
    while(count > 0);
    
    }
    
    

    
