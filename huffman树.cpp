//hufman树 及优先队列
//构建一个顺序
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define Max 200 

typedef struct Data
{
	int weight ;
	char charac;

}Data , *pData ;

typedef struct source
{
    pData resource ;
	int size ;
	 
}List ,*pList ;

typedef struct Lnode
{
	struct Lnode *pRight ;
	struct Lnode *pLeft ;
	Data data ;
	int code ;
}Lnode ,*pLnode ;

typedef struct BinaryTree
{
	pLnode  root ;
	int size ;
} BinaryTree ,*pBinaryTree ;
bool _init(pList first ,int n  ,pBinaryTree huffman) ;
pLnode findleast(pList first ) ;
bool buildtree(pBinaryTree huffman, pList list ) ;
void visitcode(pLnode root) ; 
void change(int i ) ;

int main(void)
{
	int size = 0 ;
	pList first = (pList)malloc(sizeof(List)) ;
	pBinaryTree huffman = (pBinaryTree)malloc(sizeof(BinaryTree)) ;
	
	printf(" what size do you want to build .\n") ;
	scanf("%d",&size) ;
	_init(first,size ,huffman) ;
	for(int i = 0 ; i < size; i++)
	{
		buildtree(huffman,first) ;
	} 
	visitcode(huffman->root) ;
	return 0 ;
}
bool _init(pList first ,int n , pBinaryTree huffman ) 
{
	first->resource = (pData)malloc(sizeof(Data)*n) ;
	first->size = n ;
	pData temp = first->resource ;
	const char begin = 'a' ;
	
	for(int i = 0 ; i < n  ; i++)
	{
		temp[i].charac = begin+i ;
		printf("please tell me what is the weight of the '%c'" ,begin+i) ;
		scanf("%d",&temp[i].weight) ;
		temp[i].weight = fabs(temp[i].weight) ;
    }
 
    
    huffman->root =NULL ;
    huffman->size = 0 ;

	return true ;
	
}
pLnode findleast(pList first ) 
{
	pLnode newone = (pLnode)malloc(sizeof(Lnode));
	int indexofleast = 0 ;
	pData temp =first->resource ;
	 
	for(int i = 0 ; i < first->size ; i++ )
	{
		if(temp[i].weight>temp[indexofleast].weight&&temp[indexofleast].weight!=-1)
		{
			indexofleast = i ;
		}
	}
	newone->data.charac = temp[indexofleast].charac ;
	newone->data.weight = temp[indexofleast].weight ;
	temp[indexofleast].weight = -1 ;
	newone->pLeft = NULL ;
	newone->pRight = NULL ;
	
}
bool buildtree(pBinaryTree huffman, pList list ) 
{
	
	pLnode father = (pLnode )malloc(sizeof(Lnode) );
	father->data.charac = ' ' ;
	father->data.weight =-1 ;
	if(huffman->root==NULL)
	{
		huffman->root = findleast(list) ;
		huffman->size++ ;
		return true ;
	}else
	{
		father->pLeft = huffman->root ;
		father->pRight = findleast(list) ;
		huffman->root = father;
		huffman->size = huffman->size+2 ;
		
		return true ;
	}
	
}
void visitcode(pLnode root)
{
	static int i = 0 ;
	if(root->pLeft==NULL&&root->pRight==NULL)
	{

		root->code = i ;
		printf("%c and ",root->data.charac) ;
		change(i) ;
		return ;
	}
	if(root->pLeft!=NULL)
	{
		i = i*2 ;
		visitcode(root->pLeft) ;
		 
	}
	if(root->pRight!=NULL)
	{
		i = i*2+1 ;
		visitcode(root->pRight) ;
	
	}
	
}
void change(int i ) 
{
	while(i!=0)
	{
		if(i%2==0)
		{
			printf("0") ;
		}else
		{
			printf("1") ;
		}
		
		i = i/2 ;
	}
	if(i==0)
	{
		printf("0") ;
	}
	printf("\n") ;
}
