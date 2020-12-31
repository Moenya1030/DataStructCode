#include <iostream>
using namespace std;

const int MaxSize=10;            //图的最大顶点数
int visited[MaxSize] = {0};
int indegree[MaxSize] = {0};

struct ArcNode   //定义边表结点
{
	int adjvex;  //邻接点域
	ArcNode *next;
};

template <class DataType>
struct VertexNode   //定义顶点表结点
{
	DataType vertex;
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
    void inDegree(int v);                        //求有向图G中每个顶点的入度
private:
	VertexNode<DataType> adjlist[MaxSize];  //存放顶点表的数组
	int vertexNum, arcNum;					//图的顶点数和边数
};

////////////补充1//////////

template<typename DataType>
ALGraph<DataType>::ALGraph(DataType a[ ], int n, int e)
{
	int i, j, k;
	ArcNode *s = NULL;
	vertexNum = n;
	arcNum = e;
	for(i = 0; i < n; i++)
	{
		adjlist[i].vertex = a[i];
		adjlist[i].firstedge = NULL;
	}
	for(k = 0; k < e; k++)
	{
		cout<<"请输入边的两个顶点的序号：";
		cin>>i>>j;
		s = new ArcNode;
		s->adjvex = j;
		s->next = adjlist[i].firstedge;
		adjlist[i].firstedge = s;
	}
}

template<typename DataType>
ALGraph<DataType>::~ALGraph()
{
	ArcNode *p = NULL;
	ArcNode *q = NULL;
	for(int i = 0; i < vertexNum; i++)
	{
		p = adjlist[i].firstedge;
		q = adjlist[i].firstedge;
		while (p != NULL)
		{
			p = p->next;
			delete q;
			q = p;
		}
	}
}

template<typename DataType>
void ALGraph<DataType>::DFSTraverse(int v)
{
	int j;
	ArcNode *p = nullptr;
	cout<<adjlist[v].vertex;
	visited[v] = 1;
	p = adjlist[v].firstedge;
	while (p != nullptr)
	{
		j = p->adjvex;
		if(visited[j] == 0)
			DFSTraverse(j);
		p = p->next;
	}
}


template<typename DataType>
void ALGraph<DataType>::BFSTraverse(int v)
{
	int w, j, Q[MaxSize];
	int front = -1;
	int rear = -1;
	ArcNode *p = nullptr;
	cout<<adjlist[v].vertex;
	visited[v] = 1;
	Q[++rear] = v;
	while (front != rear)
	{
		w = Q[++front];
		p = adjlist[w].firstedge;
		while (p != nullptr)
		{
			j = p->adjvex;
			if(visited[j] == 0)
			{
				cout<<adjlist[j].vertex;
				visited[j] = 1;
				Q[++rear] = j;
			}
			p = p->next;
		}
	}
}

//顶点的入度等于所有出边表中以顶点i为邻接点的结点个数
template<typename DataType>
void ALGraph<DataType>::inDegree(int v)
{
    int n = 0;
    ArcNode *p;
    // if(adjlist[v].firstedge->next != NULL)
    p=adjlist[v].firstedge;
    while (p != NULL)
    {
        //indegree[p->next->adjvex]++;
        n++;
        p = p->next;
    }
    cout<<"第"<<v+1<<"个顶点的入度为"<<n<<endl;
}

// template<typename DataType>
// void ALGraph<DataType>::inDegree(int v)
// {
//     int n = 0;
//     ArcNode *p;
//     p=adjlist[v].firstedge;
//     while (p != NULL)
//     {
//         // indegree[p->next->adjvex]++;
//         n++;
//         p = p->next;
//     }
//     indegree[v] = n; 
//     // cout<<"第"<<v<<"个顶点的入度为"<<n<<endl;
// }
// template<typename DataType>
// void ALGraph<DataType>::inDegree(int v)
// {
//     int j;
// 	ArcNode *p = nullptr;
// 	cout<<adjlist[v].vertex;
// 	visited[v] = 1;
// 	p = adjlist[v].firstedge;
// 	while (p != nullptr)
// 	{
// 		j = p->adjvex;
//         indegree[j]++;
// 		if(visited[j] == 0)
// 			DFSTraverse(j);
// 		p = p->next;
// 	}
// }
//////////////////////////

int main()
{
	char ch[ ]={'A','B','C','D','E'};
	int i;
	ALGraph<char> ALG(ch, 5, 7);
////////////补充2//////////

	cout<<"深度优先遍历序列是：";
	ALG.DFSTraverse(0);
	cout<<endl;
	for(int i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout<<"广度优先遍历序列是：";
	ALG.BFSTraverse(0);
    cout<<endl;
    // for (int i = 0; i < MaxSize; i++)
    // {
    //     ALG.indegree(i);
    // }
    // ALG.inDegree(0);
    for(int i = 0; i < 5 ; i++)
    {
        ALG.inDegree(i);
        // cout<<"第"<<i<<"个顶点的入度是"<<indegree[i]<<endl;
    }
    
//////////////////////////
	return 0;
} 
