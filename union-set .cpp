#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define INF 0x0fffffff
#define MANX INF
//���鼯��ϰ ���鼯���ã������ж�Ԫ���������ĸ����ϵ� ���磺����ͼһ���м�����ͨ��֧��Ҳ���Ǳ��ֳ��˼�����������Ŀ�
/**find()���ܣ��߲��ң��߹���������ṹ����һ����������γ�һ�������������ͬ���γ�ɭ�֣�
  *     A    ...      B
  *  / / \ \       / / \ \
  *  1 2 3..n      d c s ..3
  *
  */
int F[MAXN];
int find(int x)
{
    if(F[x]==-1) return x;
    else return F[x]=find(F[x]);//����·���ϵ�ÿһ���㣬ʹ��ָ��ǰ�µĸ���ʹ���ĸ߶Ƚ�Ϊ2
}
int main(void){

  memset(F,-1,sizeof(f));
  int t1,t2,u,v;
  cin>>u>>v;
  t1=find(u);
  t2=find(v);
  if(t1!=t2)
  {
      F[t1]=t2;
  }
  return 0;
}
