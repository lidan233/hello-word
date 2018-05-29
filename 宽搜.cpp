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
typedef struct Node 
{
	pVertex vertex ;
	struct Node *pnext ;
}Node , *pNode ;

typedef struct Queue 
{
	int size ;
	pNode tail ;
	pNode start ;
}Queue , *pQueue ;


void _init(pGraph graph) ;
void BFS(pGraph graph , pQueue queue ) ; 
void _initQueue(pQueue queue,pVertex vertex) ;
pVertex pop(pQueue queue) ;
void push(pQueue queue , pVertex vertex ) ;

int main(void)
{
	pGraph graph = (pGraph)malloc(sizeof(Graph)) ;
	_init(graph) ;
	pQueue queue = (pQueue)malloc(sizeof(Queue)) ;
	BFS(graph,queue) ;
	 
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
		}//i½Úµã½áÊø 
	}//while 
	 
}
void _initQueue(pQueue queue,pVertex vertex)
{
	queue->start = (pNode)malloc(sizeof(Node)) ;
	queue->tail = queue->start ;
	queue->start->vertex = vertex ;
	queue->start->pnext = NULL ; 
	queue->size = 1 ;
	printf("%d\n",vertex->i) ;
	vertex->isvisit = visit ;
	
	
} 
void BFS(pGraph graph , pQueue queue )
{
	_initQueue(queue,graph->vertexs) ;
	pVertex node ;
	pEdge edge ;
	int i ;

	while(queue->size!=0)
	{
		
		node = pop(queue) ;
		edge = node->firstEdge ;
		if(edge!=NULL)
		{
			printf("%d\n",graph->vertexs[edge->indexofVertex].i) ;
			graph->vertexs[edge->indexofVertex].isvisit = visit ;
			push(queue,&(graph->vertexs[edge->indexofVertex]));
			edge = edge->pnext ;
		}else 
		{
			for( i = 0 ; i < graph->size ;i++)
			{
				if(graph->vertexs[i].isvisit == unvisit)
				{
					printf("%d\n",graph->vertexs[i].i) ;
					graph->vertexs[i].isvisit = visit ;
					push(queue,&(graph->vertexs[i])) ;
					
				}
			}
			if(i == graph->size)
			{
				break ;
			}
		}
	}
	
}
void push(pQueue queue , pVertex vertex )
{
	queue->size++ ;
	pNode newone = (pNode)malloc(sizeof(Node)) ;
	newone->pnext = NULL ;
	newone->vertex = vertex ;
	if(queue->tail == NULL )
	{
		queue->tail = newone ;
		queue->start = queue->tail ; 
	}
	queue->tail->pnext = newone ;
	queue->tail = queue->tail->pnext ;
	 
}
pVertex pop(pQueue queue)
{
	
	queue->size-- ;
	pVertex temp = queue->start->vertex ;
	queue->start = queue->start->pnext ;
	if(queue->start == NULL )
	{
		queue->tail  = NULL ;
		
	}
	return temp ;
}
