//最小生成树
//kurisal算法 

 
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

int min(int **source , int dovision , pCloseEdge resource ,int *unionfind) ;
int root(int unionfind[] , int n) ;
bool isLinked(int unionfind[], int i, int j) ;
bool link(int unionfind[], int size [] , int i ,  int j) ;

int main(void)
{
	 
	int division ;
	srand(time(NULL) ) ;
	printf("what size of the matrix do you want ?\n") ;
	scanf("%d",&division) ;
	int* unionfind = (int *)malloc(sizeof(int)*division) ;
	int* size = (int *)malloc(sizeof(int)*division) ;
	
	int **source = (int **)malloc(sizeof(int *)*division) ;
	for(int i = 0 ; i < division ; i++)
	{
		source[i] = (int *)malloc(sizeof(int)*division) ;
		unionfind[i] = i ;
		size[i] = 1 ;	
	} 
	
	for(int i = 0 ; i < division ;i++)
	{
		for(int j = 0 ; j < division ;j++)
		{
			if(i!=j)
			{
				source[i][j] = rand()%100 ;
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
	

//	int k = 0 ;
//	for(int i = 0 ; i < division ;i++)
//	{
//		if(i!=k&&source[k][i]!=0) 
//		{
//			help[i].indexofvertex =  i ;
//			help[i].lowcost = source[k][i] ;
//			printf("source[k][i]=%d\n",source[k][i]) ;
//			printf("help[i].lowcost=%d\n",help[i].lowcost) ;
//		} 	
//	} 
	for(int i = 0 ; i < division ;i++)
	{
		printf("%d\t",help[i].lowcost) ;
	}
	printf("\n") ;
	int k ;
	for(int i = 0 ; i < division ; i++)
	{
		k = min(source ,division,help,unionfind ) ;

		if(k == -2 )
		{
			printf("稀疏矩阵\n") ;
		}
		printf("连接的节点是%d\n",k) ;
		printf("边的长度是%d\n",help[k].lowcost) ;
		link(unionfind,size,k,help[k].indexofvertex) ;
		help[k].lowcost = 0 ;

	}
//	printf("开始节点是%d\n",k) ; 
//	help[k].indexofvertex = 0 ;
//	help[k].lowcost = 0 ;
	
//	for(int i = 0 ; i < division-1;i++)
//	{
//		k = min(help,division) ;
//		if(k ==-2)
//		{
//			continue ;
//		 } 
//		printf("连接的节点是%d\n",k) ;
//		printf("边的长度是%d\n",help[k].lowcost) ;
//		help[k].lowcost = 0 ;
//		for(int j =0 ; j <division;j++)
//		{
//			if((source[k][j]!=0&&help[j].lowcost>source[k][j])||help[j].lowcost ==-1)
//			{
//				help[j].lowcost = source[k][j] ;
//			}
//		}
//	} 
	
	
	return 0 ;
}

int min(int **source , int division , pCloseEdge resource ,int *unionfind) 
{
	int leastweight ;
	for(int i = 0 ; i < division ; i++)
	{
		leastweight= 0 ;
		while(source[i][leastweight]==0&&leastweight<division) 
		{
			leastweight++ ;
		}
		if(leastweight == division)
		{
			fprintf(stderr," 有孤立的点 ");
			continue ;	
		} 
		for(int j = 0 ; j <division ;j++)
		{
			if(source[i][j]!=0&&!isLinked(unionfind,i,j)&&source[i][j]<source[i][leastweight])
			{
				leastweight = j ; 
			}
		}
		resource[i].indexofvertex = leastweight ;
		if(resource[i].lowcost!=0)
		resource[i].lowcost = source[i][leastweight ] ;
		
	}
	
	for(int i = 0 ; i < division ;i++)
	{
		printf("%d\t",resource[i].lowcost) ;
	}
	printf("\n") ;
	int count = 0 ;
	while(resource[count].lowcost==-1||resource[count].lowcost==0&&count<division)
	{
		count++ ;
	} 
	int result = count ;
	if(count>division)
	{
		return -2 ;
	}
//	printf("result =%d\n",result) ;
	for(int i = 0 ; i < division ; i++)
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
int root(int unionfind[] , int n )
{
	while(unionfind[n]!=n) 
	{
		n = unionfind[n] ;
	}
	return n;
}
bool isLinked(int unionfind[], int i, int j) 
{
	if(root(unionfind,i)==root(unionfind,j) ) 
	{	
		return true ;
	}else
	{
		return false ;
	}
}
bool link(int unionfind[], int size [] , int i ,  int j)
{
	int tempi = root(unionfind,i) ;
	int tempj = root(unionfind ,j) ;
	
	if(size[tempi]>size[tempj])
	{
		unionfind[j] = i ;
		size[tempi] += size[tempj] ;
	}else
	{
		unionfind[i] = j ;
		size[tempj] += size[tempi] ;
		
	}
	
	return true ;
}
