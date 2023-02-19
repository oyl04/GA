#include <bits/stdc++.h>

using namespace std;

string s[2005];

int cnt[11];

void f(){
    ifstream f;
    ofstream fch;
    f.open("C://global//program//table.txt");
    string t;
    while (f >> t){
        if (t[0] >= '0' && t[0] <= '9'){
            int d = t[0] - '0';
            if (t.size() > 1) d *= 10;
            ++cnt[d];
            for (int i = 1; i <= 26; ++i){
            s[cnt[d]] += t;
            f >> t;
            s[cnt[d]] += ' ';
            }
            s[cnt[d]] += t;
            s[cnt[d]] += '\n';
        }
        else {
            ++cnt[0];
            s[cnt[0]] += "Configuration ";
            s[cnt[0]] += t;
            s[cnt[0]] += '\n';
            s[cnt[0]] += "Run# NI F_found I_min NI_I_min I_max NI_I_max I_avg GR_early GR_avg GR_late NI_GE_late s_min NI_s_min s_max NI_s_max s_avg RR_min NI_RR_min RR_max NI_RR_max RR_avg Teta_min NI_Teta_min Teta_max NI_Teta_max Teta_avg";
            s[cnt[0]] += '\n';
        }
    }
    fch.open("C://global//program//tablet.txt");
    for (int i = 1; i <= cnt[0]; ++i){
            fch << "\n";
            fch << s[i] << '\n';
    }
    f.close();
    return;
}

int main (){
    ifstream fin("graphs.in");
    ofstream fout("graphs.plt");
    string a, b, aout, bout;
    while (fin >> a >> b){
    fout << "set grid\n";
    fout << "set terminal png\n";
    for (int i = 0; i < a.size(); ++i){
        if (a[i] == '\\') {
            aout += '/';
        }
        else aout += a[i];
    }
    for (int i = 0; i < b.size(); ++i){
        if (a[i] == '\\') {
            bout += '/';
        }
        else bout += b[i];
    }
    fout << "set output \"" << bout << "\"\n";
    fout << "set xlabel \"" << bout << "\n";
    fout << "plot \"" << aout << "\" using 1:2 with linespoints linecolor 2 pointtype 7 pointsize 2 notitle \n";
    aout.clear(), bout.clear();
    }
    f();
    fin.close();
    fout.close();
    return 0;
}
