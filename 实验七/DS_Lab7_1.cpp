#include <iostream>
using namespace std;

const int MaxSize = 10;           //图中最多顶点个数
int visited[MaxSize]={0};

template <class DataType>
class MGraph
{
public:
	MGraph(DataType a[ ], int n, int e);    //构造函数，建立具有n个顶点e条边的图
	~MGraph( ) { }                     //析构函数为空
	void DFSTraverse(int v);              //深度优先遍历图
	void BFSTraverse(int v);               //广度优先遍历图
private:
    DataType vertex[MaxSize];          //存放图中顶点的数组
    int arc[MaxSize][MaxSize];          //存放图中边的数组
    int vertexNum, arcNum;             //图的顶点数和边数
};

////////////补充1//////////
template <typename DataType>
MGraph<DataType>::MGraph(DataType a[], int n, int e)
{
	int i, j, k;
	vertexNum = n;
	arcNum = e;
	for(i = 0; i < vertexNum; i++)
	{
		vertex[i] = a[i];
	}
	for(i = 0; i < vertexNum; i++)
	{
		for(j = 0; j < vertexNum; j++)
			{
				arc[i][j] = 0;
			}
	}
	for(k = 0; k < arcNum; k++)
	{
		cout<<"请输入边的两个顶点的序号：";
		cin>>i>>j;
		arc[i][j] = 1;
		arc[j][i] = 1;
	}
}

template <typename DataType>
void MGraph<DataType>::DFSTraverse(int v)
{
	cout<<vertex[v];
	visited[v] = 1;
	for(int j = 0; j < vertexNum; j++)
	{
		if(arc[v][j] == 1 && visited[j] == 0)
		{
			DFSTraverse(j);
		}
	}
}

template <typename DataType>
void MGraph<DataType>::BFSTraverse(int v)
{
	cout<<vertex[v];
	visited[v] = 1;
	int w, j, Q[MaxSize];
	int front = -1;
	int rear = -1;
	Q[++rear] = v;
	while(front != rear)
	{
		w = Q[++front];
		for(j = 0; j < vertexNum; j++)
		{
			if(arc[w][j] == 1 && visited[j] == 0)
			{
				cout<<vertex[j];
				visited[j] = 1;
				Q[++rear] = j;
			}
		}
	}
}
//////////////////////////

int main( )
{
	char ch[]={'A','B','C','D','E','F'};
	MGraph<char> MG(ch, 6, 6);
////////////补充2//////////
	cout<<"深度优先遍历序列是：";
	MG.DFSTraverse(0);
	cout<<endl;
	for(int i = 0; i < MaxSize; i++)
		visited[i] = 0;
	// memset(visited, 0, sizeof(visited));
	cout<<"广度优先遍历序列是：";
	MG.BFSTraverse(0);
//////////////////////////
	return 0;
}