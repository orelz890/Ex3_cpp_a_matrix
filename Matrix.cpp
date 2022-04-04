#include "Matrix.hpp"

namespace zich{

    Matrix Matrix:: operator+(const Matrix &mat) const{
        return *this;
    }

    double sum_all_vals(Matrix &mat){
        double ans = 0;
        for (int i = 0; i < mat.matrix.size(); i++){
            ans += mat.matrix[(unsigned long)i];
        }
        return ans;
    }
    double sum_all_vals(const Matrix &mat){
        double ans = 0;
        for (int i = 0; i < mat.matrix.size(); i++){
            ans += mat.matrix[(unsigned long)i];
        }
        return ans;
    }
    
    Matrix Matrix:: operator-(const Matrix &mat) const{
        return *this;
    }

    Matrix Matrix:: operator-() const{
        return *this;
    }

    Matrix Matrix:: operator*(const Matrix &mat) const{
        return *this;
    }

    Matrix Matrix:: operator*(const double scalar) const{
        return *this;
    }

    Matrix& Matrix:: operator++(){

        return *this;
    }

    Matrix Matrix:: operator++(const int num){
        return *this;
    }

    Matrix& Matrix:: operator--(){
        return *this;
    }

    Matrix Matrix:: operator--(const int num){
        return *this;
    }

    Matrix& Matrix:: operator+=(const Matrix &mat){
        return *this;
    }

    Matrix& Matrix:: operator-=(const Matrix &mat){
        return *this;
    }

    Matrix& Matrix:: operator*=(const Matrix &mat){
        return *this;

    }

    Matrix& Matrix:: operator*=(const double scalar){
        return *this;

    }

    bool Matrix:: operator>(const Matrix &mat) const{
        return false;

    }

    bool Matrix:: operator>=(const Matrix &mat) const{
        return false;

    }

    bool Matrix:: operator<(const Matrix &mat) const{
        return false;

    }

    bool Matrix:: operator<=(const Matrix &mat) const{
        return false;
    }

    bool Matrix:: operator==(const Matrix &mat) const{
        return false;
    }

    bool Matrix:: operator!=(const Matrix &mat) const{
        return false;
    }

    Matrix operator*(const double scalar, const Matrix &mat){
        return mat*scalar;
    }

    std::ostream& operator<<(std::ostream& os , const Matrix& mat){

        for (int i = 0; i < mat.mat_size; i++){
            if (i % mat.columns == 0){
                os << '[' << mat.matrix.at((unsigned long)i) << ' ';
            }
            else if((i+1) % mat.columns == 0){
                os << mat.matrix.at((unsigned long)i) << ']' << '\n';
            }
            else{
                os << mat.matrix.at((unsigned long)i) << ' ';
            }
        }
        return os;
    }

    std::istream& operator>> (std::istream &is, Matrix& mat){
        int size = mat.rows * mat.columns;
        for (int i = 0; i <= size; i++){
            double temp;
            is >> temp;
            mat.matrix[(unsigned long)i] = temp;
        }
        is >> mat.rows >> mat.columns;
        return is;
    }

}
