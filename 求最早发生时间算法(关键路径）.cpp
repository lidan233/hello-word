#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


#define Max 100 

int graphinsize ;
typedef struct Edge 
{
	int weight ;
	int point ;
	struct Edge *pnext ;	
}Edge , *pEdge ;

typedef struct Lnode 
{
	int id ;
	int info ;//是节点的入度 
	pEdge firstEdge ;//第一个子节点  
	int time ;//最早发生时间 
	int lasttime ;
}Lnode , *pLnode ;

typedef struct LnodeStack
{
	pLnode top ;
	pLnode tail ;
	int size ;
	int currentsize ;
	
}LnodeStack , *pLnodeStack ;



void FindinDegree( pLnode first , pLnodeStack stack , int n) ;
pLnode _initGraph(pLnode graph) ;
pLnodeStack _initStack(pLnodeStack stack ) ;
bool _isEmptyStack(pLnodeStack stack ) ;

bool push(pLnodeStack stack,pLnode want ) ;
pLnode pop(pLnodeStack stack) ;


int main(void)
{
	pLnode graph =(pLnode )malloc(sizeof(Lnode)) ;
	graph = _initGraph( graph) ;
	pLnodeStack stack = (pLnodeStack) malloc(sizeof(LnodeStack)) ;
	stack = _initStack(stack) ;
	
	pLnodeStack stacksecond = (pLnodeStack)malloc(sizeof(LnodeStack)) ;//1
	stacksecond = _initStack(stacksecond) ;
	
	FindinDegree(graph,stack,graphinsize) ;
	pLnode temp ;
	int tempindex ;
	pEdge tempedg ;
	int count = 0;

	while(stack->currentsize!=0)
	{
//		printf("this is %d\n",stack->currentsize) ; 

		temp = pop(stack) ;
		printf("出栈%d\n",temp->id) ;
		
		if(temp == NULL )
		{
			break ;
		}
		tempindex = temp->id ;
		tempedg = temp->firstEdge ;
		count++ ;
		 push(stacksecond,temp) ;
		
		for(;tempedg!=NULL;tempedg = tempedg->pnext)
		{
			graph[tempedg->point].info-- ;
			//因为我这里的进栈和出栈操作是new了一个新的节点 故而在进行入栈之前就必须把
			//对应的节点的值改变 这样进栈里面的时间就是已经改变过得时间 否则都是零
			//也就是说我栈的时间的改变必须和外面的同步 因此现改时间再进栈 否则都是零 
			if(temp->time+tempedg->weight > graph[tempedg->point].time)
			{
				graph[tempedg->point].time = temp->time+tempedg->weight ;
			}
			
			
			if(graph[tempedg->point].info ==0 )
			{
				push(stack,&graph[tempedg->point]) ;
//				printf("入栈了%d\n",tempedg->point) ; 
				graph[tempedg->point].info =-1 ;
			}
			
//			printf("原来的时间%d现在的时间%d\n",graph[tempedg->point].time,temp->time+tempedg->weight ) ; 
		}
		
	}

	if(count<  graphinsize)
	{
		printf("非连通图\n") ;
	}
	pLnode tempsecond ;
	pEdge  psecond ;
	int firstindex ;
	int lastindex ;
	tempsecond = pop(stacksecond) ;//前提是有会点 才会有最后一个等于逻辑排序最后一个 
	psecond = graph[tempsecond->id].firstEdge;

	for(int i = 0 ; i < graphinsize ;i++)
	{
//		printf("%d",tempsecond->id) ;
		graph[i].lasttime = graph[tempsecond->id].time ;
	}

	
	while(stacksecond->currentsize!=0)
	{
		tempsecond = pop(stacksecond) ;
		printf("弹出来了%d\n",tempsecond->id) ;
		psecond = graph[tempsecond->id].firstEdge;
		
		for(;psecond!=NULL;psecond = psecond->pnext)
		{
			firstindex = tempsecond->id ;
			lastindex = psecond->point ;
			if(graph[lastindex].lasttime-psecond->weight<graph[firstindex].lasttime)
			{
				graph[firstindex].lasttime =
				 graph[lastindex].lasttime-psecond->weight ;
				 
			}
			
		}
	}

	
	pEdge pthird ;
	printf("关键路径是：\n") ;
	for(int i = 0 ; i < graphinsize ;i++)
	{
		for(pthird = graph[i].firstEdge ; pthird!=NULL ; pthird = pthird->pnext)
		{
			if(graph[i].time == graph[pthird->point].lasttime-pthird->weight)//很有意思的一部 
			{
				printf("%d-%d\n",i,pthird->point) ;//说明你现在就是在关键路径上 
			}
		}
	}
	return 0 ;
} 
pLnode  _initGraph(pLnode graph) 
{
	int size ;//图的大小 
	int count = 0 ;//计算整遍历图个大小的长度 
	int tempchild = 0 ;//记录孩子的序号 
	char flag = 'y' ;//看看一个节点的子节点是否输入完成换下一个
	 
	printf("please tell me what size of the graph do you want to resize ,\n") ;
	scanf("%d",&size) ;
	getchar() ;
	
	graph  = (pLnode)malloc(sizeof(Lnode)*size) ;
	for(int i = 0 ; i < size ;i++)
	{
		graph[i].firstEdge = NULL ; 
		graph[i].info = 0 ;
		graph[i].time = 0 ; 
		graph[i].id = i ;
	}
	pEdge temp  ;
	pEdge insert ;

	while(count<size)
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
			getchar();
			if(tempchild>=size)
			{
				printf("ArrayIndexout YOU make a mistake .\n") ;
				exit(1) ;
			 } 
			graph[tempchild].info++ ;
			insert->point= tempchild ; 
			printf("please input the value of the Lnode\n") ;
			scanf("%d",&insert->weight) ;
			getchar() ;
			if(graph[count].firstEdge==NULL)
			{
				graph[count].firstEdge = insert ;
				temp = graph[count].firstEdge ;
			}else
			{
				temp->pnext = insert ;
				temp = temp->pnext ;
			}

		
		}
		flag = 'y' ;
	}
