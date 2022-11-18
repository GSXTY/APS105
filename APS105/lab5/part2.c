//It's asked to write a C function that finds the longest sequence of increasing numbers
//in an array. A function should receives an array passed as a parameter, and prints
//the longest sequence of increasing numbers.

void longestSequence(int a[], int sizeA){
    //TODO: Implement this function
    int i=0;
    int Start=0;
    int Length_Old=0;
    int Length_New=0;

for (i=0;i<sizeA;i++){
    if(a[i]<a[i+1]&&i+1<sizeA){ //if the number is increasing, we store the length
        Length_New++;
        if(Length_New>Length_Old){ // if the new length is greater than old one, we replace it.
            Length_Old=Length_New;  
            Start=i-Length_Old+1;  // we count the start point of the longest length
        }
    }
    else if(a[i]>=a[i+1]){   // it the condition fail, we reset the length
        Length_New=0;
    }
}

printf("Longest sequence is ");

for(i=0;i<=Length_Old;i++){ //print out the positon with number the number after with longest length 
    if(i<=Length_Old-1){
        printf("%d, ",a[i+Start]);
    }
    else{
        printf("%d.",a[i+Start]);
    }
}
}