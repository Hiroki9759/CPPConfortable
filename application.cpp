#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//最大公約数
ll gcd(ll a,ll b){
    return b ? gcd(b, a%b) : a;
}

//nこの最大公約数を求める
ll ngcd(vector<ll> a){
    ll res;
    res = a[0];
    for (ll i = 0; i < a.size()&&res!=1; i++){
        res = gcd(a[i],res);
    }
    return res;
}

//最小公倍数
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}
//nこの最大公約数
int nlcm(vector<int> numbers) {
    int res;
    res = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        res = lcm(res, numbers[i]);
    }
    return res;
}

//素数判定
bool isPrime(int x){
    int i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}

//桁の和
int digsum(int n) {
    int res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}


//約数全列挙
vector<int> enum_div(int n){
    vector<int> ret;
    for(int i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if(i != 1 && i*i != n){
                ret.push_back(n/i);
            }
        }
    }
    return ret;
}

//累乗
// xのn乗%modを計算
long long int mod_pow(long long int x, long long int n, long long int mod){
    long long int res = 1;
    while(n > 0){
        if(n & 1) res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}

//文字列中の特定の文字カウント
int stringcount(string s, char c) {
    return count(s.cbegin(), s.cend(), c);
}


//幅優先探索
// 各座標に格納したい情報を構造体にする
// 今回はX座標,Y座標,深さ(距離)を記述している
struct Corr {
    int x;
    int y;
    int depth;
};
queue<Corr> q;
int bfs(vector<vector<int> > grid) {
    // 既に探索の場所を1，探索していなかったら0を格納する配列
    vector<vector<int> > ispassed(grid.size(), vector<int>(grid[0].size(), false));
    // このような記述をしておくと，この後のfor文が綺麗にかける
    int dx[8] = {1, 0, -1, 0};
    int dy[8] = {0, 1, 0, -1};
    while(!q.empty()) {
        Corr now = q.front();q.pop();
        /*
            今いる座標は(x,y)=(now.x, now.y)で，深さ(距離)はnow.depthである
            ここで，今いる座標がゴール(探索対象)なのか判定する
        */
        for(int i = 0; i < 4; i++) {
            int nextx = now.x + dx[i];
            int nexty = now.y + dy[i];

            // 次に探索する場所のX座標がはみ出した時
            if(nextx >= grid[0].size()) continue;
            if(nextx < 0) continue;

            // 次に探索する場所のY座標がはみ出した時
            if(nexty >= grid.size()) continue;
            if(nexty < 0) continue;

            // 次に探索する場所が既に探索済みの場合
            if(ispassed[nexty][nextx]) continue;

            ispassed[nexty][nextx] = true;
            Corr next = {nextx, nexty, now.depth+1};
            q.push(next);
        }
    }
}




