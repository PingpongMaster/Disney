#include <string>
#include <iostream>
#include "case.h"

using namespace std;

/**  ===================  CASE.CPP  ================
     ---------------------------------------------- */

Case::Case()
{
}

Case::~Case() {
    //cout << "destruction de la case" << endl;
}

Case::UnEtatCase Case::getEtatCase()
{
    return etatCase;
}

Carte* Case::getElementCase()
{
    return elementCase;
}

void Case::setElementCase(Carte* elt)
{
    elementCase = elt;
}

void Case::setEtatCase(UnEtatCase etat)
{
    etatCase = etat;
}
