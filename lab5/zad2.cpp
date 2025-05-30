#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>

const std::string fp = "dna.txt";

bool val(const std::string& s) {
    for (char c : s) {
        char n = std::toupper(c);
        if (n != 'A' && n != 'C' && n != 'G' && n != 'T') {
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
    while (std::getline(f, l)) {
        if (!val(l)) {
            std::cout << "Invalid DNA sequence\n";
        } else {
            double p = gc(l);
            std::cout << std::fixed << std::setprecision(2) << p << "%\n";
        }
    }

    return 0;
}
