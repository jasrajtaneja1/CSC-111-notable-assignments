//Author: Jasraj Taneja
//Student Number: V00942510

#include <stdio.h>

void print_array(int array[], int len);
int count_occurances(int array[], int len, int val);
void multiply_by(int array[], int len, int multiplier);
void multiply_by_to_dest(int array[], int dest[], int len, int multiplier);
int copy_values_above_to_dest(int array[], int dest[], int len, int threshold);
void shift_left_by_one(int array[], int start, int length);
int keep_values_above(int array[], int len, int threshold);
int contains_negatives(int array[], int len);


int main (void) {
    int array_a[5] = {1, 2, 3, 4, 5};

    print_array(array_a,5);
    printf("\n");



    int array_b[5] ={1, 2, 4, 2, 2};
    printf("Occurances for array_b: %d",count_occurances(array_b,5,2));
    printf("\n");



    multiply_by(array_b,5,2);
    printf("\n");




    int dest[0] = {};

    multiply_by_to_dest(array_b, dest, 5, -1);
    printf("\n\n");


    int array_c[4] = {4,2,1,2};
    printf("%d", copy_values_above_to_dest(array_c,dest,4,1));
    printf("\n\n");



    int array_d[5] = {1,2,4,6,3};
    int array_e[6] = {1,2,4,5,3,7};
    shift_left_by_one(array_d,0,5);
    printf("\n");
    shift_left_by_one(array_e,4,6);
    printf("\n\n");


    int array_f[5] = {1,2,4,1,2};
    printf("%d", keep_values_above(array_f,5,1));
    printf("\n\n");


    int array_g[4] = {0,5,3,-1};
    printf("%d", contains_negatives(array_g,4));


    return 0;
}



//Purpose: prints an array from specified length
//Parameters: int - array[], len
//Returns: Nothing


void print_array(int array[], int len){

  for(int i = 0; i<len; i++){

      printf("%d ",array[i]);

  }

}

//Purpose: Counts the number of times the array matches a given value
//Parameters: int - array[], len, val
//Returns: int - val

int count_occurances(int array[], int len, int val){
    int count = 0;

for(int i = 0; i<len; i++){

    if(array[i] == val){

        count++;
    }
}

return count;


}
//Purpose: Multiplies array by a given value, and prints.
//Parameters: int - array[], len, multiplier
//Returns: Nothing


void multiply_by(int array[], int len, int multiplier) {


    for(int i = 0; i<len; i++){

      array[i] *= multiplier;
    }
}

//Purpose: takes initial input array and garbage dest array, prints dest array that contains multiplied input array.
//Parameters: int - array[], dest[], len, multiplier
//Returns: Nothing

void multiply_by_to_dest(int array[], int dest[], int len, int multiplier){

    int i;

    printf("Input array: ");
    for(i = 0; i<len; i++){

        printf("%d ", array[i]);

    }
    printf("\n");

    printf("Destination array:");

    for(i=0; i<len; i++){

        dest[i] = array[i] * multiplier;
        printf("%d ", dest[i]);

    }
}

//Purpose: prints dest array which holds numbers above threshold, initial input array is given, and so is threshold and length.
//Parameters: int - array[], dest[], len, threshold
//Returns: number of values above threshold

int copy_values_above_to_dest(int array[], int dest[], int len, int threshold){


    int i;
    int count = 0;





    for(i = 0; i<len; i++){

        if(array[i]>threshold){

        dest[i] = array[count];
        count++;



        }

    }
printf("\n");
printf( "return value for copy_values_above_threshold: ");
return count;
}

//Purpose: array is shifted left by one at the start point that is given, removes the value at the start value.
//Parameters: int - array[], start, length
//Returns: Nothing


void shift_left_by_one(int array[], int start, int length) {

    int i;


        for (i = start; i < length; i++) {


            array[i] = array[i+1];
            printf("%d", array[i]);
        }

    }

//Purpose: Takes values that are above threshold and shifts them to the start, values under threshold become zero
//Parameters: int - array[], len, threshold
//Returns: Number of values above threshold

int keep_values_above(int array[], int len, int threshold) {

    int i =0;
    int count=0;
    int array1 = 0;



for(i=0;i<len;i++){

    if(array[i]>threshold){

    count++;
        printf("%d ", array[i]);

    }

}
printf("\n");
printf("number of values above threshold: ");
return count;

}





//Purpose: Checks if given array has any negative numbers
//Parameters: int - array[], len
//Returns: 1 - if array contains negative value(s), 0 - if array does not contain negatives


int contains_negatives(int array[], int len){

   int i;

    for(i=0;i<=len;i++){

        if(array[i]<0) {
            printf("Returned:");
            return 1;
        }
    }
    for(i=0;i<=len;i++){
        if(array[i] >= 0){

            printf("Returned:");
            return 0;
        }


    }

}
