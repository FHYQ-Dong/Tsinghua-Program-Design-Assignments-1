#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

bool is_prime[10000001];
int N, T;

void ertosthenes() {
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i <= 100000; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j <= 100000; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    string infilename = "", outfilename = "";
    for(int f=1; f<=10; ++f) {
        infilename = to_string(f) + ".in";
        outfilename = to_string(f) + ".out";
        freopen(infilename.c_str(), "r", stdin);
        freopen(outfilename.c_str(), "w", stdout);
        cerr << "Test Case " << f << "..." << endl;
        ertosthenes();

        scanf("%d", &T);
        while(T--) {
            scanf("%d", &N);
            if (N % 2 == 1 || N < 4) {
                printf("Input Error\n");
                continue;
            }
            else {
                for (int i = 2; i <= N; ++i) {
                    if(is_prime[i] && is_prime[N-i]) {
                        printf("%d=%d+%d\n", N, i, N-i);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}