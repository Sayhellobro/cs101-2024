#include <stdio.h>
#include <time.h>

int main()
{
    int n;
    int turn=0;
    srand((unsigned) time(NULL));
    FILE *file;
    
    scanf("%d", &n);
    
    
    file=fopen("lotto.txt", "w+");
    fwrite("========= lotto649 =========\n",sizeof(char),29,file);
    
    for(int i=0;i<n;i++){
        turn++;
        char num[4]={'[',(turn+48),']',':'};
        fwrite(num,sizeof(char),4,file);
        
        for(int j=0;j<7;j++){
            int x=rand()%69+1;
            
            char Number[3]={' ',((x/10)+48),((x%10)+48)};
            fwrite(Number,sizeof(char),3,file);
        }
        fwrite("\n",sizeof(char),1,file);
    }
    
    for(int i=0;i<5-n;i++){
        turn++;
        char num[4]={'[',(turn+48),']',':'};
        fwrite(num,sizeof(char),4,file);
        
        for(int j=0;j<7;j++){
            fwrite(" __", sizeof(char), 3, file);
        }
        fwrite("\n",sizeof(char),1,file);
    }

    fwrite("========= csie@CGU =========",sizeof(char),28,file);
    fclose(file);

    return 0;
}
