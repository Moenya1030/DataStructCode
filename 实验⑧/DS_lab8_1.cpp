#include <iostream>
using namespace std;

const int MaxSize=10;            //图的最大顶点数
int visited[MaxSize] = {0};

struct ArcNode   //定义边表结点
{
	int adjvex;  //邻接点域
	ArcNode *next;
};

template <class DataType>
struct VertexNode   //定义顶点表结点
{
	DataType vertex;
	int in;
	ArcNode *firstedge;
};

template <class DataType>
class ALGraph
{
public:
	ALGraph(DataType a[ ], int n, int e);   //构造函数，建立一个有n个顶点e条边的图
	~ALGraph( );							//析构函数，释放邻接表中各边表结点的存储空间
	void DFSTraverse(int v);				//深度优先遍历图
	void BFSTraverse(int v);				//广度优先遍历图
	void CountIn();
	void TopSort();
private:
	VertexNode<DataType> adjlist[MaxSize];  //存放顶点表的数组
	int vertexNum, arcNum;					//图的顶点数和边数
};

template <class DataType>
void ALGraph<DataType>::CountIn()
{
	ArcNode *p;
	for(int i=0;i<vertexNum;i++)
		adjlist[i].in=0;
	for (int i=0; i<vertexNum; i++)
	{
		p=adjlist[i].firstedge;
		while (p!=NULL)
		{
			adjlist[p->adjvex].in++;
			p=p->next;
		}
	}
}

template <class DataType>
void ALGraph<DataType>::TopSort()
{
	int i, j ,k,count = 0;
	int S[MaxSize],top=-1;
	ArcNode *p = nullptr;
	
	for(i = 0; i < vertexNum; i++)
	{
		if(adjlist[i].in == 0)
		{
			S[++top]=i;
		}
	}
	while (top != -1)
	{
		j = S[top--];
		cout<<adjlist[j].firstedge;
		while (p!=NULL)
		{
			k = p->adjvex;
			adjlist[k].in--;
			if (adjlist[k].in == 0)
			{
				S[++top] = k;
				p = p->next;
			}
		}
		if(count < vertexNum)
			cout<<"有回路";
	}
	
}

template <class DataType>
ALGraph<DataType>::ALGraph(DataType a[ ], int n, int e)
{
	ArcNode *s;
	int i, j, k;
	vertexNum = n; arcNum = e;
	for (i = 0; i < vertexNum; i++)			//输入顶点信息，初始化顶点表
	{ 
		adjlist[i].vertex = a[i];
		adjlist[i].firstedge = NULL;      
	}
	for (k = 0; k < arcNum; k++)			//依次输入每一条边
	{ 
		cout<<"请输入边的两个顶点的序号：";
		cin >> i >> j;						//输入边所依附的两个顶点的编号
		s = new ArcNode; s->adjvex = j;		//生成一个边表结点s
		s->next = adjlist[i].firstedge;     //将结点s插入到第i个边表的表头
		adjlist[i].firstedge = s;
	}
}

template <class DataType>
ALGraph<DataType>::~ALGraph( )
{
	ArcNode *p;
	for(int i=0; i<vertexNum; i++)
	{
		p=adjlist[i].firstedge;
		while(p!=NULL)                       //循环删除
		{
			adjlist[i].firstedge=p->next;
			delete p;                        //释放结点空间
			p=adjlist[i].firstedge;
		}
	}
}

template <class DataType>
void ALGraph<DataType>::DFSTraverse(int v)
{
	ArcNode *p; int j;
	cout<<adjlist[v].vertex;
	visited[v] = 1;
    p = adjlist[v].firstedge;				//工作指针p指向顶点v的边表
	while (p != NULL)						//依次搜索顶点v的邻接点j
	{
		j = p->adjvex;
		if (visited[j]==0) DFSTraverse(j);
		p = p->next;           
	}
}

template <class DataType>
void ALGraph<DataType>::BFSTraverse(int v)
{
	int front =-1, rear = -1;				//初始化队列, 假设队列采用顺序存储且不会发生溢出
	int Q[MaxSize];
    ArcNode *p;
	cout<<adjlist[v].vertex; visited[v] = 1; Q[++rear] = v;   //被访问顶点入队
	while (front != rear)					//当队列非空时
	{
		v = Q[++front];
		p = adjlist[v].firstedge;			//工作指针p指向顶点v的边表
		while (p != NULL) 
		{
			int j = p->adjvex;
			if (visited[j] == 0) {
				cout<<adjlist[j].vertex; visited[j]=1;Q[++rear]=j;
			}
			p=p->next;
		}
	}
}

int main()
{
	char ch[ ]={'A','B','C','D','E','F'};
	int i;
	ALGraph<char> ALG(ch, 6, 9);
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout<<"从顶点"<<ch[0]<<"进行深度优先遍历序列是：";
	ALG.DFSTraverse(0);
	cout<<endl;
    for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout<<"从顶点"<<ch[2]<<"进行广度优先遍历序列是：";
	ALG.BFSTraverse(2);
	cout<<endl;
	cout<<"其拓扑排序是：";
	ALG.TopSort();
	cout<<endl;
	return 0;
} 
