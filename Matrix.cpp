#include "Matrix.hpp"

using namespace zich;

std::vector<double> mat_data4 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
Matrix m{mat_data4, 3, 3};


// Matrix::Matrix(const vector<double> mat_vector, const int row, const int col){
//     if (mat_vector.size() != (row*col)){
//         throw runtime_error("You didnt fill the entire matrix!");
//     }
//     rows = row;
//     columns = col;
//     matrix = mat_vector;
// }

Matrix Matrix:: operator+(const Matrix &mat){
    return m;
}
Matrix Matrix:: operator-(const Matrix &mat){
    return m;

}

Matrix Matrix:: operator*(const Matrix &mat){
    return m;

}
Matrix Matrix:: operator*(const double scalar){
    return m;

}
// Matrix& Matrix:: operator=(const Matrix &mat){
//     return *this;
// }

Matrix& Matrix:: operator++(){
    return m;
}
Matrix Matrix:: operator++(const int num){
    return m;

}
Matrix& Matrix:: operator--(){
    return m;

}
Matrix Matrix:: operator--(const int num){
    return m;

}

Matrix& Matrix:: operator+=(const Matrix &mat){
    return m;

}
Matrix& Matrix:: operator-=(const Matrix &mat){
    return m;

}
Matrix& Matrix:: operator*=(const Matrix &mat){
    return m;

}
Matrix& Matrix:: operator*=(const double scalar){
    return m;

}

bool Matrix:: operator>( Matrix &mat){
    return true;

}
bool Matrix:: operator>=( Matrix &mat){
    return true;

}
bool Matrix:: operator<( Matrix &mat){
    return true;

}
bool Matrix:: operator<=( Matrix &mat){
    return true;

}
bool Matrix:: operator==( Matrix &mat){
    return true;

}
bool Matrix:: operator!=( Matrix &mat){
    return true;
}
