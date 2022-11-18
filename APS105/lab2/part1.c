#include <stdio.h>
#include <math.h>
int main() {
    int P; //Purchase Price
    int D; //Down payment
    int n; //finace term
    double r; //Interest rate/month
    double M; //Monthly payment 
    
    
    printf("Enter the purchase price P: ");
    scanf("%d", &P);
    printf("Enter the amount of down payment D: ");
    scanf("%d", &D);
    printf("Enter the finance term (in months): ");
    scanf("%d", &n);
    printf("Enter the monthly interest rate (in percent): ");
    scanf("%lf", &r);
    
    double a = 1+r/100;
    double b = pow(a,n);
    
    M=((P-D) * r/100 * (b))/(b-1);
    
    printf("\n");
    
    printf("The monthly payment is: %.2lf",M);
    
    
    
    return 0;
}