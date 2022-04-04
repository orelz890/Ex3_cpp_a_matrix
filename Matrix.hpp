#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace zich{
    class Matrix{
    private:
        int rows;
        int columns;
        vector<double> matrix;
    public:

        // Constroctor - init matrix
        Matrix(const vector<double> mat_vector, const int row, const int col){
            if (mat_vector.size() != (row*col)){
                throw runtime_error("You didnt fill the entire matrix!");
            }
            rows = row;
            columns = col;
            matrix = mat_vector;
        }

        // Value changing operators:
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
        friend Matrix operator*(const double scalar, Matrix &mat);

    };

}