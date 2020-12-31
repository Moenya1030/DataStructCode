#include <iostream>
using namespace std;

struct BiNode   //�������Ľ��ṹ
{
	char data;       
	BiNode *lchild, *rchild;
};

class BiTree
{
public:
	BiTree( ){root = Creat(root);}			//���캯��������һ�ö�����
	~BiTree( ){Release(root);}			//�����������ͷŸ����Ĵ洢�ռ�
	void PreOrder( ){PreOrder(root);}		//ǰ�����������
	void InOrder( ){InOrder(root);}			//�������������
	void PostOrder( ){PostOrder(root);}		//�������������
	void LeverOrder( );				//�������������
	int leafNode();
private:
	BiNode *root;                           //ָ�������ͷָ��
	BiNode *Creat(BiNode *bt);				//���캯������
	void Release(BiNode *bt);				//������������
	void PreOrder(BiNode *bt);              //ǰ�������������
	void InOrder(BiNode *bt);               //���������������
	void PostOrder(BiNode *bt);             //���������������
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
	cout<<"�����봴��һ�ö������Ľڵ����ݣ�"<<endl;
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

int BiTree::leafNode()
{
	BiNode *bt;
	int count = 0;
	while(bt->lchild->data != '#')
	{
		if(bt->rchild->data == '#' && bt->lchild->data == '#')
			count++;
		bt = bt->lchild;
	}	
	while(bt->rchild->data != '#')
	{
		if(bt->rchild->data == '#' && bt->lchild->data == '#')
			count++;
		bt = bt->rchild;
	}
	
//	PreOrder(bt->lchild);
//	if(bt->rchild == '#' && bt->lchild == '#')
//		count++;
//	PreOrder(bt->rchild);
//	if(bt->rchild == NULL && bt->lchild == NULL)
//		count++;
	return count;
}

int main()
{	
	BiTree T; //����һ����
	cout<<"------ǰ�����------ "<<endl;
	T.PreOrder( );
	cout<<endl;
	cout<<"------�������------ "<<endl;
	T.InOrder( );
	cout<<endl;
	cout<<"------�������------ "<<endl;
	T.PostOrder( );
	cout<<endl;
	cout<<"------�������------ "<<endl;
	T.LeverOrder();
	cout<<"Ҷ�ӽڵ�ĸ���Ϊ��"<<T.leafNode();
	cout<<endl;
	return 0;
}
