#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int number ;
    struct Node *pnext ;
}Node,*pNode ;

int main(void)
{
    pNode stack = (pNode)malloc(sizeof(Node)) ;
    pNode last = stack ;
    stack->pnext = NULL ;
    int x ;
    int sum = 0 ;
    printf("please input the value that you want to sum .\n") ;
    scanf("%d",&x) ;
    while(x!=0)
    {
         pNode temp = (pNode)malloc(sizeof(Node)) ;
         temp->number = x ;
         temp->pnext = last ;
         last = temp ;
         printf("please input the character.\n") ;
         scanf("%d",&x ) ;
    }
    printf("%d\n",sum) ;
    while(last->pnext!=NULL)
    {
        sum += last->number ;
        printf("%d\n",sum) ;
        last = last->pnext  ;
    }
}