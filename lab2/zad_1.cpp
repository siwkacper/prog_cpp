#include <iostream>
using namespace std;

int evaluate_nuc(char nucleotide){
    //Check which nucleotide has been read
    switch (nucleotide){

        case 'A':
        case 'a':
            return 0;
        
        case 'T':
        case 't':
            return 1;
        
        case 'C':
        case 'c':
            return 2;
        
        case 'G':
        case 'g':
            return 3;
    
        default:
            //If character does not match any cannonical nucleotide symbol end program
            cout<<"This sequence contains invalid characters!";
            exit(0);
    }
}

int main(){

    string sequence (1024, 'N'); /*Input nucleotide sequence*/
    int counter [4] = {0,0,0,0}; /*How many occurences of A, T, C, G*/

    cout << "Input nucleotide sequence: ";
    cin >> sequence;

    for (int i = 0; i < sequence.length(); i++){
        counter[evaluate_nuc(sequence[i])]++;
    }

    cout << "A-T-C-G" << endl;/*Header for output*/

    for (int i = 0; i <= 3; i++){
        cout << counter[i]<<'-';
    }
    cout <<'\b'<< endl; //Remove the hanging -
}