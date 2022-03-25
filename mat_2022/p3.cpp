#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x;
    int w[] = {1, 2, 3};
    cout << w[0] << endl;
    vector<int> v;
    cout << "Entre com quantos números desejar:" << endl;
    while(cin >> x){
        v.push_back(x);
    }
    for (auto& e: v){
        cout << e <<endl;
    }

    // int max = v[0];
    // int min = v[0];
    // for (uint i = 0; i < v.size(); i++) {
    //     if (v[i] > max) {
    //         max = v[i];
    //     }
    //     if (v[i] < min) {
    //         min  = v[i];
    //     }
    // }

    // cout << "Maior número: " << max << endl;
    // cout << "Menor número: " << min << endl;

    size_t i = 0; //  "size_t" ocupa menos memória do que o int
    size_t greatest_index = 0;
    size_t least_index = 0;
    while (i < v.size()) {
        if (v[i] > v[greatest_index]) 
            greatest_index = i;
        if (v[i] < v[least_index])
            least_index = i;
        i += 1;
    }

    if (v.empty()) {
        cout << "O vetor é vazio" << endl;
    } else {
        cout << "Maior elemento: " << v[greatest_index] << endl;
        cout << "Menor elemento: " << v[least_index] << endl;
    }

    return 0;
}