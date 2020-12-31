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

//////////////////////////

void main( )
{
	char ch[]={'A','B','C','D','E','F'};
	MGraph<char> MG(ch, 6, 6);
////////////补充2//////////

//////////////////////////
}