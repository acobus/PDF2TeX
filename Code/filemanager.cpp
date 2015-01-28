#include "filemanager.h"

using namespace std;

/*
 * Diese Klasse vereinigt Attribute die Klassen-
 * übergreifend per getter-/setter-Methoden
 * zur Verfügung stehen sollen.
 * Dies sind
 *
 *  target          PDF, die konvertiert wird
 *  argc,argv       Argumente der main()
 *  logo            Bild, das zu beginn gezeigt wird
 *  numberFiles     Anzahl der Seiten der PDF
 *
 */
FileManager::FileManager()
{
}

void FileManager::setTarget(string pTarget){
    target=pTarget;
}

string FileManager::getTarget(){
    return target;
}

void FileManager::setArgc(int pArgc){
    argc=pArgc;
}

int FileManager::getArgc(){
    return argc;
}

void FileManager::setArgv(char **pArgv){
    argv=pArgv;
}

char **FileManager::getArgv(){
    return argv;
}

void FileManager::setLogo(char * pLogo){
    logo=pLogo;
}

char *FileManager::getLogo(){
    return logo;
}

void FileManager::addPage(int page){
    for(int i=1; i<pages_vec.size(); i++){
        if (pages_vec[i]==page) return;
    }
    pages_vec.push_back(page);
}

vector<int> FileManager::getPageVec(){
    return pages_vec;
}
