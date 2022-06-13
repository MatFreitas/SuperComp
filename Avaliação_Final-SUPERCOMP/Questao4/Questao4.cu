#include <random>
#include <iostream>
#include <vector>
#include <thrust/random.h>
#include <thrust/device_vector.h>
#include <thrust/transform.h>
#include <thrust/iterator/counting_iterator.h>
#include<cstring>
#include <string.h>
using namespace std;

struct calculoScore {
    thrust::device_ptr<char> subA;
    thrust::device_ptr<char> subB;

    calculoScore(thrust::device_ptr<char> subA_, thrust::device_ptr<char> subB_) :
      subA(subA_),
      subB(subB_) {};

    __device__ __host__
    int operator() (const int &i) {
        int score = (subA[i] == subB[i] ? 2 : -1);
        return score;
    }
};

int main () {
    int k;
    string a, b;

    cin >> k >> a >> b;

    thrust::device_vector<char> seqA(a.begin(), a.end());
    thrust::device_vector<char> seqB(b.begin(), b.end());
    thrust::device_vector<int> result(3);


    int num_iter = k / 3;

    thrust::device_vector<int> scoresParesK(num_iter);

    for(int i = 0; i < num_iter; i++) {
        if(i == 0) {
            thrust::transform(
                thrust::make_counting_iterator<int>(0),
                thrust::make_counting_iterator<int>(3),
                result.begin(),
                calculoScore(seqA.data(), seqB.data())
            );
        } else {
            thrust::transform(
                thrust::make_counting_iterator<int>(i*3),
                thrust::make_counting_iterator<int>(i*3 + 3),
                result.begin(),
                calculoScore(seqA.data(), seqB.data())
            );   
        }

        scoresParesK[i] = thrust::reduce(
            result.begin(),
            result.end(),
            0.0f, 
            thrust::plus<int>()  
        );
    }

    int maxScore = thrust::reduce(
        scoresParesK.begin(),
        scoresParesK.end(),
        0.0f,
        thrust::maximum<int>()
    );

    cout << maxScore << endl;

    

    return 0;
}