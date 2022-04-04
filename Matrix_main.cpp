#include "Matrix.hpp"
#include <limits.h>

using namespace std;

std::vector<double> mat_data = {1, 1, 1, 1, 1, 1, 1, 1, 1};

namespace zich{

}

int main(){
    zich::Matrix m{mat_data, 3, 3};
    cout << __DBL_MAX__ + 1000;

    return 0;
}