//	for(int i = 0 ; i < size ;i++)
//	{
//		
//		printf("%d",graph[i].info);
//	
//	}
	graphinsize = size ;
	return graph;
}
pLnodeStack _initStack(pLnodeStack stack ) 
{
	stack->top = (pLnode )malloc(sizeof(Lnode)*Max) ;
	stack->tail = stack->top ;
	stack->size = Max  ;
	stack->currentsize = 0 ;
	return stack ;
}
void FindinDegree( pLnode first , pLnodeStack stack , int n )
{
	int find = -1 ;
	for(int i = 0 ; i < n ; i++)
	{
		if(first[i].info==0)
		{	
//			printf("first[i] == %d\n",first[i].id) ;
			push(stack,&first[i]) ;
			first[i].info =-1 ;
		}
	}
	
}
bool push(pLnodeStack stack,pLnode want ) 
{
	if(stack->currentsize+1>stack->size)
	{
		stack->top =(pLnode)realloc(stack->top,stack->size*2*sizeof(Lnode)) ;
		stack->tail = stack->top ;
		for(int i = 0 ; i < stack->currentsize ;i++)
		{
			stack->tail++ ;
		}
	}
	stack->tail->firstEdge = want->firstEdge ;
	stack->tail->info = want->info ;
	stack->tail->time = want->time ;
	stack->tail->id = want->id ;
//	printf("输入了%d",want->id) ;
 	stack->currentsize++ ;
	stack->tail++ ;
	return true ;
}
pLnode pop(pLnodeStack stack) 
{
	pLnode popone = (pLnode)malloc(sizeof(Lnode)) ;
	stack->tail-- ;
	popone->firstEdge = stack->tail->firstEdge ;
	popone->info = stack->tail->info ;
	popone->time = stack->tail->time ;
	popone->id = stack->tail->id ;
	stack->currentsize-- ;
	return popone ;
}
