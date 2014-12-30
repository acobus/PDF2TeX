#include "utility.h"

#include <iostream>

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
bool checkFormat(const char *file, const char *format){
    string sfile(file);
    size_t ret=sfile.find(format);
    if (ret==string::npos){
        ret=0;
    }
    return ret;
}

// Wandelt einen QString in ein char* um
char* QString2Char_p(QString str){
    QByteArray ba=str.toLocal8Bit();
    return ba.data();
}

}
