#include <iostream>
using namespace std;

const int MaxSize=10;            //图的最大顶点数
int visited[MaxSize] = {0};
int indegree[MaxSize];

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
private:
	VertexNode<DataType> adjlist[MaxSize];  //存放顶点表的数组
	int vertexNum, arcNum;					//图的顶点数和边数
};

////////////补充1//////////

//////////////////////////

void main()
{
	char ch[ ]={'A','B','C','D','E'};
	int i;
	ALGraph<char> ALG(ch, 5, 7);
////////////补充2//////////

//////////////////////////
} 
