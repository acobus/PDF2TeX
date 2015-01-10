#include "texparser.h"

#include <fstream>

using namespace std;

TexParser::TexParser()
{
}

void TexParser::parseText(const char *input){
    // Vorläufig in temp speichern
    texdat.open ("../temp/test.tex");
    makeBeginning();
    texdat << input;
    makeEnding();
    texdat.close();
}

void TexParser::makeBeginning(){
    texdat<<"\\documentclass[10pt,a4paper]{scrartcl} \n";
    texdat<<"\\usepackage[latin1]{inputenc} \n";
    texdat<<"\\begin{document} \n";
}

void TexParser::makeEnding(){
    texdat<<"\\end{document}";
}
