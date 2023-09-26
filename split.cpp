#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &str, char token)
{
    std::vector<std::string> delim;
    size_t                   startpos = 0;
    size_t                   found    = str.find(token);

    while (found != std::string::npos) {
        delim.push_back(str.substr(startpos, found - startpos));
        startpos = found + 1;
        found    = str.find(token, startpos);
    }

    delim.push_back(str.substr(startpos));
    return delim;
}

std::vector<std::string> split(std::string str, const std::string &token)
{
    std::vector<std::string> delim;
    size_t                   pos = 0;

    while ((pos = str.find(token)) != std::string::npos) {
        delim.push_back(str.substr(0, pos));
        str.erase(0, pos + token.length());
    }

    delim.push_back(str);
    return delim;
}

int main(void)
{
    auto cb{[](std::string &s) { std::cout << s << std::endl; }};

    {
        auto result{split("electric;dragon", ';')};

        std::for_each(result.begin(), result.end(), cb);
    }
    {
        auto result{split(";fire;;;flying", ';')};

        std::for_each(result.begin(), result.end(), cb);
    }
    {
        auto result{split("grass-->poison;", "-->")};

        std::for_each(result.begin(), result.end(), cb);
    }
}