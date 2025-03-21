#include <iostream>
using namespace std;

char complement(char in_nuc){
    /*This function is used to match nucleotides with their complementary counterparts*/
    
        switch(in_nuc){
            case 'A':
                return 'T';
                break;
    
            case 'T':
                return 'A';
                break;
            
            case 'C':
                return 'G';
                break;
            
            case 'G':
                return 'C';
                break;
            
            default:
                cout << "Input contains a character which is not a nucleotide symbol\n";
                exit(1);
        }
    }


int main(){
       
    string sequence; /*Input nucleotide sequence*/
    
    cout << "Input a nucleotide sequence: ";
    cin >> sequence;

    cout << "Reverse complementary sequence: ";
    
    for (int i = sequence.length()-1; i >= 0 ; i-- ){
        cout << complement(sequence[i]);
    }

    cout << '\n';

    return 0;
}