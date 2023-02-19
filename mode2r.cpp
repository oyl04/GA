#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <windows.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

vector <int> cnt;
vector <string> gen;
vector <ld> vavg, vdev;
ld c;
int n, l, prec = 60, cnt0[105];;

ifstream fin, fbest;
ofstream fout, fmn, favg, fdev, fgrow, cob;

unordered_map <int, int> mp;

ld save[35];
int counter[35];


ld eps = 1e-20;
string tostr(int x){
    string s;
    while (x != 0){
    s += (x % 10 + '0');
    x /= 10;
    }
    reverse(s.begin(), s.end());
    if (s.empty()) s += '0';
    return s;
}

int delta;

int numof0(string* s) {
    int d = 0;
    for (int i = 0; i < (*s).size(); ++i) if ((*s)[i] == '0') ++d;
    return (100 - d) + d * delta;
}

int usedrnk[105];

ld fsave (ld x, int i){
    save[i] = x;
    return x;
}

int rnkof;

ld rnk(int num0) {
    int k = n;
    for (int i = l; i > num0; --i) {
        k -= cnt0[i];
    }
    rnkof = k - usedrnk[num0];
    ld res = pow(c, (n - k + usedrnk[num0]));
    ++usedrnk[num0];
    return res;
}

void clr(){
    for (int i = 0; i <= l; ++i){
        usedrnk[i] = 0;
        cnt0[i] = 0;
    }
    cnt.clear();
    gen.clear();
    return;
}

void intens() {
    ofstream fs;
    fs.open("s.txt");
    pair <ld, int> mx, mn;
    pair <ld, int> mxs, mns;
    ld oall = 0, oalls = 0;
    mx.x = -1, mxs.x = -1;
    mn.x = 1e9, mns.x = 1e9;
    fout.open("int.txt");
    ld x;
    int n = vavg.size();
    for (int i = 0; i < n - 1; ++i){
        x = (vavg[i + 1] - vavg[i]);
        oalls += x;
        if (mns.x > x) mns.x = x, mns.y = i + 1;
        if (mxs.x < x) mxs.x = x, mxs.y = i + 1;
        fs << ++counter[7] << ' ' << x << '\n';
        x /= vdev[i];
        oall += x;
        if (mn.x > x) mn.x = x, mn.y = i + 1;
        if (mx.x < x) mx.x = x, mx.y = i + 1;
        fout << ++counter[5] << ' ' << x << '\n';
    }
    oalls /= (n - 1);
    oall /= (n - 1);
    fout << "#I_avg = " << fsave(oall, 7) << '\n';
    fs << "#s_avg = " << fsave(oalls, 16) << '\n';
    fout << "#I_min = " << fsave(mn.x, 3) << ' ' << " iteration number = " << fsave(mn.y, 4) << '\n';
    fs << "#s_min = " << fsave(mns.x, 12) << ' ' << " iteration number = " << fsave(mns.y, 13) << '\n';
    fout << "#I_max = " << fsave(mx.x, 5) << ' ' << " iteration number = " << fsave(mx.y, 6) << '\n';
    fs << "#s_max = " << fsave(mxs.x, 14) << ' ' << " iteration number = " << fsave(mxs.y, 15) << '\n';
    fout.close();
    fs.close();
    return;
}

ld deviat (ld avg){
    ld sum = 0;
    for (int i = 0; i < n; ++i){
        sum += (numof0(&gen[i]) - avg) * (numof0(&gen[i]) - avg);
    }
    sum /= n;
    sum = sqrt(sum);
    return sum;
}

void randnums(int z) {
    string path = "f//f";
    path += tostr(z).c_str();
    path += ".txt";
    fout.open(path.c_str());
    path.clear();
    int mn = l * delta;
    vector <pair <ld, ld> > v;
    ld l = 0, x = 0, avg = 0;
    v.pb(make_pair(-eps, 0));
    for (int i = 0; i < n; ++i) {
        int num0 = numof0(&gen[i]);
        mn = min(mn, num0);
        avg += num0;
        fout << rnkof << ' ' << gen[i] << ' ' << num0 << ' ';
        ld svrnk = rnk(mp[num0]), div = (1 - pow(c, (ld)n));
        v.pb(make_pair(l, l + (1 - c) / div * svrnk));
        ld prev = l;
        l += (1 - c) / div * svrnk;
        fout << (1 - c) / div * svrnk << '\n';
    }
    fout.close();
    ld t = 1. / 2;
    ld delt = l / n;
    for (int i = 0; i < prec; ++i) {
        if (rand() % 2) x += t;
        t /= 2;
    }
    vector <ld> chn;
    for (int i = 0; i < n; ++i) {
        x += delt;
        if (x >= 1) x -= 1;
        chn.pb(x);
    }
    sort(chn.begin(), chn.end());
    int j = 0;
    for (int i = 0; i < chn.size(); ++i) {
        if (v[j].x <= chn[i] && v[j].y > chn[i]) ++cnt[j];
        else --i, ++j;
    }
    fmn.open("fmin.txt", ios::app);
    fmn << counter[3]++ << ' ' << mn << '\n';
    fmn.close();
    favg.open("favg.txt", ios::app);
    avg /= n;
    favg << counter[1]++ << ' ' << avg << '\n';
    vavg.pb(avg);
    favg.close();
    fdev.open("fdev.txt", ios::app);
    vdev.pb(deviat(avg));
    fdev << counter[2]++ << ' ' << deviat(avg) << '\n';
    fdev.close();
    return;
}


vector <ld> vun;

