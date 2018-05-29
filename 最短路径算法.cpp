//���·���㷨
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>

#define Max 100 
#define INF 100000000

typedef struct Edge 
{
	int weight ;
	int point ;
	struct Edge *pnext ;	
}Edge , *pEdge ;


typedef struct Lnode 
{
	int previous ;//��һ�����һ���ڵ� 
	int  leastdistance ;//����һ�����С���� 
	pEdge firstEdge ;//��һ��ĵ�һ������ 
	int id ;//��һ���id 
	int info ;//��� 
	bool deleted ; //�Ƿ���ͼ�б�ɾ�� 
}Lnode , *pLnode ;

typedef struct Graph
{
	pLnode lnodes ;
	int size ; 
	
}Graph, *pGraph ; 

typedef struct Node 
{
	pLnode good ;
	struct Node *pnext ; 
}Node , *pNode ;

typedef struct Set 
{
	pNode begin ;
	int size ;
}Set , *pSet ;

bool _initgraph(pGraph graph) ;
bool _insert(pGraph first  ,int index , pSet set ) ;
int  findleastindex(pGraph graph) ;
bool _initset(pSet set) ;
int main(void)
{
	
	pGraph  graph = (pGraph)malloc(sizeof(Graph)) ;
	_initgraph(graph) ;
	pSet set = (pSet)malloc(sizeof(Set)) ;
	_initset(set) ;
	int temp ;

	while(graph->size>0)
	{
		temp = findleastindex(graph) ;
//		printf("this time the least is %d\n",temp) ;
		_insert(graph,temp,set) ;
		pEdge edge = graph->lnodes[temp].firstEdge ;
		for( ; edge!=NULL ; edge = edge->pnext)
		{

			if(graph->lnodes[edge->point].leastdistance>
			graph->lnodes[temp].leastdistance+edge->weight)
			{
				graph->lnodes[edge->point].leastdistance =
				 graph->lnodes[temp].leastdistance+edge->weight ;
				 graph->lnodes[edge->point].previous = temp ;
			}
			
		}

	}
	pNode node1 = set->begin ;
	 for(int i = 0 ; i < set->size ; i++)
	 {
	 	if(node1->good->leastdistance!=INF)
	 	{
	 		printf("����ڵ㵽�ڵ�%d�����·����%d\n",node1->good->id,node1->good->leastdistance) ;
		 }else
		 {
		 	printf("����ڵ㵽�ڵ�%d�����·���������\n",node1->good->id) ;
		 }
	 	
	 	node1= node1->pnext ;
	 }
	
	return 0 ;
}
bool _initgraph(pGraph graph)
{
	
	
	int count = 0 ;//����������ͼ����С�ĳ��� 
	int tempchild = 0 ;//��¼���ӵ���� 
	char flag = 'y' ;//����һ���ڵ���ӽڵ��Ƿ�������ɻ���һ��
	 
	printf("please tell me what size of the graph do you want to resize ,\n") ;
	scanf("%d",&graph->size) ;
	getchar() ; 
	
	graph->lnodes  = (pLnode)malloc(sizeof(Lnode)*graph->size) ;
	for(int i = 0 ; i < graph->size ;i++)
	{
		graph->lnodes[i].firstEdge = NULL ; 
		graph->lnodes[i].info = 0 ; 
		graph->lnodes[i].leastdistance  = INF ; 
		graph->lnodes[i].id = i ;
		graph->lnodes[i].previous = -1 ;
		graph->lnodes[i].deleted = false ; 
	}
	pEdge temp  ;
	pEdge insert ;

	while(count<graph->size)
	{
		
		
		while(flag!='n')
		{
			insert = (pEdge)malloc(sizeof(Edge)) ;
			insert->pnext = NULL ;
			printf("does %d Node has  child .\n",count)  ;
			scanf("%c",&flag) ;
			getchar() ;
//			printf("tgus is%c\n",flag) ;
			flag = tolower(flag) ;
			if(flag == 'n')
			{
				count++ ;
				break ;
			}
	
			printf("what is  the child of the %d Lnode \n",count) ;
			scanf("%d",&tempchild) ;
			getchar() ;
			if(tempchild>=graph->size)
			{
				printf("ArrayIndexout YOU make a mistake .\n") ;
				exit(1) ;
			 } 
			graph->lnodes[tempchild].info++ ;
			insert->point= tempchild ; 
			printf("please input the value of the Lnode\n") ;
			scanf("%d",&insert->weight) ;
			getchar() ;
			if(graph->lnodes[count].firstEdge==NULL)
			{
				graph->lnodes[count].firstEdge = insert ;
				temp = graph->lnodes[count].firstEdge ;
			}else
			{
				temp->pnext = insert ;
				temp = temp->pnext ;
			}

		
		}
		flag = 'y' ;
		graph->lnodes[0].leastdistance = 0 ;
		graph->lnodes[0].previous = 0 ; 
	}
//	for(int i = 0 ; i < size ;i++)
//	{
//		
//		printf("%d",graph[i].info);
//	
//	}

	return true ;
} 
bool _initset(pSet set)
{
	set->begin = NULL ;
	set->size = 0 ;
	return true ;
}
bool _insert(pGraph first  ,int index , pSet set )
{
	first->lnodes[index].deleted = true ;
	pNode newone = (pNode)malloc(sizeof(Node)) ;
	newone->good = &first->lnodes[index] ;
	newone->pnext = NULL ;
	pNode temp = set->begin ;
	if(temp == NULL )
	{
		set->begin = newone ;
	}else
	{
		while(temp->pnext!=NULL)
		{
			temp = temp->pnext ;
		}
		temp->pnext = newone ;
	}
	first->size-- ;
	set->size++ ;
	return true ; 
}
int  findleastindex(pGraph graph) 
{
	int result = 0 ;
	const static int size = graph->size ;
	while(graph->lnodes[result].deleted == true )
	{
		if(result<size)
		{
			result++ ;
		}
		
	}
	for(int i = result ; i < size ; i++)
	{
		if(graph->lnodes[i].deleted!=true&&
		graph->lnodes[i].leastdistance<graph->lnodes[result].leastdistance)
		{
			result = i ;
		}
	}
//	printf("ѡ���˵�%d���ڵ��%d\n",result,size) ;
//	if(result == size )
//	{
//		return -1 ;
//		
//	}
	return result ;
}
