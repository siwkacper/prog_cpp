#include <iostream>
using namespace std;

bool check_strand(char * seq){
    for(int i = 0; seq[i] != '\0';i++){
        char nuc = toupper(seq[i]);
        if (nuc != 'A' && nuc != 'T' && nuc != 'C' && nuc != 'G'){
            return false;
        }
    }
    return true;
}


float count_nucleotides( char * dna, int * A, int *T, int * C, int * G){

    *A = *T = *C = *G = 0;


    for (int i = 0; dna[i] != '\0'; i++){
        char nucleotide = toupper(dna[i]);

        switch (nucleotide){
            case 'A':(*A)++;
                    break;
            
            case 'T':(*T)++;
                    break;
            
            case 'C':(*C)++;
                    break;
            
            case 'G':(*G)++;
                    break;
        }
    }
    //float gc_pairs = *G + *C / *A + *T + *G + *C;

    return *G + *C / *A + *T + *G + *C;
}

int main(){

    char sequence[1024]; /*Input nucleotide sequence*/
    int A_counter = 0, T_counter = 0, C_counter = 0, G_counter = 0; /*How many occurences of A, T, C, G*/

    cout << "Input nucleotide sequence: ";
    cin >> sequence;

    cout << "GC: " << count_nucleotides(sequence, &A_counter, &T_counter, &C_counter, &G_counter) << "%" << endl;


    cout << "A-T-C-G" << endl << A_counter << "-" << T_counter << "-" << C_counter << "-" << G_counter << "-";/*Header for output*/

    return 0;
}