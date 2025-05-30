#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

bool is_valid_dna(const std::string& seq) {
    for (char n : seq) {
        char uc = toupper(n);
        if (uc != 'A' && uc != 'C' && uc != 'G' && uc != 'T') return false;
    }
    return true;
}

std::vector<int> find_motif_indices(const std::vector<std::string>& dna_seqs, const std::string& motif) {
    std::vector<int> found_indices;
    for (size_t i = 0; i < dna_seqs.size(); ++i) {
        if (dna_seqs[i].find(motif) != std::string::npos) {
            found_indices.push_back(static_cast<int>(i));
        }
    }

    return found_indices;
}

int main() {
    std::ifstream file("dna.txt");
    if (!file) {
        std::cerr << "Cannot open file" << std::endl;
        return 1;
    }

    std::vector<std::string> dna_seqs;
    std::string line;
    while (std::getline(file, line)) {
        if (is_valid_dna(line)) {
            dna_seqs.push_back(line);
        }
    }

    std::string motif;
    std::cin >> motif;

    std::vector<int> found_indices = find_motif_indices(dna_seqs, motif);

    for (size_t i = 0; i < found_indices.size(); ++i) {
        std::cout << found_indices[i];
        if (i + 1 < found_indices.size()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}
