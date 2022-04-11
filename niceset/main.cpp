#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream in("niceset.in");
ofstream out("niceset.out");

const int N = 3e5;
int n;
int v[N];
int64_t sp[N];
int cvn;
pair<int, int> cv[N];

void build_sp() {
    sp[0] = v[0];
    for (int i = 1; i < n; ++i) {
        sp[i] = sp[i - 1] + v[i];
    }
}

int main() {
    int64_t s;
    in >> n >> s;
    for (int i = 0; i < n; ++i) {
        in >> v[i];
    }
    sort(v, v + n);
    build_sp();
    int lmax = 2;
    int64_t rs = abs(v[1] - v[0]);
    for (int l = 0, r = 2; r < n; ++r) {
        rs += 1ll * (r - l) * v[r] - sp[r - 1] + sp[l - 1];
        while (rs > s) {
            rs += 1ll * (r - l) * v[l] - sp[r] + sp[l];
            ++l;
        }
        int len = r - l + 1;
        if (len > lmax) {
            lmax = len;
        }
    }
    out << lmax << '\n';
}
