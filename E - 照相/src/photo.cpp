// <!-- encoding UTF-8 --!>
/*****************************************************************************
*                      ----Stay Hungry Stay Foolish----                      *
*    @author    :   Shen                                                     *
*    @name      :   photo.cpp                                                *
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
#include <sstream>
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


#define MAXN 9999
#define MAXSIZE 1010
#define DLEN 4
class BigInt
{
private:
    int len, a[1000];
public:
    BigInt() { len = 1; memset(a, 0, sizeof(a)); }
    BigInt(const int);
    BigInt(const char*);
    BigInt(const BigInt &);
    BigInt &operator=(const BigInt &);
    friend istream& operator>>(istream&, BigInt&);
    friend ostream& operator<<(ostream&, BigInt&);
    BigInt operator+(const BigInt &) const;
    BigInt operator-(const BigInt &) const;
    BigInt operator*(const BigInt &) const;
    BigInt operator/(const int &) const;
    BigInt operator^(const int &) const;
    int operator%(const int &) const;
    bool operator>(const BigInt &T) const;
    bool operator<(const BigInt &T) const;
    bool operator>(const int &t) const;
    bool operator<(const int &t) const;
    bool operator<=(const BigInt &T) const { return !(*this > T); }
    bool operator>=(const BigInt &T) const { return !(*this < T); }
    bool operator<=(const int &t) const { BigInt b(t); return !(*this > b); }
    bool operator>=(const int &t) const { BigInt b(t); return !(*this < b); }
    void print();
};

BigInt::BigInt(const int b)
{
    int c, d = b;
    len = 0; memset(a, 0, sizeof(a));
    while (d > MAXN)
    {
        c = d - (d / (MAXN + 1)) * (MAXN + 1);
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}

BigInt::BigInt(const char *s)
{
    int t, k, index, L, i;
    memset(a, 0, sizeof(a));
    L = strlen(s);
    len = L / DLEN;
    if (L % DLEN) len++;
    index = 0;
    for (i = L - 1; i >= 0; i -= DLEN)
    {
        t = 0;
        k = i - DLEN + 1;
        if (k < 0) k = 0;
        for (int j = k; j <= i; j++)
            t = t * 10 + s[j] - '0';
        a[index++] = t;
    }
}
BigInt::BigInt(const BigInt &T):len(T.len) // 拷贝构造函数
{
    memset(a, 0, sizeof(a));
    for (int i = 0; i < len; i++)
        a[i] = T.a[i];
}
BigInt & BigInt::operator=(const BigInt &n) // 重载赋值运算符，大数之间赋值运算
{
    len = n.len;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < len; i++)
        a[i] = n.a[i];
    return *this;
}
istream& operator>>(istream &in, BigInt &b)
{
    char ch[MAXSIZE * 4];
    int i = -1;
    in >> ch;
    int L = strlen(ch);
    int count = 0, sum = 0;
    for (i = L - 1; i >= 0; )
    {
        sum = 0;
        int t = 1;
        for (int j = 0; j < 4 && i >= 0; j++, i--, t *= 10)
            sum += (ch[i] - '0') * t;
        b.a[count] = sum;
        count++;
    }
    b.len = count++;
    return in;
}
ostream& operator<<(ostream& out, BigInt& b) // 重载输出运算符
{
    cout << b.a[b.len - 1];
    for (int i = b.len - 2; i >= 0; i--)
        printf("%04d", b.a[i]);
    return out;
}
BigInt BigInt::operator+(const BigInt &T)const   //两个大数之间的相加运算
{
    BigInt t(*this);
    int i,big;
    big=T.len>len?T.len:len;
    for(i=0;i<big;i++)
    {
        t.a[i]+=T.a[i];
        if(t.a[i]>MAXN)
        {
            t.a[i+1]++;
            t.a[i]-=MAXN+1;
        }
    }
    if(t.a[big]!=0)
       t.len=big+1;
    else t.len=big;
    return t;
}
BigInt BigInt::operator-(const BigInt &T)const  //两个大数之间的相减运算
{
    int i,j,big;
    bool flag;
    BigInt t1,t2;
    if(*this>T)
    {
        t1=*this;
        t2=T;
        flag=0;
    }
    else
    {
        t1=T;
        t2=*this;
        flag=1;
    }
    big=t1.len;
    for(i=0;i<big;i++)
    {
        if(t1.a[i]<t2.a[i])
        {
            j=i+1;
            while(t1.a[j]==0)
                j++;
            t1.a[j--]--;
            while(j>i)
                t1.a[j--]+=MAXN;
            t1.a[i]+=MAXN+1-t2.a[i];
        }
        else t1.a[i]-=t2.a[i];
    }
    t1.len=big;
    while(t1.a[t1.len-1]==0 && t1.len>1)
    {
        t1.len--;
        big--;
    }
    if(flag)
        t1.a[big-1]=0-t1.a[big-1];
    return t1;
}
BigInt BigInt::operator*(const BigInt &T)const  //两个大数之间的相乘
{
    BigInt ret;
    int i,j,up;
    int temp,temp1;
    for(i=0;i<len;i++)
    {
        up=0;
        for(j=0;j<T.len;j++)
        {
            temp=a[i]*T.a[j]+ret.a[i+j]+up;
            if(temp>MAXN)
            {
                temp1=temp-temp/(MAXN+1)*(MAXN+1);
                up=temp/(MAXN+1);
                ret.a[i+j]=temp1;
            }
            else
            {
                up=0;
                ret.a[i+j]=temp;
            }
        }
        if(up!=0)
           ret.a[i+j]=up;
    }
    ret.len=i+j;
    while(ret.a[ret.len-1]==0 && ret.len>1)ret.len--;
    return ret;
}
BigInt BigInt::operator/(const int &b)const  //大数对一个整数进行相除运算
{
    BigInt ret;
    int i,down=0;
    for(i=len-1;i>=0;i--)
    {
        ret.a[i]=(a[i]+down*(MAXN+1))/b;
        down=a[i]+down*(MAXN+1)-ret.a[i]*b;
    }
    ret.len=len;
    while(ret.a[ret.len-1]==0 && ret.len>1)
        ret.len--;
    return ret;
}
int BigInt::operator%(const int &b)const   //大数对一个 int类型的变量进行取模
{
    int i,d=0;
    for(i=len-1;i>=0;i--)
        d=((d*(MAXN+1))%b+a[i])%b;
    return d;
}
BigInt BigInt::operator^(const int &n)const  //大数的n次方运算
{
    BigInt t,ret(1);
    int i;
    if(n<0)exit(-1);
    if(n==0)return 1;
    if(n==1)return *this;
    int m=n;
    while(m>1)
    {
        t=*this;
        for(i=1;(i<<1)<=m;i<<=1)
           t=t*t;
        m-=i;
        ret=ret*t;
        if(m==1)ret=ret*(*this);
    }
    return ret;
}
bool BigInt::operator>(const BigInt &T) const // 大数和另一个大数的大小比较
{
    int ln;
    if (len > T.len) return true;
    else if (len == T.len)
    {
        ln = len - 1;
        while (a[ln] == T.a[ln] && ln >= 0) ln--;
        if (ln >= 0 && a[ln] > T.a[ln])
            return true;
        else
            return false;
    }
    else
        return false;
}
bool BigInt::operator<(const BigInt &T) const // 大数和另一个大数的大小比较
{
    int ln;
    if (len < T.len) return true;
    else if (len == T.len)
    {
        ln = len - 1;
        while (a[ln] == T.a[ln] && ln >= 0) ln--;
        if (ln >= 0 && a[ln] < T.a[ln])
            return true;
        else
            return false;
    }
    else
        return false;
}
bool BigInt::operator>(const int &t) const // 大数和一个int类型的变量的大小比较
{
    BigInt b(t);
    return *this > b;
}
bool BigInt::operator<(const int &t) const // 大数和一个int类型的变量的大小比较
{
    BigInt b(t);
    return *this < b;
}
void BigInt::print() // 输出大数
{
    printf("%d", a[len - 1]);
    for (int i = len - 2; i >= 0; i--)
        printf("%04d", a[i]);
    printf("\n");
}

BigInt n, m, k;
int t, tt;
const char aye[] = "yes";
const char nay[] = "no";

void solve()
{
    cin >> n >> m >> k;
    BigInt maxVoid = (n - 1) / 2 * (m - 1) / 2;
    BigInt maxElem = n * m;
    BigInt minElem = maxElem - maxVoid;
    if (k <= maxElem && k >= minElem)
        printf("Case #%d: %s\n", ++tt, aye);
    else printf("Case #%d: %s\n", ++tt, nay);
}

int main()
{
    t = nextInt();
    while (t--) solve();
    return 0;
}
