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
néant
*/

using namespace std;
class Case
{
    public:
        enum UnEtatCase {libre, occupee};
        /** deux états possibles :
            - occupée : lorsqu'elle contient un Element (par exemple, une carte)
            - libre : pas d'élément
            */

        /// Constructeur - Destructeur
        Case();
        virtual ~Case();

        /// GETTERS et SETTERS
        UnEtatCase getEtatCase();
            // retourne l'état courant de la case
        void setEtatCase(UnEtatCase etat);
            // Initialise l'état courant etatCase avec le paramètre etat
        Carte* getElementCase();
            // Retourne un pointeur sur l'Element contenu dans la case
        void setElementCase(Carte* elt);
            // Associe l'élément elt à la case.

    private:
    ///* ATTRIBUTS MEMBRES */
    UnEtatCase etatCase;    /* libre ou occupée. Indique si un élément
                               (carte) est posé sur cette case du plateau */
    Carte* elementCase;     // pointeur vers l'élément (par exemple carte)
                            // posé sur la case

};
#endif // CASE_H
