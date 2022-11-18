#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// arrary for the direction 
int a[]={1, 1, 0,-1,-1,-1, 0, 1,}; 
int b[]={0,-1,-1,-1, 0, 1, 1, 1,};

// print direction based on the row and col direction
void printFoundLocation(int rowDir, int colDir) {
   if (rowDir==1&&colDir==0){
       printf("in the south direction.");
   }
   else if(rowDir==1&&colDir==-1){
       printf("in the south-west direction.");
   }
   else if(rowDir==0&&colDir==-1){
       printf("in the west direction.");
   }
   else if(rowDir==-1&&colDir==-1){
       printf("in the north-west direction.");
   }
   else if(rowDir==-1&&colDir==0){
       printf("in the north direction.");
   }
   else if(rowDir==-1&&colDir==1){
       printf("in the north-east direction.");
   }
   else if(rowDir==0&&colDir==1){
       printf("in the east direction.");
   }
   else if(rowDir==1&&colDir==1){
       printf("in the south-east direction.");
   }
}

//check if we can find the words from each direction 
bool search1D(char word[], int wordSize, const int Size, char grid[Size][Size], int row, int col, int rowDir, int colDir) {
    int count=0;
    int rd=row+rowDir;
    int cd=col+colDir;
    for (count=1;count<wordSize;count++){
        if(grid[rd][cd]!=word[count]){  //if the length doesnt match wordsize, break
            break;
        }
        if(rd>=Size||cd>=Size||cd<0||rd<0){ //if the search over the boardsize, break
            break;
        }
       rd=rd+rowDir;
       cd=cd+colDir;
    }
    if(count==wordSize){ // if the searched wordsize match the requirewordsize, we return true 
        return true;
    }
    return false;
}

// fucntion to find the row&col 
void search2D(char word[], int wordSize, const int Size, char grid[Size][Size]) {
    int row=0;
    int col=0;
    int rowf=0;
    int colf=0;
    int i=0;
    int j=0;
    int rowDir=0;
    int colDir=0;
    for (i=0;i<Size;i++){
        for (j=0;j<Size;j++){
            if(grid[i][j]==word[0]){ 
                rowf=i; // we get the final row and col of the first letter. which means after we search it, the program should stop
                colf=j;
            }
        }
    }
   for (i=0;i<Size;i++){
       for (j=0;j<Size;j++){
           if(grid[i][j]==word[0]){ // we find the first letter that match our target
                row=i; // we get the row and the col of the beginner 
                col=j;
                int x=0;
                for(x=0;x<8;x++){ // search 8 direction from the direction arrary
                    rowDir=a[x]; //represnt the row&col direction based on the direction arrary
                    colDir=b[x];
                    if (search1D(word,wordSize,Size,grid,row,col,rowDir,colDir)){ // it it return true we could get the postion that match our condition
                        printf("Word found at row %d and column %d ",i,j);
                        printFoundLocation(rowDir,colDir);
                        return;
                    }
                    else if((!search1D(word,wordSize,Size,grid,row,col,rowDir,colDir)&&row==rowf&&col==colf&&x==7)){ // if we search all cases and not found we return not find
                        printf("Word not found.");
                    }
                }
            }
        }    
    }
}


