//栈实现中缀表达式转后缀表达式
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max 100 
typedef enum fuck 
{
	lparen ,
	rparen ,
	plus   ,
	minus  ,
	times  ,
	divide ,
	mod    ,
	eos    ,
	operand,
	
}fuck ;

typedef enum record 
{
	isint ,
	ischar ,
}record ;

typedef union Data
{
	int number ;
	char caculate ;
}data ;

typedef struct Lnode
{
	data first ;
	record second ;
}Lnode ,*pLnode ;

typedef struct Sqack
{
	pLnode pTop ;
	pLnode pBase ;
	int StackSize ;
}Sqack ,*pSqack ;


void init(pSqack start ) ;
void push(pSqack  start,char temp  ) ;
void destroy( pSqack start ) ;
void doing(pSqack start ,char buffer[] ) ;
fuck gettoken(char *start , int n )  ;

int main(void)
{
	char buffer[1000] ;
	int size ;
	pSqack stack = (pSqack)malloc(sizeof(Sqack)) ;
	int count = 0;
	
	init(stack) ;
	printf("please input the rule \n" ) ;
	scanf("%s" ,buffer+1) ;
	
	size = strlen(buffer) ;
	
	doing(stack,buffer) ;
//	while(count<size) 
//	{
//		push( stack ,buffer[count] ) ;
//		count++ ;
//	}
	

	return 0 ;
}
void init(pSqack start) 
{
	start->pBase = (pLnode)malloc(sizeof(Lnode)*Max) ;
	start->pTop = start->pBase ;
	start->StackSize = Max ;
}
void push( pSqack start ,char temp)
{
	start->pTop++ ;
	switch(temp)
	{
		case '+' : 
		case '-' :
		case '*' :
		case '/' : start->pTop->first.caculate = temp ; 
				   start->pTop->second = ischar ;
				   break ;
		case '0' :
		case '1' :
		case '2' :
		case '3' :
		case '4' :
		case '5' :
		case '6' :
		case '7' :
		case '8' :
		case '9' : start->pTop->first.number = temp-48 ;
				   start->pTop->second = isint ;
				   break ;
		default :
			printf(" you make a mistake ! \n") ;
	}
	printf("push over \n") ;
	
}
void destroy( pSqack start )
{
	free(start->pBase) ;
	start->pBase =NULL ;
	start->pTop = NULL ;
	start->StackSize = 0 ;
	
}
void doing(pSqack start ,char buffer[] )
{
	int isp[] = { 1,19,12,12,13,13,13,0} ;
	int count = strlen(buffer)-1 ;
	int system_count = 0 ;
	
	char system[2] ;
	char* temp = buffer ;
	
	buffer[0] = ' '  ;
	fuck example ;
	
	
	
	for(example = gettoken(buffer , count);
		example != 	eos ;							
		example = gettoken(buffer ,count ) )
	{
		if(example == operand )
		{
			
			while(gettoken(buffer ,count )==operand)
			{
			 
//				printf("first%c\n" ,buffer[count]) ;
				printf("%c" ,buffer[count]) ;
//				printf("fuck") ;
				count-- ;	
			} 
			

		}else if(example == rparen)
		{
			count-- ;
			while((example=gettoken(buffer,count))!=lparen)
			{
//				printf("second%c\n",buffer[count]) ;
				printf("%c",buffer[count]) ;
				count--	;
			}	
		}else
		{
			if(strlen(system)==0)
			{
				system[0] = buffer[count] ;
			} else if(strlen(system) == 1)
			{
				if(isp[gettoken(system,0)]<isp[example])
				{
					system[1] = system[0] ;
					system[0] = buffer[count] ;
				}else
				{
//					printf("third%c",system[0]) ;
					printf("%c",system[0]) ;
					system[0] = buffer[count] ;
				}
			}else if(strlen(system) == 2)
			{
//				printf("four%s\n",system) ;
				printf("%c",system[0]) ;
				system[0] = '\0' ;
				system[1] ='\0' ;	
			}
			count-- ; 
			
			 
		}
		
	}
					
	if(strlen(system)!=0)
	{
		for(int i =0 ; i< strlen(system) ; i++)
		{
			printf("%c",system[i]) ;
		}
	}
}
fuck gettoken(char *start , int n )  
{
	char temp ;
	temp = *(start+n) ;
	switch(temp)
	{
		case '(' : return lparen ;
		case ')' : return rparen ;
		case '+' : return plus   ;
		case '-' : return minus  ;
		case '*' : return divide ;
		case '/' : return times  ;
		case '%' : return mod    ;
		case ' ' : return eos    ;
		default  : return operand ;
			
	} 
}







 
