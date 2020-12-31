#include <iostream>
#include <stdlib.h>  
#include <time.h>
using namespace std;
const int Max = 10;   

int a[Max + 1] = {0};
void Creat( );

void Creat( )
{
	srand(time(NULL));      
	for (int i = 1; i <= Max; i++)
		a[i] = 1 + rand( ) % Max; 
}

int SeqSearch(int k)
{
	int i=Max;
	a[0]=k;
	while (a[i]!=k)
	{
		i--;
	}
	return i;
}

int main( )
{
    int k;
	Creat( );
	for (int i = 1; i <= Max; i++)
		cout<<a[i]<<"  ";
	cout<<endl;
	k = 1 + rand( ) % Max;
	cout<<"k的值为"<<k<<endl;
	if(SeqSearch(k))
		cout<<"k的位置为"<<SeqSearch(k);
	else
		cout<<"元素"<<k<<"不在序列中";
	return 0;
}