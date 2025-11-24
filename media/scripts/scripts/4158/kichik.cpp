#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a;
    cin >> a;  // Zanjirlar sonini o'qish
    
    vector<int> b(a);
    for (int i = 0; i < a; ++i) {
        cin >> b[i];  // Har bir zanjirning uzunligini o'qish
    }
    
    int sum = 0;
    for (int i = 0; i < a; ++i) {
        sum += b[i];  // Zanjirlarning uzunliklari yig'indisini hisoblash
    }

    if (a == sum) {
        cout << a / 2 << endl;  // Agar zanjirlar soni yig'indiga teng bo'lsa, a // 2
    } else {
        int count = 0;
        for (int i = 0; i < a; ++i) {
            if (b[i] == 1) {
                count++;  // 1 bo'lgan zanjirlar sonini hisoblash
            }
        }
        cout << a - 1 - count << endl;  // Natijani hisoblash va chiqarish
    }

    return 0;
}
