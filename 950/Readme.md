# 950 - Cerc3
## Cerința
Se dă un număr n de cercuri pe o dreapta, definite prin poziție și rază. Se cere să aflăm numărul maxim de cercuri care nu au niciun punct comun cu alte cercuri și nu au un alt cerc în interiorul lor.

![](https://www.pbinfo.ro/resurse/probleme/950-1000/cerc3-enunt.png)
## Rezolvare
La citire, poziția și raza sunt transformate în coordonate de stanga si dreapta reprezentând începutul și sfarșitul unui segment reprezentănd cercul pe dreapta:
```cpp
cin >> poz >> r;
int st = poz-r;
int dr = poz+r;
```
Vectorul se sortează cu merge sort:  

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Merge-Sort-Tutorial.png)
Dupa care iterăm prin vector și verificăm dacă poziția de inceput a unui segment este înainte sau după poziția de sfârșit a segmentului anterior:
```cpp
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
```