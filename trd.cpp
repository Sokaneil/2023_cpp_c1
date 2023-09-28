#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Error: " << argv[0] << "<you_have_to_delete>"
                  << std::endl;
        return (1);
    }
    std::string DeletedChars(argv[1]);
    std::string line;
    while (std::getline(std::cin, line)) {
        for (auto iter = line.begin(); iter != line.end(); ++iter) {
            if (DeletedChars.find(*iter) == std::string::npos) {
                std::cout << *iter;
            }
        }
        std::cout << std::endl;
    }
    return (0);
}
