#include<iostream>
using namespace std;

void char_type() {
    char c;
    scanf("%c", &c);
    for(int i=8; i>=0; --i) {
        cout << bool((1<<i) & c) << ' ';
    }
    cout << endl;
    cout << int(c);
}

void int_type() {
    char c;
    // getchar();
    scanf("%d", &c);
    for(int i=8; i>=0; --i) {
        cout << bool((1<<i) & c) << ' ';
    }
    cout << endl;
    cout << int(c);
}

int main() {
    char_type();
    cout << endl << endl;
    int_type();
    return 0;
}