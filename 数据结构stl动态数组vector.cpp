#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/**
��̬�����÷�:
1 ��������
(1)ͷ�ļ�#include<vector>.
(2)����vector����vector<int> vec;
(3)β���������֣�vec.push_back(a);
(4)ʹ���±����Ԫ�أ�cout<<vec[0]<<endl;��ס�±��Ǵ�0��ʼ�ġ�
(5)ʹ�õ���������Ԫ��.
 vector<int>::iterator it;
 for(it=vec.begin();it!=vec.end();it++)
    cout<<*it<<endl;
(6)����Ԫ�أ�  vec.insert(vec.begin()+i,a);�ڵ�i+1��Ԫ��ǰ�����a;
(7)ɾ��Ԫ�أ�  vec.erase(vec.begin()+2);ɾ����3��Ԫ��
 vec.erase(vec.begin()+i,vec.end()+j);ɾ������[i,j-1];�����0��ʼ
(8)������С:vec.size();
(9)���:vec.clear();
vec.front() - �ش� vector ��һ��Ԫ�ص����á�
vec.back() - �ش� vector ��βԪ�ص����á�
vec.pop_back() - ɾ�� vector ��β�˵�Ԫ�ء�
vec.empty() - ��� vector �ڲ�Ϊ�գ��򴫻� true ֵ
�㷨

(1) ʹ��reverse��Ԫ�ط�ת����Ҫͷ�ļ�#include<algorithm>

reverse(vec.begin(),vec.end());��Ԫ�ط�ת(��vector�У����һ����������Ҫ������������

һ���һ����������.)

(2)ʹ��sort������Ҫͷ�ļ�#include<algorithm>��

sort(vec.begin(),vec.end());(Ĭ���ǰ���������,����С����).

����ͨ����д����ȽϺ������ս���Ƚϣ����£�

��������ȽϺ�����

bool Comp(const int &a,const int &b)
{
    return a>b;
}
����ʱ:sort(vec.begin(),vec.end(),Comp)�������ͽ�������
*/

int main()
{
    double n;
    double i,j;
    vector<int>a;
    vector<double>b;
    while(cin>>n)
    {   if(fabs(n-0)<1e-6)break;
        b.push_back(n);

    }
    vector<double>::iterator it;
    for(it=b.begin();it!=b.end();it++)
        cout<<*it<<" ";
    cout<<b.at(6)<<endl;///�൱�������a[6]��Ԫ�� ����cout<<a[6]<<endl;
    i=b.front();
    j=b.back();
    cout<<i<<" "<<j<<" "<<b.size()<<endl;

}
