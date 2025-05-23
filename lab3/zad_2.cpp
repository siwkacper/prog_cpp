#include <iostream>

int RNA_polymerase(char *dna){
    //Fetch appropriate dna
    while (*dna){
        switch (*dna){
            case 'A':
            case 'a':
                *dna='U';
                break;
            case 'T':
            case 't':
                *dna='A';
                break;
            case 'C':
            case 'c':
                *dna='G';
                break;
            case 'G':
            case 'g':
                *dna='C';
                break;
            default:
                //If character does not match any cannonical dna symbol end program
                std::cout<<"This sequence contains invalid characters!"<<std::endl;
                return 1;
        }
    dna++;
    }
    return 0;
}


int main(){
    char dna[1024];

    std::cin >> dna;
    
    RNA_polymerase(dna);

    std::cout << dna;

    return 0;
}