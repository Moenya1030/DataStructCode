#include <iostream>
using namespace std;
#include<string>

const int MaxSize = 10;           //图中最多顶点个数
int visited[MaxSize]={0};

struct element
{
	int lowcost, adjvex;
};

template <class DataType>
class MGraph
{
public:
	MGraph(DataType a[ ], int n, int e);    //构造函数，建立具有n个顶点e条边的图
	~MGraph( ) { }                     //析构函数为空
	void DFSTraverse(int v);              //深度优先遍历图
	void BFSTraverse(int v);               //广度优先遍历图
	void Prim(MGraph<DataType> G);
	void Dijkstra(MGraph<DataType> G, int v);
	int MinEdge(element *shortE, int vNum);
private:
    DataType vertex[MaxSize];          //存放图中顶点的数组
    int arc[MaxSize][MaxSize];          //存放图中边的数组
    int vertexNum, arcNum;             //图的顶点数和边数
};

template <class DataType>
MGraph<DataType>::MGraph(DataType a[ ], int n, int e)
{
	int i, j, w=0;
	vertexNum=n; arcNum=e;
	for (i=0; i<vertexNum; i++)
		vertex[i]=a[i];
	for (i=0; i<vertexNum; i++)
        for (j=0; j<vertexNum; j++)
			arc[i][j]=255;
		for (int k=0; k<arcNum; k++)
		{
			cout<<"请输入边的两个顶点的序号：";
			cin>>i;
			cin>>j;
			cout<<"请输入边的权值：";
			cin>>w;
			arc[i][j]=w; arc[j][i]=w;	
		}
}

template <class DataType>
void MGraph<DataType>::DFSTraverse(int v)
{
	cout << vertex[v]; visited[v] = 1;
	for (int j = 0; j < vertexNum; j++)
		if (arc[v][j] > 0 && visited[j]==0) 
			DFSTraverse(j);
}

template <class DataType>
void MGraph<DataType>::BFSTraverse(int v)
{
	int Q[MaxSize];
	int front = -1, rear = -1;   //初始化队列,假设队列采用顺序存储且不会发生溢出
	cout << vertex[v]; visited[v] = 1;  Q[++rear] = v;   //被访问顶点入队
	while (front != rear)                   //当队列非空时
	{
		v = Q[++front];                   //将队头元素出队并送到v中
		for (int j = 0; j < vertexNum; j++)
			if (arc[v][j] > 0 && visited[j] == 0 ) {
				cout << vertex[j]; 
				visited[j] = 1; 
				Q[++rear] = j;
			}
	}
}

template <class DataType>
void MGraph<DataType>::Prim(MGraph<DataType> G)
{
	element shortEdge[MaxSize];
	int k;
	for(int i=1;i<G.vertexNum;i++)		// 初始化辅助数组shortEdge
	{
		shortEdge[i].lowcost=G.arc[0][i];
		shortEdge[i].adjvex=0;			// 从顶点0开始
	}
	shortEdge[0].lowcost=0;				// 将顶点0加入集合U
	for(int i=1; i<G.vertexNum; i++)
	{
		k=MinEdge(shortEdge, G.vertexNum);	// 寻找最短边的邻接点k
		cout<<"("<<shortEdge[k].adjvex<<","<<k<<")"<<shortEdge[k].lowcost<<endl;
		shortEdge[k].lowcost=0;			// 将顶点k加入集合U
		for(int j=1;j<G.vertexNum;j++)	// 调整数组shortEdge
			if(G.arc[k][j]<shortEdge[j].lowcost) {
				shortEdge[j].lowcost=G.arc[k][j];
				shortEdge[j].adjvex=k;
			}
	}
}

template <class DataType>
int MGraph<DataType>::MinEdge(element *shortE, int vNum)
{
	int index = -1;
	for(int v=0;v<vNum;v++)
	{
		if(shortE[v].lowcost>0) {
			index = v;
			break;
		}
	}
	for(int v=v+1; v<vNum; v++)
	{
		if(shortE[v].lowcost>0 && shortE[v].lowcost<shortE[index].lowcost)
			index=v;
	}
	return index;
}

int main( )
{
	char ch[]={'A','B','C','D','E','F'};
	MGraph<char> MG(ch, 6, 9);
	for (int i=0; i<MaxSize; i++)
		visited[i]=0;
	cout<<"深度优先遍历序列是：";
	MG.DFSTraverse(0);
	cout<<endl;
	for (int i=0; i<MaxSize; i++)
		visited[i]=0;
    cout<<"广度优先遍历序列是：";
	MG.BFSTraverse(0);
	cout<<endl;
    cout<<"最小生成树的生成过程为："<<endl;
    MG.Prim(MG);
	cout<<endl;
    return 0;
}