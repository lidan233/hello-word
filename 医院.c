#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int number ;
    struct Node *pNext ;
}Node,*pNode ;

void queue(int i , pNode linkList) ;
void deleteN(pNode linkList) ;
void init(pNode linkList,int number) ;
void view(pNode linkList ) ;

int main(void)
{
    int i  =0 ;
    pNode linkList = (pNode)malloc(sizeof(Node)) ;
    printf(" what size is the queue now?\n") ;
    scanf("%d",&i) ;
    init(linkList , i) ;
    deleteN(linkList) ;
    view(linkList) ;
    system("pause") ;
    return  0 ;
    
}
void queue(int i , pNode linkList)
{
    pNode temp = linkList->pNext ;
    while(temp->pNext!=NULL)
    {
        temp = temp->pNext ;
    }
    pNode newone = (pNode)malloc(sizeof(Node)) ;
    newone->number = i   ;
    temp->pNext = newone  ;
    newone->pNext = NULL ;
}
 void init(pNode linkList,int number) 
 {
     pNode last = linkList ;
     pNode temp  ;
     int i  = 0 ;
     for(i =0 ; i<number ;i++)
     {
         temp = (pNode)malloc(sizeof(Node)) ;
         printf("please input the number \n") ;
         scanf("%d",&temp->number) ;
         
         last->pNext = temp ;
         last = temp ;
     }
     last->pNext = NULL ;
 }
 void view(pNode linkList ) 
 {
     pNode temp = linkList->pNext ;
     printf("queue:") ;
     while(temp!=NULL)
     {
         printf("%d\t",temp->number) ;
         temp = temp->pNext ;
     }
     printf("\n") ;
     
 }
 void deleteN(pNode linkList)
 {
     if(linkList->pNext!=NULL)
     {
        pNode temp = linkList->pNext  ;
        printf("%d is out \t",temp->number) ;
        linkList->pNext = temp->pNext ;
        free(temp) ;
     }
     
 }
    