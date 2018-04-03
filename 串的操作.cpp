#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sizea = 10;
int sizeb = 2 ;
char * first ;
char *second ;
void menu(void)
{
  printf("1 输入\n") ;
  printf("2 插入\n") ;
  printf("3 连接\n") ;
  printf("4 删除\n") ;
  printf("5 求子串\n") ;

}
void deletestring(char *init,int begin,int end)
{
	int length = strlen(init) ;
	int i  ;
	for(i  = end+1 ; i < length ;i++)
	{
		init[begin++] = init[i] ;
	}
	init[begin] ='\0' ;

	printf("%s\n",init) ;
}
void substring(char *init,int begin,int end) 
{
	char * stringchild = (char *)malloc(sizeof(char)*(end-begin+1+1)) ;
	int i ;
	int count =0 ;
	for(i = begin ;i<=end;i++)
	{
		stringchild[count++] = init[i] ;
	}
	stringchild[count] ='\0' ;
	printf("%s",stringchild) ;
}
bool concat(char *init,char *second)
{
	int sizeA = strlen(init) ;
	int sizeB = strlen(second) ;
	if(sizea < sizeA+sizeB)
	{
		printf("overflow.\n") ;
		printf(" this time I can't  concat.\n") ;
		return false ;
	}else
	{
		for(int i = 0;i < sizeB ;i++ )
		{
			init[i+sizeA] = second[i] ;
		}
	}
	printf("%s\n",init) ;
	return true ;
}
bool instring(char *init,char *second)
{
	int sizeA ;
there:    
    printf("please input the first string\n") ;
    scanf("%s",init) ;
     sizeA = strlen(init) ;
    if(sizeA >sizea)
    {
        printf(" your string is too long.\n") ;
        init = (char *)realloc(init,sizeof(char)*2*sizeA) ;
        sizea = 2*sizeA ;
        goto there ;
    }
    int sizeB ;
here:
    printf("please input the second string.\n") ;
    scanf("%s",second) ;
    sizeB = strlen(second) ;
	if(sizeB>sizeb)
	{
		printf(" you string is too long .\n") ;
		second = (char *)realloc(second,sizeof(char)*2*sizeB) ;
		sizeb = 2*sizeB ;
		goto here ;	
	} 
    return true ;
}
bool insert(char *init,char *second,int sizea,int sizeb)
{

	int position ;
	there:
	printf("please input the position\n") ;
	scanf("%d",&position) ;
	int sizeA = strlen(init) ;
	if(sizea <= sizeA+position)
	{
		printf("overflow.\n") ;
		init = (char *)realloc(init,sizeof(char)*sizea*2) ;
		sizea *= 2 ;
		goto there ;
	}else
	{
		for(int i = sizeA; i >= position-1 ;i--)
		{
			init[i+position] = init[i] ;
		}
		int sizeB = strlen(second) ;
		for(int i = 0 ; i<sizeB;i++) 
		{
			init[position+i] = second[i] ;
		}
		printf("%s",init) ;
	}
	return true ;
}
int main(void)
{
	int flag = -1 ;
	menu() ;
	first = (char *)malloc(sizeof(char)*sizea) ;
	second = (char *)malloc(sizeof(char)*sizeb) ;
	scanf("%d",&flag) ;
	switch(flag)
	{
		case 1: instring(first,second) ;break ;
		case 2: concat(first,second) ;
		case 3: printf(" what is the begin.\n") ;
		int be ; int en ;
		scanf("%d",&be) ;
		printf("what is the end.\n") ;
		scanf("%d",&en) ;
			deletestring(first,be,en) ;
			break ;
		 case 4 :	insert(first,second,sizea,sizeb) ;
		 break ;
	}
	
 	return 0 ;
}
