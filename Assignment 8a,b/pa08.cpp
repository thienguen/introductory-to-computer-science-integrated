/// @author: Thien Nguyen
/// @date: Finished by 
/// @note: Time spent in debugging: 

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

/// @brief Returns index of the first element in the array where an
/// element is equal to the target value. If the target value is not found,
/// returns size.
///
/// @param list The array to search.
/// @param size The number of elements in the array.
/// @param target The search target value.
/// @returns The index of the first occurrence of target in list, or, 
/// size if not found.

unsigned find(const int list[], unsigned size, int target)
{
    int index = size;
    bool found = false;
    for (unsigned i = 0; i < size && found != true; i++)
    {
        if (list[i] == target)
        {
            index = i;
            found = true;
        }
    }

    return index;
}

unsigned find2(const int list[], unsigned size, int target)
{
    unsigned i = 0;
    bool found = false;

    while (i < size && !found)
    {
        if (list[i] == target)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }

    return found ? i : size;
}


/// @brief Reads up to size values into list from the standard input stream.
/// Only unique values are stored in the array (i.e., no duplicates). Returns
/// the number of unique values read into the array.
///
/// @param list The array to initialize.
/// @param size The number of elements in the array.
/// @returns Number of unique values read into the array.

unsigned read(int list[], unsigned size)
{
    unsigned count = 0;
    int temp = 0;
    for (unsigned i = 0; i < size; i++)
    {
        std::cin >> temp;
        if (find2(list, count, temp) == count)
        {
            list[count++] = temp;
        }
    }

    return count;
}


/// @brief How many similar elements in two arrays
/// @param list1 The array to initialize.
/// @param list2 The array to initialize.
/// @param size1 The number of elements in the array.
/// @param size2 The number of elements in the array.
/// @returns Number of similar cards they have.

unsigned similarCard(int list1[], unsigned size1, int list2[], unsigned size2)
{
    unsigned count = 0;
    for (unsigned i = 0; i < size1; i++)
    {
        if (find2(list2, size2, list1[i]) != size2)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int A, B;
    int D = 0;
    int J = 0;
    int T = 0;

    while ((std::cin >> A >> B))
    {
        if (A != 0 && B != 0)
        {
            // check range of A and B from 1 to 10000
            if ((A >= 1 && A <= 10000) || (B >= 1 || B <= 10000))
            {
                // std::vector<int> Deven(A);
                // std::vector<int> Jake(B);
                int Deven[10000];
                int Jake[10000];

                D = read(Deven, A);
                J = read(Jake, B);
                T = similarCard(Deven, D, Jake, J);
                T = std::min(D, J) - T;

                std::cout << "D and J can trade at most " << T << " cards." << std::endl;
            }
        }
    }

    return EXIT_SUCCESS;
}


