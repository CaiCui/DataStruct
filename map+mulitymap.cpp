#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<functional>//�ṩSTL�Ѳ���make_heap()
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define INF 0x0fffffff
#define MANX INF
//map һЩ�����÷�
/**map:ӳ��<key,value>����һһ��Ӧ�ĵ���;multimap:<key,value>һ��key���Զ�Ӧ���value,��һ��key���Բ�����value,��ʾ��ʱ����������ʾ�ģ���1 sss 1 ttt 2 ddd����
  *�ڲ�Ҳ�Ǻ����ʵ�֣�Ĭ���������У��������ظ���key
  *����map��ÿ�����ݶ�Ӧ������ϵ�һ���ڵ㣬����ڵ��ڲ������������ʱ����ռ��16���ֽڵģ�һ�����ڵ�ָ�룬���Һ���ָ�룬����һ��ö��ֵ����ʾ��ڵģ��൱��ƽ��������е�ƽ�����ӣ���������Ӧ��֪������Щ�ط��ܷ��ڴ��ˡ�
  **/
	typedef struct tagStudentInfo
	{
	       int      nID;
	       string   strName;
	       bool operator < (tagStudentInfo const& _A) const
	       {
              //�������ָ��������ԣ���nID�������nID��ȵĻ�����strName����
	              if(nID < _A.nID)  return true;
	              if(nID == _A.nID) return strName.compare(_A.strName) < 0;
	              return false;
	       }
	}StudentInfo, *PStudentInfo;  //ѧ����Ϣ

int main(void){
  //�����÷�����,ֻ��map������multimapͬmap,���ȽϷ���map��set�ܶ෽���Ĳ���һ����ϸ�ڵĲ��ֿ���ģ��set
  //��ʼ������set������,�����ི

  map<int,string> mapStudent;
  map<int,string> mapStudent2(mapStudent);
  //���ֲ������ݵķ���
  //01 pair 4��д��
  pair<int,string>p1;
  p1=make_pair(1,"cui");
  pair<int,string>p2(2,"ss");
  mapStudent.insert(p1);
  mapStudent.insert(p2);
  mapStudent.insert(pair<int,string>(3,"ssss"));
  mapStudent.insert(make_pair(4,"666"));
  //02 value_type
  mapStudent.insert(map<int,string>::value_type(5,"777"));
  //03 ���飬�ٶȵ����������� ,���������鷽ʽ���Ը�����ǰ�ùؼ��ֶ�Ӧ��ֵ����ǰ���ַ������ܴﵽ����Ч��
  mapStudent[6]="cuicui";
  //��С
  int nSize = mapStudent.size();
  //������Ҳ�����֣�ǰ�����������������������������ǰ����ͬset
  map<int,string>::iterator iter;
  for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
  {
    cout<<iter->first<<"  "<<iter->second<<endl; //key value
  }
  map<int, string>::reverse_iterator  riter;
  for(riter = mapStudent.rbegin(); riter != mapStudent.rend(); riter++)
  {
    cout<<riter->first<<"   "<<riter->second<<endl;
  }
  for(int nIndex = 1; nIndex <= nSize; nIndex++)
  {
         cout<<mapStudent[nIndex]<<endl;
  }
  //����.�������ж�����ؼ����Ƿ���map�г��֣� 2�ַ���
  //01 ��count�������ж��ؼ����Ƿ���֣���ȱ�����޷���λ���ݳ���λ��, int count(value & Key) ���ص���key��Ԫ��������0��1

  //02 ��find��������λ���ݳ���λ�ã������ص�һ���������������ݳ���ʱ����������������λ�õĵ����������map��û��Ҫ���ҵ����ݣ������صĵ���������end�������صĵ�����
  map<int, string>::iterator iter2;
  iter2 = mapStudent.find(1);
  if(iter != mapStudent.end())
  {
       cout<<"Find, the value is "<<iter->second<<endl;
  }
  else
  {
      cout<<"Do not Find"<<endl;
  }
  //��� �п� clear() ��empty() ���� empty����true��˵���ǿ�map
  //ɾ�� Ҳ�Ǻ�setһ��������ɾ������
  //���Ҫɾ��1,�õ�����ɾ��
  map<int, string>::iterator ite;
  ite = mapStudent.find(1);
  mapStudent.erase(ite);
  //���Ҫɾ��1���ùؼ���ɾ��
  int n = mapStudent.erase(1);//���ɾ���˻᷵��1�����򷵻�0
  //�õ���������Ƭ��ɾ��
  //һ�´��������map���
  mapStudent.erase(mapStudent.begin(), mapStudent.end());
  //��Ƭɾ��Ҫע����ǣ�Ҳ��STL�����ԣ�ɾ��������һ��ǰ�պ󿪵ļ���

  //�Զ�������
  //01�ṹ�� ����< ��ֱ�����²���Ԫ�ؼ���
  map<StudentInfo, int>mapStudent3;
  StudentInfo studentInfo;
  studentInfo.nID = 1;
  studentInfo.strName = "student_one";
  mapStudent3.insert(pair<StudentInfo, int>(studentInfo, 90));

  //02��ͨ���� �º�����Ӧ�� ��������ֱ��д��main()�����ˣ��õ�ʱ���Ƴ�ȥ����
  	typedef struct tagStudentInfo
	{
	       int      nID;
	       string   strName;
	}StudentInfo, *PStudentInfo;  //ѧ����Ϣ
    class sort
	{
	       public:
	       bool operator() (StudentInfo const &_A, StudentInfo const &_B) const
	       {
	              If(_A.nID < _B.nID) return true;
	              If(_A.nID == _B.nID) return _A.strName.compare(_B.strName) < 0;
	              Return false;
      }
	};
    //��ѧ����Ϣӳ�����
     map<StudentInfo, int, sort>mapStudent;
     StudentInfo studentInfo;
     studentInfo.nID = 1;
     studentInfo.strName = "student_one";
     mapStudent.insert(pair<StudentInfo, int>(studentInfo, 90));
     studentInfo.nID = 2;
     studentInfo.strName = "student_two";
     mapStudent.insert(pair<StudentInfo, int>(studentInfo, 80));

   
  ################################
  //1��2�Ķ�value����
  multimap<int,string>ss;
  ss.insert(make_pair(1,"sas"));
  ss.insert(make_pair(1,"sadddds"));
  ss.insert(make_pair(2,"sas"));

  multimap<int,string>::iterator sa;
  for(sa=ss.begin();sa!=ss.end();sa++)
    cout<<sa->first<<' '<<sa->second<<endl;//��ʾ 1 sas 1 saddds 2 sas
  multimap<int,string>::iterator s2;
  s2=ss.find(1);
  if(s2!=ss.end())
  {
      cout<<s2->second<<endl;//��һ��Ԫ��sas
      s2++;
      cout<<s2->second<<endl;//�ڶ���Ԫ��sadddds
      s2++;
      cout<<s2->second<<endl;//��3��Ԫ��,��Ȼ����sas���²⿴����%ѭ���������ƵĽṹ
  }
  cout<<ss.count(1)<<endl;//2
  cout<<ss.size()<<endl;//3

  return 0;
}


