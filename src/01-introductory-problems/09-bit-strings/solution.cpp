#include <iostream>

constexpr long C = 1'000'000'000 + 7;

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    long result = 1LL;
    for (int i = 0; i < n; i++) {
        result = (result * 2) % C;
    }

    std::cout << result << std::endl;

    return 0;
}
