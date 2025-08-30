/************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define each(x, a) for (auto &x : a)

const int INF = 1e18;
const int MOD = 1e9 + 7;

vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    vector<int> res;
    for(int i=2 ; i<=n ; i++){
        if(isPrime[i]) res.pb(i);
    }
    return res;
}
/************************************************************************************/

void countDivisors(unordered_map<int, int> &mpp, int x, const vector<int> &primes)
{
    for (int p : primes)
    {
        if (1LL * p * p > x)
            break;
        while (x % p == 0)
        {
            mpp[p]++;
            x /= p;
        }
    }
    if (x > 1)
        mpp[x]++; 
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> primes = sieve(1e6);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, 0, n) cin >> a[i];

        unordered_map<int, int> mpp;
        rep(i, 0, n) countDivisors(mpp, a[i], primes);

        bool ok = true;
        for (auto &kv : mpp)
        {
            if (kv.second % n != 0)
            {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}