#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int teste1=1, teste2=0, cont=0, vezes=0;
    string sequence;
    cin >> sequence;
    for (int i=0; i<sequence.size(); i++) {
        if (sequence[i] == sequence[i+1]) {
            teste1++;
        }
        else {
            if (cont == 0) {
                teste2=teste1;
                cont = 1;
            }
            else {
                if (teste1 > teste2) {
                    teste2 = teste1;
                }
            }
            teste1=1;
        }
    }
    cout << teste2 << "\n";
 
    return 0;
}