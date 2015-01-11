#include "texparser.h"

#include <fstream>

using namespace std;

TexParser::TexParser()
{
}

/*
 * Aus dieser Funktion wird das parsen des Textes
 * gestartet und gesteuert.
 */
void TexParser::parseText(string input){
    // Vorläufig in temp speichern
    texdat.open ("../temp/test.tex");
    makeBeginning();
    texdat << input;
    makeEnding();
    texdat.close();
}

/*
 * Diese private Hilfsfunktion erstellt die allgemeinen
 * Anfangs-Optionen der .tex Datei, z.B. Pakete und Format.
 */
void TexParser::makeBeginning(){
    texdat<<"\\documentclass[10pt,a4paper]{scrartcl} \n";
    texdat<<"\\usepackage[utf8]{inputenc} \n";
    texdat<<"\\usepackage[T1]{fontenc} \n";
    texdat<<"\\usepackage[ngerman]{babel} \n";
    texdat<<"\\begin{document} \n";
}

/*
 * Diese private Hilfsfunktion erstellt das Ende der
 * .tex Datei.
 */
void TexParser::makeEnding(){
    texdat<<"\\end{document}";
}
