#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void t_main(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int p; cin >> p;
    for(auto &x: a) x -= p;

    vector<ll> pref(n+1, 0);
    for(int i=1; i<=n; i++) pref[i] = pref[i-1] + a[i-1];
    {
        vector<ll> b = pref;
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        
        for(int i=0; i<=n; i++) pref[i] = lower_bound(b.begin(), b.end(), pref[i]) - b.begin() + 1;
    }

    vector<int> bit(n+1, 0);
    auto add = [&](int i, int x){
        for(; i<=n; i+=i&-i) bit[i] += x;
    };
    auto sum = [&](int i){
        int res = 0;
        for(; i>0; i-=i&-i) res += bit[i];
        return res;
    };
    ll ans = 0;
    add(pref[0], 1);
    for(int i=1; i<=n; i++){
        ans += sum(pref[i]);
        add(pref[i], 1);
    }
    cout << ans;
}

signed main(){
    signed t = 1;
    cin.tie(nullptr)->sync_with_stdio(false);
    #ifdef with_testcases
        cin >> t;
    #endif
    while(t--){
        t_main();
        cout << '\n';
    }
    return 0;
}