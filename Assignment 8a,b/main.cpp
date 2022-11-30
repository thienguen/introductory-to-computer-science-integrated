/// @author: Thien Nguyen
/// @date: Finished by
/// @note: Time spent in debugging:

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

const int BOUND = 5;

bool knightCount(std::string matrix[5])
{
    int knights = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == 'K')
            {
                knights++;
            }
        }
    }

    return (knights == 9);
}

bool knightCount(std::string matrix[5], std::pair<int, int> XY[9])
{
    int knights = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == 'K')
            {
                knights++;
                XY[knights - 1] = std::make_pair(i, j);
            }
        }
    }

    return (knights == 9);
}

bool attactCheck1(std::string matrix[5])
{
    int n = 5;
    int x_moves[] = {-1, -1, 1, 1, -2, -2, 2, 2};
    int y_moves[] = {-2, 2, -2, 2, -1, 1, -1, 1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '.')
            {
                continue;
            }
            for (size_t k = 0; k < (sizeof(x_moves) / sizeof(x_moves[0])); k++)
            {
                int x = i + x_moves[k];
                int y = j + y_moves[k];

                if (x >= 0 && y >= 0 && x < n && y < n && matrix[x][y] == 'K')
                {
                    std::cout << "Violated at (" << i << ", " << j << ") and (" << x << ", " << y << ")" << std::endl;
                    return false;
                }
            }
        }
    }
    return true;
}

bool attackCheck2(std::string matrix[5], std::pair<int, int> XY[9])
{
    int n = 5;
    int x_moves[] = {-1, -1, 1, 1, -2, -2, 2, 2};
    int y_moves[] = {-2, 2, -2, 2, -1, 1, -1, 1};

    for (int i = 0; i < 9; i++)
    {
        for (size_t k = 0; k < (sizeof(x_moves) / sizeof(x_moves[0])); k++)
        {
            int x = XY[i].first + x_moves[k];
            int y = XY[i].second + y_moves[k];

            if (x >= 0 && y >= 0 && x < n && y < n && matrix[x][y] == 'K')
            {
                std::cout << "Violated at (" << XY[i].first << ", " << XY[i].second << ") and (" << x << ", " << y << ")" << std::endl;
                return false;
            }
        }
    }
    return true;
}

auto main() -> int
{
    std::ifstream inFile;
    std::string fileName, fileName2;
    std::string matrix[5];
    std::string matrix2[9];
    std::pair<int, int> XY[9];
    int kCounts = 0;

    fileName = "in1.txt";
    fileName2 = "in2.txt";

    inFile.open(fileName);

    for (int i = 0; i < BOUND; i++)
    {
        inFile >> matrix[i];

        for (int j = 0; j < BOUND; j++)
        {
            if (matrix[i][j] == 'K')
            {
                kCounts++;
            }
        }
    }

    std::cout << "Knight count: " << kCounts << std::endl;

    inFile.close();

    // looping the pair array and output it
    std::string valid = (knightCount(matrix, XY) && attackCheck2(matrix, XY)) ? "\nVALID" : "\nINVALID";

    std::cout << valid << std::endl;

    return EXIT_SUCCESS;
}
