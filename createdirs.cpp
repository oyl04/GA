#include <bits/stdc++.h>
#include <dir.h>
#define ld long double
using namespace std;


const int sz = 3005;

string create[sz], s[sz];

int cnt = 0, crcnt = 0;


int st[100];
int n[sz], t[sz], mode[sz], pr[sz], delt[sz];
ld C[sz];
ld coef[sz];

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

void m1(){
    ifstream fin;
    ofstream fout1, fout2;
    string s;
    char ch;
    fin.open("crt.cpp");
    while(fin)
    {
        fin.get(ch);
        if(fin.eof()) break;
        s += ch;
    }
    fin.close();
    int j = 0;
    string y[3] = {"100", "500", "1000"};
    for (int i = 34; i <= 39; ++i){
        fout1.open(create[i] + "create.cpp");
        fout1 << s;
        fout2.open(create[i] + "input.txt");
        fout2 << y[j++] << ' ' << 100 << '\n';
        fout2.close();
        fout1.close();
        string a = "g++ -std=c++11 -o ";
        a += create[i];
        a += "create.exe ";
        a += create[i];
        a += "create.cpp";
        string b = "start /b /w /D";
        b += "\"";
        b += create[i];
        b += "\"";
        b += " create.exe";
        system(a.c_str());
        system(b.c_str());
        j %= 3;
    }
    fin.open("crtpow.cpp");
    s.clear();
    while(fin)
    {
        fin.get(ch);
        if(fin.eof()) break;
        s += ch;
    }
    fin.close();
    for (int i = 40; i <= 42; ++i){
        fout1.open(create[i] + "create.cpp");
        fout1 << s;
        fout2.open(create[i] + "input.txt");
        fout2 << y[j++] << ' ' << 10 << '\n';
        fout2.close();
        fout1.close();
        string a = "g++ -std=c++11 -o ";
        a += create[i];
        a += "create.exe ";
        a += create[i];
        a += "create.cpp";
        string b = "start /b /w /D";
        b += "\"";
        b += create[i];
        b += "\"";
        b += " create.exe";
        system(a.c_str());
        system(b.c_str());
        j %= 3;
    }
    fin.open("crte.cpp");
    s.clear();
    while(fin)
    {
        fin.get(ch);
        if(fin.eof()) break;
        s += ch;
    }
    fin.close();
    for (int i = 43; i <= 45; ++i){
        fout1.open(create[i] + "create.cpp");
        fout1 << s;
        fout2.open(create[i] + "input.txt");
        fout2 << y[j++] << ' ' << 10 << '\n';
        fout2.close();
        fout1.close();
        string a = "g++ -std=c++11 -o ";
        a += create[i];
        a += "create.exe ";
        a += create[i];
        a += "create.cpp";
        string b = "start /b /w /D";
        b += "\"";
        b += create[i];
        b += "\"";
        b += " create.exe";
        system(a.c_str());
        system(b.c_str());
        j %= 3;
    }
    fin.open("crtp.cpp");
    s.clear();
    while(fin)
    {
        fin.get(ch);
        if(fin.eof()) break;
        s += ch;
    }
    fin.close();
    for (int i = 46; i <= 48; ++i){
        fout1.open(create[i] + "create.cpp");
        fout1 << s;
        fout2.open(create[i] + "input.txt");
        fout2 << y[j++] << ' ' << 10 << '\n';
        fout2.close();
        fout1.close();
        string a = "g++ -std=c++11 -o ";
        a += create[i];
        a += "create.exe ";
        a += create[i];
        a += "create.cpp";
        string b = "start /b /w /D";
        b += "\"";
        b += create[i];
        b += "\"";
        b += " create.exe";
        system(a.c_str());
        system(b.c_str());
        j %= 3;
    }
    return;
}

void m2(int i, string p){
    ofstream table;
    table.open("C:\\global\\program\\table.txt", ios::app);
    table << pr[i] << ' ';
    table.close();
    ifstream fin;
    ofstream fout;
    string s;
    char ch;
    fin.open(p);
    while(fin)
    {
        fin.get(ch);
        if(fin.eof()) break;
        s += ch;
    }
    fin.close();
    fout.open(create[i] + "main.cpp");
    fout << s;
    fout.close();
    string a = "g++ -std=c++11 -o ";
    a += create[i];
    a += "main.exe ";
    a += create[i];
    a += "main.cpp";
    string b = "start /b /w /D";
    b += "\"";
    b += create[i];
    b += "\"";
    b += " main.exe";
    system(a.c_str());
    system(b.c_str());
    return;
}

ld wht(string s){
    if (s[0] == 't') return s[2] - '0';
    else {
        return ((ld)(s[4] - '0') / 10) + ((ld)(s[5] - '0') / 100) + ((ld)(s[6] - '0') / 1000);
    }
}

int h[3] = {100, 500, 1000}, z1[3] = {10, 50, 150}, z2[2] = {2, 4};
ld z3[3] = {0.25, 1, 2};


