#include <iostream>
#include <omp.h>

using namespace std;

int main(){
    int iam;

    // esse private iam faz com que cada thread tenha uma copia privada desses valores
    // evita repetição e lixos
    #pragma omp parallel private(iam)
    {
        iam = omp_get_thread_num();
        // esse single faz com que apenas a thread mais rapida print a frase
        // single = semaforo que so deixa passar uma thread
        #pragma omp single
        cout << "Ola sou a thread " << iam << endl;
    }

    return 0;
}