#include<iostream>         //引入输入输出流
#include <time.h>
#include <stdlib.h>

using namespace std;
const int Max = 11;

int ht[Max] = {0};

int h(int k)
{
	return k % 11;
}

void insert(int k)
{
	int mod = h(k);
	if(ht[mod] == 0)
	{
		ht[mod]=k;
		cout<<"插入元素"<<k<<" "<<"插入位置为"<<mod<<endl;
	}
	else
		insert(h(k)+1);
	
}

int hashSearch(int k)
{
	int i, j = h(k);
	i = j;
	while (ht[i] != 0)
	{
		if(ht[i] == k)
			return i;
		else
			i = (i + 1) % Max;
	}
	return -1;
}

int main()
{
	int s[9]={47, 7, 29, 11, 16, 92, 22, 8, 3};
	
	int temp, i = 0, index = 0, count = 0;
	for(int i=0; i<Max; i++)
	{
		insert(s[i]);
	}
	cout<<"散列表中的元素为:"<<endl;
	for(i = 0; i < 9; i++)
		cout<<ht[i]<<"   ";
	cout<<endl;
	srand(time(NULL));
	temp = s[rand() % 9];
	cout<<"查找元素 "<<temp<<endl;
	if(hashSearch(temp) != -1)
		cout<<temp<<"的位置为"<<hashSearch(temp)+1;
	else
		cout<<"查找失败";
	return 0;
}
