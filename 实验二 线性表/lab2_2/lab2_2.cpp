#include <iostream>           //引用输入输出流库函数的头文件
using namespace std;

const int MaxSize=10;    //10只是示例性的数据，可以根据实际问题具体定义
class SeqList
{
public:
   SeqList( ){length=0;}       //无参构造函数，创建一个空表
   SeqList(int a[ ], int n);       //有参构造函数
   void Insert(int i, int x);   //在线性表中第i个位置插入值为x的元素
   int Delete(int i);        //删除线性表的第i个元素
   int Locate(int x);       //按值查找，求线性表中值为x的元素序号
   void PrintList( );      //遍历线性表，按序号依次输出各元素
   
   void Reverse();		//倒置 
   void Adjust();		//左奇数右偶数 
private:
   int data[MaxSize];      //存放数据元素的数组
   int length;            //线性表的长度
};

SeqList::SeqList(int a[ ], int n)
{
      if (n>MaxSize) throw "参数非法";
      for (int i=0; i<n; i++)  
        data[i]=a[i];
      length=n;
}

void SeqList::Insert(int i, int x)
{ 
      if (length>=MaxSize) throw "上溢";
      if (i<1 || i>length+1) throw "位置非法";
      for (int j=length; j>=i; j--)
        data[j]=data[j-1];   //注意第j个元素存在数组下标为j-1处
      data[i-1]=x;
      length++;
}

int SeqList::Delete(int i)
{ 
      if (length==0) throw "下溢";
      if (i<1 || i>length) throw "位置非法";
      int x=data[i-1];
      for (int j=i; j<length; j++)
        data[j-1]=data[j];   //注意此处j已经是元素所在的数组下标
      length--;
      return x;
}

int SeqList::Locate(int x)
{   
      for (int i=0; i<length; i++)
        if (data[i]==x)  return i+1 ;  //下标为i的元素等于x，返回其序号i+1
      return 0;  //退出循环，说明查找失败
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
      cout<<"执行操作前数据为："<<endl;
      L.PrintList( );              //输出所有元素
      L.Reverse();
      cout<<"执行逆置操作后数据为："<<endl;
      L.PrintList( );              //输出所有元素
      L.Adjust();
      cout<<"执行奇偶调整操作后数据为："<<endl;
      L.PrintList( );              //输出所有元素
	return 0;
}
