//no <algorithm>
// no STL

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < ac; i++)
    {
        for (int j = 0; av[i][j] != '\0'; j++)
        {
            char c = std::toupper(av[i][j]);
            std::cout << c;
        }
    }
    std::cout << std::endl;
}