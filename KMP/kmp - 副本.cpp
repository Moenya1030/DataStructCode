#include <iostream>
using namespace std; 

//KMP�㷨����Knuth��Morris��Pratt�����

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


int KMP(const char *Text,const char* Pattern) //const ��ʾ�����ڲ�����ı����������ֵ��
{ 
	if( !Text||!Pattern||Pattern[0]=='\0'||Text[0]=='\0')//
		return -1; //��ָ���մ�������-1��
	int len=0; 
	const char *c=Pattern; 
	while(*c++!='\0') //�ƶ�ָ����ƶ��±�졣
	{ 
		++len; //�ַ������ȡ�
	} 
	int *next=new int[len+1];
	getNext(Pattern,next); //��Pattern��next����ֵ

	cout<<"next����:";
	for(int t=0;t<len;t++)
		cout<<next[t]<<" ";
	cout<<endl;
	
	int index=0,i=0,j=0; 	
	while(Text[i]!='\0'&&Pattern[j]!='\0') 
	{
		if(Text[i]== Pattern[j]) {
			++i; // �����ȽϺ���ַ�
			++j;
		}
		else {
			index+=j-next[j]; 
			if(next[j]!=-1)
				j=next[j]; // ģʽ�������ƶ�
			else {
				j=0;
				++i;
			}
		}
	}//while  
	delete []next;
	if(Pattern[j]=='\0')
		return index+1;// ƥ��ɹ�
	else
		return -1;       
}

int main() //ababc 
{ 
    char *text="ababaababcb"; 
    char *pattern="ababc"; 
	cout<<"������"<<text<<endl;
	cout<<"�Ӵ���"<<pattern<<endl;
    int index=KMP(text,pattern); 
	cout<<"ƥ���λ����"<<index<<endl;
	return 0;
}
