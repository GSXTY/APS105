//
// APS105 Winter 2022 Lab 1 Part 3
//
// A C program that converts metres to yards, feet and inches.
//
#include <stdio.h>
    int main() {

    double meters;
   
    printf("Please provide a distance in metres:"); // get the value in meters
    scanf("%lf",&meters);
    
    double inches = meters/0.0254;  //convert meters to inches
    
 
    double y = (int)inches/36; //convert inches to yards
    double f = (int)(inches-36*y)/12; //convert inches to feet
    double i = (int)(inches-y*36-f*12); //remain inches in integer  
    double r = inches-y*36-f*12-i;// remain inches in decimal


    
    printf(" %.0lf yards, %.0lf feet, %.0lf inches, %.2lf inches remainder",y,f,i,r);

    return 0;

  }