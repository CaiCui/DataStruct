#include<bits/stdc++.h>
using namespace std;
/*
  ʡѡOI���ݽṹ���������У��������λ�ڡ����ݽṹ֮��������.docx����
  �����������У������е�Ԫ�شӶ�ͷ����β���ֲ�������
  �����ݼ����У������е�Ԫ�شӶ�ͷ����β���ֲ�������
  �������У�ֻ���ڶ�β���Ԫ�أ����ǿ����ڶ��׶�ͷ����ɾ��Ԫ��
  ��������һ������1��3��2��1��5��6�������뵥���������еĹ������£�
  1��ӣ��õ����У�1����
  3��ӣ��õ����У�1��3����
  2��ӣ���ʱ����β�ĵ�Ԫ��3>2����3�Ӷ�β�������µĶ�βԪ��1<2�����õ�������2��ӣ��õ����У�1��2����
  1��ӣ�2>1����2�Ӷ�β�������õ����У�1��1����
  5��ӣ��õ����У�1��1��5����
  6��ӣ��õ����У�1��1��5��6����
  �����ݼ�ͬ��
*/
/*��������ģ�巽������
typedef struct MQueue{
    int *q;
    int qsize;
    int f;//��ָ��
    int r;//βָ��
    MQueue(){}
    MQueue(int n)
    {
     qsize=n;
     q=(int *)malloc(sizeof(int)*n);
     r=f=0;
    }

    void pushU(int val)//������������
    {
        while( r > f && q[r-1] > val)//����������Ԫ�صĶ�βԪ��
        {
            r--;
        }
        q[r++]=val;
    }

    void pushD(int val)//����������
    {
        while( r > f && q[r-1] < val)//����С����Ԫ�صĶ�βԪ��
        {
            r--;
        }
        q[r++]=val;
    }

    int front()
    {
        if(f<r)
        {
            return q[f];
        }
        return -1;
    }

    void pop_front()
    {
        if(f<r)
            f++;
    }

    bool isempty()
    {
        return f==r;
    }

    void clear(void)
    {
        f = r = 0;
    }
    ~MQueue(){
     free((void *)q);
    }

}_MQueue;
int main()
{
  _MQueue q(6);
    q.pushU(1);
     q.pushU(3);
      q.pushU(2);
       q.pushU(1);
        q.pushU(5);
         q.pushU(6);
     while (!q.isempty())
        {
            cout << q.front() << endl;
            q.pop_front();
        }

    _MQueue p(6);
    p.pushD(8);
     p.pushD(7);
      p.pushD(12);
       p.pushD(5);
        p.pushD(16);
         p.pushD(9);
     while (!p.isempty())
        {
            cout << p.front() << endl;
            p.pop_front();
        }
    return 0;
}
*/
//poj2823������Ŀ������������һ�����У������������ÿ������Ϊm�����ж��ڵ���С��������������г��ȣ�N <=10^6 ��m<=N
struct node{
 int x,y;
}v[1000000];//x��ʾֵ��y��ʾ�±�
int a[1000],n,m,mx[100000],mn[100000];
void getmin()//�����������
{
    int i,head=1,tail=0; //Ĭ����ʼλ��Ϊ1 ��Ϊ������v[++tail]�ʳ�ʼ��Ϊ0
    for(i=1;i<m;i++)
    {
        while(head<=tail && v[tail].x>=a[i]) tail--;
        v[++tail].x=a[i],v[tail].y=i;// ������Ŀ ǰm-1����ֱ�ӽ������

    }
    for(;i<=n;i++)
    {
        while(head<=tail && v[tail].x>=a[i]) tail--;
        v[++tail].x=a[i],v[tail].y=i;
        while(v[head].y<i-m+1) head++;//Ҫ���Ѿ�������Χ�Ĵ�head��ʼ�ų�,Ȼ��ÿ����������Ŀǰm��������Сֵ
        mn[i-m+1]=v[head].x;

    }
}
void getmax()
{
    int i,h,t;
    h=1;//ͷ
    t=0;//β
    for(i=1;i<m;i++)//�����ݼ����г�ʼ�������Ȱ�m-1����ֵ���
    {
        while( t>=h && v[t].x<=a[i])t--;
        v[++t].x=a[i],v[t].y=i;
    }
    for(;i<=n;i++)//�����ݼ����У�����m��n�Ľ��,��ʱ���Կ�ʼ������ÿ��m��������ֵ��
    {
        while( t>=h && v[t].x<=a[i])t--;
        v[++t].x=a[i],v[t].y=i;
        //�������ͷ����ɾ������ͷ���Ѿ�����m��С�����ڣ�ͷָ��h++
        while(v[h].y<i-m+1)h++;
        mx[i-m+1]=v[h].x;//���ֵ����ÿ�ε�������ͷ
    }
}
int main()
{
     int i,j;
     scanf("%d%d",&n,&m);
     for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
     getmax();
     getmin();
     for(int i=1;i<=n-m+1;i++)
         if(i==1)printf("%d",mn[i]);
         else printf(" %d",mn[i]);
     printf("\n");

    for(int i=1;i<=n-m+1;i++)
         if(i==1)printf("%d",mx[i]);
         else printf(" %d",mx[i]);
     printf("\n");
     return 0;
}
