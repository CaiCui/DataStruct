#include<bits/stdc++.h>
using namespace std;
/*
  ʡѡIO���ݽṹ��stl��
  һ�㶼�����ȶ���(ʵ���Ƕѣ�֮ǰ���ܽ���ʵ�ֹ�)������ʹ��heap
  ͷ�ļ���<algorithm>֧��

  stl-heap�ṹ��飺
  heap��������STL�������������Ϊ max heap ��min heap����ȱʡ����£�max-heap�����ȶ��У�priority queue���ĵײ�ʵ�ֻ��ơ�
  �����ʵ�ֻ����е�max-heapʵ��������һ��vector���ֵ���ȫ��������complete binary tree����
  STL��<algorithm.h>��ʵ���˶Դ洢��vector/deque �е�Ԫ�ؽ��жѲ����ĺ���������make_heap, pop_heap, push_heap, sort_heap��
  �Բ�Ը�Լ�д���ݽṹ�ѵ�C++ѡ����˵���⼸���㷨���������á�

  ��Ҫ�������ĸ�����(����ԭ�͵Ĳ����ȽϺ��������п���)��
  make_heap()
  ����ԭ���ǣ�void make_heap(first_pointer,end_pointer,compare_function);
  һ�������������������ͷָ�룬�ڶ���������βָ�루ע��������β��ָ���β������������������һ��Ԫ�صĵ�ַ���������������ǱȽϺ��������֡�
  ��ȱʡ��ʱ��Ĭ���Ǵ󶥶ѡ���ע�����Ҫ�Զ���ȽϺ�������������С�ں�������С���ô��ں�����
  ���ã�����һ�ε��������������һ���ѵĽṹ����Χ��[first,last)ע�ⲻ����lastβ��ָ���β�������

  push_heap()
  ����ԭ���ǣ�void push_heap(first_pointer,end_pointer,compare_function);
  ���ã�push_heap()������[first,last-1)��һ����Ч�Ķѣ�Ȼ���ٰѶ��е���Ԫ�ؼ�
  ��������һ���ѣ������µ�����
  ԭ��
  �����һ��Ԫ����ĩβ��Ȼ�����µ�������Ҳ���ǰ�Ԫ������ڵײ�vector��end()����
  ���㷨��������һ���Ѿ��������������£����Ԫ�ء��ú�����������������������ֱ��ʾfirst,end,���䷶Χ��
  �ؼ���ִ����һ��siftup()���������ݺ��������µ�������

  pop_heap()
  ����ԭ���ǣ�void pop_heap(first_pointer,end_pointer,compare_function);
  ���ã�pop_heap()������İ������С����Ԫ�شӶ��е�������������������ѡ���
  ��first��last-1������Ȼ��[first,last-1)������������һ���ѡ�
  ԭ��
  ����㷨��push_heap���ƣ�����һ������ͬ�������ǰѶѶ�Ԫ��ȡ�������ŵ������������vector��ĩβ����ԭ��ĩβԪ��ȥ�����
  Ȼ��end��������1��ִ��siftdown()���ݺ��������µ�������
  ע���㷨ִ����Ϻ�����Ԫ�ز�û�б�ȡ�ߣ����Ƿ��ڵײ�������ĩβ�����Ҫ����pop���������ʹ�õײ�������vector���ṩ��pop_back()����,����back()ȡ�����Ԫ�ء�

  sort_heap()
  ����ԭ���ǣ�void sort_heap(first_pointer,end_pointer,compare_function);
  ������sort_heap��[first,last)�е����н������������������������Ч�ѡ�����Ȼ
  ����������֮��Ͳ���һ����Ч���ˣ�
  ԭ��
  ��Ȼÿ��pop_heap���Ի�ö�������Ԫ�أ���ô���ǳ���������heap��pop_heap������ÿ�ν������ķ�Χ��ǰ����һ��Ԫ�ء�
  ����������ִ����Ϻ����ǵõ�һ���ǽ������С�ע���������ִ�е�ǰ���ǣ���һ������ִ�С�

*/
bool cmpMin(int a,int b)
{
    return a>b;
}
int cmpMax(int a,int b)
{
    return a<b;
}
int main()
{
     /*д��һ��
     int i;
     int a[15]={29,23,20,22,17,15,26,51,19,12,35,40};//12��Ԫ�ز���
     for(i=0;i<12;i++)
        cout<<a[i]<<" ";
     cout<<endl;
     //����д��
     make_heap(a,a+12);//Ĭ������
     for(i=0;i<12;i++)
        cout<<a[i]<<" ";
     cout<<endl;

     make_heap(&a[0],&a[12]);
     for(i=0;i<12;i++)
        cout<<a[i]<<" ";
     cout<<endl;

     make_heap(a,a+12,cmpMax);
     for(i=0;i<12;i++)
        cout<<a[i]<<" ";
     cout<<endl;

     make_heap(&a[0],&a[12],cmpMin);//С����
     for(i=0;i<12;i++)
        cout<<a[i]<<" ";
     cout<<endl;

     //����Ԫ��8
     a[12]=8;
     //��������
     push_heap(a,a+13,cmpMin);
     for(i=0;i<13;i++)
        cout<<a[i]<<" ";
     cout<<endl;

     //����Ԫ��8
     pop_heap(a,a+13,cmpMin);
     for(i=0;i<13;i++)
        cout<<a[i]<<" ";
     cout<<endl;

     //����,�ȽϺ���Ҫ���������Ͷѽ���������ıȽϺ����õ��Ľ���෴
     sort_heap(&a[0],&a[13],cmpMax);
     for(i=0;i<13;i++)
        cout<<a[i]<<" ";
     cout<<endl;
     */
     //д����
     int a[] = {15, 1, 12, 30, 20};
     vector<int>ivec(a,a+5);
     for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();iter++)
        cout<<*iter<<" ";
	 cout<<endl;

     make_heap(ivec.begin(),ivec.end(),greater<int>());//������С��
     for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter)
		cout<<*iter<<" ";
	 cout<<endl;

     make_heap(ivec.begin(),ivec.end());//��������
     for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter)
		cout<<*iter<<" ";
	 cout<<endl;

	 pop_heap(ivec.begin(),ivec.end());//��pop������������ɾ��
	 int maxE=ivec.back();//��ȡvector�����һ��Ԫ�أ���pop�������Ԫ��
	 int ss=ivec.front();//��ȡvector�ĵ�һ��Ԫ��
	 cout<<"���Ԫ��: "<<maxE<<endl;
	 ivec.pop_back();//����pop
	 for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter)
		cout<<*iter<<" ";
	 cout<<endl;

	 ivec.push_back(99);//���������м��룬��push
	 push_heap(ivec.begin(), ivec.end());
	 for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter)
		cout<<*iter<<" ";
	 cout<<endl;

	 sort_heap(ivec.begin(), ivec.end());
	 for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter)
		cout<<*iter<<" ";
	 cout<<endl;

     return 0;
}
