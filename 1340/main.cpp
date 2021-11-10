#include <iostream>
#include <algorithm>

using namespace std;

struct OBIECTE 
{
    int val,greutate;
    double med;
}v[1000];

bool cmp(OBIECTE a,OBIECTE b)
{
    return a.med > b.med;
}

int main()
{
    int i,n,gmax,greu = 0,conto;
    double val = 0;
    cin >> n >> gmax;
    for (i = 1;i <= n;i++)
    {
        cin >> v[i].greutate >> v[i].val;
        v[i].med = (double) v[i].val / (double) v[i].greutate;
    }
    sort(v + 1,v + n + 1,cmp);
    for (i = 1;i <= n;i++)
    {
            conto = gmax - greu;
            if (conto >= v[i].greutate)
            {
                val = val + (double) v[i].val;
                greu = greu + v[i].greutate;
            }
            else
            {
                val = val + (double) conto * v[i].med;
                greu = greu + conto;
                break;
            }
    }
    cout << val;
    
    return 0;
}