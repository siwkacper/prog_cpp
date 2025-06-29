#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>

const std::string fp = "dna2.txt";

bool val(const std::string& s) {

    std::size_t colon_pos = s.find(':');
    if (colon_pos == std::string::npos) {
        return false;
    }

    std::size_t start = colon_pos + 1;
    while (start < s.size() && std::isspace(s[start])) {
        ++start;
    }

    for (std::size_t i = start; i < s.size(); ++i) {
        char n = std::toupper(s[i]);
        if (n != 'A' && n != 'C' && n != 'G' && n != 'T' && '\n') {
            return false;
        }
    }
    return true;
}

double gc(const std::string& s) {
    int gc = 0;
    int len = s.length();

    for (char c : s) {
        char n = std::toupper(c);
        if (n == 'G' || n == 'C') {
            gc++;
        }
    }

    if (len == 0) return 0.0;
    return (100.0 * gc) / len;
}

int main() {
    std::ifstream f(fp);
    if (!f) {
        std::cerr << "err: can't open " << fp << "\n";
        return 1;
    }

    std::string l;
    int i = 0;

    while (std::getline(f, l)) {
        i++;
        if (!val(l)) {
            std::cout << "Invalid DNA sequence\n";
        } else {
            double p = gc(l);
            std::cout << i << ": " << std::fixed << std::setprecision(2) << p << "%\n";
        }
    }

    return 0;
}
