#include<iostream>
using namespace std;

class Node
{
public:
	Node(int x);
	~Node();
	int GetData();
	void SetData(int x);
private:
	int data;
	Node *next;
};

Node::Node(int x)
{
	data=x;
	next=0;
}

Node::~Node()
{

}

int Node::GetData()
{
	return data;
}

void Node::SetData(int x)
{
	data=x;
}

void main()
{
	Node s(3.14);
	Node t(5);
	cout<<s.GetData()<<endl;
	t.SetData(10);
	cout<<t.GetData()<<endl;
}