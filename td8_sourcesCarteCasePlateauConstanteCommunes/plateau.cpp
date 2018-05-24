#include "plateau.h"
#include "memory.h"
#include <string>
#include <iostream>
#include <wx/string.h> // pour wxString
#include <wx/msgdlg.h>  // pour wxMessageBox

/**  ===================  PLATEAU.CPP  ================
     -------------------------------------------------- */

Plateau::Plateau(unsigned short int dim)
{
    /*
        Le plateau est cr�� de taille 0 et sans carte lors de l'appel du constructeur.
        En effet, le constructeur de Memory appelle le constructeur du plateau
        d�s le d�but du programme, mais on ne sait pas encore � ce moment l�
        combien de cartes aura le plateau.
        L'utilisateur param�tre ensuite ce qui est li�e aux cartes :
        - le paquet choisi --> d�termine la collection d'images choisies
        - la taille du plateau
        Une fois ces �l�ments d�termin�s, le plateau sera
        - dimensionn� � la taille choisie (setDimension), en v�rifiant qu'il y aura
          assez de cartes dans le paquet
        - initialis� avec les cartes que l'utilisateur aura choisies
    */

    dimension = dim;
    nbCasesOccupees = 0;
    nbCasesSelectionnees = 0;
}

Plateau::~Plateau()
{}

unsigned short int Plateau::getDimension()
{
    return dimension;
}
unsigned short int Plateau::getHauteur()
{
    return NB_CASES_HAUT_PLATEAU[getDimension()];
}
unsigned short int Plateau::getLargeur()
{
   return NB_CASES_LARGE_PLATEAU[getDimension()];
}

void Plateau::setDimension (unsigned short int dim)
{
    dimension = dim;
}

Case::UnEtatCase Plateau::getEtatCase(unsigned short int lig,
                                      unsigned short int col)
{
    return casesPlateau[lig][col].getEtatCase() ;
}

unsigned short int Plateau::getNbCasesOccupees()
{
    return nbCasesOccupees;
}

Carte* Plateau::getElementPlateau (unsigned short int lig,
                                 unsigned short int col)
{
    Carte * maCarte;
    if (casesPlateau[lig][col].getEtatCase() == Case::occupee)
    {
        maCarte = casesPlateau[lig][col].getElementCase() ;
    }
    else
    {
        maCarte = NULL;
    }
    return maCarte;
}

void Plateau::placerElementDansCasePlateau (Carte * elt,
                                            unsigned short int lig,
                                            unsigned short int col)
{
    casesPlateau[lig][col].setElementCase(elt);
    casesPlateau[lig][col].setEtatCase (Case::occupee);
    nbCasesOccupees++;
}

void Plateau::remplirCasesPlateau(Carte* tabElements[], Carte::UnEtatCarte etat)
{
    unsigned ind = 0;   // indice de parcours du tableau de cartes tabElements
    for (unsigned short int ligne = 1; ligne <= this->getHauteur() ; ligne++)
    {
        for (unsigned short int colonne = 1; colonne <= this->getLargeur(); colonne++)
        {
            tabElements[ind]->setEtat(etat);
            placerElementDansCasePlateau (tabElements[ind], ligne, colonne);
            ind++;
        }
    }
}

unsigned short int Plateau::getNbCasesSelectionnees ()
{
    return nbCasesSelectionnees;
}

void Plateau::ajouterCaseASelection(unsigned short int lig,
                                     unsigned short int col)
{
    /* on garde la carte s�lectionn�e dans l'�tat o� elle est (cad faceVisible),
       mais aussi sa position sur le plateau
       pour pouvoir la replacer telle quelle sur le plateau si elle ne convient pas,
       ou bien l'enlever du plateau si elle convient
       */
    casesSelectionnees[getNbCasesSelectionnees()].ligne = lig;
    casesSelectionnees[getNbCasesSelectionnees()].colonne = col;
    nbCasesSelectionnees++;
    // ou bien setNbCasesSelectionnees (getNbCasesSelectionnees() + 1);
}

// retourne un Struct avec la case du tableau casesSelctionnees siuee � l'indice ind
unsigned short int Plateau::getLigneCaseSelectionnee(unsigned short int ind)
{
    return casesSelectionnees[ind].ligne;
}

unsigned short int Plateau::getColonneCaseSelectionnee(unsigned short int ind)
{
    return casesSelectionnees[ind].colonne;
}

bool Plateau::caseDejaSelectionnee(unsigned short int lig,
                                   unsigned short int col)
    /* retourne true si la case du PLateau situe en (lig, col) a d�j� �t� s�lectonn�e
       retourne false sinon
       Strat�gie : recherche premiere occurrence dans tableau casesSelectionn�es
     */
{
    bool trouve = false;
    unsigned short int ind = 0;
    for (;;)
    {
        if (ind == getNbCasesSelectionnees())
        {
            break;
        }
        if ( (getLigneCaseSelectionnee(ind) == lig) &&
             (getColonneCaseSelectionnee(ind) == col)
            )
        {
            trouve = true;
            break;
        }
        ind = ind + 1;
    }
    return trouve;
}

void Plateau::setNbCasesSelectionnees (unsigned short int nb)
{
    nbCasesSelectionnees = nb;
}

Carte* Plateau::supprimerElementPlateau (unsigned short int ligne,
                                       unsigned short int colonne)
{
    Carte * maCarte;
    if (casesPlateau[ligne][colonne].getEtatCase() == Case::occupee)
    {
        maCarte = casesPlateau[ligne][colonne].getElementCase() ;
        casesPlateau[ligne][colonne].setEtatCase(Case::libre);
        nbCasesOccupees--;
        // ou bien setNbCasesSelectionnees (getNbCasesSelectionnees() - 1);
    }
    else
    {
        maCarte = NULL;
    }
    return maCarte;
}
