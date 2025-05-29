#include <iostream>
#include <cstring>

int count_substring( char * dna, char * substring){
    int counter = 0;
    int len = strlen(substring);
    
    while (*dna){
        char * sub = substring;
        char * str = dna;
        while(*sub && *str == *sub){
            str++;
            sub++;
        }

        if (*sub == '\0'){
                counter++;
            }

        dna++;
        }

    return counter;
}

int main(){
    char dna[1024];
    char substring[1024];

    std::cin >> dna;
    std::cin >> substring;

    std::cout << count_substring(dna, substring);

    return 0;
}