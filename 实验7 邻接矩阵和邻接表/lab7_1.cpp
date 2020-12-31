#include <iostream>
using namespace std;

const int MaxSize = 10;           //ͼ����ඥ�����
int visited[MaxSize]={0};

template <class DataType>
class MGraph
{
public:
	MGraph(DataType a[ ], int n, int e);    //���캯������������n������e���ߵ�ͼ
	~MGraph( ) { }                     //��������Ϊ��
	void DFSTraverse(int v);              //������ȱ���ͼ
	void BFSTraverse(int v);               //������ȱ���ͼ
private:
    DataType vertex[MaxSize];          //���ͼ�ж��������
    int arc[MaxSize][MaxSize];          //���ͼ�бߵ�����
    int vertexNum, arcNum;             //ͼ�Ķ������ͱ���
};

////////////����1//////////

//////////////////////////

void main( )
{
	char ch[]={'A','B','C','D','E','F'};
	MGraph<char> MG(ch, 6, 6);
////////////����2//////////

//////////////////////////
}