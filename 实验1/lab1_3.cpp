#include<iostream>
using namespace std;

void main()
{
	int i,k,a[10]={1,2,3,4,5,6,7,8,9,10};
	cout<<"循环移动前:"<<endl;
	for(i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	
	cout<<"循环移动多少位(0-10):"<<endl;
	cin>>k;
	
	RRotate(a,k);
	
	cout<<"循环移动后:"<<endl;
	for(i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}


