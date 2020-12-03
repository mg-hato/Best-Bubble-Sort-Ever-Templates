#include <vector>
#include <iostream>

template <class T>
void bubbleSort(std::vector<T>& a) {
    for(unsigned i = 0; i < a.size(); ++i) {
        for(unsigned j = 1; j < a.size() - i; ++j) {
            if(a[j] < a[j-1]) {
                T tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
        }
    }
}

template <class T>
void printVector(const std::vector<T>& a) {
    for(unsigned i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
}

template <class T>
void printSortPrint(std::vector<T>& a) {
    std::cout << "Before: ";
    printVector(a);
    bubbleSort(a);
    std::cout << "After: ";
    printVector(a);
}


int main() {
    std::vector<int> vec{ 37, 9, 100, 13 };
    printSortPrint(vec);

    std::vector<std::string> svec{ "unu", "doi", "trei", "patru", "cinci", "sase" };
    printSortPrint<std::string>(svec);
    return 0;
}