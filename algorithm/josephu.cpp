#include <iostream>
#include <list>
 
using namespace std;

int JosephusProblem_Solution2(int n, int m);
 
int main()
{
    int n = 10;
    int m = 2;
    int last = JosephusProblem_Solution2(n, m); 
    cout<<"last is "<<last<<endl;    

    return 0;
}

int JosephusProblem_Solution2(int n, int m)
{
    if(n < 1 || m < 1)
        return -1;

    list<int> listInt;
    unsigned i;
    
    for(i = 0; i < n; i++)
        listInt.push_back(i);

    list<int>::iterator iterCurrent = listInt.begin();

    while(listInt.size() > 1)
    {
        for(i = 0; i < m-1; i++)
        {
            if(++iterCurrent == listInt.end())
                iterCurrent = listInt.begin();
        }
        
        list<int>::iterator iterDel = iterCurrent;
        cout<<*iterCurrent<<endl;

        if(++iterCurrent == listInt.end())
            iterCurrent = listInt.begin();
        
        listInt.erase(iterDel);
    }

    return *iterCurrent;
}
