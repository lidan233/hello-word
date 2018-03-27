#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int number ;
    struct Node *pnext ;
}Node,*pNode ;

bool compare(pNode a ,pNode b ) ;
int pop(pNode a ) ;
int main(void)
{
   pNode stack = (pNode)malloc(sizeof(Node)) ;
   pNode stack1 = (pNode)malloc(sizeof(Node)) ;
   pNode last1 = stack1 ;
   pNode last = stack ;
   stack->pnext = NULL ;
   int x ;
   printf("please input the value that you want to sum .\n") ;
   scanf("%d",&x ) ;
   while(x!=0)
   {
       pNode temp = (pNode)malloc(sizeof(Node)) ;
       pNode temp1 = (pNode)malloc(sizeof(Node)) ;
       
       temp->number = x ;
       temp1->number = x ;
       
       temp->pnext = last ;
       last1->pnext = temp1 ;
       
       last = temp ;
       last1 = temp1 ;
       
       printf("please input the value that you want to sum .\n") ;
       scanf("%d",&x ) ;
   }
   last1->pnext = NULL ;
   
   bool flag = compare(last,stack1->pnext) ;
   if(flag)
   {
       printf(" we have find that \n") ; 
   }else
   {
       printf(" we don't have find that .\n");
   }
   return 0 ;
}
bool compare(pNode a ,pNode b ) 
{
    printf("%d and %d",a->number,b->number) ;
    while(a->number == b->number)
    {
        printf("%d and %d",a->number,b->number) ;
        a = a->pnext ;
        b = b->pnext ; 
        if(a == NULL || b == NULL)
        {
            break ;
        }
    }
    if(a == NULL || b == NULL)
    {
        return true ;
    }else
    {
        return false ;
    }
}
