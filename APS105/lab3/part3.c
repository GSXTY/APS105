#include <stdio.h>
int main() {
    
    // show the ratio of conversion
   int Input_Cents;
   int Nickel_to_Cents = 5;
   int Dime_to_Cents = 10;
   int Quarter_to_Cents = 25;
   
   
   
   // requrire for input
   printf("Please give an amount in cents less than 100: ");
   scanf("%d", &Input_Cents);
   
   // loop till the invalid value appear
   while(Input_Cents>0&&Input_Cents<100){
       
       
   // unit calculation
   int Quarter = (int)(Input_Cents / Quarter_to_Cents);
  
   int Dime = (int)(Input_Cents - Quarter_to_Cents * Quarter)/(Dime_to_Cents);
   
   int Nickel = (int)(Input_Cents - Dime * Dime_to_Cents - Quarter * Quarter_to_Cents)/(Nickel_to_Cents);
   
   int Cent = Input_Cents - Nickel * Nickel_to_Cents - Dime * Dime_to_Cents - Quarter * Quarter_to_Cents;
   
   
   // show the input in front of output    
   printf("%d cents: ",Input_Cents );
   
  
   //Determine if add s of Quarter
   
   if(Quarter>1&&Quarter<4){
       printf("%d quarters",Quarter);
    }
    else if(Quarter==1){
        printf("%d quarter",Quarter);
    }
    else if(Quarter<1){
        printf("");
    }
    
    //Determine the punctuation. 
    
    if(Quarter!=0&&(Dime==0&&Nickel==0&&Cent==0)){
        printf(".");
    }
    else if(Quarter!=0&&((Dime!=0&&Nickel!=0)||(Dime!=0&&Cent!=0)||(Nickel!=0&&Cent!=0))){
        printf(",");
    }
    //For the space between value and "and"
    
    if (Quarter!=0&&((Dime!=0&&Nickel!=0)||(Dime!=0&&Cent!=0)||(Nickel!=0&&Cent!=0))){
        printf(" ");
    }
    
    
    //For value connect with "and"
    
    if(Quarter!=0&&Dime!=0&&Nickel==0&&Cent==0){
        printf(" and ");
    }
    
    //Determine if add s of Dime
    
    if(Dime>1&&Dime<10){
        printf("%d dimes", Dime);
    }
    else if(Dime==1){
        printf("%d dime",Dime);
    }
    else if(Dime<1){
        printf("");
    }
    
    //Determine the punctuation.
    
    if(Dime!=0&&Nickel==0&&Cent==0){
        printf(".");
    }     
    else if (Dime!=0&&((Quarter!=0&&Nickel!=0)||(Quarter!=0&&Cent!=0)||(Nickel!=0&&Cent!=0))){
        printf(",");
    }
    
    //For value connect with "and"
    
    if((Nickel!=0&&(Dime!=0||Quarter!=0))&&Cent==0){
        printf(" and ");
    }
    
    //For the space between value and "and"
    
    if(Dime!=0&&(Nickel!=0&&Cent!=0)){
        printf(" ");
    }
    
    //Determine if add s of Nickel  
    
    if(Nickel>1&&Nickel<20){
        printf("%d nickels", Nickel);
    }
    else if(Nickel==1){
        printf("%d nickel",Nickel);
    }
    else if(Nickel<1){
        printf("");
    }   
    
    //Determine the punctuation.
    
    if(Cent==0&&Nickel!=0){
        printf(".");
    }
    
    else if (Nickel!=0&&Cent!=0&&(Quarter!=0||Dime!=0)){
        printf(",");
    }
    
    
    //For value connect with "and"
    if((Quarter!=0||Dime!=0||Nickel!=0)&&Cent!=0){
        printf(" and ");
    }
    
    if(Cent>1&&Cent<100){
        printf("%d cents.", Cent);
    }
    else if(Cent==1){
        printf("%d cent.", Cent);
    }
    else if(Cent<1){
        printf("");
    }           
    
    //require for a new input within the loop
    printf("\nPlease give an amount in cents less than 100: ");
    scanf("%d", &Input_Cents);
          
    
   }  
   
   //For the input show in front 
   
   printf("%d cents: ",Input_Cents );
   
   //For value excess the range it stop
   
   if (Input_Cents<=0||Input_Cents>=100){
       printf("invalid amount.");
      
   }
   
   
    return 0;   
}
