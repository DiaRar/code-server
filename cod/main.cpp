#include <iostream>

using namespace std;
struct POTATO {
    int a,b, c;
} potato[3];

int main() {
    potato[0].a = 1;
    potato[0].c = -1;
    potato[0].b = 8;
    potato[2].c = 319;
    for(auto& [x, y, z] : potato)
        cout << x << ' ' << y << ' ' << z << '\n';
    return 0;
}