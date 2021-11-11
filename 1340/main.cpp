#include <iostream>
#include <algorithm>

using namespace std;

struct OBIECTE 
{
    int val,greutate;
    double med;
}v[1000];
// Comparam eficient
bool cmp(OBIECTE a,OBIECTE b)
{
    return a.med < b.med;
}

// Sortam in functie de eficienta
void bubble_sort(int n) {
    OBIECTE aux;
    for (int i = 0; i < n-1; i++)    
    for (int j = 0; j < n-i-1; j++)
           if(cmp(v[j],v[j+1])) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
}
int main()
{
    int i,n,gmax,greu = 0,conto;
    double val = 0;
    cin >> n >> gmax;
    for (i = 0;i < n;i++)
    {
        cin >> v[i].greutate >> v[i].val;
        v[i].med = (double) v[i].val / (double) v[i].greutate;
    }
    bubble_sort(n);
    for (i = 0;i < n;i++)
    {
        if(gmax == greu) break;
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
            }
    }
    cout << val;
    
    return 0;
}