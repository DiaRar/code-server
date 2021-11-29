#include <bits/stdc++.h>

std::ifstream in("multiplu.in");
std::ofstream out("multiplu.out");

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b;
    in >> a >> b;
    out << gcd(a, b) << "\n";
}