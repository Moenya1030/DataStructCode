#include<iostream>
using namespace std;

void RRotate(int a[],int k);

int main()
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
	} //��ǰk��Ԫ�ط��� 
	
	for (int i=k,j=1;i<5+k/2;i++,j++)
	{
		temp=a[i];
		a[i]=a[10-j];
		a[10-j]=temp;
	}//����10-k��Ԫ�ط��� 
	
	for (int i=0;i<5;i++)
	{
		temp=a[i];
		a[i]=a[9-i];
		a[9-i]=temp;
	}//�����鷴��
}
