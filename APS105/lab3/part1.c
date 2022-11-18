#include <stdio.h>
#include <math.h>
int main() {
    
   int Water_Normal_boiling_point = 100;
   int Mercury_Normal_boiling_point = 357;
   int Copper_Normal_boiling_point = 1187;
   int Silver_Normal_boiling_point = 2193;
   int Gold_Normal_boiling_point = 2660;
   int threshold;
   int Observed_boiling_point;
   
   
   
    printf("Enter the threshold in Celsius: ");
    scanf("%d", &threshold);
   
    printf("Enter the observed boiling point in Celsius: ");
    scanf("%d", &Observed_boiling_point);
    
    if (abs(Observed_boiling_point-Water_Normal_boiling_point)<=threshold)
    {
        printf("The substance you tested is: Water\n");    
    }
     
    else if (abs(Observed_boiling_point-Mercury_Normal_boiling_point)<=threshold)
    {
    printf("The substance you tested is: Mercury\n");
    }
     
    else if (abs(Observed_boiling_point-Copper_Normal_boiling_point)<=threshold)
    {
        printf("The substance you tested is: Copper\n");
    }
     
   else if (abs(Observed_boiling_point-Silver_Normal_boiling_point)<=threshold)
    {
        printf("The substance you tested is: Silver\n");
    }
     
   else if (abs(Observed_boiling_point-Gold_Normal_boiling_point)<=threshold)
    {
        printf("The substance you tested is: Gold\n");
    }
    else{
      printf("Substance unknown.");
    }
   
    return 0;
}











