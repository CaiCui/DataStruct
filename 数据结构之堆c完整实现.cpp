#include<bits/stdc++.h>
using namespace std;
/*
  ʡѡIO���ݽṹ����(cʵ��)
  ��Ҫ����ʵ��"�ϵ�"��"�»�"�����㷨
  ����һ�־����������ȫ��������
  ������һ���ն˽ڵ������ֵ�������ڣ���С�ڣ������Ӻ��Һ��ӽڵ��ֵ��
*/
//ʵ�֣����/С����������tmp��arr[j]��С�Ƚϻ�һ�£�����arr[j]��arr[j+1]ҲҪ�������ͻ���С�ѱ��ѣ�������ʵ����ȫ��������

//��С��
//�ϵ��㷨������Ԫ����ӽ��Ѻ�ĵ��������Ѵ�����Ԫ��iһֱ�͸��ڵ�Ƚ�ֱ��һ�����ʵ�λ�á�
void fix_up_min_heap(int arr[],int i)//�ѵ�ǰ��i���ӽڵ���Ѷ�����
{
    int j;
    j=(i-1)/2;//���ڵ�
    int tmp=arr[i];
    while(j>=0&&tmp<arr[j])
    {
        arr[i]=arr[j];
        i=j;
        if(j>0)
            j=(j-1)/2;//�����Ҹ���
        else
            break;
    }
    arr[i]=tmp;
}
//�»��㷨���������µ��������ڶѶ�Ԫ��ɾ��pop������ĵ���,���Ѵ�����Ԫ��iһֱ���������ӽڵ��нϴ���С�ıȽ�ֱ���ҵ�һ�����ʵ�λ�á�
void fix_down_min_heap(int arr[],int len,int i)//len:��ǰ����,������Ԫ���Ǵ�0��ʼ��
{
   int j;
   j=2*i+1;//���ӽڵ�
   int tmp=arr[i];
   while(j<len)
   {
       if(j<len-1 && arr[j+1]<arr[j])//Ԥ������ĩβԪ��Խ�磬��֤���鲻��Խ�磬ͬʱѡ�������н�С�ĵ��tmp�Ƚ�
       {
           j++;
       }
       if(arr[j]<tmp)
       {
         arr[i]=arr[j];
         i=j;
         j=2*i+1;
       }
       else
         break;
   }
   arr[i]=tmp;
}

//�Ѳ���push,����β����ÿ��Ҫ�͸����Ƚϣ����ϵ��㷨
int insert_min_heap(int arr[],int n,int len,int x)
{
    if(n==len)return -1;
    arr[len++]=x;
    fix_up_min_heap(arr,len-1);
    return 1;
}
//ȡ�Ѷ�Ԫ��top
int top_min_heap(int arr[])
{
   return arr[0];
}
//��ɾ��pop,�����һ��Ԫ�ظ��ǵ��Ѷ���Ȼ�����µ��㷨
void pop_min_heap(int arr[],int len)
{
    arr[0]=arr[--len];
    fix_down_min_heap(arr,len,0);
}

//���ѵ����㷨
//�ϵ��㷨������Ԫ����ӽ��Ѻ�ĵ��������Ѵ�����Ԫ��iһֱ�͸��ڵ�Ƚ�ֱ��һ�����ʵ�λ�á�
void fix_up_max_heap(int arr[],int i)//�ѵ�ǰ��i���ӽڵ���Ѷ�����
{
    int j;
    j=(i-1)/2;//���ڵ�
    int tmp=arr[i];
    while(j>=0&&tmp>arr[j])
    {
        arr[i]=arr[j];
        i=j;
        if(j>0)
            j=(j-1)/2;//�����Ҹ���
        else
            break;
    }
    arr[i]=tmp;
}
//�»��㷨���������µ��������ڶѶ�Ԫ��ɾ��pop������ĵ���,���Ѵ�����Ԫ��iһֱ���������ӽڵ��нϴ���С�ıȽ�ֱ���ҵ�һ�����ʵ�λ�á�
void fix_down_max_heap(int arr[],int len,int i)//len:��ǰ����,������Ԫ���Ǵ�0��ʼ��
{
   int j;
   j=2*i+1;//���ӽڵ�
   int tmp=arr[i];
   while(j<len)
   {
       if(j<len-1 && arr[j+1]>arr[j])//Ԥ������ĩβԪ��Խ�磬��֤���鲻��Խ�磬ͬʱѡ�������нϴ�ĵ��tmp�Ƚ�
       {
           j++;
       }
       if(arr[j]>tmp)
       {
         arr[i]=arr[j];
         i=j;
         j=2*i+1;
       }
       else
         break;
   }
   arr[i]=tmp;
}

int main()
{
    int p[10];
	int t;
	int i;
	for(i=0;i<5;i++)
	{
		cin>>p[i];
        t=i;
        insert_min_heap(p,5,t,p[i]);
	}

	for(i=0;i<5;i++)
		cout<<p[i]<<' ';
    cout<<endl;
	for(i=5;i>0;i--)
	{
		t=i;
		cout<<top_min_heap(p)<<" ";
		pop_min_heap(p,t);
	}
	cout<<endl;

     return 0;
}
