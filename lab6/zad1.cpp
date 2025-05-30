#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

bool is_palindrome(const std::string& seq) {
    const char* left = seq.c_str();
    const char* right = seq.c_str() + seq.length() - 1;
    while (left < right) {
        if (std::toupper(*left) != std::toupper(*right)) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

bool is_valid_dna(const std::string& seq) {
    for (char n : seq) {
        char uc = toupper(n);
        if (uc != 'A' && uc != 'C' && uc != 'G' && uc != 'T') return false;
    }
    return true;
}

int main() {
    std::ifstream file("in.txt");
    if (!file) {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }

    int n;
    file >> n;

    for (int i = 0; i < n; ++i) {
        int len;
        file >> len;
        file.ignore();

        char* buffer = new char[len + 1];
        file.getline(buffer, len + 1);
        std::string seq(buffer);
        delete[] buffer;

        if (!is_valid_dna(seq)) {
            std::cout << "INVALID" << std::endl;
        } else if (is_palindrome(seq)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
