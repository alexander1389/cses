#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    if (((1LL + n) * n / 2) % 2) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    std::cout << "YES" << std::endl;

    std::cout << n / 2 << std::endl;
    for (int i = n; i > 0; i -= 4) {
        std::cout << i << " ";
        if (i > 3) {
            std::cout << i - 3 << " ";
        }
    }

    std::cout << std::endl;

    std::cout << n / 2 + n % 2 << std::endl;
    for (int i = n - 1; i > 0; i -= 4) {
        std::cout << i << " ";
        if (i > 1) {
            std::cout << i - 1 << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
