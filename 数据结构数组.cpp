#include <bits/stdc++.h>
using namespace std;
/*
    acm����С�ᡣע�⣺�ܴ������Ҫ���ں�����Ķѿռ���
*/
int main()
{
      //����
      int a[10];
      int b[10]={1,2,3,5};
      int c[10]{1,2,3,4,5};
      int m=10,n=10,h=10;

      //��̬����c++һά����m���ͷ�
      int *d=new int[m];
      d[0]=1;
      delete []d;//��delete d;

      //��̬����c++��ά����mxn���ͷ�
      int **dd=new int *[m];
      for(int i=0;i<m;i++)
        dd[i]=new int [n];
      for(int i=0;i<m;i++)
        delete []dd[i];
      delete dd;

      //��ά�Դ����� mxnxh
      int ***ddd=new int **[m];
      for(int i=0;i<m;i++)
      {
         ddd[i]=new int *[n];
         for(int j=0;j<n;j++)
             ddd[i][j]=new int [h];
      }
      for(int i=0;i<m;i++)
      {
          for(int j=0;j<n;j++)
          {
              delete ddd[i][j];//�ͷŵ���ά��һά����h
          }
          delete ddd[i];//�ͷŵڶ�ά�Ķ�ά����
      }
      delete ddd;//�ͷŵ�һά��ά����

      //��̬����c����һά���飬�ͷ�
      int *p=NULL;
      p=(int *)malloc(sizeof(int)*n);
      p[0]=2;
      cout<<p[0]<<endl;
      free((void*)p);//��ʱp[0]Ϊһ��������

      //��̬����c���Զ�ά����mxn���ͷ�
      int **pp;
      pp=(int **)malloc(m*sizeof(int *));
      for(int i=0;i<m;i++)
       pp[i]=(int *)malloc(sizeof(int)*n);
      for(int i=0;i<m;i++)
         free((void*)pp[i]);
      free ((void *)pp);

      //��̬����c������ά����mxnxh���ͷ�
      int ***ppp;
      ppp=(int ***)malloc(m*sizeof(int**));
      for(int i=0;i<m;i++)
        ppp[i]=(int **)malloc(n*sizeof(int *));
      for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
         ppp[i][j]=(int *)malloc(h*sizeof(int));
      for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
         free((void*)ppp[i][j]);
      for(int i=0;i<m;i++)
         free((void*)ppp[i]);
      free((void *)ppp);

      return 0;
}
