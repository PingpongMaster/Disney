#ifndef CASE_H
#define CASE_H

#include <string>
#include <iostream>
#include "constantesCommunes.h"
#include "carte.h"

/**  ===================  CASE.H  ================
     ---------------------------------------------

Lien avec les constantes du programme (fichier constantesCommmunes.h :
----------------------------------------------------------------------
n�ant
*/

using namespace std;
class Case
{
    public:
        enum UnEtatCase {libre, occupee};
        /** deux �tats possibles :
            - occup�e : lorsqu'elle contient un Element (par exemple, une carte)
            - libre : pas d'�l�ment
            */

        /// Constructeur - Destructeur
        Case();
        virtual ~Case();

        /// GETTERS et SETTERS
        UnEtatCase getEtatCase();
            // retourne l'�tat courant de la case
        void setEtatCase(UnEtatCase etat);
            // Initialise l'�tat courant etatCase avec le param�tre etat
        Carte* getElementCase();
            // Retourne un pointeur sur l'Element contenu dans la case
        void setElementCase(Carte* elt);
            // Associe l'�l�ment elt � la case.

    private:
    ///* ATTRIBUTS MEMBRES */
    UnEtatCase etatCase;    /* libre ou occup�e. Indique si un �l�ment
                               (carte) est pos� sur cette case du plateau */
    Carte* elementCase;     // pointeur vers l'�l�ment (par exemple carte)
                            // pos� sur la case

};
#endif // CASE_H
