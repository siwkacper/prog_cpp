#include <iostream>
#include <string>
#include <map>
#include <cctype>

char translate_codon(const std::string& codon, const std::map<std::string, char>& codon_tab) {
    auto it = codon_tab.find(codon);
    if (it != codon_tab.end()) {
        return it->second;
    }
    return '?';
}

std::string translate_seq(const std::string& input, const std::map<std::string, char>& codon_tab) {
    std::string output;
    for (size_t i = 0; i + 2 < input.length(); i += 3) {
        std::string codon = input.substr(i, 3);
        char amino = translate_codon(codon, codon_tab);
        if (amino == '?') {
            return "INVALID";
        }
        output += amino;
        if (amino == '|') break;
    }
    return output;
}

int main() {
    std::string input;
    std::cin >> input;

    for (char& nuc : input) {
        nuc = std::toupper(nuc);
    }

    std::map<std::string, char> codon_tab = {
        {"UUU", 'F'}, {"UUC", 'F'}, {"UUA", 'L'}, {"UUG", 'L'},
        {"UCU", 'S'}, {"UCC", 'S'}, {"UCA", 'S'}, {"UCG", 'S'},
        {"UAU", 'Y'}, {"UAC", 'Y'}, {"UAA", '|'}, {"UAG", '|'},
        {"UGU", 'C'}, {"UGC", 'C'}, {"UGA", '|'}, {"UGG", 'W'},
        {"CUU", 'L'}, {"CUC", 'L'}, {"CUA", 'L'}, {"CUG", 'L'},
        {"CCU", 'P'}, {"CCC", 'P'}, {"CCA", 'P'}, {"CCG", 'P'},
        {"CAU", 'H'}, {"CAC", 'H'}, {"CAA", 'Q'}, {"CAG", 'Q'},
        {"CGU", 'R'}, {"CGC", 'R'}, {"CGA", 'R'}, {"CGG", 'R'},
        {"AUU", 'I'}, {"AUC", 'I'}, {"AUA", 'I'}, {"AUG", 'M'},
        {"ACU", 'T'}, {"ACC", 'T'}, {"ACA", 'T'}, {"ACG", 'T'},
        {"AAU", 'N'}, {"AAC", 'N'}, {"AAA", 'K'}, {"AAG", 'K'},
        {"AGU", 'S'}, {"AGC", 'S'}, {"AGA", 'R'}, {"AGG", 'R'},
        {"GUU", 'V'}, {"GUC", 'V'}, {"GUA", 'V'}, {"GUG", 'V'},
        {"GCU", 'A'}, {"GCC", 'A'}, {"GCA", 'A'}, {"GCG", 'A'},
        {"GAU", 'D'}, {"GAC", 'D'}, {"GAA", 'E'}, {"GAG", 'E'},
        {"GGU", 'G'}, {"GGC", 'G'}, {"GGA", 'G'}, {"GGG", 'G'}
    };

    std::string result = translate_seq(input, codon_tab);
    std::cout << result << std::endl;


    return 0;
}
