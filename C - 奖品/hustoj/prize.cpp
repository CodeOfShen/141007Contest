// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   prize.cpp                                                *
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

const int MaxN = 32;
const int MaxL = 70000;
const char aye[] = "yes";
const char nay[] = "no";

int va[MaxL], vb[MaxL];
int itva, itvb;
int n, k, a[MaxN];
int t, tt;

void dfs1(int sum, int cur, int endflag)
{
    if (cur == endflag) { va[itva++] = sum; return; }
    else for(int i = 0; i < 4; i++)
        dfs1(sum + a[cur] * i, cur + 1, endflag);
}

void dfs2(int sum, int cur, int endflag)
{
    if (cur == endflag) { vb[itvb++] = sum; return; }
    else for(int i = 0; i < 4; i++)
        dfs2(sum + a[cur] * i, cur + 1, endflag);
}

void solve()
{
    itva = itvb = 0;
    n = nextInt(); k = nextInt();
    for (int i = 0; i < n; i++) a[i] = nextInt();
    dfs1(0, 0, n / 2);
    dfs2(0, n / 2, n);
    sort(va, va + itva);
    sort(vb, vb + itvb);
    bool flag = 0;
    for (int i = 0; i < itvb; i++)
        if (k == vb[i] + *(lower_bound(va, va + itva, k - vb[i])))
    {
        flag = 1; break;
    }
    printf("Case #%d: %s\n", ++tt, flag? aye: nay);
}

int main()
{
    t = nextInt(); while (t--) solve();
    return 0;
}
