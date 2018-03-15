#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//表达式的最后记得放# 不要放等号 
#define Max 100


typedef struct nLnode
{
	int number ;
	struct nLnode *pnext ;
	
}nLnode , *nLinkList ;

typedef struct rLnode
{
	char caculate ;
	struct rLnode  *pnext ;
	
}rLnode , *rLinkList ;

typedef struct nStack 
{
	nLinkList base ;
	nLinkList top ;
	int size ;
	
}nStack , *pnStack ; 

typedef struct rStack 
{
	rLinkList base ;
	rLinkList top ;
	int size;
	
}rStack , *prStack ;

void _init(pnStack a) ;
void _init(prStack a) ;

void push(pnStack a , int i );
void push(prStack a , char i) ;

int  pop(pnStack a ) ;
char pop(prStack a ) ;

char Precede( char a , char c ) ;
double gettype(char a) ;
int caculate(int i , int j , char fuck);
bool isnumber(char c ) ;

int main(void)
{
	pnStack a = (pnStack)malloc(sizeof(nStack)) ;
	prStack b = (prStack)malloc(sizeof(rStack)) ;
	
	int i ;
	int j ;
	char oper ;
	int result ; 
	_init(a) ;
	_init(b) ;
	
	char c ;
	printf("please input the value.\n") ;
	c= getchar() ;
	 
	while(!(c == '#' && b->top->caculate=='#')&&c!='\n')
	{
		if(isnumber(c)) 
		{
			push(a,c-48) ;
			printf("please input the value.\n") ; 	
			c= getchar() ;
		} else
		{
			switch( Precede( b->top->caculate , c ))
			{
				case '<': push(b,c) ;
				printf("please input the value.\n") ;
						  c= getchar() ;
						  break ;
				case '=': pop(b) ;
						  c = getchar() ;
						  break ;
				case '>': printf("可以运算") ; 
						  i = pop(a) ;
						  j = pop(a) ;
						  oper = pop(b) ;
						  result = caculate(i , j , oper) ;
						  push(a,result) ;
						  break ;
				
			}
		}
		
	}
	printf("\n%d",a->top->number) ;
	
	return 0 ;
	
}
void _init(prStack a)
{

	a->base = (rLinkList)malloc(sizeof(rLnode)*Max) ;
	a->top = a->base ;
	a->size = 0 ; 
	rLinkList temp  = a->base ; 
	for( int i = 1 ; i< Max ; i++)
	{
		temp->pnext = &(a->base)[i] ;
		temp = temp->pnext ; 
	}
	push(a,'#') ;
}
void _init(pnStack a)
{
	a->base = (nLinkList)malloc(sizeof(nLnode)*Max) ;
	a->top = a->base ;
	a->size = 0 ; 
	nLinkList temp  = a->base ; 
	for( int i = 1 ; i< Max ; i++)
	{
		temp->pnext = &(a->base)[i] ;
		temp = temp->pnext ; 
	}
	push(a,'#') ;
}
void push(pnStack a , int i )
{
	a->top =a->top->pnext ;
	a->top->number = i ;
	a->size++ ;
}
void push(prStack a , char i )
{
	a->top =a->top->pnext ;
	a->top->caculate = i ;
	a->size++ ;
}
int  pop(pnStack a )
{
	int result = a->top->number ;
	a->top = &(a->base[--(a->size)]) ;
	return result ;
}
char  pop(prStack a )
{
	char result = a->top->caculate ;
	a->top = &(a->base[--(a->size)]) ;
	return result ;
}
bool isnumber(char c )
{
	if(c-48>=0&&c-48<10)
	{
		return true ;
	}else
	{
		return false ;
	}
}


char Precede( char a , char c )
{
	double a1 = gettype(a) ;
	double c1 = gettype(c)-0.5 ;
	if(a1==c1)
	{
		return '=' ;
	}	
	if(a1>c1)
	{
		return '>' ;
	}
	if(a1<c1)
	{
		return '<' ;
	}

}

double gettype(char fuck)
{
	switch(fuck)
	{
		case '+' : return 1.0 ; break ;
		case '-' : return 2.0 ; break ;
		case '*' : return 3.0 ; break ;
		case '/' : return 4.0 ; break ;
		case '(' : return 0 ; break ;
		case ')' : return 0.5 ; break ;
		case '#' : return -1 ;break ;
	}
}
int caculate(int i , int j , char fuck)
{
	switch(fuck)
	{
		case '+' : return i+j ; break ;
		case '-' : return i-j ; break ;
		case '*' : return i*j ; break ;
		case '/' : return i/j ; break ;
		
	}
}
