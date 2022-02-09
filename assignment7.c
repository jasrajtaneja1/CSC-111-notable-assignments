//Author: Jasraj Taneja
//Student Number: V00942510

#include <stdio.h>

#define NUM_COLS 3  // you are free to change this value, we will when we test your code


void print_array(int array[], int len);
void print_matrix(int m[][NUM_COLS], int num_rows);
void get_location_of_min(int matrix[][NUM_COLS], int num_rows, int* location_row, int* location_col);
void get_location_of_max(int matrix[][NUM_COLS], int num_rows, int* location_row, int* location_col);
void swap_min_max_values(int matrix[][NUM_COLS], int num_rows);

void print_matrix_pointers(int* matrix[], int num_rows, int num_cols);
void matrix_transpose_pointers(int* m1[], int* m_result[], int num_rows, int num_cols);
void matrix_multiply_by_vector_pointers(int* matrix[], int vector[], int v_result[], int num_rows, int num_cols);
void matrix_multiply_pointers(int* m1[], int* m2[], int* m_result[], int num_rows_m1, int num_cols_m1, int num_cols_m2);

int main (void) {

    int a3[2] = {1, 7};
    int b3[2] = {4, 2};
    int a4[2] = {3, 9};

    int b4[3] = {3, 3, 3};
    int b5[3] = {3, 3, 3};
    int a1[] = {1,1};
    int a2[] = {1,1};
    int* dest[2] = {a1,a2};

    int matrix[3][NUM_COLS] = {{3, 7,5}, {8, 4,4}, {8, 8,8}};
    int* table1[3] = {a3, b3, a4};
    int* predest_table[] = {b4,b5};
    int vector1[] = {2, 1, 0};
    int vector_result[] = {};
    int thing1[] = {1,-1,2};
    int thing2[] = {0,-3,1};
    int thing3[] = {0,4,-2};
    int thing4[] = {-4,-3,0};
    int thing5[] = {0,1};
    int thing6[] = {1,-1};
    int thing7[] =  {2,3};
    int* table2[2] = {thing1,thing2};

    int* matrix1[2] = {thing3, thing4};
    int* matrix2[3] = {thing5, thing6, thing7};


    print_array(a3,2);
    printf("\n");


    print_matrix(matrix,3);
    printf("\n");

    int row = 0, column = 0;
    get_location_of_min(matrix, 3,  &row, &column);
    printf("test get_location_of_min : %d, %d\n", row, column);

    printf("\n");

     row = 0, column = 0;
    get_location_of_max(matrix, 3,  &row, &column);
    printf("test get_location_of_max : %d, %d\n", row, column);
    printf("\n");

    swap_min_max_values(matrix,3);
   printf("The swapped matrix: \n");
   print_matrix(matrix,3);
    printf("\n");


    print_matrix_pointers(table1, 3,2);
    printf("\n");


   matrix_transpose_pointers(table1,predest_table,3,2);
   printf("The transposed: \n");
   print_matrix_pointers(predest_table,2,3);
     printf("\n");

     matrix_multiply_by_vector_pointers(table2,vector1,vector_result,2,3);
    print_array(vector_result,2);
   printf("\n");

    matrix_multiply_pointers(matrix1,matrix2, dest, 2, 3, 2);
    print_matrix_pointers(dest,2,2);
    printf("\n");

    return 0;
}


// Purpose: prints values in array on one line with space after each
// Params:  int array[], int len - number of elements in array
// Returns: nothing
void print_array(int array[], int len){
    int i;
    for(i=0; i<len; i++) {
        printf("%d ", array[i]);
        printf("\n");
    }
}

// Purpose: prints values in in a matrix using 2d arrays
// Params:   m[][NUM_COLS], num_rows
// Returns: Nothing

void print_matrix(int m[][NUM_COLS], int num_rows){

    int row;
    int column;

    for(row = 0; row<num_rows; row++){
        for(column = 0; column<NUM_COLS; column++){
            printf("%d " , m[row][column]);
        }
        printf("\n");
    }

}

