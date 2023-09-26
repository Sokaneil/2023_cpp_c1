#include <algorithm>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cerr << "Error: " << argv[0] << "\n";
        return (1);
    }
    std::string written = argv[1];
    std::string result  = argv[2];
    std::string line;
    while (std::getline(std::cin, line)) {
        std::string translated;
        for (char l : line) {
            auto pos = written.find(l);
            if (pos != std::string::npos) {
                translated += result[pos];
            } else {
                translated += l;
            }
        }
        std::cout << translated << std::endl;
    }
    return (0);
}