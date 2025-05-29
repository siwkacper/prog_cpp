#include <iostream>
#include <cstring>

#define IS_TRANSITION(n1, n2) (((n1 == 'A' && n2 == 'G') || (n1 == 'G' && n2 == 'A') || \
                              (n1 == 'C' && n2 == 'T') || (n1 == 'T' && n2 == 'C')))



float calculate_ratio(const char* strand_1, const char* strand_2) {
    float transition_count = 0;
    float transversion_count = 0;

    for (int i = 0; strand_1[i] != '\0' && strand_2[i] != '\0'; ++i) {
        if (*(strand_1 + i) != *(strand_2 + i)) {
            if (IS_TRANSITION(*(strand_1 + i), *(strand_2 + i))) {
                ++transition_count;
            } else {
                ++transversion_count;
            }
        }
    }
    if (transversion_count == 0){
        return transition_count;
    }else{
        return transition_count/transversion_count;
    }
}

int main() {
    char strand_alpha[1024], strand_beta[1024];

    std::cin >> strand_alpha;
    std::cin >> strand_beta;

    if (std::strlen(strand_alpha) != std::strlen(strand_beta)) {
        return 1;
    }

    float ratio = calculate_ratio(strand_alpha, strand_beta);
    
    std::cout << ratio << std::endl;

    return 0;
}
