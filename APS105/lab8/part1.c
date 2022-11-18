//
// Author:盖世小汤圆
//

// #include "reversi.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//globle array for test row/col &&direction 
char a[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int ra[]={-1,-1,-1, 0, 0, 1, 1, 1,};
int ca[]={-1, 0, 1,-1, 1,-1, 0, 1,};

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

bool positionInBounds(int n, int row, int col) {    
  if((row>=0&&row<n)&&(col>=0&&col<n)){
    return true;
  }
  return false;
}

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
bool availabe_check(char board[][26], int n, char colour){
  int count=0;
  for(int row=0;row<n;row++){
    for(int col=0;col<n;col++){
      if(board[row][col]=='U'){
        for(count=0;count<8;count++){
          int deltaRow=ra[count];
          int deltaCol=ca[count];
          if(checkLegalInDirection(board,n,row,col,colour,deltaRow,deltaCol)){
            return true;
            break;
          }
        }
      }
    }
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
bool stop(char board[][26],int n){
  for(int row=0;row<n;row++){
    for(int col=0;col<n;col++){
      if(board[row][col]!='U'&&row==n-1&&col==n-1){
        return true;
        
      }
      else if(board[row][col]=='U'){
        return false;
      }
      
    }
  }
  return false;
}
void computermove(char board[][26], int n, char colour){
  int count=0;
  int mt=1;
  int num=0;
  int numlargest=0;
  int rowc=0;
  int colc=0;
  //printf("Available moves for %c:\n",colour);
  for(int row=0;row<n;row++){
    for(int col=0;col<n;col++){
      if(board[row][col]=='U'){
        if(availabe_check(board,n,colour)){
          for(count=0;count<8;count++){
            int deltaRow=ra[count];
            int deltaCol=ca[count];
            if(checkLegalInDirection(board,n,row,col,colour,deltaRow,deltaCol)&&positionInBounds(n,row+mt*deltaRow,col+mt*deltaCol)){
              for(mt=1;board[row+mt*deltaRow][col+mt*deltaCol]!=colour;mt++){
                num++;
                if(num>numlargest){
                  numlargest=num;
                  rowc=row;
                  colc=col;
                }
              }
            }
          }
          num=0;  
        }
        if(!availabe_check(board,n,colour)){
          printf("%c player has no valid move.\n",colour);
          return;
        }
        
      }
    }
  }
  if(!stop(board,n)){
    printf("Computer places %c at %c%c.\n",colour,a[rowc],a[colc]);
    board[rowc][colc]=colour;
    flip(board,n,colour,a[rowc],a[colc]);
    printBoard(board,n);
    return;
  }
          
}

void lastcheck(char board[][26], int n){
  int countw=0;
  int countb=0;
  if(stop(board,n)==true){
    for(int row=0;row<n;row++){
      for(int col=0;col<n;col++){
        if(board[row][col]=='W'){
          countw++;
        }
        else if(board[row][col]=='B'){
          countb++;
        }
      }
    }
    if(countw>countb){
      printf("W player wins.\n");
    }
    else if(countb>countw){
      printf("B player wins.\n");
    }
    else if(countb==countw){
      printf("Tie\n");
    }
  }
}

void game(char board[][26], int n, char colourc ){
  char colourh;
  char r;
  char c;
  int row=0;
  int col=0;
  //printf("%c",colourc);
  if(colourc=='B'){
    colourh='W';
    do{
    computermove(board,n,colourc);
    if(!stop(board,n)){
    printf("Enter move for colour W (RowCol): ");
    scanf("\n%c%c",&r,&c);
    }
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
    if(positionInBounds(n,row,col)&&movecheck(board,n,r,c,colourh)&&!stop(board,n)){
    ctrans(board,colourh,r,c);
    flip(board,n,colourh,r,c);
    printBoard(board,n);
    }
    else if(!movecheck(board,n,r,c,colourh)&&!stop(board,n)){
      printf("Invalid move.\n");
      printf("B player wins.");
      break;
    }
    else if(!availabe_check(board,n,colourh)&&availabe_check(board,n,colourc)){
      computermove(board,n,colourc);
    }
    }while(positionInBounds(n,row,col)&&(!stop(board,n)));   
  }
  if(colourc=='W'){
    colourh='B';
    do{
    if(!stop(board,n)){
    printf("Enter move for colour B (RowCol): ");
    scanf("\n%c%c",&r,&c);
    }
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
    if(positionInBounds(n,row,col)&&movecheck(board,n,r,c,colourh)){
    ctrans(board,colourh,r,c);
    flip(board,n,colourh,r,c);
    printBoard(board,n);
    }
    else if(!movecheck(board,n,r,c,colourh)&&!stop(board,n)){
      printf("Invalid move.\n");
      printf("W player wins.");
      break;
    }
    computermove(board,n,colourc);
    if(stop(board,n)){
      break;
    }
    }while(positionInBounds(n,row,col)&&!stop(board,n)); 
  } 
  if(!availabe_check(board,n,colourh)&&!availabe_check(board,n,colourc)){
    return;
  }
}

int main(void) {
  char board[26][26];
  int n;
  char colourc;
  
  printf("Enter the board dimension: ");
  scanf("%d",&n);
  initialize(board,n);
  printf("Computer plays (B/W): ");
  scanf("\n%c",&colourc);
  printBoard(board,n);
  game(board,n,colourc);
  lastcheck(board,n);
  return 0;
}
