#include <iostream>         //引用输入输出流
using namespace std;

const int StackSize=10;  //10只是示例性的数据，可以根据实际问题具体定义

template <class DataType>       //定义模板类SeqStack
class SeqStack
{
public:
    SeqStack( ) ;            //构造函数，栈的初始化
	~SeqStack( );            //析构函数
    void Push(DataType x);          //将元素x入栈
    DataType Pop( );                //将栈顶元素弹出
    DataType GetTop( );	         //取栈顶元素（并不删除）
	int Empty( );           //判断栈是否为空
private:
    DataType data[StackSize];      //存放栈元素的数组
    int top;                //栈顶指针，指示栈顶元素在数组中的下标
};

template <class DataType>
SeqStack<DataType>::SeqStack( )
{
	top=-1;
}

template <class DataType>
SeqStack<DataType>::~SeqStack( )
{

} 

template <class DataType> 
void SeqStack<DataType>::Push(DataType x)
{
	if(top==StackSize-1)	throw"上溢";
	data[++top]=x;
}

template <class DataType>
DataType SeqStack<DataType>::Pop( )
{ 
	DataType x;
	if(top==-1)	throw"上溢";
	x=data[top--];
	return x;
}

template <class DataType> 
DataType SeqStack<DataType>::GetTop( )
{
	return data[top];
}

template <class DataType> 
int SeqStack<DataType>::Empty( )
{
	if(top==-1)
		return 1;
	else
		return 0;
} 
int main( )
{    
    SeqStack<int> S;      //创建模板类的实例
	if (S.Empty()==1)
		cout<<"栈为空"<<endl;
	else
        cout<<"栈非空"<<endl;
    cout<<"对15和10执行入栈操作"<<endl;
	S.Push(15);
	S.Push(10);   
	cout<<"栈顶元素为:"<<endl;   //取栈顶元素
	cout<<S.GetTop( )<<endl;  
	cout<<"执行一次出栈操作"<<endl;
	S.Pop( );          //执行出栈操作
    cout<<"栈顶元素为:"<<endl;
    cout<<S.GetTop( )<<endl;
	return 0;
}
