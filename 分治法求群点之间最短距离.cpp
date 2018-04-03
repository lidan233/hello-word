#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<math.h>

#define Max 1e10
 using namespace std;
typedef struct Point
{
  int x ;
  int y ;
}Point,*pPoint ;

Point ar[10000] ;
Point br[10000] ;//ÄÚ´æ±äÁ¿

int distance(pPoint a ,pPoint b)
{
  return sqrt((a->x - b->x)*(a->x - b->x)+
   (a->y - b->y)*(a->y - b->y)) ;
}
bool comparex(Point a,Point b) 
{
  return a.x<b.x ;
}
bool comparey(Point a,Point b) 
{
  return a.y<b.y ;
}
 double min(double a,double b)
{
   return a<b?a:b;
}
double cal(int begin,int end)
{
  int mid ;
  int i ;
  int j ;
  int tail = 0 ;
  double pdistance ;
  if(begin >= end )
  {
        return Max ;
  }
  mid = (begin+end)/2 ;
  i = mid ;
  pdistance = min(cal(begin,mid),cal(mid+1,end)) ;
  while(i>=begin&&ar[mid].x-ar[i].x < pdistance)
  {
    br[tail++] = ar[i--] ;
  }
  i =  mid+1 ;
  while(i<end&&ar[i].x - ar[mid].x< pdistance)
  {
    br[tail++] = ar[i++] ;
  }
  sort(br,br+tail,comparey) ;
  for(i=0 ; i<tail;i++)
  {
    for(j = i+1 ;j<tail&&br[j].y-br[i].y<pdistance;j++)
    {
      if(distance(&br[i],&br[j])<pdistance)
      {
        pdistance = distance(&br[i],&br[j]) ;
      }
    }
  }
  return pdistance;
} 
int main(void)
{
  srand(time(NULL)) ;
  int n = rand() %100+100;
  int i = 0;
  for(i =0 ;i <n;i++)
  {
    ar[i].x = rand()%100*pow(-1,rand()%2) ;
    ar[i].y = rand()%100*pow(-1,rand()%2) ;
  }
  sort(ar,ar+n,comparex);
  double d=cal(0,n);    
  printf("%f",d) ;   
  return 0 ;
}
