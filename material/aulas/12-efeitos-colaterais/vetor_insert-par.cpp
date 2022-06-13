#include <vector>
#include <iostream>
#include <unistd.h>
#include<omp.h>
using namespace std;


double conta_complexa(int i) {
	return 2 * i;
}

int main() {
	int N = 10000; 
    double init_time, final_time;
	std::vector<double> vec;

    init_time = omp_get_wtime();

    #pragma omp parallel for 
	for (int i = 0; i < N; i++) {
        double conta_complexa = 2*i;
        #pragma omp critical 
        {
		    vec.push_back(conta_complexa);
        }
	}
	
	for (int i = 0; i < N; i++) {
		cout << i << " ";
	}

    final_time = omp_get_wtime() - init_time;

    std::cout << final_time << " secs\n";
	
	return 0;
}
