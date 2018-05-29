#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


#define Max 100 

typedef struct Data 
{
	int *source ;
	int size ;
}Data , *pData ;


bool _init( pData data ) ;
int find(pData data ) ;

int main(void)
{
	srand(time(NULL)) ;
	pData data = (pData)malloc(sizeof(Data)) ;
	_init(data) ;
	int i = find(data) ;
	return 0 ;
}
bool _init( pData data )
{
	data->size = Max ;
	data->source = (int *)malloc(sizeof(int)*data->size) ;
	for(int i = 0 ; i < data->size ;i++)
	{
		data->source[i] = rand()%100 ;	
	}	
} 
int find(pData data )
{
	int findnumber ;
	printf("what number do you want to find.\n") ;
	scanf("%d",&findnumber) ;
	
	for(int i = 0 ; i < data->size ;i++)
	{
		if(data->source[i]==findnumber)
		{
			printf("had find .\n") ;
			return i ;	
		}	
	} 
	printf("hadn't find.\n") ;
	return -1 ;
}
