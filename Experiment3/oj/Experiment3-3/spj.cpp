#include<fstream>
#include<vector>
#include<iostream>
#define AC 0
#define WA 1
#define ERROR -1

std::vector <int> ans1 = {1, 10, 2, 20, 4, 40, 8, 80, 16, 160}, \
                  ans2 = {1, 10, 1, 10, 2, 20, 3, 30, 5, 50}, \
                  user_output;
int buf;

int main(int argc, char *argv[]) {
    std::ifstream finput(argv[1]);
    std::ifstream fuser_output(argv[2]);
    while (fuser_output >> buf) user_output.push_back(buf);

    if (user_output.size() != ans1.size()) {
        std::cout << "WA" << std::endl;
        return WA;
    }
    for (int i=0; i<user_output.size(); ++i) {
        if (user_output[i]!=ans1[i] && user_output[i]!=ans2[i]) {
            std::cout << "WA" << std::endl;
            return WA;
        }
    }
    std::cout << "AC" << std::endl;
    return AC;
}