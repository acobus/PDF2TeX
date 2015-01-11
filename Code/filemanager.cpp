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

void FileManager::setNumb(int numb){
    numberFiles=numb;
}

int FileManager::getNumb(){
    return numberFiles;
}
