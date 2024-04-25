#include <stdio.h> 
#include <stdlib.h> 
 
void arrayRand(int[5][7], int); 
void out2Txt(int[5][7]); 
 
 
int main(){ 
 
    int input; 
    int target[5][7] = {0}; 
 
    scanf( "%d", &input); 
 
    arrayRand(target, input); 
    out2Txt(target); 
 
    return 0; 
 
    } 
 
 
void arrayRand(int v[5][7], int k){ 
 
    int myRow; 
    int myColumn; 
    int idx; 
 
    srand(1); 
 
    for ( myRow=0 ; myRow<k ; myRow++ ){ 
        for ( myColumn=0 ; myColumn<7 ; myColumn++ ){ 
            v[myRow][myColumn] = rand()%69+1; 
 
            for ( idx=myColumn-1 ; idx>=0 ; idx--){ 
                if ( v[myRow][idx] == v[myRow][myColumn] ){ 
                    idx=-1; 
                    myColumn--; 
                } 
            } 
        } 
    } 
 
 
} 
 
 
void out2Txt(int out[5][7]){ 
 
    int x; 
    int y; 
 
    FILE *fptr; 
    fptr = fopen("lotto.txt","w"); 
 
    fprintf(fptr,"========= lotto649 =========\n"); 
 
    for ( x=0 ; x<5 ;x++){ 
        fprintf(fptr,"[%1d]:",x+1); 
 
        for ( y=0 ; y<7 ; y++){ 
            if ( out[x][y] > 0 ){ 
                fprintf(fptr," %02d",out[x][y]); 
            } 
            else{ 
                fprintf(fptr," __"); 
            } 
        } 
 
        fprintf(fptr,"\n"); 
    } 
    fprintf(fptr,"========= csie@CGU =========\n"); 
    fclose(fptr); 
 
}
