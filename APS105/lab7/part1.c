//
// Author:Jiahao Mo
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "reversi.h"
//globle arrayr for test row/col &&d irection 
char a[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int ra[]={-1,-1,-1, 0, 0, 1, 1, 1,};
int ca[]={-1, 0, 1,-1, 1,-1, 0, 1,};

//function of printboard 
//using bigger board include the small one 
void printBoard(char board[][26], int n) {
  int countrow=0;
  int countcol=0;
  char bigboard[28][28];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n+1;j++){
      if((j==1)||(i==0&&j==0)){
        bigboard[i][j]=' ';
      } 
      else if(j==0&&i>0){
        bigboard[i][0]=a[countrow++];
      }
      else if(i==0&&j>0){
        bigboard[0][j]=a[countcol++];
      }
      else if(i>0&&j>1){
        int row=i-1;
        int col=j-2;
        bigboard[i][j]=board[row][col];
      }
      printf("%c",bigboard[i][j]);
    }
     printf("\n");
  }
}

//function for check if over the bound
bool positionInBounds(int n, int row, int col) {    
  if((row>=0&&row<n)&&(col>=0&&col<n)){
    return true;
  }
  return false;
}

//check if the position is legal for 8 directions
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) {
  int mt=1;
  char test;
  if(colour=='W'){
    test='B';
  }
  if (colour=='B'){
    test='W';
  }
  while(board[row+mt*deltaRow][col+mt*deltaCol]==test){
    mt++;
    if(board[row+mt*deltaRow][col+mt*deltaCol]==colour&&positionInBounds(n,row+mt*deltaRow,col+mt*deltaCol)){
      return true;
    }
    else if(((!(board[row+mt*deltaRow][col+mt*deltaCol]!=colour))||((board[row+mt*deltaRow][col+mt*deltaCol]=='U')))&&(row+mt*deltaRow==n&&col+mt*deltaCol==n)){
      return false;
    }
  }
  return false;
}
//function to what are the available pistions to move 
void availabe_check(char board[][26], int n, char colour){
  int count=0;
  printf("Available moves for %c:\n",colour);
  for(int row=0;row<n;row++){
    for(int col=0;col<n;col++){
      if(board[row][col]=='U'){
        for(count=0;count<8;count++){
          int deltaRow=ra[count];
          int deltaCol=ca[count];
          if(checkLegalInDirection(board,n,row,col,colour,deltaRow,deltaCol)){
            printf("%c%c\n",a[row],a[col]);
            break;
          }
        }
      }
    }
  }
}

//function to transform letter to row/col
void ctrans(char board[][26],char colour, char r, char c){
  int row=0;
  int col=0;
  for(int countrow=0;countrow<=26;countrow++){
      if(a[countrow]==r){
        row=countrow;
      }
    }
  for(int countcol=0;countcol<=26;countcol++){
    if(a[countcol]==c){
      col=countcol;
    }
  }
  board[row][col]=colour;
}
//function for initialize the board
void initialize(char board[][26],int n){
  for(int row=0;row<n;row++){
    for(int col=0;col<n;col++){
      if((row==n/2&&col==n/2)||(row==(n/2)-1&&col==(n/2)-1)){
        board[row][col]='W';
      }
      else if((row==n/2&&col==n/2-1)||(row==(n/2)-1&&col==(n/2))){
        board[row][col]='B';
      }
      else {
        board[row][col]='U';
      }
    }
  }
}
//function to check if it is legal to move
bool movecheck(char board[][26], int n, char r, char c, char colour){
  int row=0;
  int col=0;
  for(int countrow=0;countrow<=26;countrow++){
      if(a[countrow]==r){
        row=countrow;
      }
    }
  for(int countcol=0;countcol<=26;countcol++){
    if(a[countcol]==c){
      col=countcol;
    }
  }
  if(positionInBounds(n,row,col)&&board[row][col]=='U'){
    for(int count=0;count<8;count++){
      int deltaRow=ra[count];
      int deltaCol=ca[count];
      if(checkLegalInDirection(board,n,row,col,colour,deltaRow,deltaCol)){
        board[row][col]=colour;
        return true;
      }
      else if(checkLegalInDirection(board,n,row,col,colour,deltaRow,deltaCol)&&count==7){
        //printf("no");
        return false;
      }
    }
  }
  else if(!positionInBounds(n,row,col)||board[row][col]!='U'){
    return false;
  }
  return false;
}
//function for flip
void flip(char board[][26],int n, char colour, char r, char c){
  int row=0;
  int col=0;
  for(int countrow=0;countrow<=26;countrow++){
      if(a[countrow]==r){
        row=countrow;
      }
    }
  for(int countcol=0;countcol<=26;countcol++){
    if(a[countcol]==c){
      col=countcol;
    }
  }
  int mt=1;
  int count=0;
  for(count=0;count<8;count++){
    int deltaRow=ra[count];
    int deltaCol=ca[count];
    if(checkLegalInDirection(board,n,row,col,colour,deltaRow,deltaCol)&&positionInBounds(n,row+mt*deltaRow,col+mt*deltaCol)){
      for(mt=1;board[row+mt*deltaRow][col+mt*deltaCol]!=colour;mt++){
        board[row+mt*deltaRow][col+mt*deltaCol]=colour;
      }
    }
  }
  
}

int main(void) {
  char board[26][26];
  int n;
  char r;
  char c;
  char colour;
  printf("Enter the board dimension: ");
  scanf("%d",&n);
  initialize(board,n);
  printBoard(board,n);
  
  printf("Enter board configuration:\n");
  do{
  scanf("\n%c%c%c",&colour,&r,&c);
  if(colour!='!'&&r!='!'&&c!='!'){
    ctrans(board,colour,r,c);
  }
  }while(colour!='!'&&r!='!'&&c!='!');
  printBoard(board,n);

  availabe_check(board,n,'W');
  availabe_check(board,n,'B');
  
  printf("Enter a move:\n");
  scanf("\n%c%c%c",&colour,&r,&c);
  if(movecheck(board,n,r,c,colour)){
    printf("Valid move.\n");
    flip(board,n,colour,r,c);
    printBoard(board,n);
  }
  else{
    printf("Invalid move.\n");
    printBoard(board,n);
  }
  return 0;
}
