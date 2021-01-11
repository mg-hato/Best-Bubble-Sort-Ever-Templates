
#include <queue>
#include <iostream>
#include <vector>

class oddLessThanEven {
public:
    bool operator()(const int x, const int y) {
        return x % 2 != 0 && y % 2 == 0;
    }
};

void screaming() {
    return "Screaming";
}

int main() {
    std::vector<int> x{ 11, 21, 35, 43 };
    std::priority_queue<int, std::vector<int>, screaming> pq(x.begin(), x.end());
    std::cout << pq.top() << std::endl;
    return 0;
}