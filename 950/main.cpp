#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("cerc3.in");
ofstream cout("cerc3.out");
const int NMAX = 3e2;

// Definim structura segmentului ce reprezintă cercul pe dreaptă
struct cerc
{
    int st, dr;
};

// Comparam poziția de sfarșit între cele 2 segmente
bool cmp(cerc a = {0 , 0}, cerc b = {0 , 0}){
    return a.dr<b.dr;
}

// Începutul sortării

void merge(cerc *arr, int st, int dr, int m)
{
    int i, j, k;
    cerc v2[NMAX+5];
    i = st;
    k = st;
    j = m + 1;
    while(i <= m && j <= dr) {
        // Comparăm coordonatele marginilor drepte ale segmentelor
        if (cmp(arr[i] , arr[j])) {
            v2[k] = arr[i];
            k++;
            i++;
        }
        else  {
            v2[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i <= m) {
        v2[k] = arr[i];
        k++;
        i++;
    }
    while(j <= dr) {
        v2[k] = arr[j];
        k++;
        j++;
    }
    for(i = st; i < k; i++)  {
        arr[i] = v2[i];
    }
}

// Merge sort, algoritm divide et impera cu complexitate nlog(n)
void merge_sort(cerc *arr, int st, int dr)
{
    int m;
    if(st < dr){
        m=(st+dr)/2;
        merge_sort(arr,st,m);
        merge_sort(arr,m+1,dr);
        merge(arr,st,dr,m);
    }
}

cerc v[NMAX+5];

//Sfârșitul sortării

// Citim poziția și raza cercului și o transformăm într-un segment
void citire(int n = 1)
{

    int r, poz;
    for(int i = 0; i < n; i++)
    {
        cin >> poz >> r;
        v[i].st = poz-r;
        v[i].dr = poz+r;
    }
}

// Parcurgem segmentele cu condiția ca un segment să aibe începutul după sfârșitul segmentului anterior
void parc(int n = 1)
{
    int x, nr = 1;
    x = v[0].dr;
    for(int i=0; i<n-1; i++)
    {
        if(x < v[i+1].st)
        {
            nr++;
            x = v[i+1].dr;
        }
    }
    cout<<nr;
}

// Printare a valorilor pentru a verifica algoritmul de sortare
void print(int n = 1) {
    for(int i=0; i<n; ++i) cout << v[i].dr << endl;
}
int main ()
{
    int n;
    cin >> n;
    citire(n);
    merge_sort(v, 0, n-1);
    parc(n);
//  print(n);
    return 0;
}