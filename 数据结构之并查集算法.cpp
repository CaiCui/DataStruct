#pragma comment(linker,"/STACK:1024000000,1024000000")
#include<bits/stdc++.h>
using namespace std;
/*
  ʡѡIO���鼯:nion-set ��Ҫ�����ж϶��Ԫ���Ƿ�����ͬһ�����ϣ���ͼ����ͨ��֧�����������ж�ͼ�еĻ��Ĵ���
  find()���ܣ����Ҹ��ڵ�ͬʱ�������ṹ����һ����ѹ����һ�������������ͬ�����γ�ɭ��
        A    ...      B
     / / \ \       / / \ \
     1 2 3..n      d c s ..3
  ���Ӷȣ���ʵ�ϣ�·��ѹ����Ĳ��鼯�ĸ��Ӷ���һ����С�ĳ�����
*/
#define MAXN 0x0fffffff
int F[MAXN];//���鼯����
int Find(int x)//�ڵ���Һͽṹ���£��ݹ�д��������RE
{
    //����һ��if(F[x]==-1)return x;
    if(F[x]==x)return x;
    return F[x]=Find(F[x]);
}
int Find2(int x)//�ڵ���Һͽṹ���£��ǵݹ�д����������RE
{
    int root=x;
    while(root!=F[root])//�ҵ����ڵ�r
    {
        root=F[root];
    }
    int y=x;
    while(y!=root)//·��ѹ������Ϊ2�����ṹ
    {
      int tmp=F[y];
      F[y]=root;//�ӽڵ㸸�׸���Ϊ���ڵ�r
      y=tmp;//�ظ��Ҹ��ڵ�
    }
    return root;
}
void join(int x, int y)//����Ԫ��
{
    int t1,t2;
    t1=Find(x);
    t2=Find(y);
    if(t1!=t2)
        F[t1]=t2;
}
void init(int n)//��ʼ�����鼯
{
    //����һ��memset(F,-1,sizeof(F))
    for(int i=1;i<=n;i++)
    {
        F[i]=i;
    }
}

int main()
{
    int n,v,u;
    cin>>n;
    init(n);
    cin>>v>>u;
    join(u,v);
    return 0;
}
