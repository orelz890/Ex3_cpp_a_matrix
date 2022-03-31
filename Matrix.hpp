#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace zich{
    class Matrix{
    private:
        int row;
        int col;
        vector<double> mat_vector;
    public:

        // Constroctor - init matrix
        Matrix(const vector<double> mat_vector, const int row, const int col);

        // Value change operators:
        Matrix operator+(const Matrix &mat);
        Matrix operator-(const Matrix &mat);

        Matrix operator*(const Matrix &mat);
        Matrix operator*(const double scalar);

        Matrix& operator++();
        Matrix operator++(const int num);
        Matrix& operator--();
        Matrix operator--(const int num);

        Matrix& operator+=(const Matrix &mat);
        Matrix& operator-=(const Matrix &mat);
        Matrix& operator*=(const Matrix &mat);
        Matrix& operator*=(const double scalar);

        // Compering operators
        bool operator>(Matrix &mat);
        bool operator>=(Matrix &mat);
        bool operator<(Matrix &mat);
        bool operator<=(Matrix &mat);
        bool operator==(Matrix &mat);
        bool operator!=(Matrix &mat);

        // Input/output
        friend ostream& operator<<(const Matrix& mat, ostream& output);
        friend istream& operator>> (Matrix& mat, istream &os);
                
        friend Matrix operator-(Matrix &mat);
        friend Matrix operator*( Matrix &mat, const double scalar);

    };

}