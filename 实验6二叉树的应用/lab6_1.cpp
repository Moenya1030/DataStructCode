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
    InThrBiTree( );          //���캯��������������������
    ~InThrBiTree( ) {};      //�����������ͷŸ����Ĵ洢�ռ�
	void LeverOrder( );		 //�������������
private:
    ThrNode *root;      //ָ�����������ͷָ��
    ThrNode *Creat(ThrNode *bt); 
    void ThrBiTree(ThrNode *bt, ThrNode *pre); //���캯������
};


InThrBiTree::InThrBiTree()
{
	cout<<"�����봴��һ�ö������Ľ������"<<endl; 
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
	     bt = new ThrNode;       //����һ�����
/////////////////////////////////////////////////////
// ����1

////////////////////////////////////////////////////
    } 
    return bt;
}   


void InThrBiTree::ThrBiTree(ThrNode *bt, ThrNode *pre)
{
/////////////////////////////////////////////////////
// ����2

////////////////////////////////////////////////////
}



void InThrBiTree::LeverOrder( )
{
/////////////////////////////////////////////////////
// ����3

////////////////////////////////////////////////////
}




void main()
{
	cout<<"------����һ����������������------ "<<endl;
	InThrBiTree T; 
	cout<<"------�������------ "<<endl;
	T.LeverOrder( );
	cout<<endl;
	// cout<<"------�������Ҷ�ӽڵ�------ "<<endl;
    // T.Print( );
	// cout<<endl;
}

