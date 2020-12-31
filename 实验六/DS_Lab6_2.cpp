#include <iostream>
using namespace std;

enum flag {Chirld,Thread};//Chirld=0,Thread=1
struct ThrNode
{
    char data;
    ThrNode *lchild, *rchild;
    flag ltag, rtag;
};

class InThrBiTree
{
public:
    InThrBiTree( );          //构造函数，建立中序线索链表
    ~InThrBiTree( ) {};      //析构函数，释放各结点的存储空间
	void LeverOrder( );		 //层序遍历二叉树
    void Print();            //输出叶子节点
private:
    ThrNode *root;      //指向线索链表的头指针
    ThrNode *Creat(ThrNode *bt); 
    void ThrBiTree(ThrNode *bt, ThrNode *pre); //构造函数调用
};


InThrBiTree::InThrBiTree()
{
	cout<<"请输入创建一棵二叉树的结点数据"<<endl; 
	root=Creat(root);
	ThrNode *pre = new ThrNode;
	ThrBiTree(root,pre);
}

ThrNode *InThrBiTree::Creat(ThrNode *bt)
{
	char ch;
	cin>>ch;
    if (ch=='#') 
		return NULL;
    else
	{ 
	    bt = new ThrNode;       //生成一个结点
		bt->data = ch;
		bt->ltag=Chirld;
		bt->rtag=Chirld;
		bt->lchild = Creat(bt);
		bt->rchild = Creat(bt);
    } 
    return bt;
}   


void InThrBiTree::ThrBiTree(ThrNode *bt, ThrNode *pre)
{
	if(bt == NULL)
		return;
	ThrBiTree(bt->lchild, pre);
	if(bt->lchild == NULL)
	{
		bt->ltag = Thread;
		bt->lchild = pre;
	}
	if(bt->rchild == NULL)
		bt->rtag = Thread;
	if(pre->rtag == Thread)
		pre->rchild = bt;
	pre = bt;
	ThrBiTree(bt->rchild, pre);
}

void InThrBiTree::LeverOrder( )
{
	ThrNode *Q[100];
	ThrNode *q = root;
	int front = -1;
	int rear = -1;
	// ThrNode *p = root;
	if(root == NULL)
		return;
	Q[++rear] = root;
	// while (p->ltag == Chirld && front != rear)
	while(front != rear)
	{
		q = Q[++front];
		cout<<q->data<<"\t";
		if(q->lchild != NULL && q->ltag == Chirld)
			Q[++rear] = q->lchild;
		if(q->rchild != NULL && q->rtag == Chirld)
			Q[++rear] = q->rchild;
	}
}

void InThrBiTree::Print()
{
    ThrNode *Q[100];
	ThrNode *q = root;
	int front = -1;
	int rear = -1;
	if(root == NULL)
		return;
	Q[++rear] = root;
    while(front != rear)
    {
        q = Q[++front];
        if(q->ltag == Thread && q->rtag == Thread)
            cout<<q->data<<"\t";
        if(q->lchild != NULL && q->ltag == Chirld)
			Q[++rear] = q->lchild;
		if(q->rchild != NULL && q->rtag == Chirld)
			Q[++rear] = q->rchild;
    }
}


int main()
{
	cout<<"------创建一棵中序线索二叉树------ "<<endl;
	InThrBiTree T; 
	cout<<"------层序遍历------ "<<endl;
	T.LeverOrder( );
	cout<<endl;
	cout<<"------输出所有叶子节点------ "<<endl;
    T.Print( );
	cout<<endl;
	return 0;
}

