#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class LinkList
{
public:
	LinkList();
	LinkList(int a[], int n);
	~LinkList(){};
	void PrintList();
	void Insert(int i, int x);
public:
	Node *first;
};

LinkList::LinkList()
{
	first=new Node;
	first->next=first; 
}

LinkList::LinkList(int a[], int n)
{
	first=new Node;
	first->next=first;  
	for(int i=0;i<n;i++)
	{
		Node *s=new Node;
		s->data=a[i];
		s->next=first->next;
		first->next=s;
	}
}

void LinkList::PrintList()
{
	Node *p;
	p=first->next;
	while(p!=first)  
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

void LinkList::Insert(int i, int x)
{ 
   Node *p;
   int j;
   p=first; j=0;    //工作指针p初始化
   while (p->next!=first && j<i-1)  
   {
     p=p->next;   //工作指针p后移
     j++;
   }
   if (p->next==first) throw "位置"; 
   else {   
	  Node *s;
      s=new Node; 
	  s->data=x;  //向内存申请一个结点s，其数据域为x
      s->next=p->next;       //将结点s插入到结点p之后
      p->next=s;
   }
}

void merge(Node *first1, Node *first2)
{
	Node *s=first1->next;
	while(s->next != first1)
	{
		s=s->next;
	}
	Node *p=first2->next;
	while (p->next != first2)
	{
		p=p->next;
	}
	s->next=first2->next;
	p->next=first1;
	delete first2;
}

int main()
{
	int a[]={1,2,3};
    LinkList testA(a,3);
	cout<<"循环链表testA为："<<endl;
	testA.PrintList();
	int b[]={4,5,6};
    LinkList testB(b,3);
	cout<<"循环链表testB为："<<endl;
	testB.PrintList();
	cout<<"合并循环链表testA和testB后，testA为："<<endl;
	merge(testA.first, testB.first);
	testA.PrintList();
	getchar();
}