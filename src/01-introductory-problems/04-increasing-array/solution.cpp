#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n, next, prev;
    std::cin >> n;

    long moves = 0;

    std::cin >> prev;
    for (int i = 1; i < n; i++) {
        std::cin >> next;

        if (prev > next) {
            moves += prev - next;
        } else {
            prev = next;
        }
    }

    std::cout << moves << std::endl;

    return 0;
}
