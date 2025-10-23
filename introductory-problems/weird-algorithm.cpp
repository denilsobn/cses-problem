#include <iostream>
using namespace std;
 
int main() {
    long long int num;
    bool impar;
    cin >> num;
    cout << num << " ";
    while (num != 1) {
        impar = num%2;
        if (impar) {
            num = (num*3) + 1;
        }
        else {
            num = num/2;
        }
        cout << num << " ";
    }
    cout << endl;
 
    return 0;
}