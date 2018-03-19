#include <stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct Bd 
{
    int begin ;
    int end ;
    int sum ;
}Bd ,*pBd ;

pBd findgreatestArray(int *array,int begin ,int end) ;

int main(void)
{
	char *  string = (char*)malloc(sizeof(char)*100) ;
	int *temp = (int *)malloc(sizeof(int)*100); 
	int i = 0 ;
	char flag = 'y' ; 

	while(flag=='y')
	{
		printf("please input the value of the data list .\n") ;
		scanf("%d",&temp[i++]) ;
		getchar() ;
		printf(" do you want continue ?\n") ;
		scanf("%c",&flag);
	}
    pBd first = findgreatestArray(temp,0,i-1) ;
    printf("%d is begin and %d is the end\n",first->begin+1,first->end+1) ;
    return 0;
}
pBd findgreatestArray(int *array,int begin, int end )
{
    pBd last = (pBd) malloc(sizeof(Bd)) ;
    last->begin = 0 ;
    last->end = 0 ;
    last->sum = -32767 ;
    int tsum = 0 ;
    int iresult = 0 ;
    int nresult = -32766 ;
    
    for(int i = 0 ;i <= end ;i++)
    {
        int j = i ;
        iresult = i ;
        nresult = -32766 ;
        while(j>=last->begin)
        {
            tsum = tsum + array[j] ;
            if(tsum>nresult)
            {
                nresult = tsum ;
                iresult = j ;
            }
            j-- ;
        }
        if(nresult>last->sum)
        {
            last->sum = nresult ;
            last->begin = iresult ;
            last->end = i ;
        }
        
            
    }
    return last ;
    
    
}
