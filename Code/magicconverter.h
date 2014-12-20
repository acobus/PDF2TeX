#ifndef MAGICCONVERTER_H
#define MAGICCONVERTER_H

#include <string>

using namespace std;

class MagicConverter
{
public:
    MagicConverter(char *&argv, string &target);
    string replace(std::string& str, const std::string& from, const std::string& to);
};

#endif // MAGICCONVERTER_H
