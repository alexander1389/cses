#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n, next;
    std::cin >> n;

    long long sum = 0;
    for (int i = 0; i < n - 1; i++) {
        std::cin >> next;
        sum += next;
    }

    long long S = (1LL + n) * n / 2LL;
    std::cout << (S - sum) << std::endl;

    return 0;
}
