#include<bits/stdc++.h>
using namespace std;
/*
  acm�������:��/˫����ѭ������˫��ѭ������ȣ�������˫������Ϊ�������������ƣ�ֻ�Ƕ˵㴦��ʱ������Ҫע����
*/
/*
���ֽ�㶨���д����
typedef struct node{
   int a;
   struct node *next;
   struct node *pre;
}node_t;

typedef struct node{
   int a;
   node *next;
   node *pre;
}node_t;

struct node{
 int a;
 struct node *next;
 struct node *pre;
};
typedef struct node node_t;

struct node{
 int a;
 node *next;
 node *pre;
};
typedef struct node node_t;
*/
typedef struct node{
   int a;
   struct node *next;
   struct node *pre;
}node_t, *Node;
//��������ͷ����ͷ�����һ��Ԫ��
Node CreateH()
{
    Node L,p,r;
    L=(node_t*)malloc(sizeof(node_t));//��ͷ: L=(Node)malloc(sizeof(node_t)); ��ֵΪ-1
    L->next=NULL;
    L->pre=NULL;
    L->a=-1;
    r=L;
    r->next=NULL;
    int x;
    while(scanf("%d",&x)!=EOF)
    {
      p=(Node)malloc(sizeof(node_t));
      p->a=x;
      p->next=NULL;
      p->pre=r;
      r->next=p;
      r=p;
    }
    r->next=NULL;
    return L;
}
//����������ͷ����һ��Ԫ�ؾ�������ͷ
Node Create()
{
    Node L=NULL,p,r;
    int x;
    while(scanf("%d",&x)!=EOF)
    {
      if(L==NULL)//��һ��Ԫ��
      {
           p=(Node)malloc(sizeof(node_t));
           p->a=x;
           p->next=NULL;
           p->pre=NULL;
           L=r=p;
           continue;
      }
      p=(Node)malloc(sizeof(node_t));
      p->a=x;
      p->next=NULL;
      p->pre=r;
      r->next=p;
      r=p;
    }
    r->next=NULL;
    return L;
}
//����
void ScanX(Node L)
{
  Node p;
  p=L;
  if(p==NULL){printf("NULL\n");return;}
  while(p!=NULL)
  {
      printf("%d\t",p->a);//Ҳ���� printf("%d\t",(*p).a);
      p=p->next;
  }
  printf("\n");
}
//�������
void ScanY(Node L)
{
  Node p,Last;
  Last=p=L;
  if(p==NULL){printf("NULL\n");return;}
  while(p!=NULL)
  {
      Last=p;
      p=p->next;
  }
  while(Last!=NULL)
  {
       printf("%d\t",(*Last).a);
       Last=Last->pre;
  }
   printf("\n");
}

//����x
int FindX(Node L,int x)
{
    Node p=L;
    p=p->next;
    while(p!=NULL)
    {
        if(p->a==x)
            return 1;
        p=p->next;
    }
    return -1;
}

//����ͷ���룬��ͷ��������˫����ĵ�i��λ�ò���ֵΪx��Ԫ�أ���ԭ����i��λ��ǰ��,i��0��ʼ
Node InsertHX(Node l,int i,int x)
{
    Node L,p,r,tmp;
    L=tmp=l;
    tmp=tmp->next;//��һ��Ԫ��,�±�Ϊ0
    int countX=0;
    while(tmp!=NULL)
    {
      if(countX==i)
         break;
      tmp=tmp->next;
      countX++;
    }//�������ʱ��λ�ô����������ȣ�����β�����뼴�ɣ�����Ͳ�ʵ����
    p=(Node)malloc(sizeof(node_t));
    p->next=tmp;
    p->a=x;
    p->pre=tmp->pre;
    p->pre->next=p;
    tmp->pre=p;
    return L;
}

//������ͷ���룬��˫����ĵ�i��λ�ò���ֵΪx��Ԫ�أ���ԭ����i��λ��ǰ��,i��0��ʼ
Node InsertX(Node l,int i,int x)
{
    Node L,p,r,tmp;
    L=tmp=l;
    int countX=0;
    while(tmp!=NULL)
    {
      if(countX==i)
         break;
      tmp=tmp->next;
      countX++;
    }//�������ʱ��λ�ô����������ȣ�����β�����뼴�ɣ�����Ͳ�ʵ����
    p=(Node)malloc(sizeof(node_t));
    p->next=tmp;
    p->a=x;
    p->pre=tmp->pre;
    if(p->pre!=NULL)//p���ǵ�һ��Ԫ��
      p->pre->next=p;
    else
      L=p;
    tmp->pre=p;
    return L;
}

//����ͷɾ��,i��0��ʼ
void DeleteH(Node &l,int i)
{
    int countX=0;
    Node p,r;
    p=l;
    p=p->next;
    while(p!=NULL)
    {
        if(countX==i)
            break;
        p=p->next;
        countX++;
    }
    if(p==NULL&&i>=countX)
    {
        printf("�����ڸ�Ԫ��!\n");
        return;
    }
    p->pre->next=p->next;
    if(p->next!=NULL)//p��������β��
        p->next->pre=p->pre;
    p->next=NULL;
    p->pre=NULL;
    free((void *)p);
}

//������ͷɾ��,i��0��ʼ
void Delete(Node &l,int i)
{
    int countX=0;
    Node p,r;
    p=l;
    while(p!=NULL)
    {
        if(countX==i)
            break;
        p=p->next;
        countX++;
    }
    if(p==NULL&&i>=countX)
    {
        printf("�����ڸ�Ԫ��!\n");
        return;
    }
    if(p->pre==NULL && p->next==NULL)//ֻ��һ���ڵ�
    {
        free((void *)p);
        l=NULL;
        return;
    }
    if(p->pre!=NULL)//p���������һ��
        p->pre->next=p->next;
    if(p->next!=NULL)//p��������β��
        {
            p->next->pre=p->pre;
            if(p->pre==NULL)//���������ͷ��������L
             l=p->next;
        }
    p->next=NULL;
    p->pre=NULL;
    free((void *)p);

}

int main()
{

    node_t *Linklist=NULL;
    Linklist=CreateH();
    ScanX(Linklist);
    ScanY(Linklist);
    if(FindX(Linklist,2)==1)
        printf("ok\n");

    Node LinklistNew=InsertHX(Linklist,0,100);
    ScanX(LinklistNew);
    ScanY(LinklistNew);

    DeleteH(Linklist,1);
    ScanX(Linklist);
    ScanY(Linklist);*/

    Node Linklist2=NULL;
    Linklist2=Create();
    ScanX(Linklist2);
    ScanY(Linklist2);

    Node Linklist2New=InsertX(Linklist2,0,100);
    ScanX(Linklist2New);
    ScanY(Linklist2New);

    Delete(Linklist2,0);
    ScanX(Linklist2);
    ScanY(Linklist2);

    return 0;
}
