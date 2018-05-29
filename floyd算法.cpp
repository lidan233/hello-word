#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

#define ROW 3 

using namespace std ;
int **_init(int **matrix ,int row ,int col)
{
	srand(time(NULL)) ;
	matrix =(int **)malloc(sizeof(int *)*row) ;
	for(int i = 0 ; i < row ;i++)
	{
		matrix[i] = (int *)malloc(sizeof(int)*col) ;
	}
	
	for(int i= 0 ; i <row;i++)
	{
		for(int j =0 ;j <col;j++)
		{
			matrix[i][j] = rand()%5 ;	
			if(i==j)
			{
				matrix[i][j] = 0 ;
			}
		} 
	}
	return matrix ;
} 
int main(void)
{
	int **matrix = _init(matrix,ROW,ROW) ;
	for(int i=0;i<ROW;i++)
	{
	 	for(int j = 0 ; j<ROW ;j++)
	 	{
	 		printf("%d ",matrix[i][j]) ;
	 	} 
	 	printf("\n") ; 
	} 
	for(int k = 0 ;k <ROW;k++)
	{
		for(int i = 0;i <ROW;i++)
		{
			for(int j= 0;j<ROW;j++)
			{
				if(i!=j&&matrix[i][k]!=0&&matrix[k][j]!=0
				&&((matrix[i][j]>matrix[i][k]+matrix[k][j])||(matrix[i][j]==0)))
				{
					matrix[i][j]= matrix[i][k]+matrix[k][j] ;
				}
			}
		}//我不想区分0和正无穷 因为0只出现在对角线上（毕竟不是有负权值的特殊图）
			//如果是负权值的特殊图 我就连0和负权值一起调整 给节点加权值咯 所以
			//我就不考虑0了 也就是不考虑对角线了 
	}
	printf("最短路径是：") ; 
	for(int i=0;i<ROW;i++)
	{
	 	for(int j = 0 ; j<ROW ;j++)
	 	{
	 		printf("%d ",matrix[i][j]) ;
		 } 
		 printf("\n") ; 
	} 
	  return 0;
} 
