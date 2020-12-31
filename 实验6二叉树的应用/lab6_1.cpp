#include <iostream>
using namespace std;

enum flag {Chirld,Thread};
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
    if (ch=='#') return NULL;
    else{ 
	     bt = new ThrNode;       //生成一个结点
/////////////////////////////////////////////////////
// 补充1

////////////////////////////////////////////////////
    } 
    return bt;
}   


void InThrBiTree::ThrBiTree(ThrNode *bt, ThrNode *pre)
{
/////////////////////////////////////////////////////
// 补充2

////////////////////////////////////////////////////
}



void InThrBiTree::LeverOrder( )
{
/////////////////////////////////////////////////////
// 补充3

////////////////////////////////////////////////////
}




void main()
{
	cout<<"------创建一棵中序线索二叉树------ "<<endl;
	InThrBiTree T; 
	cout<<"------层序遍历------ "<<endl;
	T.LeverOrder( );
	cout<<endl;
	// cout<<"------输出所有叶子节点------ "<<endl;
    // T.Print( );
	// cout<<endl;
}

