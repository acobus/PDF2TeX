#ifndef UTILITY_H
#define UTILITY_H

#include <string>

#include <QString>
#include <QByteArray>

namespace utility {

using namespace std;

    string replace(std::string& strz, const std::string& from, const std::string& to);

    bool checkFormat(const char *file, const char *format);

    char* QString2Char_p(QString str);

    string convertInt(int number);

}


#endif // UTILITY_H
