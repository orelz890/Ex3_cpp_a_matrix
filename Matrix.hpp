#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string.h>

namespace zich{

    class Matrix{
    private:
        int rows;
        int columns;
        int mat_size;
        std::vector<double> matrix;

    public:
        int get_rows() const{
            return rows;
        }
        int get_cols() const{
            return columns;
        }
        double get_val_at(int i) const{
            return matrix.at((unsigned long)i);
        }

        // Deffult constructor
        Matrix(const int row, const int col){
            if (row <= 0 || col <= 0){
                throw std::runtime_error("Size don't match rows & cols input!");
            }
            rows = row;
            columns = col;
            mat_size = row * col;
            matrix.resize((unsigned long)mat_size);
        }
        // Constroctor - init matrix
        Matrix(std::vector<double> mat_vector, const int row, const int col){
            if (mat_vector.size() != (row*col) || row <= 0 || col <= 0){
                throw std::runtime_error("Size don't match rows & cols input!");
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
