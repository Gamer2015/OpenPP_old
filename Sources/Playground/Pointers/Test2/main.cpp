#include <iostream>
#include <cstring>

double *upperTriangular(const double* Mtrx, int n)
{
    double* matrix = new double[n];

    memcpy(matrix, Mtrx, n*sizeof(double));

    return matrix;
}

int main(void)
{
    double matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    double* upper = upperTriangular(&(matrix[0][2]), 5);

    for(int i = 0; i < 3; ++i)
        std::cout << upper[i] << std::endl;

    return 0;
}
