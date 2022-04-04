#include "Matrix.hpp"
#include <limits.h>


// How to run: g++ -o a.out Matrix.cpp Matrix_main.cpp Matrix.hpp
using namespace std;

std::vector<double> mat_data = {1, 1, 1, 1, 1, 1, 1, 1, 1};

namespace zich{

}

int main(){
    zich::Matrix m{mat_data, 3, 3};
    zich::Matrix m2{mat_data, 3, 3};

    // zich::Matrix ans = (m2*2) * (m*3);
    // cout << m << '\n' << m;
    cout << ((m > m2) == false);
    return 0;
}