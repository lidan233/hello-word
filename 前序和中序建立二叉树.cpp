#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std ;
int num = 0 ;
typedef struct Node
{
	char data ;
	struct Node* pleft ;
	struct Node* pright ;
}Node,*pNode ;

pNode buildtree(string a ,string b,int a_start,int a_end,int b_start,int b_end) ;
int findindex(string a,char b) ; 
void transport(pNode tree);

int main(void)
{
	pNode root ;
	string a,b ;
	cin>>a ;
	cin>>b ;
	root = buildtree(a,b,0,a.length()-1,0,b.length()-1);
	transport(root);
	return 0 ;
	 
}

pNode buildtree(string a ,string b,int a_start,int a_end,int b_start,int b_end) 
{
	if(a_start>a_end)
	return NULL ;
	int result = b.find(a[a_start]) ;
	pNode newone = new Node ;
	newone->data = a[a_start];
	
	newone->pleft=  buildtree(a,b,a_start+1,a_start+result-b_start,b_start,result-1) ;
	newone->pright =  buildtree(a,b,a_start+result-b_start+1,a_end,result+1,b_end);
	return newone ;	
} 
void transport(pNode tree)
{
	//ÀÁµÃ½¨Õ» 
	if(tree == NULL)
	return ;
	printf("%c",tree->data) ;
	transport(tree->pleft) ;
	transport(tree->pright) ; 
}

