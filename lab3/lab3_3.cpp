//错误代码
#include <iostream>
#include <string.h>
using namespace std;

int arrCount(int arr[], int n)//统计0的个数
{
    int count = 0;
    for (int i=0; i<n; i++)
    {
        if (arr[i] == 0)
            count++;
    }
    return count;
}

int deleteArr(int arr[], int n, int i)//删掉第n个元素
{
    int x;
    x=arr[i-1];
    for (int j=i; j<n; j++)
    {
        arr[j-1]=arr[j];
    }
    n--;
    return x;
}

int main()
{
    int n;
    int m;
    cin>>n>>m;
    int count=0;
    int num=0;
    int* arr = new int[n+1];
    int* pop = new int[n];
    memset(pop,0,sizeof(pop)+32);
    for (int i=0; i<n+1; i++)
    {
        arr[i] = i+1;
    }//默认编号从1-n
    while (arrCount(pop, n) >= m)//当pop[]中为0的个数小于m退出
    {
        count += m;
        if (count >= n)
        {
            int count1 = count%n;
            pop[num]=deleteArr(arr, n, count1);
            count = count1;
        }
        else
        {
            pop[num]=deleteArr(arr, n, count);
        }
        num++;  
    }

    for (int i=0; i<n; i++)
    {
        if (pop[i] != 0)
            cout<<"出列的顺序为"<<pop[i]<<" ";
    }
    return 0;
}