#pragma GCC optimize("unroll-loops")
#pragma gcc optimize("Ofast")
#pragma GCC optimization("Ofast")
#pragma optimize(Ofast)
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define str string
#define fs first
#define ss second
#define all(a) a.begin(), a.end()

#define print(a) for(auto x : a) cout << x << ' '; cout << endl;
#define printmp(a) for(auto x : a) cout << x.fs << ' ' << x.ss << endl;

const int mod = 1e9 + 7;

int ans = 0;
vector<int> a, pre;

struct BINAR_TREE {

    int size = 1;
    vector<vector<int>> pref;
    vector<int> sums;

    BINAR_TREE (){
        while(size < (int)a.size())
            size <<= 1;
        pref.resize(size << 1);
        sums.resize(size << 1);
        run(0, size - 1, 0);
    }

    void run(int l, int r, int x){
        if(l >= (int)a.size())
            return;
        if(r == l){
            if(l < (int)a.size())
                pref[x].push_back(a[l]), sums[x] = a[l], ans += (a[l] >= 0);
            return;
        }
        int mid = (l + r) >> 1;
        run(l, mid, (x << 1) + 1);
        run(mid + 1, r, (x << 1) + 2);
        sums[x] = sums[(x << 1) + 1] + sums[(x << 1) + 2];
        if(pref[(x << 1) + 2].size() > 0){
            int sm = 0;
            for(int j = mid; j >= l; j --){
                sm += a[j];
                int left = 0, right = pref[(x << 1) + 2].size() - 1;
                print(pref[(x << 1) + 1])
                print(pref[(x << 1) + 2])
                while(left < right){
                    int mid = (left + right + 1) >> 1;
                    if(-sm <= pref[(x << 1) + 2][mid])
                        left = mid;
                    else
                        right = mid - 1;
                }
                if(-sm > pref[(x << 1) + 2][left])
                    left --;
                ans += left + 1;
            }
        }
        int i1 = 0, i2 = 0;
        while(i1 < pref[(x << 1) + 1].size() or i2 < pref[(x << 1) + 2].size()){
            if(i1 >= pref[(x << 1) + 1].size() or i2 < pref[(x << 1) + 2].size() and sums[(x << 1) + 1] + pref[(x << 1) + 2][i2] >= pref[(x << 1) + 1][i1])
                pref[x].push_back(sums[(x << 1) + 1] + pref[(x << 1) + 2][i2]), i2 ++;
            else
                pref[x].push_back(pref[(x << 1) + 1][i1]), i1 ++;
        }
    }
};

void solve(){
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    int p;
    cin >> p;
    for(int i = 0; i < n; i ++)
        a[i] -= p;
    pre.resize(n + 1);
    for(int i = 0; i < n; i ++)
        pre[i + 1] = pre[i] + a[i];
    BINAR_TREE b;
    cout << ans;
}

signed main(){
    fastio;
    #ifdef Javohir
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
        cout << endl;
    }
}