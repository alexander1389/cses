#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    std::vector<unsigned long long> out;
    out.reserve(t);

    for (int i = 0; i < t; i++) {
        unsigned long long x, y;
        std::cin >> y >> x;

        out.push_back(
            (x > y)
                ? (x % 2) ? (x * x) - (y - 1) : (x * x - 2 * (x - 1)) + (y - 1)
                : (y % 2) ? (y * y - 2 * (y - 1)) + (x - 1) : (y * y) - (x - 1)
        );
    }

    for (size_t i = 0; i < out.size(); i++) {
        std::cout << out[i] << std::endl;
    }

    return 0;
}
