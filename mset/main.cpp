#include <iostream>
#include <set>

using namespace std;

set <int> s;

int main()
{
    int x, a;
    cin >> a;
    while(cin >> x){
        s.insert(x);
    }
    set <int> ::iterator itl, itu;
    itl = s.lower_bound(a);
    if(itl == s.end())
        cout << "nu exista" << "\n";
    else
        cout << *itl << "\n";
    itu = s.upper_bound(a);
    if(itu == s.end())
        cout << "nu exista" << "\n";
    else
        cout << *itu << "\n";
    return 0;
}
