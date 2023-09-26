#include <iostream>
#include <string>

void temp_read_convert(std::istream &input, std::ostream &output)
{
    float temp;
    char unit;

    input >> temp >> unit;
    float cel;
    if (unit == 'K') {
        cel = temp - 273.15;
    } else if (unit == 'F') {
        cel = (temp - 32) * (5.0/9.0);
    } else {
        cel = temp;
    }
    float kal = cel + 273.15;
    float fahr = (cel * 9.0/5.0) + 32;
    
    output << cel << " C" << std::endl;
    output << fahr << " F" << std::endl;
    output << kal << " K" << std::endl;
}