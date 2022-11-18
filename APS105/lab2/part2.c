#include <stdio.h>

int main() {
    
    int pw;
    
    printf("Enter an encrypted 4-digit combination: ");
    scanf("%d", &pw);
    
    //pw=dcba
    int a = pw- ((int)(pw/10))*10;//Find the 4th digit
    
    int b = (int) (pw- ((int)(pw/100))*100)/10;//Find the 3rd digit
    
    int c = (int)((pw-(((int)(pw/1000))*1000))/100);//Find the 2nd digit
    
    int d = (int)(pw/1000);////Find the 1st digit
    

    //replace the 9’s complement
    int cc = (9-c)*100;
    int bb = (9-b)*10;
    
    //swap the 1st and 4th digits
    int dd = a*1000;
    int aa = d;
    
    
    int rc = dd+cc+bb+aa; //re combiante
    
    // for 0 as the last digit 
    if (dd==0){
        printf("The real combination is: %04d", rc);
    }
    else{
    printf("The real combination is: %d", rc);
    }
    
    
    
    
    return 0;
}