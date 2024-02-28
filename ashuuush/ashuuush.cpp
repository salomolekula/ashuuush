#include <iostream>
#include <string>
#include <ctime>

class Matrix
{
private:

    int m;
    int n;
    int** matrix;

public:

    Matrix(int M, int N)
    {
        m = M;
        n = N;
        matrix = new int* [n];
        for (int i = 0; i < m; i++)
        {
            matrix[i] = new int[m];
        }
    }
    void randomFulling()
    {
        srand(time(0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = rand() % 10;
            }
        }
    }

    int getN()
    {
        return n;
    }

    int getM()
    {
        return m;
    }
    int getElementMatrix(int n, int m)
    {
        return matrix[n][m];
    }

    int& operator() (int n, int m)
    {
        return this->matrix[n-1][m-1];
    }


    ~Matrix()
    {

    }
};

std::ostream& operator<< (std::ostream& s, Matrix matrix)
{
    s << "Вывод матрицы: " << std::endl;
    for (int i = 0; i < matrix.getM(); i++)
    {
        for (int j = 0; j < matrix.getN(); j++)
        {
            s << matrix.getElementMatrix(i, j) << " ";
        }
        s << std::endl;
    }
    return s;
}

Matrix operator+ (Matrix matrix1, Matrix matrix2)
{
    if ((matrix2.getN() == matrix1.getN()) && (matrix2.getM() == matrix1.getM())) {
        Matrix result(matrix1.getN(), matrix1.getM());

        for (int i = 0; i < matrix1.getM(); i++)
        {
            for (int j = 0; j < matrix1.getN(); j++)
            {
                result(i, j) = matrix1.getElementMatrix(i, j) + matrix2.getElementMatrix(i, j);
            }
        }
    }
}

int main()
{
    Matrix matrix = Matrix(3, 4);
    matrix.randomFulling();
    matrix(2, 2) = 10;
    std::cout << matrix;

}