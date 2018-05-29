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
		}//�Ҳ�������0�������� ��Ϊ0ֻ�����ڶԽ����ϣ��Ͼ������и�Ȩֵ������ͼ��
			//����Ǹ�Ȩֵ������ͼ �Ҿ���0�͸�Ȩֵһ����� ���ڵ��Ȩֵ�� ����
			//�ҾͲ�����0�� Ҳ���ǲ����ǶԽ����� 
	}
	printf("���·���ǣ�") ; 
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
