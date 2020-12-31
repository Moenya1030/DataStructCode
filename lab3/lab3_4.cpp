#include <iostream>
using namespace std;
#include <vector>
using std::vector;
#include <list>
using std::list;

int main ()
{
    vector<int> ivec(4,3);
    list<int> ilist(2.5);

    ilist.push_back(1);
    ilist.insert(ilist.begin(),3);
    for (list<int>::iterator it=ilist.begin(); it!=ilist.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    ilist.insert(ilist.end(),ivec.begin(),ivec.end());
    ilist.sort();
    ilist.reverse();

    for (list<int>::iterator it=ilist.begin(); it!=ilist.end(); it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}