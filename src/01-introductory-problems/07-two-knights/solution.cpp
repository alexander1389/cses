#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for (long k = 1; k <= n; k++) {
        std::cout << (k * k * k * k - 9 * k * k + 24 * k - 16LL) / 2LL << std::endl;
    }

    return 0;
}
