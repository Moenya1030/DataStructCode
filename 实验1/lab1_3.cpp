#include<iostream>
using namespace std;

void main()
{
	int i,k,a[10]={1,2,3,4,5,6,7,8,9,10};
	cout<<"ѭ���ƶ�ǰ:"<<endl;
	for(i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	
	cout<<"ѭ���ƶ�����λ(0-10):"<<endl;
	cin>>k;
	
	RRotate(a,k);
	
	cout<<"ѭ���ƶ���:"<<endl;
	for(i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}


