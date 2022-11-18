// APS105S-W22 Lab 4 Part 2

// It is program that to find  an Erdos-Woods number
// For a integer and the n consecutive integers after it will all have at least one 
// common factor greater than 2

#include <stdio.h>

int gcd(int a, int b) //Euclidean algorithm to find gcd
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


int main() {
    int ki=0; //k initial
    int kf=0; //k final
    int ai=0; //a initial
    int af=0; //a final
    int i=0; // actual i
    int k=0; // actual k
    int a=0; // atual a
    int True_Check;
    

    while (ki<=2){
        printf("Enter the number to start searching for k (> 2, inclusive): ");
        scanf("%d",&ki);
    }
    while (kf<=ki){
        printf("Enter the number to stop searching for k (inclusive): ");
        scanf("%d",&kf);
    }
    while(ai<=0){
        printf("Enter the number to start searching for a (> 0, inclusive): ");
        scanf("%d",&ai);
    }
    while (af<=ai){
        printf("Enter the number to stop searching for a (inclusive): ");
        scanf("%d",&af);
    }    
    
    for (k=ki;k<=kf;k++){

        printf("Trying k = %d...\n",k);

        for (a=ai;a<=af;a++){

            for(i=1;i<k;i++){

                if((gcd(a,a+i)==1)&&(gcd(a+i,a+k)==1)){ //if they have gcd 1, jump to next group
                    True_Check=0;
                    break;
                    }
                else if(a+i==a+(k-1)){
                        printf("Erdos-Woods number: %d\na = %d", k, a);
                        return 0;
                    }
            }
        }       
    }
        if (True_Check==0){
             printf("Erdos-Woods number not found.");
        }

    return 0;
}