#include <iostream>
#include <string>

void print_kmers(const char* seq, int len, int k) {
    for (int i = 0; i <= len - k; ++i) {
        const char* nuc = seq + i;
        for (int j = 0; j < k; ++j) {
            std::cout << *(nuc + j);
        }
        std::cout <<std::endl;
    }
}


int main () {
    std::string seq;

    int k;
    std::cin >> seq >> k;

    int len = seq.length();

    print_kmers(seq.c_str(), len, k);

    return 0;
}