void f1(){
 for (int i = st[1]; i < st[2]; ++i){
        int z = i - st[1];
        if (z < 3) {
            mode[crcnt] = mode[2];
            delt[crcnt] = z1[z];
            create[crcnt++] = create[2] + s[i];
        }
        else {
            if (z >= 5){
                z -= 5;
                mode[crcnt] = mode[3];
                C[crcnt] = z2[z];
                create[crcnt++] = create[3] + s[i];
            }
        }
     }
     for (int i = st[1]; i < st[2]; ++i){
        int z = i - st[1];
            if (z >= 3 && z <= 5){
                z -= 3;
                C[crcnt] = z3[z];
                mode[crcnt] = mode[4];
                create[crcnt++] = create[4] + s[i];
            }
     }
     return;
}

void add(string s){
    ofstream gr;
    gr.open("graphs.in", ios::app);
    string t[10] = {"cob","favg", "fdev", "fmin", "grow", "int", "rr", "s", "teta", "unique"};
    for (int j = 0; j < 10; ++j){
        gr << s + t[j] + ".txt" << '\n';
        gr << s + t[j] + ".png" << '\n';
    }
    gr.close();
}

int main()
{
//    int j = 1;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    for (int j = 1; j <= 10; ++j){
    s[cnt++] = "C:\\global\\program\\";
    create[crcnt++] = s[0];
    st[0] = cnt;
    s[cnt++] = "FH\\";
    s[cnt++] = "FHD\\";
    s[cnt++] = "XpowC\\";
    s[cnt++] = "E\\";
    s[cnt++] = "P(X)\\";
    st[1] = cnt;
    s[cnt++] = "delt=10\\";
    s[cnt++] = "delt=50\\";
    s[cnt++] = "delt=150\\";
    s[cnt++] = "const=0.25\\";
    s[cnt++] = "const=1\\";
    s[cnt++] = "const=2\\";
    s[cnt++] = "const=4\\";
    st[2] = cnt;
    s[cnt++] = "N=100\\";
    s[cnt++] = "N=500\\";
    s[cnt++] = "N=1000\\";
    st[3] = cnt;
    s[cnt++] = "range\\";
    s[cnt++] = "c=0.945\\";
    s[cnt++] = "c=0.955\\";
    s[cnt++] = "c=0.979\\";
    st[4] = cnt;
    s[cnt++] = "tournament\\";
    s[cnt++] = "t=2\\";
    s[cnt++] = "t=4\\";
    s[cnt++] = "t=5\\";
    st[5] = cnt;
    for (int i = st[0]; i < st[1]; ++i){
        mode[crcnt] = i;
        create[crcnt++] = s[0] + s[i];
    }
    f1();
    for (int i = 1; i <= 13; ++i){
            if (i >= 2 && i <= 4) continue;
            mode[crcnt] = mode[i];
            C[crcnt] = C[i];
            delt[crcnt] = delt[i];
            create[crcnt++] = create[i] + s[st[3]];
            mode[crcnt] = mode[i];
            C[crcnt] = C[i];
            delt[crcnt] = delt[i];
            create[crcnt++] = create[i] + s[st[4]];
    }
    for (int i = 1; i <= 5; ++i){
        for (int j = st[2]; j < st[3]; ++j){
            mode[crcnt] = mode[i];
            n[crcnt] = h[j - st[2]];
            create[crcnt++] = create[i] + s[j];
        }
    }
    for (int i = 14; i <= 33; ++i){
        for (int j = st[2]; j < st[3]; ++j){
        mode[crcnt] = mode[i];
        C[crcnt] = C[i];
        delt[crcnt] = delt[i];
        n[crcnt] = h[j - st[2]];
        create[crcnt++] = create[i] + s[j];
        }
    }
    for (int i = 49; i <= 108; ++i){
        int z = i - 49;
        z %= 6;
        for (int j = st[3 + (z >= 3)] + 1; j < st[4 + (z >= 3)]; ++j){
        mode[crcnt] = mode[i];
        C[crcnt] = C[i];
        delt[crcnt] = delt[i];
        n[crcnt] = n[i];
        if (wht(s[j]) < 1) coef[crcnt] = wht(s[j]);
        else t[crcnt] = wht(s[j]);
        create[crcnt++] = create[i] + s[j];
        }
    }
    for (int i = 109; i < 289; ++i){
        string l = "progin";
        mode[crcnt] = mode[i];
        n[crcnt] = n[i];
        t[crcnt] = t[i];
        C[crcnt] = C[i];
        delt[crcnt] = delt[i];
        coef[crcnt] = coef[i];
        pr[crcnt] = j;
        create[crcnt++] = create[i] + l + tostr(j) + "\\";
        }
    for (int i = 0; i < crcnt; ++i){
        mkdir(create[i].c_str());
    }
    m1();
    bool v[5];
    for (int i = 0; i < crcnt; ++i){
        v[0] = mode[i], v[1] = n[i], v[2] = t[i], v[3] = coef[i], v[4] = pr[i];
        int x = v[0] + v[1] + v[2] + v[3] + v[4];
        if (x >= 4){
            ofstream out;
            out.open(create[i] + "in.txt");
            string u;
            for (int j = 0; j < crcnt; ++j){
                if (n[j] == n[i] && mode[j] == mode[i] && coef[j] + pr[j] + t[j] == 0) {
                    u = create[j];
                    break;
                }
            }
            out << n[i] << ' ' << (t[i] > 0 ? t[i] : coef[i]) << ' ';
            if (delt[i]  + C[i] > 0) out << delt[i] + C[i]  << '\n';
            out << u << '\n';
            out.close();
        }
    }
    for (int i = 0; i < crcnt; ++i){
        v[0] = mode[i], v[1] = n[i], v[2] = t[i], v[3] = coef[i], v[4] = pr[i], v[5] = C[i] + delt[i];
        int x = v[0] + v[1] + v[2] + v[3] + v[4] + v[5];
        if (x >= 5 || (x >= 4 && mode[i] == 1)){
            if (mode[i] == 1 && coef[i] > 0){
                if (pr[i] == 1) {
                    ofstream table;
                    table.open("C:\\global\\program\\table.txt", ios::app);
                    table << "FH_rang_c=" << coef[i] << "_n=" << n[i] << '\n';
                    table.close();
                }
                add(create[i]);
                m2(i, "mode1r.cpp");
            }
            if (mode[i] == 1 && t[i] > 0){
                if (pr[i] == 1) {
                    ofstream table;
                    table.open("C:\\global\\program\\table.txt", ios::app);
                    table << "FH_tour_t=" << t[i] << "_n=" << n[i] << '\n';
                    table.close();
                }
                add(create[i]);
                m2(i, "mode1t.cpp");
            }
            if (mode[i] == 2 && coef[i] > 0){
                if (pr[i] == 1) {
                    ofstream table;
                    table.open("C:\\global\\program\\table.txt", ios::app);
                    table << "FHD_rang_c=" << coef[i] << "_n=" << n[i] << "_delta=" << delt[i] << '\n';
                    table.close();
                }
                add(create[i]);
                m2(i, "mode2r.cpp");
            }
            if (mode[i] == 2 && t[i] > 0){
                if (pr[i] == 1) {
                    ofstream table;
                    table.open("C:\\global\\program\\table.txt", ios::app);
                    table << "FHD_tour_t=" << t[i] << "_n=" << n[i] << "_delta=" << delt[i] << '\n';
                    table.close();
                }
                add(create[i]);
                m2(i, "mode2t.cpp");
            }
            if (mode[i] == 3 && t[i] > 0){
                if (pr[i] == 1) {
                    ofstream table;
                    table.open("C:\\global\\program\\table.txt", ios::app);
                    table << "X^C_tour_t=" << t[i] << "_n=" << n[i] << "_const=" << C[i] << '\n';
                    table.close();
                }
                add(create[i]);
                m2(i, "mode3t.cpp");
            }
            if (mode[i] == 3 && coef[i] > 0){
                if (pr[i] == 1) {
                    ofstream table;
                    table.open("C:\\global\\program\\table.txt", ios::app);
                    table << "X^C_rang_c=" << coef[i] << "_n=" << n[i] << "_const=" << C[i] << '\n';
                    table.close();
                }
                add(create[i]);
                m2(i, "mode3r.cpp");
            }
            if (mode[i] == 4 && t[i] > 0){
                if (pr[i] == 1) {
                    ofstream table;
                    table.open("C:\\global\\program\\table.txt", ios::app);
                    table << "E_tour_t=" << t[i] << "_n=" << n[i] << "_const=" << C[i] << '\n';
                    table.close();
                }
                add(create[i]);
                m2(i, "mode4t.cpp");
            }
            if (mode[i] == 4 && coef[i] > 0){
                if (pr[i] == 1) {
                    ofstream table;
                    table.open("C:\\global\\program\\table.txt", ios::app);
                    table << "E_rang_c=" << coef[i] << "_n=" << n[i] << "_const=" << C[i] << '\n';
                    table.close();
                }
                add(create[i]);
                m2(i, "mode4r.cpp");
            }
            if (mode[i] == 5 && t[i] > 0){
                if (pr[i] == 1) {
                    ofstream table;
                    table.open("C:\\global\\program\\table.txt", ios::app);
                    table << "P(X)_tour_t=" << t[i] << "_n=" << n[i] << "_const=" << C[i] << '\n';
                    table.close();
                }
                add(create[i]);
                m2(i, "mode5t.cpp");
            }
            if (mode[i] == 5 && coef[i] > 0){
                if (pr[i] == 1) {
                    ofstream table;
                    table.open("C:\\global\\program\\table.txt", ios::app);
                    table << "P(X)_rang_c=" << coef[i] << "_n=" << n[i] << "_const=" << C[i] << '\n';
                    table.close();
                }
                add(create[i]);
                m2(i, "mode5r.cpp");
            }
        }
    }
        crcnt = 0;
        cnt = 0;
    }
    return 0;
}
