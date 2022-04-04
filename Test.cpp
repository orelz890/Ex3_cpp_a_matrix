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
std::vector<double> mat_data = {1, 1, 1, 1, 1, 1, 1, 1, 1};
std::vector<double> mat_data_neg = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
std::vector<double> mat_data2 = {2, 2, 2, 2, 2, 2, 2, 2, 2};
std::vector<double> fourX3 = {3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1};
std::vector<double> twoX2 = {3, 3, 2, 2};

Matrix matId{identity, 3, 3};
Matrix matNegId{negIdentity, 3, 3};
Matrix mat2on2{twoX2, 2, 2};
Matrix mat3on3{arr3, 3, 3};
Matrix mat4on4{arr4, 4, 4};
Matrix mat4on3{fourX3, 4, 3};


TEST_CASE("Good tests"){

    SUBCASE("Basic math test"){
        Matrix mat{mat_data, 3, 3};
        Matrix mat2{mat_data2, 3, 3};
        Matrix mat3{mat_data, 3, 3};
        
        SUBCASE("Both prefix & postfix funcs works"){
            // Checking the ++ & -- operators
            for (size_t i = 2; i < 10; i++){
                CHECK(--mat2 == mat);
                CHECK(++mat2 == mat*2);
                // Checking that the position of the operator matters
                CHECK(mat2++ == (mat+mat));
                CHECK(mat2-- == (mat+mat));
                CHECK(++mat3 == mat * i);
            }
            Matrix m = -mat;
            Matrix m2{mat_data_neg, 3, 3};
            CHECK(m2 == m);      
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
            // Checking that * and *= returns the same matrix
            for (int i = -10; i < 10; i++){
                double scalar = (double)i;
                Matrix temp = mat * scalar;   
                mat *= temp;
                CHECK(temp == (mat * temp));
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
            CHECK_FALSE((mat * 2) == mat);
        }

    }

    SUBCASE("Matrix comparing tests"){

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

    // SUBCASE("Input/Output operations"){
        
    // }

}


TEST_CASE("Bad input") {

    Matrix mat{mat_data, 3, 3};
    Matrix mat2{mat_data2, 3, 3};
    Matrix mat3{mat_data, 3, 3};
    std::vector<double> empty_data = {};

    SUBCASE("Negetive input"){
        
        for (int i = -50; i < 0; i++){
            CHECK_THROWS((Matrix{mat_data, i, 3}));
            CHECK_THROWS((Matrix{mat_data, 3, i}));
            CHECK_THROWS((Matrix{mat_data, i, i}));
            CHECK_THROWS((Matrix{mat_data, i*i, i}));
            CHECK_THROWS((Matrix{mat_data, i, i*i}));
        }
    }

    SUBCASE("Illigal empty case"){
        for (int i = 0; i < 50; i++){
            CHECK_THROWS((Matrix{mat_data, 0, i}));
            CHECK_THROWS((Matrix{mat_data, i, 0}));  
            CHECK_THROWS((Matrix{empty_data, i, i}));
        }
    }

    SUBCASE("Matrix size not equels Row*Col == size"){
        for (int i = 0; i < 50; i++){
            CHECK_THROWS((Matrix{fourX3, i, i}));
            CHECK_THROWS((Matrix{fourX3, i, i + 2}));
            CHECK_THROWS((Matrix{fourX3, i, i + 3}));
        }
    }

}

// TEST_CASE("Illigal operations"){

//     SUBCASE("Diffrent matrix size"){
//         for (int i = 0; i < 50; i++){
//             Matrix m4on3 = (mat4on3 * i);
//             Matrix m2on2 = (mat2on2 * i);
//             Matrix m3on3 = (mat3on3 * i);
//             Matrix m4on4 = (mat4on4 * i);

//             // Mix even & odd
//             CHECK_THROWS(m4on3 * m4on4);
//             CHECK_THROWS((m2on2 < mat3on3) == false);
//             CHECK_THROWS((m3on3 <= mat4on3) == false);
//             CHECK_THROWS((m2on2 != mat3on3) == false);
//             CHECK_THROWS((m3on3 > mat2on2) == false);
//             CHECK_THROWS((m4on3 >= mat3on3) == false);
//             CHECK_THROWS((m2on2 == mat3on3) == false);

//             // Even & even
//             CHECK_THROWS((m4on4 >= mat2on2) == false);
//             CHECK_THROWS((m2on2 < mat4on4) == false);
//             CHECK_THROWS((m2on2 > mat4on4) == false);
//             CHECK_THROWS((m4on4 <= mat2on2) == false);
//             CHECK_THROWS((m2on2 != mat4on4) == false);
//             CHECK_THROWS(m2on2 * mat4on4 );
//             CHECK_THROWS(m4on4 == mat2on2);
            
//         }        
//     }



// }
