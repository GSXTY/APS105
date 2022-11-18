// It's a C function, named median, that receives two arrays as parameters passed and returns
//the median of the values stored in these two arrays.

#include <stdio.h> 
double median(int a[], int b[], int sizeA, int sizeB){
    //TODO: Implement this function 
int i=0; 
int j=0;
int count;
double Median_Right=0;
double Median_Left=0;

for (count=0;count<=((sizeA+sizeB)/2);count++){ // repeate to the lenght of half of size
    if(i!=sizeA&&j!=sizeB){
        if(a[i]<=b[j]){
            Median_Right=a[i++]; //if one arrary is greater than another, we count the smaller one and turn it into next
        }
        else if (a[i]>=b[j]){
            Median_Right=b[j++]; // if if one arrary is greater than another, we count the smaller one and turn it into next
        }
    }
    else if(j==sizeB){
        Median_Right=a[i++]; // if one arrary run out, we only count for another arrary
    }
    else if (i==sizeA){
        Median_Right=b[j++]; // if one arrary run out, we only count for another arrary
    }
    if(count==((sizeA+sizeB)/2)-1){
        Median_Left=Median_Right;
    }
}
if((sizeA+sizeB)%2==1){ // for sum of 2 sizes are odd
    return Median_Right;
}
else{ // for sum of 2 sizes are even
    return (Median_Right+Median_Left)/2;
}
}

 