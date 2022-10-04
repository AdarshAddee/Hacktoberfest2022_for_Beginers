/*
Author : Prathamesh Patil
In selection sort,
we get the least from array and place it at first position, then recursively leaving the first element do the same
*/


#include<stdio.h>

//declaration of display function
void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

//declaration of funtion :- selection sort
void selection_sort(int array[], int size)
{
    int least, i, j, temp, l;
    
    for ( i = 0; i < size; i++)         //loop for accessing the ith element from array
    {
        least = array[i];           //taking the i element as the least starting from 0
        printf("Least : %d")
        
        for ( j = i + 1; j < size; j++)         //loop for comparing the array elements with ith element
        {
            if (least > array[j])           //getting the least element from the array
            {
                least = array[j];           //storing it in the least variable
                l=j;            //storing the index of least variable in l
            }   
        }
        //swap logic in least and ith element
        temp = array[i];
        array[i] = array[l];
        array[l] = temp;
    }
}

int main()
{
    int array[5] = {23,11,1,35,21};
    int size = 5;

    //calling the selection_sort funtion
    selection_sort(array, size);
     
    //calling the display function
    display(array, size);

    return 0;
}
