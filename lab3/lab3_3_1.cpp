#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int i,j,n,m,a[1000],temp,len; 
    cin>>n>>m; 
    len = n;
    for (i=0;i<n;i++)
        a[i] = i+1;
    i=0;
    while(n>1)//人数大于1
    {
        i = (i+m-1)%n;//计算需要移动的节点 
        temp = a[i];
        for(j=i;j<n-1;j++)//移动i后面的节点,相当于删除掉这个数组下标 
            a[j]=a[j+1];
        a[j]=temp;//将i放到新数组的末尾 
        n--;
    }
    // reverse(a,a+len);//反转
    cout<<"出列顺序为:"<<endl; 
    for (i=len-1;i>=0;i--)
    // for (i=0;i<len;i++)
        cout<<a[i]<<" ";
    return 0;
}
