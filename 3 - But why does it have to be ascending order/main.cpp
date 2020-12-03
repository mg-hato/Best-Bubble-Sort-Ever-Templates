#include <vector>
#include <iostream>
#include <functional>

template <class T, class Compare = std::less<T>>
void bubbleSort(std::vector<T>& a) {
    for(unsigned i = 0; i < a.size(); ++i) {
        for(unsigned j = 1; j < a.size() - i; ++j) {
            if(Compare()(a[j], a[j-1])) {
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

template <class T, class Compare = std::less<T>>
void printSortPrint(std::vector<T>& a) {
    std::cout << "Before: ";
    printVector(a);
    bubbleSort<T, Compare>(a);
    std::cout << "After: ";
    printVector(a);
    std::cout << std::endl;
}


// for integers x,y, define decimal digits ordering as:
//  x < y if and only if number of decimal digits of x
//  is smaller than number of decimal digits of y
//  (for negative numbers, minus-sign is not counted)
class decimalDigitsOrdering {
public:
    bool operator()(const int x, const int y) {
        return digitCount(x) < digitCount(y);
    }

private:
    unsigned digitCount(int n) {
        if(n == 0) return 1;

        unsigned digCount = 0;
        if(n < 0) n = -n;
        while(n > 0) {
            n /= 10; ++digCount;
        }
        return digCount;
    }
};


// for strings x,y, define string-size ordering as:
//  x < y if and only if size of x is smaller than size of y
struct stringSizeOrdering {
    bool operator()(const std::string& x, const std::string& y) {
        return x.size() < y.size();
    }
};


int main() {
    std::vector<int> vec{ 37, 9, 100, 13 };

    std::cout << "Less than ordering:" << std::endl;
    printSortPrint(vec);

    std::cout << "Greater than ordering:" << std::endl;
    printSortPrint<int, std::greater<int>>(vec);

    std::cout << "Decimal digit ordering:" << std::endl;
    printSortPrint<int, decimalDigitsOrdering>(vec);

    std::vector<std::string> svec{ "unu", "doi", "trei", "patru", "cinci", "sase" };

    std::cout << "Lexicographical ordering:" << std::endl;
    printSortPrint<std::string>(svec);

    std::cout << "String-size ordering:" << std::endl;
    printSortPrint<std::string, stringSizeOrdering>(svec);
    return 0;
}