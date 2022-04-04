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


    Matrix mat{mat_data, 3, 3};
    Matrix mat2{mat_data2, 3, 3};
    Matrix mat3{mat_data, 3, 3};
    

/* ===================================
    Both prefix & postfix funcs works
   ===================================
*/

    // Checking the ++ & -- operators
    for (size_t i = 2; i < 10; i++){
        CHECK(--mat2 == mat);
        CHECK(++mat2 == mat*2);
        // Checking that the position of the operator matters
        CHECK(mat2++ == (mat+mat));
        CHECK(mat2-- != (mat+mat));
        CHECK(++mat3 == mat * i);
    }

    Matrix m = -mat;
    Matrix m2{mat_data_neg, 3, 3};
    CHECK(m2 == m);

    Matrix temp = mat * 2;
    CHECK(temp == mat2);

    temp += temp;
    CHECK(temp == mat2 * 2);

    temp -= mat2;
    CHECK(temp == mat2);

/*
   ======================
    Matrix on matrix
   ======================
*/
    // Checking that + and += returns the same matrix
    for (int i = -10; i < 10; i++){
        Matrix temp2 = mat * (double)i;
        Matrix temp3 = mat + temp2;
        mat += temp2;
        CHECK(temp3 == mat);
    }


    // Checking that - and -= returns the same matrix
    for (int i = -10; i < 10; i++){
        Matrix temp2 = mat * (double)i;
        Matrix temp3 = mat - temp2;
        mat -= temp2;
        CHECK(temp3 == mat);
    }
    
    // Checking that * and *= returns the same matrix
    for (int i = -10; i < 10; i++){
        double scalar = (double)i;
        Matrix temp = mat * scalar;   
        mat *= scalar;
        CHECK(temp == mat);
        temp = mat * mat;
        mat *= mat;
        CHECK(temp == mat);
    }

    // Mat should be 0 matrix
    CHECK((mat * 2) == mat);

/*
    ==========================
    Matrix comparing tests
    ==========================
*/
    Matrix mat6{mat_data, 3, 3};
    Matrix mat7{mat_data2, 3, 3};
    Matrix mat8{mat_data, 3, 3};

    CHECK(mat6 == mat8);
    CHECK(mat6 <= mat8);
    CHECK(mat6 >= mat8);
    CHECK(mat6 < mat7);
    CHECK(mat7 > mat6);
    CHECK(mat6 != mat7);

    mat8 *= 10;
    for (int i = 0; i < 20; i++){
        if (i < 10){
            CHECK((mat6 * (double)i) < mat8);
            CHECK((mat6 * (double)i) <= mat8);
            CHECK((mat6 * (double)i) != mat8);
        }
        else if(i == 10){
            CHECK((mat6 * (double)i) == mat8);
            CHECK((mat6 + mat6) == (mat6 * 2));
        }
        else{
            CHECK((mat6 * (double)i) >= mat8);
            CHECK((mat6 * (double)i) > mat8);
            CHECK((mat6 * (double)i) != mat8);
        }      
    }

/*
   =========================
    Input/Output operations
   =========================
*/
    // Output:
    Matrix m9{twoX2 , 2, 2};
    std::stringstream os;
    os << m9 << endl;
    CHECK(os.str() == "[3 3]\n[2 2]\n\n");

    Matrix m10{identity , 3, 3};
    std::stringstream os1;
    os1 << m10 << endl;
    CHECK(os1.str() == "[1 0 0]\n[0 1 0]\n[0 0 1]\n\n");

    Matrix m11{fourX3 , 4, 3};
    std::stringstream os2;
    os2 << m11 << endl;
    CHECK(os2.str() == "[3 2 1]\n[3 2 1]\n[3 2 1]\n[3 2 1]\n\n");

    Matrix m12{mat_data_neg , 3, 3};
    std::stringstream os3;
    os3 << m12 << endl;
    CHECK(os3.str() == "[-1 -1 -1]\n[-1 -1 -1]\n[-1 -1 -1]\n\n");

    // Input:
    Matrix m13{2, 2};
    std::stringstream is;
    is << "[3 3], [2, 2]";
    is >> m13;
    CHECK(m13 == m9);

    Matrix m14{3, 3};
    std::stringstream is1;
    is1 << "[1 0 0], [0 1 0], [0 0 1]";
    is1 >> m14;
    CHECK(m14 == m10);

    Matrix m15{4, 3};
    std::stringstream is2;
    is2 << "[3 2 1], [3 2 1], [3 2 1], [3 2 1]";
    is2 >> m15;
    CHECK(m15 == m11);

    Matrix m16{3, 3};
    std::stringstream is3;
    is3 << "[-1 -1 -1], [-1 -1 -1], [-1 -1 -1]";
    is3 >> m16;
    CHECK(m16 == m12);


}


