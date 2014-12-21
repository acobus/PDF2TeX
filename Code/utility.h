#ifndef UTILITY_H
#define UTILITY_H

#include <string>

namespace utility {

using namespace std;

    string replace(std::string& str, const std::string& from, const std::string& to);

    bool checkFormat(char *file, char *format);

}
#endif // UTILITY_H
