#include <iostream>
using namespace std; 

//KMP算法是有Knuth、Morris、Pratt提出的

void getNext(const char* pattern,int next[]) 
{ 
	next[0]=-1; 
	int j=0,k=-1; 
	while(pattern[j]!='\0') 
	{ 
		if(k==-1 || pattern[j]==pattern[k])
		{
			++j;
			++k;
			next[j]=k;
		}
		else
			k=next[k];
	} 
}


int KMP(const char *Text,const char* Pattern) //const 表示函数内部不会改变这个参数的值。
{ 
	if( !Text||!Pattern||Pattern[0]=='\0'||Text[0]=='\0')//
		return -1; //空指针或空串，返回-1。
	int len=0; 
	const char *c=Pattern; 
	while(*c++!='\0') //移动指针比移动下标快。
	{ 
		++len; //字符串长度。
	} 
	int *next=new int[len+1];
	getNext(Pattern,next); //求Pattern的next函数值

	cout<<"next数组:";
	for(int t=0;t<len;t++)
		cout<<next[t]<<" ";
	cout<<endl;
	
	int index=0,i=0,j=0; 	
	while(Text[i]!='\0'&&Pattern[j]!='\0') 
	{
		if(Text[i]== Pattern[j]) {
			++i; // 继续比较后继字符
			++j;
		}
		else {
			index+=j-next[j]; 
			if(next[j]!=-1)
				j=next[j]; // 模式串向右移动
			else {
				j=0;
				++i;
			}
		}
	}//while  
	delete []next;
	if(Pattern[j]=='\0')
		return index+1;// 匹配成功
	else
		return -1;       
}

int main() //ababc 
{ 
    char *text="ababaababcb"; 
    char *pattern="ababc"; 
	cout<<"主串是"<<text<<endl;
	cout<<"子串是"<<pattern<<endl;
    int index=KMP(text,pattern); 
	cout<<"匹配的位置是"<<index<<endl;
	return 0;
}