// Purpose: gets location of the smallest value in 2d array
// Params:  matrix[][NUM_COLS], int num_row int*location_row, int* location_col
// Returns:Nothing


void get_location_of_min(int matrix[][NUM_COLS], int num_rows, int* location_row, int* location_col){

    int row;
    int column;
    int smallest = matrix[0][0];

    for(row = 0; row<num_rows; row++){
        for(column = 0; column<NUM_COLS; column++){

         if(smallest >= matrix[row][column]){
             smallest = matrix[row][column];
             *location_row = row;
             *location_col = column;
         }

        }
        printf("\n");
    }
}

// Purpose: gets location of the largest value in the matrix
// Params: matrix[][NUM_COL}, int num_rows, int* location_row, int* location_col
// Returns: Nothing

void get_location_of_max(int matrix[][NUM_COLS], int num_rows, int* location_row, int* location_col){

    int row;
    int column;
    int largest = matrix[0][0];

    for(row = 0; row<num_rows; row++){
        for(column = 0; column<NUM_COLS; column++){

            if(largest <= matrix[row][column]){
                largest = matrix[row][column];
                *location_row = row;
                *location_col = column;

            }

        }
        printf("\n");
    }
}


// Purpose: swaps the max and min values in the array
// Params:   matrix[][NUM_COLS], int num_rows
// Returns: Nothing

void swap_min_max_values(int matrix[][NUM_COLS], int num_rows){

    int min_row;

    int min_column;

    get_location_of_min(matrix, num_rows, &min_row, &min_column);

    int max_row;

    int max_column;

    get_location_of_max(matrix,num_rows,&max_row,&max_column);

    int initial_matrix = matrix[min_row][min_column];

    matrix[min_row][min_column] = matrix[max_row][max_column];

    matrix[max_row][max_column] = initial_matrix;




}
// Purpose: prints a 2d array from pointers
// Params:   int* matrix[], int num_rows, int num_cols
// Returns: Nothing

void print_matrix_pointers(int* matrix[], int num_rows, int num_cols){
    int row;
    int column;

    for(row=0; row<num_rows;row++){
        for(column=0;column<num_cols;column++){
            printf("%d ", matrix[row][column]);
        }
        printf("\n");
    }

}

// Purpose: prints the transpose of an array in a destination matrix
// Params:   int* m1[], int*m_result[], int num_rows, int num_cols
// Returns: Nothing

void matrix_transpose_pointers(int* m1[], int* m_result[], int num_rows, int num_cols) {

    int row = 0;
    int column = 0;



    for (row = 0; row < num_rows; row++) {
        for (column = 0; column < num_cols; column++) {

            m_result[column][row] = m1[row][column];

        }


    }
}
// Purpose: this function performs matrix vector multiplication
// Params:   int *matrix[], int vector[], int v_result[], int num_rows, int num_cols
// Returns: Nothing

    void matrix_multiply_by_vector_pointers(int *matrix[], int vector[], int v_result[], int num_rows, int num_cols) {
        int row;
        int column;
        int sum;


        printf("The result is: \n");
        for (row = 0; row < num_rows; row++) {
             sum = 0;
             for (column = 0; column < num_cols; column++){
                sum = sum +  (matrix[row][column]) * (vector[column]);

            }

            v_result[row] = sum;
            printf("\n");
        }


    }

// Purpose: this function performs matrix multiplication and stores the value in a destination matrix
// Params:   int* m1[], int* m2[], int* m_result[], int num_rows_m1, int num_cols_m1, int num_cols_m2
// Returns: Nothing


void matrix_multiply_pointers(int* m1[], int* m2[], int* m_result[], int num_rows_m1, int num_cols_m1, int num_cols_m2){
    int row;
    int column;
    int sum = 0;
    int rows_m2;


    printf("The result is: \n");
    for(row=0;row<num_rows_m1;row++){

        for(column=0; column<num_cols_m2;column++){

            for(rows_m2=0;rows_m2<num_cols_m1;rows_m2++){

                sum = sum + (m1[row][rows_m2] * m2[rows_m2][column]);
            }

            m_result[row][column] = sum;

            sum=0;
        }

    }
}






