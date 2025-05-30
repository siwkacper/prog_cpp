#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

void get_seqs(std::vector<std::string>& sequences)
{
    std::ifstream in_file("dna.txt");
    if (!in_file){
        std::cerr << "Cannot open file" << std::endl;
        
        return;
    }

    std::string line;

    while (std::getline(in_file, line)){
        for (std::size_t i = 0; i < line.size(); ++i){
        
            if (line[i] >= 'a' && line[i] <= 'z'){
                line[i] = line[i] - 'a' + 'A';
            }
        }

        sequences.push_back(line);
    }
}

int find_max_count(const std::vector<std::string>& sequences)
{
    std::map<std::string, int> count_map;

    for (std::size_t i = 0; i < sequences.size(); ++i){
        count_map[sequences[i]]++;
    }

    int max_count = 0;

    for (std::map<std::string, int>::iterator it = count_map.begin(); it != count_map.end(); ++it){
        if (it->second > max_count){
            max_count = it->second;
        }
    }

    return max_count;
}

int main()
{
    std::vector<std::string> seqs;
    get_seqs(seqs);

    if (seqs.empty()){
        return 1;
    }

    int max_count = find_max_count(seqs);

    std::cout << max_count << std::endl;

    return 0;
}
