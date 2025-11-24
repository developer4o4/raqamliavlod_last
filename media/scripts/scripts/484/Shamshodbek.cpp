#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;

    if (a > 100) {
        cout << 100 << endl;
    } else if (a < 0) {
        cout << 0 << endl;
    } else if (a < 38) {
        cout << a << endl;
    } else if (a % 5 == 0) {
        cout << a << endl;
    } else if (a % 5 == 1 || a % 5 == 2) {
        cout << a << endl;
    } else if (a % 5 == 4) {
        cout << a + 1 << endl;
    } else {
        cout << a + 2 << endl;
    }

    return 0;
}
