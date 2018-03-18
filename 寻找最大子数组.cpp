#include<stdio.h>
#include<stdlib.h>


typedef struct Bd
{
	int begin ;
	int end  ;
	int sum ;
}Bd ,*pBd ;

pBd findmaxsubarray(int *array ,int begin , int end );
pBd findacrossmaxarray(int *array,int begin ,int mid ,int end ) ;

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
	pBd result = findmaxsubarray(temp,0,i-1) ;
	return 0 ;
}
pBd findmaxsubarray(int *array ,int begin , int end )
{
	printf("fuck4") ; 
	if(begin == end)
	{
		pBd newone  = (pBd)malloc(sizeof(Bd)) ;
		newone->begin = begin ;
		newone->end = end ;
		newone->sum = array[begin] ;
		return newone ;
	}
	int middle = (begin+end)/2 ;
	pBd a = findmaxsubarray(array,begin,middle) ;
	pBd b = findmaxsubarray(array,middle+1,end) ;
	pBd c = findacrossmaxarray(array,begin,middle,end ) ;
	
	if(a->sum>b->sum)
	{
		if(a->sum>c->sum)
		{
			return a ;
		}else
		{
			return c ;
		}
	}else
	{
		if(b->sum>c->sum)
		{
			return b ;
		}else
		{
			return c ;
		}
	}

	
}
pBd findacrossmaxarray(int *array,int begin ,int mid ,int end )
{
	printf("fuck1"); 
	pBd newone = (pBd)malloc(sizeof(Bd));
	newone->begin = 0 ;
	newone->end = 0 ;
	newone->sum = -32766 ;
	int lsum = -32766 ;
	int rsum = -32766 ;
	int su = 0 ;
	int temp = mid ;
	while(temp>=0)
	{
		su = su + array[temp] ;
		if(su>lsum)
		{
			lsum = su ;
			newone->begin = temp;
		}
		temp-- ;
	}
	temp = mid ;
	su = 0 ;
	while(temp<=end)
	{
		su = su + array[temp] ;
		if(su>rsum)
		{
			rsum =  su ;
			newone->end = temp ;
		}
		temp++ ;
	}
	newone->sum = lsum + rsum ;
	return newone ;

}
