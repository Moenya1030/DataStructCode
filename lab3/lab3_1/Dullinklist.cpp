// 锟斤拷锟轿拷锟斤拷锟斤拷娲拷峁�

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *prior,*next;
};

class LinkList
{
public:
	LinkList();
	LinkList(int a[], int n);
	~LinkList();
	void Insert(int i, int x);
	void PrintList();
private:
	Node *first;
	Node *prior;
};

LinkList::LinkList()
{
	prior=new Node;
	first=new Node;
	prior=NULL;
	first->next=NULL;
}

LinkList::LinkList(int a[], int n)//尾插法
{
	first=new Node;
	prior=new Node;
	Node *r=first;
	Node *p=prior;
	r->prior=p;
	for(int i=0;i<n;i++)
	{
		Node *s=new Node;
		s->data=a[i];
		r->next=s;
		r->next->prior=p;
		r=s;
	}
	r->next=NULL;
}

LinkList::~LinkList()
{
	while(first!=NULL)
	{
		Node *q=first;
		first=first->next;
		delete q;
	}
}

void LinkList::Insert(int i, int x)
{ 
   Node *p;
   int j;
   p=first; j=0;    //宸ヤ綔鎸囬拡p鍒濆鍖�
   while (p!=NULL && j<i-1)
   {
     p=p->next;   //宸ヤ綔鎸囬拡p鍚庣Щ
     j++;
   }
   if (p==NULL) throw "浣嶇疆";
   else { 
	  Node *s;
      s=new Node;  
	  s->data=x;   //鍚戝唴瀛樼敵璇蜂竴涓粨鐐箂锛屽叾鏁版嵁鍩熶负x
      s->prior=p;
	  s->next=p->next;       //灏嗙粨鐐箂鎻掑叆鍒扮粨鐐筽涔嬪悗
	  p->next->prior=s;
	  p->next=s;
   }
}

void LinkList::PrintList()
{
	Node *p=new Node;
	p=first->next;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

int main()
{
	int a[]={1,2,3,4,5};
    LinkList test(a,5);
	test.PrintList();
	test.Insert(2,6);
	test.PrintList();

	getchar();
}