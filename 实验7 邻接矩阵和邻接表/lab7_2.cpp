#include <iostream>
using namespace std;

const int MaxSize=10;            //ͼ����󶥵���
int visited[MaxSize] = {0};
int indegree[MaxSize];

struct ArcNode   //����߱���
{
	int adjvex;  //�ڽӵ���
	ArcNode *next;
};
template <class DataType>
struct VertexNode   //���嶥�����
{
	DataType vertex;
	ArcNode *firstedge;
};

template <class DataType>
class ALGraph
{
public:
	ALGraph(DataType a[ ], int n, int e);   //���캯��������һ����n������e���ߵ�ͼ
	~ALGraph( );							//�����������ͷ��ڽӱ��и��߱���Ĵ洢�ռ�
	void DFSTraverse(int v);				//������ȱ���ͼ
	void BFSTraverse(int v);				//������ȱ���ͼ
private:
	VertexNode<DataType> adjlist[MaxSize];  //��Ŷ���������
	int vertexNum, arcNum;					//ͼ�Ķ������ͱ���
};

////////////����1//////////

//////////////////////////

void main()
{
	char ch[ ]={'A','B','C','D','E'};
	int i;
	ALGraph<char> ALG(ch, 5, 7);
////////////����2//////////

//////////////////////////
} 
