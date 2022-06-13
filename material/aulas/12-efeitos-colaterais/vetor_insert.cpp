#include <vector>
#include <iostream>
#include<omp.h>
#include <unistd.h>


double conta_complexa(int i) {
	return 2 * i;
}

int main() {
	int N = 10000; 
	std::vector<double> vec;
	double init_time, final_time;
	init_time = omp_get_wtime();

	for (int i = 0; i < N; i++) {
		vec.push_back(conta_complexa(i));
	}
	
	for (int i = 0; i < N; i++) {
		std::cout << i << " ";
	}

	final_time = omp_get_wtime() - init_time;

    std::cout << final_time << " secs\n";
	
	return 0;
}