TEST_CASE("Bad input") {

    Matrix mat{mat_data, 3, 3};
    Matrix mat2{mat_data2, 3, 3};
    Matrix mat3{mat_data, 3, 3};
    std::vector<double> empty_data = {};

/*
   ==================
    Negetive input
   ==================
*/
        
    for (int i = -50; i < 0; i++){
        CHECK_THROWS((Matrix{mat_data, i, 3}));
        CHECK_THROWS((Matrix{mat_data, 3, i}));
        CHECK_THROWS((Matrix{mat_data, i, i}));
        CHECK_THROWS((Matrix{mat_data, i*i, i}));
        CHECK_THROWS((Matrix{mat_data, i, i*i}));
    }

/*
   ====================
    Illigal empty case
   ====================
*/
    for (int i = 0; i < 50; i++){
        CHECK_THROWS((Matrix{mat_data, 0, i}));
        CHECK_THROWS((Matrix{mat_data, i, 0}));  
        CHECK_THROWS((Matrix{empty_data, i, i}));
    }
    
/*
   ========================================
    Matrix size not equels Row*Col == size
   ========================================
*/
    for (int i = 0; i < 50; i++){
        CHECK_THROWS((Matrix{fourX3, i, i}));
        CHECK_THROWS((Matrix{fourX3, i, i + 2}));
        CHECK_THROWS((Matrix{fourX3, i, i + 3}));
    }

}

TEST_CASE("Illigal operations"){


/*
   =======================
    Diffrent matrix size
   =======================
*/

    for (int i = 0; i < 50; i++){
        Matrix m4on3 = (mat4on3 * i);
        Matrix m2on2 = (mat2on2 * i);
        Matrix m3on3 = (mat3on3 * i);
        Matrix m4on4 = (mat4on4 * i);
/* 
   ==================
   Illigal compering
   ==================
*/
        bool t;
        // Mix even & odd compering
        CHECK_THROWS(t = (m2on2 < mat3on3));
        CHECK_THROWS(t = (m3on3 <= mat4on3));
        CHECK_THROWS(t =(m2on2 != mat3on3));
        CHECK_THROWS(t = (m3on3 > mat2on2));
        CHECK_THROWS(t = (m4on3 >= mat3on3));
        CHECK_THROWS(t = (m2on2 == mat3on3));

        // Even & even compering
        CHECK_THROWS(t = (m4on4 >= mat2on2));
        CHECK_THROWS(t = (m2on2 < mat4on4));
        CHECK_THROWS(t = (m2on2 > mat4on4));
        CHECK_THROWS(t = (m4on4 <= mat2on2));
        CHECK_THROWS(t = (m2on2 != mat4on4));
        CHECK_THROWS(t = (m4on4 == mat2on2));

/*
   =====================
    Illigal aritmetics:
   =====================
*/  
        CHECK_THROWS(m2on2 + mat3on3);
        CHECK_THROWS(m3on3 - mat4on3);
        CHECK_THROWS(m2on2 * mat3on3);

        CHECK_THROWS(m4on4 += mat2on2);
        CHECK_THROWS(m2on2 -= mat4on4);
        CHECK_THROWS(m2on2 *= mat4on4);

        CHECK_THROWS(m3on3 + mat2on2);
        CHECK_THROWS(m4on3 * mat3on3);
        CHECK_THROWS(m2on2 - mat3on3);
        
        CHECK_THROWS(m4on4 -= mat2on2);
        CHECK_THROWS(m2on2 += mat4on4);
        CHECK_THROWS(m4on4 *= mat2on2);                
    }

/*
   =========================
    Input/Output operations
   =========================
*/

    // Matrix size < data size

    // Input:
    Matrix m13{1, 2};
    std::stringstream is;
    is << "[3 3], [2, 2]";
    CHECK_THROWS(is >> m13);

    Matrix m14{3, 2};
    std::stringstream is1;
    is1 << "[1 0 0], [0 1 0], [0 0 1]";
    CHECK_THROWS(is1 >> m14);

    // // Matrix size > data size

    // Matrix m15{4, 4};
    // std::stringstream is2;
    // is2 << "[3 2 1], [3 2 1], [3 2 1], [3 2 1]";
    // CHECK_THROWS(is2 >> m15);

    // Matrix m16{10, 10};
    // std::stringstream is3;
    // is3 << "[-1 -1 -1], [-1 -1 -1], [-1 -1 -1]";
    // CHECK_THROWS(is3 >> m16);
}
