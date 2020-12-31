#include<iostream>
using namespace std;

void RRotate(int a[],int k);

int main()
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
	return 0;
}

void RRotate(int a[],int k)
{
	int temp=0;

	for (int i=0;i<k/2;i++)
	{
		temp=a[i];
		a[i]=a[k-i-1];
		a[k-i-1]=temp;
	} //将前k个元素反序 
	
	for (int i=k,j=1;i<5+k/2;i++,j++)
	{
		temp=a[i];
		a[i]=a[10-j];
		a[10-j]=temp;
	}//将后10-k个元素反序 
	
	for (int i=0;i<5;i++)
	{
		temp=a[i];
		a[i]=a[9-i];
		a[9-i]=temp;
	}//将数组反序
}