void nextgen(int z){
    ofstream nxtgen;
    string path = "g//g";
    path += tostr(z).c_str();
    path += ".txt";
    nxtgen.open(path.c_str());
    int p = 0;
    for (int i = 1; i <= n; ++i){
        if (cnt[i]) ++p;
        while (cnt[i] != 0){
            nxtgen << gen[i - 1] << '\n';
            --cnt[i];
        }
    }
    vun.pb((ld)p / n);
    nxtgen.close();
    return;
}


set <string> us;


void uniq(){
    ofstream unout;
    unout.open("unique.txt", ios::app);
    unout << counter[9]++ << ' ' << us.size() << '\n';
    unout.close();
    return;
}

int NumPop;

void afteruniq(){
    ofstream fout1, fout2;
    pair <ld, int> mx, mn;
    pair <ld, int> mxteta, mnteta;
    ld oall = 0, oallteta = 0;
    mx.x = -1, mxteta.x = -1;
    mn.x = 1 + eps, mnteta.x = 1;
    fout1.open("rr.txt");
    fout2.open("teta.txt");
    ld x, xteta;
    int n = vun.size();
    for (int i = 0; i < n; ++i){
        x = vun[i];
        xteta = (1 - vun[i]);
        oall += x;
        oallteta += xteta;
        if (mn.x > x) mn.x = x, mn.y = i + 1;
        if (mnteta.x > xteta) mnteta.x = xteta, mnteta.y = i + 1;
        if (mx.x < x) mx.x = x, mx.y = i + 1;
        if (mxteta.x < xteta) mxteta.x = xteta, mxteta.y = i + 1;
        fout1 << ++counter[6] << ' ' << x << '\n';
        fout2 << ++counter[8] << ' ' << xteta << '\n';
    }
    oall /= n;
    oallteta /= n;
    fout1 << "#RR_avg = " << fsave(oall, 21) << '\n';
    fout2 << "#Teta_avg = " << fsave(oallteta, 26) << '\n';
    fout1 << "#RR_min = " << fsave(mn.x, 17) << ' ' << " iteration number = " << fsave(mn.y, 18) << '\n';
    fout2 << "#Teta_min = " << fsave(mnteta.x, 22) << ' ' << " iteration number = " << fsave(mnteta.y, 23) << '\n';
    fout1 << "#RR_max = " << fsave(mx.x, 19) << ' ' << " iteration number = " << fsave(mx.y, 20) << '\n';
    fout2 << "#Teta_max = " << fsave(mxteta.x, 24) << ' ' << " iteration number = " << fsave(mxteta.y, 25) << '\n';
    fout1.close();
    fout2.close();
    return;
}

string Path;

void foo(){
    CreateDirectoryW(L"g", NULL);
    CreateDirectoryW(L"f", NULL);
    ifstream fin, f;
    ofstream fout;
    f.open("in.txt");
    int n;
    string path, xx;
    f >> n >> c >> delta >> path;
    for (int i = 0; i <= 100; ++i){
        mp[(100 - i) + i * delta] = i;
    }
    NumPop = n;
    Path = path;
    f.close();
    path += "g0.txt";
    fin.open(path.c_str());
    fout.open("g//g0.txt");
    string s;
    vector <string> p;
    while (fin >> s){
        p.pb(s);
    }
    fin.close();
    for (int i = 0; i < p.size(); ++i){
        fout << p[i] << '\n';
    }
    fout.close();
    return;
}

void output(){
    ofstream table;
    table.open("C:\\global\\program\\table.txt", ios::app);
    for (int i = 1; i <= 26; ++i){
        table << save[i] << ' ';
    }
    table << '\n';
    table.close();
    return;
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    srand(time(0));
    foo();
    fgrow.open("grow.txt");
    string s, best;
    int i = 0;
    int cntbest = 0, prevcntbest = 0;
    bool fl = 0;
    fbest.open(Path + "fbest.txt");
    fbest >> best;
    ld grlate = 0, grearly = 0, gravg = 0;
    int t = 0;
    int sv = 0;
    while (!fl){
    fl = 1;
    string path = "g//g";
    path += tostr(i);
    path += ".txt";
    fin.open(path.c_str());
    while (fin >> s) {
        l = s.size();
        ++n;
        gen.pb(s);
        us.insert(s);
        ++cnt0[mp[numof0(&s)]];
        if (s != best) fl = 0;
        else ++cntbest;
    }
        cob.open("cob.txt", ios::app);
        cob << counter[0]++ << ' ' << (ld)cntbest / n << '\n';
        cob.close();
        if(prevcntbest != 0){
        ld x = (ld)cntbest / prevcntbest;
        if (i == 2) grearly = x;
        gravg += x;
        fgrow << ++counter[4] << ' ' << x << '\n';
        if (cntbest * 2 >= n && !t) t = i, grlate = x;
        }
        prevcntbest = cntbest;
        cntbest = 0;
        uniq();
        fin.close();
        cnt.resize(n + 1);
        randnums(i);
        if (us.size() != 1) nextgen(++i);
        us.clear();
        clr();
        sv = n;
        n = 0;
    }
    intens();
    afteruniq();
    fsave(i, 1);
    fsave(100, 2);
    gravg /= i;
    fgrow << "#GR_early = " << fsave(grearly, 8) << '\n';
    fgrow << "#GR_avg = " << fsave(gravg, 9) << '\n';
    fgrow << "#GR_late = " << fsave(grlate, 10) << '\n';
    fgrow << "#Index of GR_late = " << fsave(t, 11) << '\n';
    output();
    return 0;
}
