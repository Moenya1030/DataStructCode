#include <iostream>
#include <stdlib.h>  
#include <time.h>
#include<algorithm>
using namespace std;
const int Max = 10;   

int a[Max + 1] = {0};
void Creat( );

void Creat( )
{
	srand(time(NULL)); 
	a[0] = 0;
	for (int i = 1; i <= Max; i++)
		a[i] = a[i - 1] + rand() % Max; 
}

int BinSearch(int k)
{
	int mid, low = 1;
	int high = Max;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if(k < a[mid])
			high = mid - 1;
		else if(k > a[mid])
			low = mid + 1;
		else 
			return mid;
	}
	return 0;
}

int main( )
{
    int k;
	Creat( );
	for (int i = 1; i <= Max; i++)
		cout<<a[i]<<"  ";
	cout<<endl;
	k = a[1 + rand( ) % Max];
	// sort(a, a+Max);
	// cout<<"升序排列后为：";
	// for(int i=0; i<Max; i++)
	// 	cout<<a[i]<<" ";
	// cout<<endl;
	cout<<"k的值为"<<k<<endl;
	if(BinSearch(k))
		cout<<"k的位置为"<<BinSearch(k);
	else
		cout<<"元素"<<k<<"不在序列中";
	return 0;
}
