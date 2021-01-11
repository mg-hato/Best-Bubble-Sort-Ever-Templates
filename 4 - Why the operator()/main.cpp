
#include <queue>
#include <iostream>
#include <vector>
#include <set>

// class that defines decimal digit ordering
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

int main() {
    std::vector<int> x{ 21, 11, 10000, 35, 43, 111 };

    // priority queue whose top element is some number written with most digits (in decimal)
    std::priority_queue<int, std::vector<int>, decimalDigitsOrdering> pq(x.begin(), x.end());
    std::cout << "Top element for a priority queue with decimal-digits ordering: " << pq.top() << std::endl;

    // ordered set usng `<` operator to order
    std::set<int, std::less<int>> numbers(x.begin(), x.end());

    auto lb = numbers.lower_bound(21);
    auto ub = numbers.upper_bound(21);
    std::cout << "Lower & upper bound of 21: " << *lb << ' ' << *ub << std::endl;
    return 0;
}