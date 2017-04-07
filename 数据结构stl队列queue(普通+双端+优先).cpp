#include<bits/stdc++.h>
using namespace std;
/*
  ʡѡOI���ݽṹ֮����: STL����(����˫�ˣ�����)ʵ��
  ����:F-I-F-O��β��ͷ��
*/
//�Զ�������ȶ��еıȽϺ���
struct cmp1{
    bool operator()(int &a,int &b){
        return a>b;//��Сֵ����
  }
};
struct cmp2{
    bool operator()(int &a,int &b){
        return a<b;//���ֵ����
    }
};
//����ʹ�����ȶ��еĽṹ��
struct number1{
   int x;
   bool operator <(const number1 &a)const
   {
       return x>a.x;//��С����
   }
};
struct number2{
   int x;
   bool operator <(const number2 &a)const
   {
       return x<a.x;//��������
   }
};
struct node1{
  friend bool operator <(node1 n1,node1 n2)//��������>
  {
      return n1.priority< n2.priority; //��������
  }
  int priority;
  int value;
};
struct node2{
  friend bool operator <(node2 n1,node2 n2)//��������>
  {
      return n1.priority> n2.priority;//С������
  }
  int priority;
  int value;
};

int main()
{
    //STL-Queue��������iterator�������Բ����õ���������
    //���캯��
    queue<int>Qd;
    queue<int>Qd2(Qd);
    int fr,ba;
    //���ò���
    Qd.push(1);
    Qd.push(2);
    Qd.push(3);
    Qd.push(4);
    fr=Qd.front();//��ͷ
    ba=Qd.back();//��β
    printf("%d %d\n",fr,ba);
    Qd.pop();//����
    fr=Qd.front();//��ͷ
    ba=Qd.back();//��β
    printf("%d %d\n",fr,ba);
    if(!Qd.empty())
        {
            printf("Not Empty\nSize: %d\n",Qd.size());
        }
    //����
    while(!Qd.empty())
    {
        printf("%d\n",Qd.front());
        Qd.pop();
    }

    //STL-Dequeue��˫�˶��У���vector���ƣ�֧��������ʺͿ��ٲ���ɾ���� ����������ĳһλ���ϵĲ��������ѵ�������ʱ�䡣��vector��ͬ���ǣ�deque��֧�ִӿ�ʼ�˲������ݣ�push_front()��
    //����������list��vector����ϸ�����μ������ݽṹstl˫�˶���deque.docx��
    deque<int>c,d;
    d=c;
    c.push_back(2);
    c.push_front(1);
    printf("%d\n",c[1]);
    deque<int>::iterator it;
    for(it=c.begin();it!=c.end();it++)
        printf("%d \t",*it);
    printf("\n");
    c.clear();

    //STL-Priority_Queue�����ȶ��У����ѣ����ȶ��������֣�һ����������ȶ��У�һ������С���ȶ��У�ÿ��ȡ�Զ��еĵ�һ��Ԫ�طֱ������ȼ��������ȼ���С��Ԫ�ء�
    priority_queue<int>pq;//Ĭ��Ϊ������ȶ���<
    priority_queue<int,vector<int>,greater<int> >qp1;//������С���ȶ���>��������Ԫ�����ͣ��������ͣ��ȽϺ���
    priority_queue<int,vector<int>,less<int> >qp2;//����������ȶ���<��������Ԫ�����ͣ��������ͣ��ȽϺ���
    pq.push(5);
    pq.push(8);
    pq.push(1);
    pq.push(-10);
    if(!pq.empty())
      printf("%d\n",pq.size());
    printf("%d\n",pq.top());
    pq.pop();
    printf("%d\n",pq.top());

    qp1.push(5);
    qp1.push(8);
    qp1.push(1);
    qp1.push(-10);
    printf("%d\n",qp1.top());

    //�Զ�������ȶ������ͺͱȽϺ���ʵ��
    priority_queue<node1>qn;
    node1 b[5];
    b[0].priority = 6; b[0].value = 1;
    b[1].priority = 9; b[1].value = 5;
    b[2].priority = 2; b[2].value = 3;
    b[3].priority = 8; b[3].value = 2;
    b[4].priority = 1; b[4].value = 4;
    for(int i=0;i<5;i++)
        qn.push(b[i]);
    for(int i = 0; i < 5; i++)
    {
        cout<<qn.top().priority<<'\t'<<qn.top().value<<endl;
        qn.pop();
    }

    priority_queue<int,vector<int>,cmp1>qp3;//�Զ�����С���ȶ��бȽϺ���
    priority_queue<int,vector<int>,cmp2>qp4;//�Զ���������ȶ��бȽϺ���
    priority_queue<number1>numq1;
    priority_queue<number2>numq2;
    number1 num1[]{-10,10,-100,66};
    number2 num2[]{-10,10,-100,66};
    numq1.push(num1[0]);
    numq1.push(num1[1]);
    numq1.push(num1[2]);
    numq1.push(num1[3]);
    printf("%d\n",numq1.top());
    numq2.push(num2[0]);
    numq2.push(num2[1]);
    numq2.push(num2[2]);
    numq2.push(num2[3]);
    printf("%d\n",numq2.top());
    return 0;
}
