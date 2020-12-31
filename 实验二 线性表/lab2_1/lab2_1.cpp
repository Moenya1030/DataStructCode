#include <iostream>           //��������������⺯����ͷ�ļ�
using namespace std;

////  ����3.  ���Ӷ������͵�֧�� ////

class B
{
	public:
		B(int i=0):data(i) {}
		friend ostream & operator <<(ostream &out,const B &c);
	private:
		int data;
};


const int MaxSize=10;    //10ֻ��ʾ���Ե����ݣ����Ը���ʵ��������嶨��
template <typename DataType>
class SeqList
{
public:
    SeqList( ){length=0;}       //�޲ι��캯��������һ���ձ�
    SeqList(DataType a[ ], int n);       //�вι��캯��
    void Insert(int i, DataType x);   //�����Ա��е�i��λ�ò���ֵΪx��Ԫ��
    DataType Delete(int i);        //ɾ�����Ա�ĵ�i��Ԫ��
    void PrintList( );      //�������Ա���������������Ԫ��
    DataType Locate(int x);      //ɾ��λ��Ϊx��Ԫ��
private:
    DataType data[MaxSize];      //�������Ԫ�ص�����
    int length;            //���Ա�ĳ���
};


template <typename DataType>
SeqList<DataType>::SeqList(DataType a[ ], int n)
{
    if (n>MaxSize) throw "�����Ƿ�";
    for (int i=0; i<n; i++)
        data[i]=a[i];
    length=n;
}

template <typename DataType>
void SeqList<DataType>::Insert(int i, DataType x)
{
    if (length>=MaxSize) throw "����";
    if (i<1 || i>length+1) throw "λ�÷Ƿ�";
    for (int j=length; j>=i; j--)
        data[j]=data[j-1];   //ע���j��Ԫ�ش��������±�Ϊj-1��
    data[i-1]=x;
    length++;
}

template <typename DataType>
DataType SeqList<DataType>::Delete(int i)
{
    if (length==0) throw "����";
    if (i<1 || i>length) throw "λ�÷Ƿ�";
    int x=data[i-1];
    for (int j=i; j<length; j++)
        data[j-1]=data[j];   //ע��˴�j�Ѿ���Ԫ�����ڵ������±�
    length--;
    return x;
}

template <typename DataType>
void SeqList<DataType>::PrintList( )
{
    for (int i=0; i<length; i++)
        cout<<data[i]<<"  ";
    cout<<endl;
}

template <typename DataType>
DataType SeqList<DataType>::Locate(int x)
{
    for (int i=0;i<length;i++)
    {
        if (data[i]==x)
            return i+1;
    }
    return 0;
}

int main( )
{
    int r[5]={1, 2, 3, 4, 5};
    SeqList<int> L(r, 5);
    cout<<"ִ�в������ǰ����Ϊ��"<<endl;
    L.PrintList( );              //�������Ԫ��
    L.Insert(2,3);
    cout<<"ִ�в������������Ϊ��"<<endl;
    L.PrintList( );              //�������Ԫ��
    cout<<"ֵΪ3��Ԫ��λ��Ϊ:";
    cout<<L.Locate(3)<<endl;    //����Ԫ��3���������ڵ�������λ��
    return 0;
/////////////////////////////////////
//// ����3.  ���Ӷ������͵�֧��  ////
    cout<<"֧�������͵�����Ԫ��:";
	B b[3]={B(10),B(20),B(30)};
	SeqList<B> list(b,3);
	list.PrintList();
}

