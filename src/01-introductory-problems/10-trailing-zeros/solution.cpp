#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    long n;
    std::cin >> n;

    int result = 0;
    for (long i = 5; i <= n; i *= 5) {
        result += n / i;
    }

    std::cout << result << std::endl;

    return 0;
}
