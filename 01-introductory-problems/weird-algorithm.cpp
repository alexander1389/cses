#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    long n;
    std::cin >> n;

    while (n != 1) {
        std::cout << n << " ";
        n = (n % 2) ? (n * 3 + 1) : (n / 2);
    }

    std::cout << n << std::endl;

    return 0;
}
