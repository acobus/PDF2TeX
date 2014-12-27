#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

using namespace std;

class FileManager
{
public:
    FileManager();

    void setTarget(string pTarget);
    string getTarget();

    void setArgc(int pArgc);
    int getArgc();

    void setArgv(char **pArgv);
    char **getArgv();

private:
    int argc;
    char **argv;
    string target;
};

#endif // FILEMANAGER_H
