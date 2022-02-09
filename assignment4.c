//Author: Jasraj Taneja
//Student Number: V00942510



#include <stdio.h>

int sum_odd(int n);
void draw_tail(int size);
void draw_booster(int size);
void draw_instrument_unit(int size);
void draw_lem_adapter(int size);
void draw_space_craft(int size);
void draw_rocket(int size, int n);


int main() {
    printf("\n");
    printf("Assignment 4\n");
    printf("\n\n");

    printf("The sum is : %d",sum_odd(-7));
    printf("\n");
    printf("\n");

    draw_rocket(2,9);

    return 0;
}

//Purpose: this function takes an integer and returns the sum of all the odd numbers from 0 to n(inclusive)
//Parameters:integer - n
//Return:int - sum


int sum_odd(int n) {

int sum = 0;

    for (int i = 0; i <= n; i++) {

        if(i%2 != 0){

             sum = sum + i;
        }
    }
    return sum;
}


//Purpose: prints the space craft segment of the rocket
//Parameters:integer - size(must greater than zero)


void draw_space_craft(int size) {
    int row;
    int space;
    int frontslash;
    int backslash;
    int row_size= 2*size;


    for(row=1;(row<=row_size); row++) {

        printf("   ");

        for (space = row_size - row; space > 0; space--) {

            printf(" ");
        }



        for(frontslash =1; frontslash<row;frontslash++) {

            printf("/");
        }

        printf("**");


        for(backslash=1; backslash<row; backslash++){

            printf("\\");
        }


             printf("\n");
    }
            printf("  ");

            printf("+");

    for(int equalstar=0;equalstar<=row_size-1; equalstar++){

            printf("=*");
    }
            printf("+");

             printf("\n");
}




//Purpose: Prints the lem adapter segment of the rocket
//Parameters:integer - size (must be greater than zero)

void draw_lem_adapter(int size){

    int row_size = 2*size;
    int and2;

    for(int row=1;row<=1; row++){

        printf(" ");

        printf("//");

       for(int and1 =1; and1<=row_size;and1++) {

           printf(" &");
       }

       printf("\\\\");

       printf("\n");

       }
    for(int row=2;row<=2; row++){


        printf("//");

             for(and2=1; and2<=row_size+1; and2++){

                 printf(" &");

        }
        printf("\\\\");

        printf("\n");

        printf("+");

        for(int equal_star=1;equal_star<=and2;equal_star++){

            printf("=*");

        }

        printf("+");

        printf("\n");

    }


}

//Purpose: this function prints the instrument unit segment of the rocket
//Parameters:integer - size(must be greater than zero)


void draw_instrument_unit(int size){

    int row_size = 2*size;
    int equalstar;

    for(int row=1;row<=2;row++){

    printf("||");

        for(int tildanumber=1;tildanumber<=row_size+1;tildanumber++){

            printf("~#");
        }
    printf("||");

     printf("\n");
    }
printf("+");

for(equalstar=1;equalstar<=row_size+2;equalstar++){

    printf("=*");

}
printf("+");

printf("\n");





}


//Purpose: this function prints the booster segment of the rocket
//Parameters:integer - size(must be greater than or equal to zero)

void draw_booster(int size){


    for(int row=1;row<=size+1;row++){

            printf("|");

            for (int dot1 = size  - row; dot1>= 0; dot1--) {

                printf(".");
            }
            for(int twoslash=1;twoslash<=row;twoslash++){

                printf("/\\");
            }
            for (int dot1 = size  - row; dot1>= 0; dot1--) {

                printf(".");
            }

            for (int dot1 = size  - row; dot1>= 0; dot1--) {

                printf(".");
            }
            for(int twoslash=1;twoslash<=row;twoslash++){

                printf("/\\");
            }
            for (int dot1 = size  - row; dot1>= 0; dot1--) {

                printf(".");
            }
            printf("|");

            printf("\n");
        }

    for(int row=1;row<=size+1;row++){

        printf("|");

        for (int dot1 = size+2; dot1<=size+row; dot1++) {

            printf(".");
        }
        for(int twoslash=size+1;twoslash>=row;twoslash--){

            printf("\\/");
       }
        for (int dot1 = size+2; dot1<= size+row; dot1++) {

            printf(".");
        }
        for (int dot1 = size+2; dot1<= size+row; dot1++) {

            printf(".");
        }
       for(int twoslash=size+1;twoslash>=row;twoslash--){

           printf("\\/");
       }
        for (int dot1 = size+2; dot1<=size+ row; dot1++) {

            printf(".");
        }
        printf("|");

        printf("\n");
    }

    printf("+");

    for(int equal_star=1;equal_star<=2*size+2;equal_star++){

        printf("=*");

    }
    printf("+");

    printf("\n");


}

//Purpose: this function prints the tail segment of the rocket
//Parameters:integer - size(must be greater than zero)

void draw_tail(int size){

    printf("//");

for(int backv=1;backv<=size;backv++){

printf("  /\\");
}
printf("  ");

printf("\\\\");

printf("\n");


}

//Purpose: this function calls all of the segments of the rocket, and prints the full picture of the rocket
//Parameters:integer - size(must be greater than zero), n (must be greater than or equal to zero)



void draw_rocket(int size, int n) {


    draw_space_craft(size);

    draw_lem_adapter(size);

    draw_instrument_unit(size);

    for(int i=1;i<=n;i++){

        draw_booster(size);
    }

    draw_tail(size);


}





















































