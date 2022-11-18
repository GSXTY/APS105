// APS105S-W22 Lab 4 Part 1

// This program includes a function named "triangle" that outputs Pascal's
// triangle. In general the Pascal's triangle can be represented as:

//             0C0
//           1C1 1C0
//         2C2 2C1 2C0
//       3C3 3C2 3C1 3C0
//      4C4 4C3 4C2 4C1 4C0

// where nCr represents how many ways there are to choose r from n, not
// counting duplicates.

// The formula used to calculate nCr can be written as:
//  nCr=n!/(r!(n-r)!)
// where n! is the factorial of n.


#include <stdio.h>

int factorial(int n){
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}

// function of choose nCr
int nCr(int n, int r){
    return factorial(n) / (factorial(r) * factorial(n - r));
}


int triangle(int rows){
    // function of factorial

    int i,j;

   do{ 
       
   for (i=1;i<=rows;i++){
        for(j=3*i;j<3*rows;j++){
        printf(" ");// fill in the empty space
        } 
        int n = i-1;//n is always 1 less than rows
        int r;// r is decenting to 0
        for (r=n;r>=0;r--){
       if(nCr(n,r)>=10&&nCr(n,r)<100){
           printf("%d    ", nCr(n, r));  // space for 2 digits
       }
       else if (nCr(n,r)<10){
           printf("%d     ", nCr(n, r)); // space for 1 digits
       }
       else if (nCr(n,r)>=100){
           printf("%d   ", nCr(n, r)); // space for 3 digits
       }
   } 

       printf("\n");
      
   }
    return 0;
   
   }while (rows >= 0&&rows<=13); //invalid value 
     
} 


//Main function to run the created function
int main() {
    int rows;
    
    printf("Enter the number of rows: ");
        scanf("%d", &rows);
    while (rows >= 0&&rows<=13){
        triangle(rows); //recall the function
        printf("Enter the number of rows: ");
        scanf("%d", &rows);
    }
    
    return 0;  
   }

