#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::vector<int> f(26);

    for (auto c: s) { f[c - 'A']++; }

    char central = 0;
    for (size_t i = 0; i < f.size(); i++) {
        if (f[i] % 2) {
            if (s.length() % 2 == 0 || central) {
                std::cout << "NO SOLUTION" << std::endl;
                return 0;
            }

            central = static_cast<char>(i + 'A');
        }
    }

    for (size_t i = 0; i < f.size(); i++) {
        std::cout << std::string(f[i] / 2, static_cast<char>(i + 'A'));
    }

    if (central) {
        std::cout << central;
    }

    for (int i = f.size() - 1; i >= 0; i--) {
        std::cout << std::string(f[i] / 2, static_cast<char>(i + 'A'));
    }

    std::cout << std::endl;

    return 0;
}
