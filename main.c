#include <stdio.h>
#define PI_VALUE 3.14

/*
 * Allows the compiler to print a picture of a pig
 */

void print_pig();

/*
 * Allows the compiler to print a picture of a frog
 */

void print_frog();

/*
 * This function calls the previous two ascii animals and adds a spacer line in between.
 */

void print_logo();

/*
 * Outputs surface area through computation of given values
 */

void print_surface_area();


int main() {


    printf("Welcome\n\n");
    printf("\n");
    print_logo();
    printf("\n");
    print_surface_area();



    return 0;

}

void print_pig() {

    printf("  ^  ^\n");
    printf(" (0  0)\n");
    printf("  (oo)\n");
    printf("@(\")_(\")\n");



    }

void print_frog() {

    printf("  @..@\n");
    printf(" (----)\n");
    printf("( >__< )\n");
    printf(" \"    \"\n");
}

void print_logo() {


     printf("/~~~~~~\\\n");

     print_frog();

     printf("/~~~~~~\\\n");

     print_pig();

     printf("/~~~~~~\\\n");

     print_frog();

     printf("/~~~~~~\\\n");

     print_pig();

     printf("/~~~~~~\\\n");

     printf("/~~~~~~\\");


}


void print_surface_area() {

    double height = 6;

    double diameter = 5;

    double circumference = (diameter * PI_VALUE);

    double area_of_top = (PI_VALUE * diameter / 2 * diameter / 2);

    double area_of_wall = (circumference * height);

    double surface_area = (area_of_top * 2) + (area_of_wall);


    printf("%.2f", surface_area);

    printf(" square meters");

}
