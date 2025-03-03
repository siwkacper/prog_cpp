#include <iostream>
using namespace std;

void complement(char in_nuc){

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

    while (true){    cout << "Input a nucleotide symbol [A,T,C,G] or q to quit:";
    cin >> in_nuc;
        if (in_nuc == 'q'){
            break;
        }else{
        complement(in_nuc);
        }
    }
    return 0;
}