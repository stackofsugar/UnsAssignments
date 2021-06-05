#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

void bogosort(std::vector<int> &vec) {
    while (!std::is_sorted(vec.begin(), vec.end())) {
        std::random_shuffle(vec.begin(), vec.end());
    }
    return;
}

int main() {
    std::vector<int> testVec{ 765, 9, 2 };

    bogosort(testVec);

    std::cout << "Sorted vector: ";
    for (int &i : testVec) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}


