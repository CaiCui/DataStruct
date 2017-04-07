#include<bits/stdc++.h>
using namespace std;
/*
  ʡѡOI���ݽṹ֮������д(���������ʵ��): ˫�˶��У�ѭ������
*/
//һ����м�ʵ��c
typedef struct Queue{

  int sum=0;
  int *p=NULL;
  int tail=0;
  Queue(){}
  Queue(int n)
  {
      sum=n;
      p=(int *)malloc(n*sizeof(int));
  }
  int push(int x)
    {
        p[tail++]=x;
        return 1;
    }
  int pop()
    {
        int x=p[0];
        for(int i=0;i<tail-1;i++)
            p[i]=p[i+1];
        p[tail--]=0;
        return x;
    }
   int top()
   {
       return p[0];
   }
   int qsize()
   {
       return tail;
   }
   int qempty()
   {
       if(tail>0)
        return 0;
       return 1;
   }
}_Queue;
//ѭ�����м�ʵ��c
typedef struct CQueue{

  int sum=0;//���г���
  int *p=NULL;
  int countq;
  int frontp;//��ͷָ��
  int rearp;//��βָ��
  CQueue(){}
  CQueue(int n)
  {
      sum=n;
      p=(int *)malloc(n*sizeof(int));
      frontp=rearp=0;
      countq=0;
  }
  int push(int x)
    {
        p[rearp]=x;
        rearp=(rearp+1)%sum;
        countq++;
        return 1;
    }
  int pop()
    {
        int x=-1;
        if(countq!=0)
        {
            x=p[frontp];
            frontp=(frontp+1)%sum;
            countq--;
        }
        return x;
    }
   int qfront()
   {
       return p[frontp];
   }
   int qback()
   {
       return p[(rearp+sum-1)%sum];
   }
   int qsize()
   {
       return countq;
   }
   int qempty()
   {
      if(countq==0)
        return 1;
      return 0;
   }
   int qfull()
   {
       if((rearp+1)%sum==frontp)
        return 1;
       return 0;
   }
}_CQueue;
int main()
{
    _Queue p(4);
    _CQueue pp(5);
    return 0;
}
