#include "Matrix.hpp"

namespace zich{

    Matrix Matrix:: operator+(const Matrix &mat) const{
        return *this;
    }

    double sum_all_vals(Matrix &mat){
        double ans = 0;
        return ans;
    }
    double sum_all_vals(const Matrix &mat){
        double ans = 0;
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
        return os;
    }

    std::istream& operator>> (std::istream &is, Matrix& mat){
        return is;
    }

}