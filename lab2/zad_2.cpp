#include <iostream>
using namespace std;

char RNA_polymerase(char nucleotide){
    //Fetch appropriate nucleotide
    switch (nucleotide){

        case 'A':
        case 'a':
            return 'U';
        
        case 'T':
        case 't':
            return 'A';
        
        case 'C':
        case 'c':
            return 'G';
        
        case 'G':
        case 'g':
            return 'C';
    
        default:
            //If character does not match any cannonical nucleotide symbol end program
            cout<<"This sequence contains invalid characters!";
            exit(0);
    }
}


int main(){
    
    string sequence; /*Input nucleotide sequence*/
    
    cout << "Input nucleotide sequence: ";
    cin >> sequence;

    cout << "Transcribed sequence: ";
    
    for (int i = 0;i<sequence.length();i++){
        cout << RNA_polymerase(sequence[i]);
    }

    cout << '\n';

    return 0;
}