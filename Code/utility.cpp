#include "utility.h"

namespace utility{

// Ersetzt in string "str" einen teilstring "from" durch einen anderen "to"
string replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    string nStr=str;
    if(start_pos == std::string::npos)
        return NULL;
    nStr.replace(start_pos, from.length(), to);
    return nStr;
}

// Soll Dateiformat überprüfen (vorerst nur durch Benennung -> verbessern)
bool checkFormat(char *file, char *format){
    string sfile(file);
    return sfile.find(format);
}

}
