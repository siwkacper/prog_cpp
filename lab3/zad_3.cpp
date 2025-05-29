#include <iostream>

int count_substring( char * dna, char * substring){
    while (*dna){
        while(*substring){
            int i = 0;
            if (*dna=*substring){
                dna++;
                substring++;
            }else{
                dna-i;
                substring-i;
            }
            strlen
        }

    }

}

int main(){
    char dna[1024];
    char substring[1024];

    std::cin >> dna;
    std::cin >> substring;
    int l = sizeof(substring);



    return 0;
}