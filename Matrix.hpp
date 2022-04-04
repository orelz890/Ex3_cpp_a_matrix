#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace zich{

    class Matrix{
        int rows;
        int columns;
        int mat_size;

    public:
        std::vector<double> matrix;

        // Constroctor - init matrix
        Matrix(std::vector<double> mat_vector, const int row, const int col){
            if (mat_vector.size() != (row*col)){
                throw std::runtime_error("You didnt fill the entire matrix!");
            }
            rows = row;
            columns = col;
            matrix = mat_vector;
            mat_size = row * col;
        }

        // Value changing operators:
        Matrix operator+(const Matrix &mat) const;
        Matrix operator-(const Matrix &mat) const;
        Matrix operator-() const;

        Matrix operator*(const Matrix &mat) const;
        Matrix operator*(const double scalar) const;

        Matrix& operator++();
        Matrix operator++(const int num);
        Matrix& operator--();
        Matrix operator--(const int num);

        Matrix& operator+=(const Matrix &mat);
        Matrix& operator-=(const Matrix &mat);
        Matrix& operator*=(const Matrix &mat);
        Matrix& operator*=(const double scalar);

        // Compering operators
        bool operator>(const Matrix &mat) const;
        bool operator>=(const Matrix &mat) const;
        bool operator<(const Matrix &mat) const;
        bool operator<=(const Matrix &mat) const;
        bool operator==(const Matrix &mat) const;
        bool operator!=(const Matrix &mat) const;

        // // Input/output
        friend std::ostream& operator<<(std::ostream& os , const Matrix& mat);
        friend std::istream& operator>> (std::istream &is, Matrix& mat );
        friend Matrix operator*(const double scalar, const Matrix &mat);

    };


}
