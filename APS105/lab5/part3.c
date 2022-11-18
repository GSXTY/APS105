// This part requires that implement a C function that takes in as parameters two arrays and their
//sizes. This function is required to find the longest common sequence of numbers in these arrays.

void longestMutualSequence(int firstArr[], int secondArr[], int sizeA, int sizeB){
    //TODO: Implement this function
    int i=0;
    int j=0;
    int Length_Old=0;
    int Length_New=0;
    int Constant=0;
    int Start=0;

for(i=0;i<sizeA;i++){

    for(j=0;j<sizeB;j++){

        if(firstArr[i]==secondArr[j]){ // we compare each a[i] with b[j], if they are same we start count
        
           for (Constant=0;Constant<sizeB&&Constant<sizeA;Constant++){ // if they have atleast one same, we start compare the rest
               if((firstArr[i+Constant]==secondArr[j+Constant])&&(i+Constant<sizeA&&j+Constant<sizeB)){
                   Length_New++; // if the rest are same, we count the length
                   
                   if(Length_New>Length_Old&&Length_New<=sizeA&&Length_New<=sizeB){
                       Length_Old=Length_New;   // if the new length is longer than before, we replace it
                       Start=i; //count the i as the start point with the longest length
                   }
               }
               else if (firstArr[i+Constant]!=secondArr[j+Constant]){
                   Length_New=0; // if condition fail, we reset the length
               } 
           }
        }
    }
}

printf("Longest common sequence is ");
// print out the series of number with the start point and the length
for(i=0;i<=Length_Old-1;i++){
    if(i<Length_Old-1){
        printf("%d, ",firstArr[i+Start]);
    }
    else if (i==Length_Old-1){
        printf("%d.",firstArr[i+Start]);
    }
}
}


