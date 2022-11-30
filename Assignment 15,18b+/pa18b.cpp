#include <iostream>
#include <queue>
#include <vector>

std::ostream &operator<<(std::ostream &output, const std::vector<int> &vec);

int main()
{
    int n{};

    while (std::cin >> n && n != 0)
    {
        std::queue<int> deck{};
        std::vector<int> discarded{};

        for (int card = 1; card <= n; deck.push(card++))
        {
        }

        while (deck.size() > 1)
        {
            discarded.push_back(deck.front());
            deck.pop();
            deck.push(deck.front());
            deck.pop();
        }

        std::cout << "Discarded cards: " << discarded << '\n';
        std::cout << "Remaining card: " << deck.front() << '\n';
    }

    return EXIT_SUCCESS;
}

std::ostream &operator<<(std::ostream &output, const std::vector<int> &vec)
{
    char separator[]{'\0', ' ', '\0'};

    for (const auto item : vec)
    {
        output << separator << item;
        *separator = ',';
    }

    return output;
}