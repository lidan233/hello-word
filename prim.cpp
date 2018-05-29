//最小生成树
//prime算法
 
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h> 

#define Max 100
 
typedef struct closeEdge 
{
	int indexofvertex ;
	int  lowcost ;
}closeEdge , *pCloseEdge ;

int min(pCloseEdge resource ,int n) ;

int main(void)
{
	int division ;
	srand(time(NULL) ) ;
	printf("what size of the matrix do you want ?\n") ;
	scanf("%d",&division) ;
	
	int **source = (int **)malloc(sizeof(int *)*division) ;
	for(int i = 0 ; i < division ; i++)
	{
		source[i] = (int *)malloc(sizeof(int)*division) ;	
	} 
	
	for(int i = 0 ; i < division ;i++)
	{
		for(int j = 0 ; j < division ;j++)
		{
			if(i!=j)
			{
				source[i][j] = rand()%3 ;
			}else
			{
				source[i][j] = 0 ;
			}
		
		}
	}
	
	for(int i = 0 ; i < division ;i++)
	{
		for(int j = 0 ; j < division ;j++)
		{
			printf("%d\t",source[i][j]) ;
		
		}
		printf("\n") ;
	}		
	pCloseEdge help = (pCloseEdge)malloc(sizeof(closeEdge)*division) ;
	
	for(int i = 0 ; i < division ;i++)
	{
		help[i].lowcost = -1 ;
	}
	int k = 0 ;
	for(int i = 0 ; i < division ;i++)
	{
		if(i!=k&&source[k][i]!=0) 
		{
			help[i].indexofvertex =  i ;
			help[i].lowcost = source[k][i] ;
			printf("source[k][i]=%d\n",source[k][i]) ;
			printf("help[i].lowcost=%d\n",help[i].lowcost) ;
		} 	
	} 
//	for(int i = 0 ; i < division ;i++)
//	{
//		printf("%d\t",help[i].lowcost) ;
//	}
	printf("\n") ;
	printf("开始节点是%d\n",k) ; 
	help[k].indexofvertex = 0 ;
	help[k].lowcost = 0 ;
	
	for(int i = 0 ; i < division-1;i++)
	{
		k = min(help,division) ;
		if(k ==-2)
		{
			continue ;
		 } 
		printf("连接的节点是%d\n",k) ;
		printf("边的长度是%d\n",help[k].lowcost) ;
		help[k].lowcost = 0 ;
		for(int j =0 ; j <division;j++)
		{
			if((source[k][j]!=0&&help[j].lowcost>source[k][j])||help[j].lowcost ==-1)
			{
				help[j].lowcost = source[k][j] ;
			}
		}
	} 

	
	return 0 ;
}

int min(pCloseEdge resource ,int n) 
{
	int count = 0 ;
	while(resource[count].lowcost==-1||resource[count].lowcost==0)
	{
		count++ ;
	} 
	int result = count ;
	if(count>n)
	{
		return -2 ;
	}
//	printf("result =%d\n",result) ;
	for(int i = 0 ; i < n ; i++)
	{
		if(resource[result].lowcost>resource[i].lowcost&&
		resource[i].lowcost!=0&&resource[i].lowcost!=-1)
		{
			result = i ;
		}
	}
//	printf("result =%d\n",resource[result].lowcost) ;
	return result ;
	  
}
