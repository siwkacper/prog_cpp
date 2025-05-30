#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

const std::string input_path = "dna.txt";
const std::string output_path = "dna_diff.txt";


bool is_valid_dna(const std::string& seq) {
    for (char n : seq) {
        char uc = toupper(n);
        if (uc != 'A' && uc != 'C' && uc != 'G' && uc != 'T') return false;
    }
    return true;
}

std::string compare_sequences(const std::string& s1, const std::string& s2) {
    std::string result;
    bool first = true;

    for (size_t i = 0; i < s1.size(); ++i) {
        if (toupper(s1[i]) != toupper(s2[i])) {
            if (!first) result += ",";
            result += std::to_string(i);
            first = false;
        }
    }

    return result;
}

void process_dna_pairs() {
    std::ifstream f_in(input_path);
    std::ofstream f_out(output_path);

    if (!f_in || !f_out) {
        std::cerr << "Cannot open input or output file."<<std::endl;
        return;
    }

    std::string line1, line2;
    while (std::getline(f_in, line1) && std::getline(f_in, line2)) {
        if (!is_valid_dna(line1) || !is_valid_dna(line2)) {
            f_out << "invalid dna sequence" << std::endl;
        } else {
            f_out << compare_sequences(line1, line2) << std::endl;
        }
    }
}


int main() {
    process_dna_pairs();

    return 0;
}
