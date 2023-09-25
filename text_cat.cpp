#include <iostream>
#include <string>

int main(void)
{
    std::string line;

    while (std::getline(std::cin,line)) {
        std::cout << line << "\n";
    }
    return (0);
}