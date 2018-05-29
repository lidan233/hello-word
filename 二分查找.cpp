#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define Max 100 

typedef struct Data 
{
	int *source ;
	int size ;
}Data , *pData ;


bool _init( pData data ) ;
int find(pData data ,int findnumber ) ;

int main(void)
{
	pData data = (pData)malloc(sizeof(Data)) ;
	_init(data) ;
	int findnumber ;
	printf("what number do you want to find.\n") ;
	scanf("%d",&findnumber) ;
	getchar() ;
	int i = find(data , findnumber );
	return 0 ;
}
bool _init( pData data )
{
	data->size = Max ;
	data->source = (int *)malloc(sizeof(int)*data->size) ;
	for(int i = 0 ; i < data->size ;i++)
	{
		data->source[i] = i ;	
//		printf("%d",data->source[i]) ;
	}	
//	printf("\n") ;
	
} 
int find(pData data ,int findnumber )
{
	int begin = 0 ;
	int end = data->size-1 ;
	int mid  ;//= (begin+end)/2 ;
	
	while(end>=begin)
	{
//		printf("%d",mid) ;
		mid = (begin+end)/2 ;
		if(data->source[mid]==findnumber)
		{
			printf("we have find .\n") ;
			return mid ;
		}else
		{
			if(data->source[mid]>findnumber)
			{
				end = mid-1 ;
			}else 
			{
				begin = mid+1  ;
			}
			
		}
	}
	printf(" we can't find\n") ;
	return -1 ;
	
}
