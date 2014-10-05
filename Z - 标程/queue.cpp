// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   queue.cpp                                                *
*****************************************************************************/
// 人一我百，人十我万！追逐青春的梦想，怀着自信的心，永不放弃！
//#pragma GCC optimize ("O2")
//#pragma comment(linker, "/STACK:1024000000,1024000000")

//#include <bits/stdc++.h>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;
template<class T>inline bool updateMin(T& a, T b){ return a > b ? a = b, 1: 0; }
template<class T>inline bool updateMax(T& a, T b){ return a < b ? a = b, 1: 0; }
inline int    nextInt() { int x; scanf("%d", &x); return x; }
inline int64  nextI64() { int64  d; cin >> d; return d; }
inline char   nextChr() { scanf(" "); return getchar(); }
inline string nextStr() { string s; cin >> s; return s; }
inline double nextDbf() { double x; scanf("%lf", &x); return x; }
inline int64  nextlld() { int64 d; scanf("%lld", &d); return d; }
inline int64  next64d() { int64 d; scanf("%I64d",&d); return d; }

const int MaxN = 10;
const int MaxM = 10;
const int Mod = 1000000007;

struct Matrix
{
    int n, m;
    int64 mat[MaxN][MaxM];
    Matrix(): n(-1), m(-1){}
    Matrix(int _n, int _m): n(_n), m(_m)
    {
        memset(mat, 0, sizeof(mat));
    }
    void Unit(int _s)
    {
        n = _s; m = _s;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = (i == j)? 1: 0;
    }
    void print()
    {
        printf("n = %d, m =  %d\n", n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                printf("%8d", mat[i][j]);
            printf("\n");
        }
    }
};

Matrix add_mod(const Matrix& a, const Matrix& b, const int64 mod)
{
    Matrix ans(a.n, a.m);
    for (int i = 0; i < a.n; i++) for (int j = 0; j < a.m; j++)
        ans.mat[i][j] = (a.mat[i][j] + b.mat[i][j]) % mod;
    return ans;
}

Matrix mul(const Matrix& a, const Matrix& b)
{
    Matrix ans(a.n, b.m);
    for (int i = 0; i < a.n; i++) for (int j = 0; j < b.m; j++)
    {
        int64 tmp = 0;
        for (int k = 0; k < a.m; k++)
            tmp += a.mat[i][k] * b.mat[k][j];
        ans.mat[i][j] = tmp;
    }
    return ans;
}

Matrix mul_mod(const Matrix& a, const Matrix& b, const int mod)
{
    Matrix ans(a.n, b.m);
    for (int i = 0; i < a.n; i++) for (int j = 0; j < b.m; j++)
    {
        int64 tmp = 0;
        for (int k = 0; k < a.m; k++)
            tmp += (a.mat[i][k] * b.mat[k][j]) % mod;
        ans.mat[i][j] = tmp % mod;
    }
    return ans;
}

Matrix pow_mod(const Matrix& a, int64 k, const int mod)
{
    Matrix p(a.n,a.m), ans(a.n,a.m);
    p = a; ans = a;
    ans.Unit(a.n);
    if (k == 0) return ans;
    else if (k == 1) return a;
    else
    {
        while (k)
        {
            if (k & 1) { ans=mul_mod(ans, p, mod); k--; }
            else { k /= 2; p = mul_mod(p, p, mod); }
        }
        return ans;
    }
}

const int Mi[20] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 6, 7, 7, 7, 8, 8};
const int Mj[20] = {3, 6, 0, 3, 0, 6, 4, 7, 1, 7, 1, 4, 7, 5, 8, 2, 5, 8, 2, 5};

int t, tt;

void solve()
{
    int64 n = nextI64();
    if (n == 0) { printf("Case #%d: 0\n", ++tt); return; }
    if (n == 1) { printf("Case #%d: 3\n", ++tt); return; }
    Matrix ans(1, 1), beg(9, 1), vec(1, 9);
    for (int i = 0; i < 9; i++)
        beg.mat[i][0] = vec.mat[0][i] = 1;
    Matrix cef(9, 9), tmp(9, 9), res(9, 1);
    memset(cef.mat, 0, sizeof(cef.mat));
    for (int i = 0; i < 20; i++)
        cef.mat[Mi[i]][Mj[i]] = 1;
    tmp = pow_mod(cef, n - 2, Mod);
    res = mul_mod(tmp, beg, Mod);
    ans = mul_mod(vec, res, Mod);
    printf("Case #%d: %I64d\n", ++tt, ans.mat[0][0]);
    return;
}

int main()
{
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    t = nextInt();
    while (t--) solve();
    return 0;
}
