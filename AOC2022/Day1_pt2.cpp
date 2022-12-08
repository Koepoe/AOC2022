#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

std::ifstream myfile;
int main() {
    std::vector <int> Calories;
    std::string a;
    int b;
    int count;
    int totalCount;
    myfile.open("InputDay1.txt");
    while (std::getline(myfile, a)) {
        b = atoi(a.c_str());
        if (b == 0) {
            Calories.push_back(count);
            count = 0;
        }
        count += b;
    }
    myfile.close();
    int c;
    for (int i = 0; i < 3; i++) {
        c = *std::max_element(Calories.begin(), Calories.end());
        totalCount += c;
        std::remove_copy(Calories.begin(), Calories.end(), Calories.begin(), c);
        c = 0;
    }
    std::cout << totalCount;
}
