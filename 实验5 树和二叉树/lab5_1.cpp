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
private:
	BiNode *root;                           //ָ�������ͷָ��
	BiNode *Creat(BiNode *bt);				//���캯������
	void Release(BiNode *bt);				//������������
	void PreOrder(BiNode *bt);              //ǰ�������������
	void InOrder(BiNode *bt);               //���������������
	void PostOrder(BiNode *bt);             //���������������
};


void main()
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
	cout<<endl;
	system("pause");
}