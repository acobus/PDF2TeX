#ifndef UTILITY_H
#define UTILITY_H

#include <string>

#include <QString>
#include <QByteArray>

namespace utility {

using namespace std;

    string replace(std::string& str, const std::string& from, const std::string& to);

    bool checkFormat(char *file, char *format);

    char* QString2Char_p(QString str);

}
#endif // UTILITY_H
