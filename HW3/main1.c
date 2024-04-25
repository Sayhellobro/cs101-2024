#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char record(){
    FILE* file;
    char filename[] = "record.bin";
    file = fopen(filename, "rb+");
    char num[1];
    fread(num, sizeof(char), 1, file);
    fseek(file, 0, SEEK_SET);
    //printf("%s", num);
    num[0]+=1;
    fwrite(num, sizeof(char), 1, file);
    fclose(file);
    return num[0];
}

void buy(int input){
    
    int seed = 1;
    char num[1], filename[100]="lotto";
    time_t Time, curtime;
    time(&curtime);
    Time = time(NULL);
    seed = Time%10;
    FILE* file;
    srand(seed);
    
    num[0] = record();
    printf("你購買的%d組特透號碼儲存至lotto%d.txt\n", input, num[0]-48);
    strcat(filename, num);
    strcat(filename, ".txt");
    file = fopen(filename, "w+");
    
    char *arr_time = ctime(&curtime);
    fwrite(arr_time, sizeof(char), 30, file);
    
    for(int i=0; i<input; i++){
        fwrite("\n", sizeof(char), 2, file);
        for(int j=0; j<7; j++){
            int num = rand()%70;
            //printf("%d ", num);
            char arr_write[3] = {(num/10)+48,(num%10)+48, 32};
            fwrite(arr_write, sizeof(char), 3, file);
        }
        //printf("\n");
    }
    fclose(file);
}
void check(){

    char ans[6],filename[100]="lotto", lotto_num[100];
    char num[]="0";
    int line=0;
    FILE* file;
    
    printf("請輸入中獎號碼(個位數字前面加上0)：");
    scanf("%s", ans);
    printf("請輸入你的樂透彩編號：");
    scanf("%s", num);
    
    strcat(filename, num);
    strcat(filename, ".txt");
    
    file = fopen(filename, "r");
    
    for(int i=1;i<100; i++){
        if(i%8==0){
            line+=1;
        }
        fseek(file, 29+3*i-line, SEEK_SET);
        fread(lotto_num, sizeof(char), 2, file);
        if(strcmp(lotto_num, ans)==0){
            printf("\n%s ", lotto_num);
            printf("中獎了!");
        }
    }
    fclose(file);
    
}

int main()
{
    int input=0;
    
    printf("請輸入你要購買的樂透彩數量：");
    scanf("%d", &input);
    
    if(input==0){
        check();
    }
    else{
        buy(input);
    }
    return 0;
}
