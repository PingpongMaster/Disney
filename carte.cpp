#include "carte.h"
/**  ==================  CARTE.CPP  ==============
     --------------------------------------------- */

using namespace std;

/** INITIALISATION DES ATTRIBUTS STATIQUES
    --------------------------------------
    Ils seront modifiés lors de la construction de l'objet Memory
    */

string Carte::nomCollection = "";
unsigned short int Carte::nbCartesCollection = 0;
string Carte::typeImage = "";
string Carte::nomDos = "";

/** METHODES d'INSTANCES
    --------------------*/
Carte::Carte(string nFace)
{
    nomFace = nFace;    // nom du fichier image de la face
    etatCarte = indetermine;
}

Carte::~Carte() {
    //cout << "destruction de la carte" << endl;
}

string Carte::getNomFace()
{
    return (nomFace);
}

Carte::UnEtatCarte Carte::getEtat()
{
    return etatCarte;
}

void Carte::retourner()
{
    if (etatCarte == faceVisible)
        { setEtat(faceNonVisible); }
    else if (etatCarte == faceNonVisible)
        { setEtat(faceVisible); }
}

void Carte::setEtat (UnEtatCarte etat)
{
    etatCarte = etat;
}

void Carte::setNomFace (string nFace)
{
    nomFace = nFace;
}

/** Methodes STATIQUES communes à toutes les instances de la classe
    ---------------------------------------------------------------*/

string Carte::getNomCollection()
{
    return nomCollection;
}

unsigned short int Carte::getNbCartesCollection()
{
    return nbCartesCollection;
}

string Carte::getTypeImage()
{
    return typeImage;
}

string Carte::getNomDos()
{
    return nomDos;
}

void Carte::setNomCollection (string nomCol)
{
    nomCollection = nomCol;
}

void Carte::setTypeImage (string typeIm)
{
    typeImage = typeIm;
}

void Carte::setNbCartesCollection (unsigned short int nbCa)
{
    nbCartesCollection = nbCa;
}

void Carte::setNomDos(string nDos)
{
    nomDos = nDos;
}
