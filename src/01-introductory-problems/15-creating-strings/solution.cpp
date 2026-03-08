#include <array>
#include <iostream>
#include <string>

template<int N>
struct Factorial {
    static constexpr long long value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0> {
    static constexpr long long value = 1;
};

constexpr std::array<long long, 9> factorials = {
    Factorial<0>::value, Factorial<1>::value, Factorial<2>::value,
    Factorial<3>::value, Factorial<4>::value, Factorial<5>::value,
    Factorial<6>::value, Factorial<7>::value, Factorial<8>::value
};

long long count_unique_permutations(const std::string& s, std::array<int, 26>& f) {
    for (char c : s) {
        f[c - 'a']++;
    }

    long long total = factorials[s.length()];
    for (int count : f) {
        if (count > 1) {
            total /= factorials[count];
        }
    }

    return total;
}

void perm(int index, std::string& s, std::array<int, 26>& freq) {
    if (index == (int)s.size()) {
        std::cout << s << "\n";
        return;
    }

    for (int c = 0; c < 26; c++) {
        if (freq[c] > 0) {
            s[index] = 'a' + c;
            freq[c]--;
            perm(index + 1, s, freq);
            freq[c]++;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::array<int, 26> f = {0};
    std::cout << count_unique_permutations(s, f) << std::endl;

    perm(0, s, f);

    return 0;
}
