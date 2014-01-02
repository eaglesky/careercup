#include <iostream>

void rotate_counter(int** mat, int N)
{
    int layer_max = N/2 - 1;

    for (int layer = 0; layer <= layer_max; layer++)
    {
        for (int j = layer; j < N - 1 - layer; j++)
        {
            int temp = mat[layer][j];
            mat[layer][j] = mat[j][N-layer-1];
            mat[j][N-layer-1] = mat[N-layer-1][N-j-1];
            mat[N-layer-1][N-j-1] = mat[N-j-1][layer];
            mat[N-j-1][layer] = temp;
        }
    }
}

void print_mat(int** mat, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void delete_mat(int** mat, int N)
{
    for (int i = 0; i < N; i++)
        delete []mat[i];

    delete []mat;
}

int main(int argc, char** argv)
{
    int** m1 = new int*[4];
    for (int i = 0; i < 4; i++)
    {
        m1[i] = new int[4];
        for (int j = 0; j < 4; j++)
        {
            m1[i][j] = i*4 + j;
        }
    }

    int** m2 = new int*[5];
    for (int i = 0; i < 5; i++)
    {
        m2[i] = new int[5];
        for (int j = 0; j < 5; j++)
        {
            m2[i][j] = i*5 + j;
        }
    }

    int** m3 = new int*[2];
    for (int i = 0; i < 2; i++)
    {
        m3[i] = new int[2];
        for (int j = 0; j < 2; j++)
            m3[i][j] = i*2 + j;
    }
   
    std::cout << "Test1: " << std::endl;
    print_mat(m1, 4);
    std::cout << "After rotation:" << std::endl;
    rotate_counter(m1, 4);
    print_mat(m1, 4);
    std::cout << std::endl;

    std::cout << "Test2: " << std::endl;
    print_mat(m2, 5);
    std::cout << "After rotation:" << std::endl;
    rotate_counter(m2, 5);
    print_mat(m2, 5);
    std::cout << std::endl;

    std::cout << "Test3: " << std::endl;
    print_mat(m3, 2);
    std::cout << "After rotation:" << std::endl;
    rotate_counter(m3, 2);
    print_mat(m3, 2);
    std::cout << std::endl;

    delete_mat(m1, 4);
    delete_mat(m2, 5);
    delete_mat(m3, 2);   
    return 0;
}
