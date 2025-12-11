#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b;
        std::cin >> a >> b;

        if ((a + b) % 3 != 0) {
            std::cout << "NO" << std::endl;
            continue;
        }

        if (std::abs(a - b) > std::max(a, b) / 2) {
            std::cout << "NO" << std::endl;
            continue;
        }

        std::cout << "YES" << std::endl;
    }

    return 0;
}
