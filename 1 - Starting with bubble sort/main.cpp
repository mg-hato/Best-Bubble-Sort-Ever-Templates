#include <vector>
#include <iostream>

void bubbleSort(std::vector<int>& a) {
    for(unsigned i = 0; i < a.size(); ++i) {
        for(unsigned j = 1; j < a.size() - i; ++j) {
            if(a[j] < a[j-1]) {
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }
}

void printVector(const std::vector<int>& a) {
    for(unsigned i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
}

void printSortPrint(std::vector<int>& a) {
    std::cout << "Before: ";
    printVector(a);
    bubbleSort(a);
    std::cout << "After: ";
    printVector(a);
}


int main() {
    std::vector<int> vec{ 37, 9, 100, 13, 51 };
    printSortPrint(vec);
    return 0;
}