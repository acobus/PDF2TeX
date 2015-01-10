#include "utility.h"

#include <iostream>
#include <sstream>
#include <cstdio>

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

// Umwandlung int2str
string convertInt(int number)
{
   stringstream s;// string Stream erzeugen
   s<< number;// Zahl hinzufügen
   return s.str();// string zurückgeben
}

// Leert den temp-Ordner
void emptyTemp(){
    string file;
    for(int i=0; true; i++){
        file="../temp/pg"+convertInt(i)+".png";
        if(remove(file.c_str())!=0){
            return;
        }
    }
}

}
