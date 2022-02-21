#include <fstream>
using namespace std;
ifstream cin ("dfs.in");
ofstream cout ("dfs.out");



int a[101][101];
int v[101], v1, v2;
int n;
void dfs (int k)
{
v[k] = 1;

cout << k << " ";
for (int i = 1; i <= n; i++)
if (a[k][i] == 1 && v[i] == 0)
{
dfs(i);
}
}



int main()
{ int m, x;
cin >> n >> m >> x;

for(int i = 1; i <= m; i++)
{
cin >> v1 >> v2;
a[v1][v2] = 1; a[v2][v1] = 1;
}

dfs(x);

return 0;
}