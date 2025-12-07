#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    std::string sequence;
    std::cin >> sequence;

    int longest = 0;
    for (unsigned int i = 0; i < sequence.length(); i++) {
        int current;
        for (current = 1; i < sequence.length() - 1 && sequence[i] == sequence[i+1]; i++, current++) {
            ;
        }

        if (current > longest) {
            longest = current;
        }
    }

    std::cout << longest << std::endl;

    return 0;
}
