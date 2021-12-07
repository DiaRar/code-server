#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include <fstream>
ofstream fout("uva.out");
constexpr int NMAX = 100;
char a[NMAX+5][NMAX+5];
bool rez[NMAX+5][NMAX+5];
int dx[]={1, 0, -1, 0, 1, 1, -1, -1};
int dy[]={0, 1, 0, -1, 1, -1, 1, -1};
int n, m;
bool inside(int x, int y, int n, int m) {
    if(x>=0 && x<n && y>=0 && y<n) return 1;
    return 0;
}
void fill(int x, int y, int &dim){
    int xn, yn;
    rez[x][y] = 1;
    dim++;
    for(int i =0 ; i<8; ++i)
    {
        xn = x + dx[i];
        yn = y + dy[i];
        if(inside(xn, yn, n, m) && rez[xn][yn] == 0 && a[xn][yn] == 'W')
            fill(xn, yn, dim);
    }
}
void coord(char s[], int &x, int &y){
    char *p;
    p = strtok(s, " ");
    x = 0;
    for(int i = 0; i< strlen(p); ++i)
        x = x*10 + p[i] - '0';

    p = strtok(NULL, " ");
    y = 0;
    for(int i = 0; i < strlen(p); ++i)
        y = y*10 + p[i] - '0';
   // fout << x << " " << y << "\n";
}
int main()
{
    int T, t, i, j, l, c, dim;
    char line[102];
    cin >> T ;
    for(t=1; t<=T;++t) {
        n=0;
        cin.getline(line, 102);
        m = strlen(line);
        while(!m) {
            cin.getline(line,102);
            m = strlen(line);
        }
        strcpy(a[n++], line);
        while(cin.getline(line, 102) && !isdigit(line[0]))
            strcpy(a[n++], line);
        for(i=0; i<n; ++i)
            fout << a[i]<<"\n";
        //fout << a[0]<< "\n";
        // fout << line << "a";
        // fout.close();
         do
        {
        coord(line, l, c);
        dim = 0;
        fill(l-1,c-1, dim);
        fout << dim << "\n";
        memset(rez, 0, sizeof(rez));
        cin.getline(line, 102);
        }while(strlen(line));
        fout << "\n";
        memset(a, 0, sizeof(a));
        memset(rez, 0, sizeof(rez));
    }
    return 0;
}
