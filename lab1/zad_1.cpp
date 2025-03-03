#include <iostream>
using namespace std;

void complement(char in_nuc){
/*This function is used to match nucleotides with their complementary counterparts*/
    cout << "Complimentary nucleotide is ";

    switch(in_nuc){
        case 'A':
            cout << 'T'<< endl;
            break;

        case 'T':
            cout << 'A'<< endl;
            break;
        
        case 'C':
            cout << 'G'<< endl;
            break;
        
        case 'G':
            cout << 'C'<< endl;
            break;
        
        default:
            cout << "Input is not a nucleotide symbol\n";
    }
}

int main(){

    char in_nuc='N'; /*Initialize nucleotide as any*/
    
    while (true){
        cout << "Input a nucleotide symbol [A,T,C,G]. Input q to quit:";

        cin >> in_nuc; /*get user input nucleotide*/

            if (in_nuc == 'q'){/*Check if user wants to quit*/
                break;
            }
            else{
            complement(in_nuc); /*use function to find a complementary nucleotide*/
            }
    }

    return 0;
}