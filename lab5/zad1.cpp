#include <iostream>

struct dna_t {
    int a=0;
    int t=0;
    int c=0;
    int g=0;
};

dna_t count_nucleotides(char * dna){
    dna_t result = {0, 0, 0, 0};

    for (int i = 0; dna[i] != '\0'; i++) {

    switch (dna[i]){

        case 'A':
        case 'a':
            result.a++;
            break;
        
        case 'T':
        case 't':
            result.t++;
            break;
        
        case 'C':
        case 'c':
            result.c++; // ;)
            break;
        
        case 'G':
        case 'g':
            result.g++; // :]
            break;
    
        default:
            //If character does not match any cannonical nucleotide symbol end program
            std::cout<<"This sequence contains invalid characters!";
            exit(0);
        }
    }
    return result;
}

int main(){

    char sequence[1024]; /*Input nucleotide sequence*/



    std::cin >> sequence;


    dna_t results = count_nucleotides(sequence);

    printf("A: %d T: %d C: %d G: %d\n", results.a, results.t, results.c, results.g);


    return 0;
}