#include "doctest.h"
#include "Matrix.hpp"
#include <string>
#include <algorithm>

using namespace std;
using namespace zich;

std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
std::vector<double> negIdentity = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
std::vector<double> arr3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
std::vector<double> arr4 = {3, 1, 1, 3, 4, 0, 0, 1, 3, 2, 2, 0, 0, 0, 0, 0};

const Matrix matId{identity, 3, 3};
const Matrix matNegId{negIdentity, 3, 3};
Matrix mat3on3{arr3, 3, 3};
Matrix mat4on4{arr4, 4, 4};

TEST_CASE("Good tests"){
    std::vector<double> mat_data = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<double> mat_data2 = {2, 2, 2, 2, 2, 2, 2, 2, 2};

    SUBCASE("Basic math test"){
        Matrix mat{mat_data, 3, 3};
        Matrix mat2{mat_data2, 3, 3};
        Matrix mat3{mat_data, 3, 3};

        // Checking the ++ & -- operators
        for (size_t i = 2; i < 10; i++){
            CHECK(--mat2 == mat);
            CHECK(++mat2 == mat*2);
            // Checking that the position of the operator metters
            CHECK(mat2++ == (mat+mat));
            CHECK(mat2-- == (mat+mat));
            CHECK(++mat3 == mat * i);
        }
        
        Matrix temp = mat * 2;
        CHECK(temp == mat2);

        temp += temp;
        CHECK(temp == mat2 * 2);

        temp -= temp;
        CHECK(temp == mat2);
        
        SUBCASE("Matrix on matrix"){

            // Checking that + and += returns the same matrix
            for (int i = -10; i < 10; i++){
                Matrix temp2 = mat * (double)i;
                Matrix temp3 = mat + temp2;
                mat += temp2;
                CHECK(temp == mat);
            }
            // Checking that - and -= returns the same matrix
            for (int i = -10; i < 10; i++){
                Matrix temp2 = mat * (double)i;
                Matrix temp3 = mat - temp2;
                mat -= temp2;
                CHECK(temp == mat);
            }
        }
        SUBCASE("Matrix & scalar"){

            // Checking that * and *= returns the same matrix
            for (int i = -10; i < 10; i++){
                double scalar = (double)i;
                Matrix temp = mat * scalar;   
                mat *= scalar;
                CHECK(temp == mat);
            }
        }

    }

    SUBCASE("Matrix compare"){

        Matrix mat{mat_data, 3, 3};
        Matrix mat2{mat_data2, 3, 3};
        Matrix mat3{mat_data, 3, 3};

        CHECK(mat == mat3);
        CHECK(mat <= mat3);
        CHECK(mat >= mat3);
        CHECK(mat < mat2);
        CHECK(mat2 > mat);
        CHECK(mat != mat2);

        mat3 *= 10;
        for (int i = 0; i < 20; i++){
            if (i < 10){
                CHECK((mat * (double)i) < mat3);
                CHECK((mat * (double)i) <= mat3);
                CHECK((mat * (double)i) != mat3);
            }
            else if(i == 10){
                CHECK((mat * (double)i) == mat3);
                CHECK((mat + mat) == (mat * 2));
            }
            else{
                CHECK((mat * (double)i) >= mat3);
                CHECK((mat * (double)i) > mat3);
                CHECK((mat * (double)i) != mat3);
            }      
        }
    }

    SUBCASE(""){

    }

}


TEST_CASE("Bad input") {

    CHECK_THROWS();




}
