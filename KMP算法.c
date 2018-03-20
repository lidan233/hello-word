//KMP 算法
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define Max 100

int *next(char *str ,int size) ;
int sort(int *next ,char *string ,char *str) ; 

int main(void)
{
    char *str = (char*)malloc(sizeof(char)*Max) ;
    char *string = (char *)malloc(sizeof(char)*Max) ;
    printf("please input the string .\n") ;
    scanf("%s",str) ;
    printf("please input the string.\n");
    scanf("%s",string) ;
    printf("%d",strlen(str)) ;
    int* kmp = next(str,strlen(str)) ;
    int i = 0 ;
    for(i = 0 ; i< strlen(str);i++)
    {
        printf("%d    " ,kmp[i]);
    }
    sort(kmp,string ,str ) ;
    return 0 ;
}
int *next(char *str ,int size) 
{
    int *result = (int *)calloc(sizeof(int),size) ;
    result[0] = -1 ;
    int k = -1 ;
    int i = 0 ;
    while(i <size-1)
    {
        if(k == -1 || str[k] == str[i])
        {
            k++ ;
            i++ ;
            result[i] = k ;
        }else{
            k = result[k] ;
        }
    }
    return result ;
}
int sort(int *next ,char *string ,char *str)
{
    printf("fuck");
    int i = 0 ;
    int j = 0 ;
    char flag = 'n' ;
    int size = strlen(string) ;
    int psize = strlen(str) ;
    printf("%d",psize);
    while(i<size)
    {
        printf("i =%d\n",i);
        printf("j = %d\n",j);
        printf("fuck\n");
        if(string[i] == str[j])
        {
            printf("fuck1\n");
            i++ ;
            j++ ;
            if(j>=psize)
            {
                flag  = 'y' ;
                break ;
            }
        }else{
            printf("fuck2\n");
            j = next[j] ;
            if(j==-1)
            {
                i++;
                j++;
            }
        }
    }
    if(flag =='y')
    {
        printf(" we have got that .\n") ;
        return i ;
    }
    else
    {
        printf(" we dont get that .\n") ;
        return 0 ;
    }
    
}