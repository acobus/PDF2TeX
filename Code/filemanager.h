#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

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

    void addPage(int page);
    vector<int> getPageVec();

    int getAktPage();
    void setAktPage(int page);

private:
    vector<int> pages_vec;
    int aktPage;
    int argc;
    char **argv;
    string target;
    char *logo;
};

#endif // FILEMANAGER_H
