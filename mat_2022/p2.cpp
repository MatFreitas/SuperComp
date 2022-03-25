#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Entre com um número: ";
    cin >> x;
    if (!cin) {
        cout << "Você não digitou um número!" << endl;
        return 1;
    }
    int y;
    cout << "Entre com outro número: ";
    if (!(cin >>y)) {
        cout << "Você não digitou um número!" << endl;
        return 1;
    }
    cout << "Você digitou o valor " << x <<endl;

    cout << "Digite dois números! " << endl;
    cin >> x >> y;
    cout << "x = " << x << " y = " << y << endl; 

    return 0;
}