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
// set/multiset һЩ�����÷�
/**set��������ʵ���˺������Red-Black Tree����ƽ����������������Ԫ��ʱ�ͽ�����Ԫ���Զ��ĵ�����set����Ԫ�ص�ֵ����ֱ�ӱ��ı�
  *��ȷ��ÿ���������ڵ�ļ�ֵ�������������нڵ�ļ�ֵ����С�����������нڵ�ļ�ֵ
  *���⣬����ȷ�����ڵ���������ĸ߶����������ĸ߶���ȣ��������������ĸ߶���С���Ӷ������ٶ���졣
  *Ҫע����ǣ��������ظ�������ͬ��ֵ��Ԫ�أ�����ȡ���Դ���set�����ٶȽϿ죬����vector��deque����list������
  *����set���ϵ���ҪĿ����Ϊ�˿��ټ�����Ҳ����ͳ�Ʒ��ظ���Ԫ����������ʵ�ֵ���ͳ�ơ�
  *mutilset �� set ����ǰ����������ظ�Ԫ�أ�����Ĭ��Ҳ������洢
  ���÷���
  *begin()   ����set�����ĵ�һ��Ԫ��
  *end()  ����set���������һ��Ԫ��
  *clear()  ɾ��set�����е�����Ԫ��
  *empty()  �ж�set�����Ƿ�Ϊ��
  *max_size()  ����set�������ܰ�����Ԫ��������
  *size()   ���ص�ǰset�����е�Ԫ�ظ���
  *count() �ú���Ҳ�ж�ĳһ��ֵ�Ƿ���set�г��ֹ���0��1
  *erase(iterator), ɾ����λ��iteratorָ���ֵ ��һ��ɾ��
  *erase(first, second)  ɾ����λ��first��second֮���ֵ �ڶ���ɾ��
  *erase(key_value)   ɾ����ֵkey_value��ֵ  ������ɾ��
  *find() ���ظ���ֵ�Ķ�λ�������û�ҵ��򷵻�end()
  *insert(key_value)  ��key_value���뵽set�У�����ֵ��pair<set<int>::iterator,bool>��bool��־�Ų����Ƿ�ɹ�����iterator��������λ�ã���key_value�Ѿ���set�У���iterator��ʾ��key_value��set�е�λ�á�
  *insert(first, second) ����λ��first��second֮���Ԫ�ز��뵽set�У�����ֵ��void
  *const_iterator lower_bound(key_value)  ���ص�һ�����ڵ���key_value�Ķ�λ��
  *const_iterator upper_bound(key_value)  �������һ�����ڵ���key_value�Ķ�λ��
  *equal_range()  ������һ�Զ�λ�����ֱ��ʾ��һ�����ڻ���ڸ����ؼ�ֵ��Ԫ�غ� ��һ�����ڸ����ؼ�ֵ��Ԫ�أ��������ֵ��һ��pair���ͣ������һ�Զ�λ�����ĸ�����ʧ�ܣ��ͻ����end()��ֵ��
  *void swap(set& s):��������Ԫ��
  *void swap(multiset& s):�����༯��Ԫ��
  **/
struct mycomp{
  //��ͨ���Զ���ȽϺ��������ء�������������
  bool operator() (const int &a,const int &b) const //���һ��const���п���
  {
     return a>b;
  }
};
struct Info //�ṹ�����رȽ�д�ڽṹ�屾���ڲ�
{
    string name;
    double score;
    bool operator < (const Info &a) const // ���ء�<�����������Զ����������
    {
        //��score�ɴ�С�������Ҫ��С��������ʹ�á�>�����ɡ�
        return a.score < score;
    }
};
int main(void){
    //�����÷�����,ֻ��set������multisetͬset
    //��ʼ��:
    int a[] = {1,2,3};
    set<int>s;
    set<int,mycomp>s1;
    set<int>s11(a,a+3);
    set<int,mycomp>s12(a,a+3);
    set<int>p(s); //����
    set<int>pp(s.begin(),s.end());
    multiset<int>ss;
    multiset<int>ss1(a,a+3);
    //����,Ĭ���Ǵ�С������룬�����Լ�����ȽϺ�����
    s.insert(5); //��һ�β���5�����Բ���
    s.insert(1);
    s.insert(6);
    s.insert(3);
    s.insert(5); //�ڶ��β���5���ظ�Ԫ�أ��������
    s.insert(a,a+3);
    //s.insert (it,25); ָ��itλ�ô�����Ԫ��
    ss.insert(5); //��һ�β���5�����Բ���
    ss.insert(1);
    ss.insert(6);
    ss.insert(3);
    ss.insert(5); //�ڶ��β���5���ظ�Ԫ�أ������
    set<int>::iterator it;//����ǰ�������
    //�������Ԫ��
    multiset<int>::iterator itt;//����ǰ�������
    for(it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<endl;
    }
    set<int>::reverse_iterator rit;//���巴�������
    for(rit=s.rbegin();rit!=s.rend();rit++)
    {
        cout<<*rit<<endl;
    }
    //��֤insert����ֵ
    pair<set<int>::iterator,bool> prr;
	prr = s.insert(5);
	if(prr.second)
	{
		cout<<*prr.first<<endl;
	}

    //ɾ��Ԫ��
    //��һ��ɾ��
	s.erase(s.begin());
	//�ڶ���ɾ�� ָ������ɾ��
	set<int>::iterator first;
	set<int>::iterator second;
	first = s.begin();
	second = s.begin();
	second++;
	second++;
	s.erase(first,second);
	//���ߵڶ���ɾ������д
	it=s.begin();
    for(int i=0;i<2;i++)
      s.erase(it++);//ɾ��ǰ����Ԫ��.it����ͨ��++�������㣬���ǲ���ֱ�����ӷ������ӻ����
    //������ɾ���� ɾ����ֵΪ6��Ԫ��
    s.erase(6);
    s.clear();//���
    s.erase(s.begin(),s.end());//���

    //����
     it = s.find(6); //���Ҽ�ֵΪ6��Ԫ��
     if(it != s.end())
        cout << *it << endl;
     else
        cout << "not find it" << endl;

    //�Զ���Ƚ�Ԫ��,�Ӵ�С
    set<int,mycomp>test;
    //�ṹ��Ļ����ȽϺ�����ֱ��д�ڽṹ���ڲ�
    set<Info>info;

    //equal_range()
    pair<set<int>::const_iterator,set<int>::const_iterator>pr;
    pr = s.equal_range(3);
    cout<<"��һ�����ڵ��� 3 ������ ��"<<*pr.first<<endl;
	cout<<"��һ������ 3������ �� "<<*pr.second<<endl;

	//lower_bound upper_bound ,s����set����
	cout<<*s.lower_bound(2)<<endl;
	cout<<*s.lower_bound(3)<<endl;
	cout<<*s.upper_bound(3)<<endl;

    //�������ͷ��ڴ�
    s.~set();
  return 0;
}


