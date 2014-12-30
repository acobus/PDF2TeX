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

    void setLogo(char * pLogo);
    char * getLogo();

private:
    int argc;
    char **argv;
    string target;
    char *logo;
};

#endif // FILEMANAGER_H
