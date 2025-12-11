#include <iostream>
#include <string>

void gray(int n, const std::string& s, bool rev = false) {
    if (n == 0) {
        std::cout << s << std::endl;
        return;
    }

    if (!rev) {
        gray(n - 1, s + "0", false);
        gray(n - 1, s + "1", true);
    } else {
        gray(n - 1, s + "1", false);
        gray(n - 1, s + "0", true);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    gray(n, "");

    return 0;
}
