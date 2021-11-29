#include <fstream>
 
std::ifstream in("multiplu.in");
std::ofstream out("multiplu.out");
 
constexpr int N = 2e6;

int prev_mod[N];
int digit_count[N];
int digit[N];
int ans[N];

/// Returnăm cel mai mare divizor comun.
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
 
void bfs(int mod) {
    static int q[N];
    int q_top, q_bot;
    q_top = q_bot = 0;
 
    q[q_top++] = 1;
    prev_mod[1] = -1;
    digit[1] = 1;
    digit_count[1] = 1;
    bool found = false;
    while (q_top != q_bot && !found) {
        int m = q[q_bot++];
        for (int d = 0; d < 2; ++d) {
            int new_m = (m * 10 + d) % mod;
            if (digit_count[new_m] != 0) {
                continue;
            }
 
            q[q_top++] = new_m;
            prev_mod[new_m] = m;
            digit[new_m] = d;
            digit_count[new_m] = digit_count[m] + 1;
 
            found = new_m == 0;
        };
    }
}
int main() {
    int a, b;
    in >> a >> b;
    int lcm = a / gcd(a, b) * b;
    bfs(lcm);
    int i = digit_count[0];
    for (int m = 0; m != -1; m = prev_mod[m]) {
        ans[--i] = digit[m];
    }
    for (int i = 0; i < digit_count[0]; ++i) {
        out << ans[i];
    }
    out << "\n";
}