#include <iostream>           //��������������⺯����ͷ�ļ�
using namespace std;

const int MaxSize=10;    //10ֻ��ʾ���Ե����ݣ����Ը���ʵ��������嶨��
class SeqList
{
public:
   SeqList( ){length=0;}       //�޲ι��캯��������һ���ձ�
   SeqList(int a[ ], int n);       //�вι��캯��
   void Insert(int i, int x);   //�����Ա��е�i��λ�ò���ֵΪx��Ԫ��
   int Delete(int i);        //ɾ�����Ա�ĵ�i��Ԫ��
   int Locate(int x);       //��ֵ���ң������Ա���ֵΪx��Ԫ�����
   void PrintList( );      //�������Ա���������������Ԫ��
   
   void Reverse();		//���� 
   void Adjust();		//��������ż�� 
private:
   int data[MaxSize];      //�������Ԫ�ص�����
   int length;            //���Ա�ĳ���
};

SeqList::SeqList(int a[ ], int n)
{
      if (n>MaxSize) throw "�����Ƿ�";
      for (int i=0; i<n; i++)  
        data[i]=a[i];
      length=n;
}

void SeqList::Insert(int i, int x)
{ 
      if (length>=MaxSize) throw "����";
      if (i<1 || i>length+1) throw "λ�÷Ƿ�";
      for (int j=length; j>=i; j--)
        data[j]=data[j-1];   //ע���j��Ԫ�ش��������±�Ϊj-1��
      data[i-1]=x;
      length++;
}

int SeqList::Delete(int i)
{ 
      if (length==0) throw "����";
      if (i<1 || i>length) throw "λ�÷Ƿ�";
      int x=data[i-1];
      for (int j=i; j<length; j++)
        data[j-1]=data[j];   //ע��˴�j�Ѿ���Ԫ�����ڵ������±�
      length--;
      return x;
}

int SeqList::Locate(int x)
{   
      for (int i=0; i<length; i++)
        if (data[i]==x)  return i+1 ;  //�±�Ϊi��Ԫ�ص���x�����������i+1
      return 0;  //�˳�ѭ����˵������ʧ��
}

void SeqList::PrintList( )
{
  for (int i=0; i<length; i++)
	cout<<data[i]<<"  ";
  cout<<endl;
}

void SeqList::Reverse()
{
	int temp;
	for (int i=0;i<length/2;i++)
	{
		temp=data[i];
		data[i]=data[length-i-1];
		data[length-i-1]=temp;
	}
}


void SeqList::Adjust()
{
	int i=0;
	int j=length-1;
	int temp;
	while (i<j)
	{
		while(data[i]%2!=0)i++;
		while(data[j]%2==0)j--;
		if(i<j)
		{
			temp=data[i];
			data[i]=data[j];
			data[j]=temp;
		}
	}		
}
 

int main( )
{
      int r[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
      SeqList L(r, 10);
      cout<<"ִ�в���ǰ����Ϊ��"<<endl;
      L.PrintList( );              //�������Ԫ��
      L.Reverse();
      cout<<"ִ�����ò���������Ϊ��"<<endl;
      L.PrintList( );              //�������Ԫ��
      L.Adjust();
      cout<<"ִ����ż��������������Ϊ��"<<endl;
      L.PrintList( );              //�������Ԫ��
	return 0;
}
