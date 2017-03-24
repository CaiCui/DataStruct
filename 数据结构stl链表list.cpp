#include <bits/stdc++.h>
using namespace std;
/*
    acm����: stl��
    STL:list����������һ��˫������,���Ը�Ч�Ľ������ݲ���ɾ������֧���������!!!!!!ͷ�ļ�#include<list>,list����std�����������,��Ҫusingָ��
*/
int comp(int n1,int n2){
    return n1>n2;
}
int comp2(int n)
{
   return n<2;
}
int main()
{
       //list���÷���
      list<int>l;//�ձ�
      list<int>ll(10);//��һ����10��Ĭ��ֵ��0��Ԫ�ص�����
      list<int>lll(10,2);//��һ����10��ֵ��Ϊ2��Ԫ�ص�����
      list<int>l2(l); //��һ��l��copy����
      list<int>l3(ll.begin(),ll.end()); ////��llһ�������Ԫ��[_First, _Last)

      //�������
      list<int>a1(5,2);
      list<int>::iterator it;
      for(it=a1.begin();it!=a1.end();it++){
        cout<<*it<<"\t";
      }
      cout<<endl;

      //�������
      //rbegin(): ������������ĵ�һ��Ԫ��,����������һ�����ݡ�rend():����������������һ��Ԫ�ص���һ��λ��,������ĵ�һ����������ǰ��λ�á�
      list<int>::reverse_iterator it1;
      for(it1 = a1.rbegin();it1!=a1.rend();it1++){
         cout << *it1 << "\t";
      }
      cout << endl;

      //a1ֱ�Ӹ��Ƹ�l
      l=a1;

      //��ֵ
      //c.assign(n,num)     ��n��num������ֵ������c��
      //c.assign(beg,end)   ��[beg,end)�����Ԫ�ؿ�����ֵ������c��
      a1.assign(6,2);
      int test[4]{1,2,3,4};
      a1.assign(test,test+4);

      //front()���ص�һ��Ԫ�أ�back()�������һ��Ԫ��,
      //size()����Ԫ�ظ���
      //empty()�ж��Ƿ�Ϊ��
      //max_size()������������ɵ����Ԫ������
      //clear()������������е�Ԫ��
      l.front();
      l.back();
      l.size();
      l.clear();
      l.max_size();
      if(!l.empty())
         cout<<"bu kong"<<endl;
       else
         cout<<"kong"<<endl;
      /*
      c.insert(pos,num)        ��posλ�ò���Ԫ��num��
      c.insert(pos,n,num)      ��posλ�ò���n��Ԫ��num��
      c.insert(pos,beg,end)    ��posλ�ò�������Ϊ[beg,end)��Ԫ�ء�
      c.erase(pos)��������     ɾ��posλ�õ�Ԫ��,�����������
      c.erase(c.begin(),c.end()) ɾ�������ڵ�Ԫ��
      */
      l.insert(l.begin(),3);
      l.insert(++l.begin(),3,6);
      l.insert(++l.begin(),test,test+2);
      list<int>::iterator itl;
      for(itl=l.begin();itl!=l.end();itl++){
        cout<<*itl<<"\t";
      }
      cout<<endl;

      l.erase(l.begin());//l.erase(0); l.erase(l.begin()+1) �����ԣ���Ϊ��֧���������
      l.erase(l.begin(),++l.begin());
      /*
      c.push_back(num)   ��ĩβ����һ��Ԫ�ء�
      c.pop_back()       ɾ��ĩβ��Ԫ�ء�
      c.push_front(num)  �ڿ�ʼλ������һ��Ԫ�ء�
      c.pop_front()      ɾ����һ��Ԫ�ء�
      */
      l.push_back(23);
      l.pop_back();
      l.push_front(14);
      l.pop_front();

      /*
      resize(n)      ���¶�������ĳ���,����ԭʼ���Ȳ�����0����,С��ԭʼ����ɾ����
      resize(n,num)  ���¶�������ĳ���,����ԭʼ���Ȳ�����num���档
      */
      l.resize(100);
      l.resize(15,4);

      /*
      c1.swap(c2);      ��c1��c2������
      swap(c1,c2);      ͬ�ϡ�
      */
      l.swap(a1);

      /*
      c1.merge(c2)      �ϲ�2�����������ʹ֮����,���·ŵ�c1��,�ͷ�c2��
      c1.merge(c2,comp) �ϲ�2�����������ʹ֮�����Զ����������֮����·ŵ�c1��,�ͷ�c2��
      */
      l.merge(a1);
      l.merge(a1,comp);

      //c1.splice(c1.beg,c2)      ��c2������c1��begλ��,�ͷ�c2
      //c1.splice(c1.beg,c2,c2.beg)   ��c2��begλ�õ�Ԫ�����ӵ�c1��begλ�ã�������c2��ʩ�ŵ�begλ�õ�Ԫ��
      //c1.splice(c1.beg,c2,c2.beg,c2.end)   ��c2��[beg,end)λ�õ�Ԫ�����ӵ�c1��begλ�ò����ͷ�c2��[beg,end)λ�õ�Ԫ��
      l.splice(l.begin(),a1);
      l.splice(l.begin(),a1,++a1.begin());
      l.splice(l.begin(),a1,a1.begin(),a1.end());

      //remove(num)        ɾ��������ƥ��num��Ԫ�ء�
      //remove_if(comp)    ɾ�����������Ԫ��,����Ϊ�Զ���Ļص�������
      l.remove(3);
      l.remove_if(comp2);

      //reverse()       ��ת����
      //unique()       ɾ�����ڵ��ظ�Ԫ��
      //c.sort()       ����������Ĭ������
      //c.sort(comp)       �Զ���ص�����ʵ���Զ�������
      l.unique();
      l.reverse();
      l.sort();
      l.sort(comp);
      l.sort(greater<int>());//����ģ�庯��,����
      l.sort(less<int>());
      return 0;
}
