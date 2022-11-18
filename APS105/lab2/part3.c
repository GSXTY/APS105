#include <stdio.h>

int main() {
    
    int hour;//for hours 
    int minute;//for minutes
    double triptime;//for the trip time
    
    printf("Enter current time: ");//get the current time 
    scanf("%d %d", &hour,&minute);
    
    printf("Enter trip time: \n");//get the trip time
    scanf("%lf",&triptime);
    
    int timeInMinute = triptime*60; //turn the trip time in to min 
    
    int FinalTripTime = minute+timeInMinute; // add the initial min
    
    int HourFromFTT = (int)(FinalTripTime/60); // turn the min in to hour
    int FinalHour = hour+HourFromFTT; //final hour
    int FinalMinute = (FinalTripTime-HourFromFTT*60); // rest of min
    int FinalHourNextday; //used when ah is greater than 24
    

     printf("Current time is %02d:%02d\n", hour,minute);//for the current time
    
    
    if(FinalHour<24){
        printf("Arrival Time is same day %02d:%02d", FinalHour,FinalMinute);//within that day
    }
    else{
        FinalHourNextday=FinalHour-24;// to the next day
         printf("Arrival Time is next day %02d:%02d", FinalHourNextday,FinalMinute);
    }  
    return 0;
}











