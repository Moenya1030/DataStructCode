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
    LinkQueue( );          //构造函数，初始化一个空的链队列
    ~LinkQueue( );      //析构函数，释放链队列中各结点的存储空间
    void EnQueue(DataType x);  //将元素x入队
    DataType DeQueue( );       //将队头元素出队
    DataType GetQueue( );     //取链队列的队头元素
    int Empty( );     //判断链队列是否为空
private:
    Node<DataType> *front, *rear;  //队头和队尾指针，分别指向头结点和终端结点
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
	if(rear==front)	throw"下溢";
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
    LinkQueue<int> Q;         //创建模版类的实例 
    if (Q.Empty())
	    cout<<"队列为空"<<endl;
	else
		cout<<"队列非空"<<endl;
	cout<<"元素10和15执行入队操作:"<<endl;
	try
	{
		Q.EnQueue(10);             //入队操作
        Q.EnQueue(15);
	}
	catch (char* wrong)
	{
		cout<<wrong<<endl;;
	}
	cout<<"查看队头元素:"<<endl;
	cout<<Q.GetQueue( )<<endl;     //读队头元素
	cout<<"执行出队操作:"<<endl;  //出队操作
	try
	{
	    Q.DeQueue( );              
	}
	catch (char* wrong)
	{
		cout<<wrong<<endl;
	}
	cout<<"查看队头元素:"<<endl;
	cout<<Q.GetQueue( )<<endl;
}

