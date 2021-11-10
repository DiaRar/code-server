#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("cerc3.in");
ofstream cout("cerc3.out");
const int NMAX = 3e2;

// Definim structura segmentului ce reprezinta cercul pe dreapta
struct cerc
{
    int st, dr;
};

// Comparam pozitia de sfarsit intre cele 2 segmente
bool cmp(cerc a = {0 , 0}, cerc b = {0 , 0}){
    return a.dr<b.dr;
}

cerc v[NMAX+5];

// Citim pozitia si raza cercului si o transformam intr-un segment
void citire(int n = 1)
{

    int r, poz;
    for (int i = 0; i < n; i++)
    {
        cin >> poz >> r;
        v[i].st = poz-r;
        v[i].dr = poz+r;
    }
}

// Parcurgem segmentele cu conditia ca un segment sa aibe inceputul dupa sfarsitul segmentului anterior
void parc(int n = 1)
{
    int x, nr = 1;
    x = v[0].dr;
    for (int i=0; i<n-1; i++)
    {
        if (x < v[i+1].st)
        {
            nr++;
            x = v[i+1].dr;
        }
    }
    cout<<nr;
}
int main ()
{
    int n;
    cin >> n;
    citire(n);
    sort(v, v+n, cmp);
    parc(n);
    return 0;
}