#include <iostream>
using namespace std;

int ret = 0;

struct BiNode   //二叉树的结点结构
{
	char data;       
	BiNode *lchild, *rchild;
};

class BiTree
{
public:
	BiTree( ){root = Creat(root);}			//构造函数，建立一棵二叉树
	~BiTree( ){Release(root);}			//析构函数，释放各结点的存储空间
	void PreOrder( ){PreOrder(root);}		//前序遍历二叉树
	void InOrder( ){InOrder(root);}			//中序遍历二叉树
	void PostOrder( ){PostOrder(root);}		//后序遍历二叉树
	int leafNode(){leafNode(root); return ret;}
	void LeverOrder( );				//层序遍历二叉树
	
private:
	BiNode *root;                           //指向根结点的头指针
	BiNode *Creat(BiNode *bt);				//构造函数调用
	void Release(BiNode *bt);				//析构函数调用
	void PreOrder(BiNode *bt);              //前序遍历函数调用
	void InOrder(BiNode *bt);               //中序遍历函数调用
	void PostOrder(BiNode *bt);             //后序遍历函数调用
	int leafNode(BiNode *bt);
};

void BiTree::PreOrder(BiNode *bt)
{
	if (bt == NULL)
		return;
	else
	{
		cout<<bt->data<<"\t";
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

void BiTree::InOrder(BiNode *bt)
{
	if (bt == NULL)
		return;
	else
	{
		InOrder(bt->lchild);
		cout<<bt->data<<"\t";
		InOrder(bt->rchild);
	}
}

void BiTree::PostOrder(BiNode *bt)
{
	if (bt == NULL)
		return;
	else
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout<<bt->data<<"\t";
	}
}

void BiTree::LeverOrder()
{
	BiNode *Q[100], *q = NULL;
	int front = -1, rear = -1;
	if(root == NULL)
		return;
	Q[++rear] = root;
	while(front != rear)
	{
		q= Q[++front];
		cout<<q->data<<"\t";
		if(q->lchild != NULL)
			Q[++rear] = q->lchild;
		if(q->rchild != NULL)
			Q[++rear] = q->rchild;
	}
}

BiNode *BiTree::Creat(BiNode *bt)
{
	
	char ch;
	cout<<"请输入创建一棵二叉树的节点数据："<<endl;
	cin>>ch;
	if(ch == '#')
		bt = NULL;
	else
	{
		bt = new BiNode;
		bt->data = ch;
		bt->lchild = Creat(bt);
		bt->rchild = Creat(bt);
	}
	return bt;
}

void BiTree::Release(BiNode *bt)
{
	if(bt == NULL)
		return;
	else
	{
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}

int BiTree::leafNode(BiNode *bt)
{
	if(bt == NULL) return 0;
	leafNode(bt->rchild);
	leafNode(bt->lchild);
	if(bt->lchild == NULL && bt->rchild == NULL)
		ret++;
	return ret == 0 ? 1 : ret;
	// while(bt->lchild->data != '#')
	// {
	// 	if(bt->rchild->data == '#' && bt->lchild->data == '#')
	// 		count++;
	// 	bt = bt->lchild;
	// }	
	// while(bt->rchild->data != '#')
	// {
	// 	if(bt->rchild->data == '#' && bt->lchild->data == '#')
	// 		count++;
	// 	bt = bt->rchild;
	// }
	
//	PreOrder(bt->lchild);
//	if(bt->rchild == '#' && bt->lchild == '#')
//		count++;
//	PreOrder(bt->rchild);
//	if(bt->rchild == NULL && bt->lchild == NULL)
//		count++;
}

int main()
{	
	BiTree T; //创建一棵树
	cout<<"------前序遍历------ "<<endl;
	T.PreOrder( );
	cout<<endl;
	cout<<"------中序遍历------ "<<endl;
	T.InOrder( );
	cout<<endl;
	cout<<"------后序遍历------ "<<endl;
	T.PostOrder( );
	cout<<endl;
	cout<<"------层序遍历------ "<<endl;
	T.LeverOrder();
	cout<<endl<<"递归求叶子节点的个数为："<<T.leafNode();
	cout<<endl;
	return 0;
}
