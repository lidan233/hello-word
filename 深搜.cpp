//首先此种深搜算法大多应用于无向图 
//但是这里为了算法的检验方便
//我使用了有向图 因为随机矩阵的生成
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max 100 

typedef enum visited 
{
	visit ,
	unvisit ,
}visitofvertex ;

typedef struct EdgeBox
{
	int indexofVertex ;
	struct EdgeBox *pnext ; 
}Edge,*pEdge ; 

typedef struct Vertex 
{
	int i ;
	visitofvertex isvisit ; 
	pEdge firstEdge ;
	
} Vertex , *pVertex;

typedef struct Graph 
{
	pVertex vertexs ;
	int size ;
}Graph , *pGraph ;

void _init(pGraph graph) ;
void DFS(pGraph graph , int i )
{
	pEdge temp =  graph->vertexs[i].firstEdge ;
	graph->vertexs[i].isvisit = visit ;
	printf("%d is visit .\n",i)  ;
	
	while(temp )
	{
		if(graph->vertexs[temp->indexofVertex].isvisit == unvisit)
		{
			DFS(graph,temp->indexofVertex) ;
		}
		temp = temp->pnext ;
	}

}



int main(void)
{
	pGraph graph = (pGraph)malloc(sizeof(Graph)) ;
	_init(graph) ;
	DFS(graph,0) ;
	
	 
	return 0 ;
}
void _init(pGraph graph)
{
	pEdge temp ;
	int size = 0 ;
	printf("what size Vertex do you need .\n");
	scanf("%d",&size) ;
	getchar() ;
	graph->vertexs = (pVertex)malloc(sizeof(Vertex)*size) ;
	graph->size = size ;
	for(int i = 0 ; i < size ;i++)
	{
		graph->vertexs[i].firstEdge = NULL ;
		graph->vertexs[i].isvisit = unvisit ;
		graph->vertexs[i].i = i ; 
		
	}
	char flag = 'n' ;
	for(int i = 0 ; i < size ;  )
	{
		printf("does the %d vertex has child Vertex .\n",i) ;
		scanf("%c",&flag) ;
		getchar() ;
		if(flag == 'n')
		{
			i++ ;	
		}else
		{
			pEdge newone = (pEdge)malloc(sizeof(Edge)) ;
			newone->pnext = NULL ;
			printf(" what is the index of this child vertex.\n") ;
			scanf("%d",&newone->indexofVertex) ;
			getchar() ;
			if(graph->vertexs[i].firstEdge == NULL )
			{
				graph->vertexs[i].firstEdge = newone ;
			}else
			{
				temp = graph->vertexs[i].firstEdge ;
				while(temp->pnext!=NULL)
				{
					temp = temp->pnext ;
				}
				temp->pnext = newone ;
			}
		}//i节点结束 
	}//while 
	 
}
