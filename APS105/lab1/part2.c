//
// APS105 Winter 2022 Lab 1 Part 2
//
// Program that reads in the daily rate, number of rental days,
// and prints the eligible free rental days and the total rental
// charge tax inclusive.

// Note: Every 4-day block in a rental period is counted as 3 days.
// Assumption: All input values are valid.
//
#include <stdio.h>

int main() {
    //Present 2 variables for rate and period
  float a;
  float b;
  
  //Get the varble and stores in a&b
  printf("Enter the daily rate:");
  scanf("%f", &a );
  
  printf(" Enter the rental period (in days): \n");
  scanf("%f", &b);
  
  //free day will be the integer part and total will be origin value-the freeday cost
  float freeday= (int)b/4;
  float charge= 1.13*(a*b-a*freeday);
  printf("Your total free day(s) in this rental is: %.0f\n", freeday);
  printf("Your total charge including taxes is: %.2f", charge);
    
    return 0;
}