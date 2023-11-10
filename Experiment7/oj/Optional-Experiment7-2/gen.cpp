#include<cstring>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

int main() {
    for(int i=1; i<=10; ++i) {
        string infname = to_string(i) + ".in";
        string outfname = to_string(i) + ".out";
        int a, b, n;
        ofstream infile(infname);
        ofstream outfile(outfname);
        cin >> a >> b >> n;
        infile << a << " " << b << " " << n << endl;
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += (a - i) * (b - i);
        }
        outfile << sum << endl;
    }
    return 0;
}