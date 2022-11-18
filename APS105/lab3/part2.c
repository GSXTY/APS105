#include <stdio.h>
int main() {
   int in,jn,totrow,space;
   
   printf("Enter the number of rows in the triangle: ");
   scanf("%d", &totrow);// get the total rows
   
   for (in=1;in<=totrow;in++)//repete the lines to the rows
   {
    for(jn=in;jn<totrow;jn++){
        printf(" ");// fill in the empty space
        
    }
        for(jn=1;jn<=2*in-1;jn++) //repete the column to 2n-1 n=rows
        {
            if(jn==1||jn==2*in-1||in==totrow)// fill in the stars based on 1st line/ their column position, and full fill the last row
            {
                printf("*");
            }
            else
            {
            printf(" ");    // else postion are all empty
            }
        
            
        }
    
       printf("\n");
   }
   
   
   
   
   
   
   
   
   
   
    return 0;   
}
