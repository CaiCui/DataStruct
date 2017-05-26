#pragma comment(linker,"/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
/*
    OIʡѡ֮Hash
    poj 3349: ����Hash,����Hash��Ľ������ж�����Բ�������Ƿ���ͬ
    ��Ŀ���⣺ÿ��ѩ������������֧���������������������������Ǵ�����һ����֧��ʼ����˳ʱ�����ʱ�뷽������õ��ġ�������ѩ�����ж��Ƿ�����״һ�µ�ѩ�����ڡ�
    ����˼·�����ֹ�ϣ��Ҫע�����ÿ��ѩ�������ɶ���������ϱ�ʾ��
    �����������1 2 3 4 5 6��
    ��2 3 4 5 6 1��3 4  5 6 1 2��������6 5 4 3 2 1��5 4 3 2 1 6�ȶ�����ͬ��״�ġ�
    ��˿����ڶ���һ��ѩ����ʱ�����Щ���ȫ�������ϣ���У����ĳ�β����ʱ������ͻ����˵�������ظ���ѩ�������Һ���Ĳ���Ҫ�ٴ���
    Hash�ṹ����
    head:[  hashValue1 ,hashValue2 ... hashValueN ]   ����head[hashValue]��ֵ��Ӧ��hashValue��edge[]�����е�ipͷָ��
                |
           [edge[ip1]] 
                |               
           [edge[ip2]]
                |
                .
                .
                .
           [edge[ipN]]                 
*/

typedef long long LL;
const int maxn=1200010;
const int mod=1200007;
int head[maxn],ip;
void init()
{
    memset(head,-1,sizeof(head));
    ip=0;
}
struct node{ //ѩ��
   int num[6];
   int next;//��һ������ͬ��hashValue�ĵ�ַ
}edge[1200010];

int getHash(int *num)
{
    int h=0;
    for(int i=0;i<6;i++)
    {
        h+=num[i];//hash����,�Ӻ�������
    }
    return h%mod;
}

void insertHash(int *num,int h)//ͷ�巨����Ԫ�ز���ͷ������һ�β����Ԫ��ָ��-1������hash��ͬ��hashֵ��num[]��������num����һ��head[h]ÿ�α����²����Ԫ�ص�ip,edge[ip].next������һ�β����Ԫ�ص�ip,���һ��Ԫ�ص�nextΪ-1
{
    for(int i=0;i<6;i++)
        edge[ip].num[i]=num[i];
    edge[ip].next=head[h];
    head[h]=ip; 
    ip++;
}
bool compare(int *a,int *b)
{
    for(int i=0;i<6;i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}
bool searchHash(int *num)
{
    int h=getHash(num);
    for(int i=head[h];i!=-1;i=edge[i].next)
    {
        if(compare(num,edge[i].num))
            return true;
    }
    insertHash(num,h);
    return false;
}
int main(){

    int n,num[2][15];
    scanf("%d",&n);
    init();
    int flag=0;
    while(n--)
    {
        for(int i=0;i<6;i++)
        {
            scanf("%d",&num[0][i]);
            num[0][i+6]=num[0][i];//˳����123456123456,����ƴ����Ϊ��������п��ܵ���״����Ϊ�ǻ�123456 234561 345612...
        }
        if(flag)continue;
        for(int i=0;i<6;i++)
        {
            num[1][i+6]=num[1][i]=num[0][5-i];//����654321654321 654321 543216 432165
        }
        for(int i=0;i<6;i++)
        {
            if(searchHash(num[0]+i)||searchHash(num[1]+i))//���п�������ö��
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag)printf("Twin snowflakes found.\n");
    else printf("No two snowflakes are alike.\n");
    return 0;
}
