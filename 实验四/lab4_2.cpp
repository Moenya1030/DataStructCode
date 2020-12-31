#include <iostream>     
using namespace std;

template <class DataType>
struct Node
{
    DataType data;
    Node<DataType> *next;  
};

template <class DataType>
class LinkQueue
{
public:
    LinkQueue( );          //���캯������ʼ��һ���յ�������
    ~LinkQueue( );      //�����������ͷ��������и����Ĵ洢�ռ�
    void EnQueue(DataType x);  //��Ԫ��x���
    DataType DeQueue( );       //����ͷԪ�س���
    DataType GetQueue( );     //ȡ�����еĶ�ͷԪ��
    int Empty( );     //�ж��������Ƿ�Ϊ��
private:
    Node<DataType> *front, *rear;  //��ͷ�Ͷ�βָ�룬�ֱ�ָ��ͷ�����ն˽��
};

template <class DataType>
LinkQueue<DataType>::LinkQueue( )
{
	Node<DataType> *s=NULL;
	s=new Node<DataType>;
	s->next=NULL;
	front=s;
	rear=s;
	
}

template <class DataType>
LinkQueue<DataType>::~LinkQueue( )
{
	Node<DataType> *p=front;
	while(front!=rear)
	{
		front=front->next;
		delete p;
		p=rear;
	}
}

template <class DataType> 
void LinkQueue<DataType>::EnQueue(DataType x)
{
	Node<DataType> *s=NULL;
	s=new Node<DataType>;
	s->data=x;
	s->next=NULL;
	rear->next=s;
	rear=s;
}

template <class DataType>
DataType LinkQueue<DataType>::DeQueue()
{ 
	DataType x;
	Node<DataType> *p=NULL;
	if(rear==front)	throw"����";
	p=front->next;
	x=p->data;
	front->next=p->next;
	if(p->next==NULL)
		rear=front;
	delete p;
	return x;
}

template <class DataType> 
DataType LinkQueue<DataType>::GetQueue()
{
	return front->next->data;
}

template <class DataType> 
int LinkQueue<DataType>::Empty( )
{
	if(front==rear)
		return 1;
	return 0;
}
int main()
{
    LinkQueue<int> Q;         //����ģ�����ʵ�� 
    if (Q.Empty())
	    cout<<"����Ϊ��"<<endl;
	else
		cout<<"���зǿ�"<<endl;
	cout<<"Ԫ��10��15ִ����Ӳ���:"<<endl;
	try
	{
		Q.EnQueue(10);             //��Ӳ���
        Q.EnQueue(15);
	}
	catch (char* wrong)
	{
		cout<<wrong<<endl;;
	}
	cout<<"�鿴��ͷԪ��:"<<endl;
	cout<<Q.GetQueue( )<<endl;     //����ͷԪ��
	cout<<"ִ�г��Ӳ���:"<<endl;  //���Ӳ���
	try
	{
	    Q.DeQueue( );              
	}
	catch (char* wrong)
	{
		cout<<wrong<<endl;
	}
	cout<<"�鿴��ͷԪ��:"<<endl;
	cout<<Q.GetQueue( )<<endl;
}

