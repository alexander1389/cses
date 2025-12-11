#include <iostream>
#include <string>

void move(int n, int src, int dst, int aux) {
    if (n == 0) {
        return;
    }

    move(n - 1, src, aux, dst);
    std::cout << src << " " << dst << std::endl;
    move(n - 1, aux, dst, src);
}

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::cout << (1 << n) - 1 << std::endl;
    move(n, 1, 3, 2);

    return 0;
}
