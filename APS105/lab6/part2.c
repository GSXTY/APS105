#include <stdio.h>
#include <stdbool.h>

void fillSudoko(const int Size, int sudoko [Size][Size]){
    int i=0;
    int j=0;
    int row=0;
    int col=0;
    int num=0;
    int count=0;
    int rows=0;
    int cols=0;

    for (i = 0; i < Size; i++){
        for (j = 0; j < Size; j++){
            if (sudoko [i][j] == 0){
                for(num=1;num<=4;num++){
                    count=0;
            
                    for (row=0;row<Size;row++){
                     
                        if((num==sudoko[row][j]&&i!=row)){
                            count=0;
                        }
                        else {
                            count++;
                            
                        }
                        if(count==4){
                            count=0;
                            
                            for (col=0;col<Size;col++){
                                if(num==sudoko[i][col]&&j!=col){
                                    count=0;
                                }
                                else{
                                    count++;
                                }
                                if(count==4){
                                    
                                    sudoko[i][j]=num;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
   
        
        

}

