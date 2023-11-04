#include<iostream>
#include<cstdlib>
#include<fstream>
#include<random>
#include<ctime>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int T, n;

string my_itoa(int x) {
    string s;
    while(x) {
        s += x%10+'0';
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(NULL));
    for(int i=1; i<=10; i++) {
        string filename = my_itoa(i) + ".in";
        freopen(filename.c_str(), "w", stdout);
        cerr << filename << endl;
        T = rand()%100000 + 1;
        cerr << T << endl;
        cout << T << '\n';
        for(int j=1; j<=T; j++) {
            n = rand()%1000000+ 1;
            cout << n << '\n';
        }
        fclose(stdout);
    }
    return 0;
}