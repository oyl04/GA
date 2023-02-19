#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <iomanip>
#include <fstream>
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

unsigned int n, l;

void create() {
    ofstream fout, foutbest;
    ifstream fin;
    fin.open("input.txt");
    foutbest.open("fbest.txt");
    fout.open("g0.txt");
    string s, best;
    fin >> n >> l;
    for (int i = 0; i < l; ++i) best += '0';
    fout << best << '\n';
    foutbest << best << '\n';
    for (int i = 2; i <= n; ++i) {
        s.clear();
        int d = 0;
        while (s.size() < l) {
            int x = rand() % 2;
            s += ('0' + x);
        }
        if (s == best) --i;
        else {
            fout << s << '\n';
        }
    }
}

int main() {
    srand(time(0));
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    create();
}
