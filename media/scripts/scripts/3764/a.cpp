#include <bits/stdc++.h>
using namespace std;

#define int long long
#define str string
#define endl '\n'
#define fs first
#define ss second
#define all(a) a.begin(), a.end()
#define print(a) for(auto x : a) cout << x << ' '; cout << endl;
#define printmp(a) for(auto x : a) cout << x[0] << ' ' << x[1] << endl;

const int mod = 1e9 + 7;

vector<int> dp(42), gd(42);

void strength(int x){
    for(int i = 2; i <= 41; i ++)
        if(x % i != 0){
            dp[x] = dp[i] + 1;
            return;
        }
}

void solve(){
    int l, r;
    cin >> l >> r;
    int ans = 0, cnt = 0;
    for(int i = 40; i >= 1; i --){
        int c = r / gd[i] - (l - 1) / gd[i];
        ans += (c - cnt) * (dp[i + 1] + 1);
        cnt += (c - cnt);
    }
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Javohir
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    int x = 2;
    gd[1] = 1;
    while(gd[x - 1] < 1e17){
        gd[x] = gd[x - 1] * x / __gcd(gd[x - 1], x);
        x ++;
    }
    for(int i = 2; i <= 41; i ++)
        strength(i);
    print(dp)
    print(gd)
    // cin >> t;
    while(t --){
        solve();
        if(t > 0)
            cout << endl;
    }
}