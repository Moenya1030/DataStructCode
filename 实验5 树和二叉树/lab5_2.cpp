#include <iostream>
using namespace std;

#define max(a,b)    (((a) > (b)) ? (a) : (b))

const int Max = 20;  // 假定树最多有20个结点
struct TNode
{
	char data;	// 假定树的元素类型为char型
	TNode *firstchild, *rightsib;
};

class Tree
{
public:
	Tree( );
	~Tree( ){Release(root);}          //析构函数，释放各结点的存储空间
	void PreOrder( ){PreOrder(root);}
	void PostOrder( ){PostOrder(root);}
	int Depth(){return Depth(root);};
private:
	TNode *root;
	void PreOrder(TNode *bt);
	void PostOrder(TNode *bt);
	void Release(TNode *bt);  // 析构函数的调用
	int Depth(TNode *bt);
};

Tree::Tree( )
{
	TNode *Q[Max] = {NULL}; // TNode型的数组指针
	char ch1 = '#', ch2 = '#';
	int front = -1, rear = -1;
	TNode *p = NULL, *q = NULL;
	
	cout<<"请输入根结点：";
	cin>>ch1;
	p = new TNode; p->data = ch1; 
	p->firstchild = p->rightsib = NULL;
	root = p;								// 建立根结点
	Q[++rear] = p;							// 根结点入队
    
	cout<<"请输入结点对，以空格分隔：";
	fflush(stdin);						        // 清空键盘缓冲区
    ch1 = getchar(); getchar(); ch2 = getchar();// 中间getchar注释掉中间的空格，ch1是父结点，ch2是孩子结点
	while (ch1 != '#' || ch2 != '#')			// 输入结束的条件是有序对（# #）
	{
		p = new TNode; p->data = ch2; 
		p->firstchild = p->rightsib = NULL;
		Q[++rear] = p;			// 入队
		while (front != rear)   // 当队列非空
		{
			q = Q[front + 1];	// 取队头元素，存储为q
			if (q->data != ch1)	// 当队头元素不是有序对的第一个字符
				front++;		// 出队
			else 
			{
				if (q->firstchild == NULL)
					q->firstchild = p;	// 设置结点p是结点q的第一个孩子
				else
				{
					q = q->firstchild;
					while (q->rightsib != NULL) // 查找结点q的最右兄弟
						q = q->rightsib;
					q->rightsib = p;			// 设置结点p为结点q的右兄弟
				}
				break;
			}
		}
		cout<<"请输入结点对，以空格分隔：";
		fflush(stdin);
        ch1 = getchar(); getchar(); ch2 = getchar();
	}
}

void Tree::Release(TNode *bt)
{
	if (bt == NULL)  return;     //递归调用的结束条件
	else
	{
		Release(bt->firstchild);  //后序递归释放bt的第一棵子树  
		Release(bt->rightsib);    //后序递归释放bt的右兄弟子树  
		delete bt;                //释放根结点
	}
}

void Tree::PreOrder(TNode *bt)
{

}

void Tree::PostOrder(TNode *bt)
{

}

int Tree::Depth(TNode *bt)
{

}


int main( )
{
	Tree t1;
	cout<<"前序遍历的结果是：";
	t1.PreOrder();
	cout<<endl;
	cout<<"层序遍历的结果是：";
	t1.PostOrder();
	cout<<endl;
	cout<<"树的深度是："<<t1.Depth()<<endl;
	return 0;
}