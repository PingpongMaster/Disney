#ifndef PLATEAU_H
#define PLATEAU_H

#include <string>
#include <iostream>
#include "constantesCommunes.h"
#include "carte.h"
#include "case.h"

using namespace std;
/**  ===================  PLATEAU.H  ================
     ------------------------------------------------

Le plateau est une grille de cases.
Chaque case est situ�e � une position (ligne, colonne) de la grille.
Sa dimension est un indice permettant de d�finir :
   - la hauteur du plateau = nombre de lignes de cases = NB_CASES_HAUT_PLATEAU[dimension]
   - la largeur du plateau = nombre de colonnes de cases = NB_CASES_LARGE_PLATEAU[dimension]

A tout moment, une case peut �tre libre ou bien occup�e par un �l�ment (par exemple une carte).

Le plateau maintient la liste des cases s�lectionn�s par l'utilisateur.
(Pour les cartes du Memory, les cartes s�lectionn�es sont les cartes pos�es sur le plateau
  avec face tourn�e vers le haut.)
Le plateau m�morise aussi le nombre de cases occup�es � tout moment.

Lien avec les autres �l�ments du programme
(fichier constantesCommmunes.h, autres classes... :
---------------------------------------------------
- Dans version actuelle, la dimension est initialis�e avec la constante DIM_PLATEAU.

Relations � prendre en compte dans une future version du programme o� la dimension du plateau et
le jeu de cartes utilis� dseront param�trables :
- dimension < DIMENSION_MAX_PLATEAU
- largeur*hauteur multiples de NB_CARTES_A_RASSEMBLER
- ET largeur*hauteur <= Memory::nbCartesUtilis�es

DESCRIPTION DES ELEMENTS DU PLATEAU
    // ELEMENTS DU PLATEAU
        Le plateau est compos� des �l�ments suivants :

    0.- DIMENSION DU PLATEAU
      unsigned short int dimension;

    1.- LES CASES DU TABLEAU SUR LESQUELLES SONT POS�ES les CARTES
      Case casesPlateau[NB_MAX_DIMENSIONS][NB_MAX_DIMENSIONS];
      un tableau = une matrice (ligne * colonne) compos� de cases.
      Elle est d�finie par l'�l�ment dimension ci-dessus


    2.- LE NBRE DE CARTES SUR LE PLATEAU
      unsigned short int nbCasesOccupees;
      Le nombre de cases du plateau occup�es par des cartes.
      En effet, les cases du plateau se vident de cartes au fur et � mesure
      que le joueur trouve des paires/triplet...

    3.- LES POSITIONS DES CARTES SELECTIONNEES
      UnePosition casesSelectionnees [NB_MAX_CARTES_A_RASSEMBLER] ;
      Tableau des positions (ligne, colonne) des cases (et donc cartes) du plateau
      qui sont s�lectionn�es.
      Dans la version actuelle du memory, ce tableau peut contenir 0, 1 ou 2 cases, vu que
      dans la version actuelle, NB_MAX_CARTES_A_RASSEMBLER = 2, c'est � dire que le joueur
      doit trouver des PAIRES de cartes.

    - unsigned short int nbCasesSelectionnees ;
      Le nombre d'�l�ments du tableau pr�c�dent
      */

/* Position d'une case sur le plateau
   */
struct UnePosition {
    unsigned short int ligne;       // nbre total de lignes = hauteur
    unsigned short int colonne;     // nbre otal de colonnes = largeur
};

class Plateau
{
    public:
        Plateau(unsigned short int dim);
        virtual ~Plateau();

        unsigned short int getDimension();
        /* Retourne la combinaison de lignes*colonnes actuelle du tableau.
           Indice des tableaux NB_CASES_HAUT_PLATEAU et NB_CASES_LARGE_PLATEAU
         */

        unsigned short int getHauteur();
        /* Retourne le nombre de lignes (de cases) du plateau
           = NB_CASES_HAUT_PLATEAU[getDimension()]
           */

        unsigned short int getLargeur();
        /* Retourne le nombre de colonnes (de cases) du plateau
           = NB_CASES_LARGE_PLATEAU[getDimension()]
           */

        void setDimension (unsigned short int dim);
        /* Initialise  la dimension du plateau
           Post-condition : dimension <= DIMENSION_MAX_PLATEAU
           */

        unsigned short int getNbCasesOccupees();
        /* retourne nbCasesOccupees, le nbre de cases du plateau
           occup�es par des �l�ments (cartes)
           */

        Carte* getElementPlateau (unsigned short int lig,
                                  unsigned short int col);
        /* Si la case est occup�e :
                - retourne un pointeur sur l'�l�ment plac� en position
                  (lig, col) du tableau casesPlateau
           Sinon retourne NULL
           */

        Carte* supprimerElementPlateau (unsigned short int lig,
                                        unsigned short int col);
        /* But : �limine l'�l�ment du plateau.
                 Si la case situ�e en position (lig, col est occup�e :
                  - elle ne pointera plus vers un �l�ment du jeu
                  - la m�thode retourne le pointeur vers l'�lement supprim�.
                  - et rend la case libre.
                 Si la case indiqu�e est vide, retourne NULL
           */

        Case::UnEtatCase getEtatCase(unsigned short int lig,
                                     unsigned short int col);
        /* retourne l'�tat de la case situ�e en position (lig, col)
           du plateau casesPlateau, c'est � dire la valeur : libre ou occupee
           */

        void placerElementDansCasePlateau (Carte * elt,
                                           unsigned short int lig,
                                           unsigned short int col);
        /* place dans la case (lig, col) du plateau casesPlateau
           l'�l�ment point� par le param�tre elt,
           Incr�mente l'attribut nbCartesPlac�es
           */

        void remplirCasesPlateau(Carte* tabElements[], Carte::UnEtatCarte etat);
        /* Initialise toutes les cases du tableau casesPlateau
           � partir des nbElts elements contenus dans le tableau tabElements
           Les �l�ments du plateau sont tous initialis� avec la valeur du param�tre etat

           Pr�-condition : tableau tabElements a assez d'�l�ments pour remplir le
           plateau : getLargeur() * getHauteur() * <= Carte::nbCartesUtilis�es.
        */

        void ajouterCaseASelection (unsigned short int lig,
                                    unsigned short int col);
        /* Ajoute les coordonn�es de la case (et donc carte) s�lection�e au tableau
           cartesSelectionnees et incr�mente le nbre nbreCartesSelectionnees qui
           repr�sente le nbre de cartes dans ce tableau
           Attention, les tableaux d�marrent � 0 :
           Ainsi, lorsque nbreCartesSelectionnees = 1, la valeur est rang�e �
           l'indice nbreCartesSelectionnees-1 et la prochaine carte sera rang�e �
           l'indice nbreCartesSelectionnees
           */

       /* Retourne la ligne (respectivement colonne) de l'�l�ment situ� � l'indice
          ind du tableau casesSelectionnees
          */
        unsigned short int getLigneCaseSelectionnee(unsigned short int ind);
        unsigned short int getColonneCaseSelectionnee(unsigned short int ind);

        bool caseDejaSelectionnee(unsigned short int lig,
                                   unsigned short int col);
        /* retourne true si la case du PLateau situe en (lig, col) a d�j� �t�
           s�lectionn�e retourne false sinon
           */

        /* Getter et Setter du tableau casesSelectionnees
           */
        unsigned short int getNbCasesSelectionnees ();
        void setNbCasesSelectionnees (unsigned short int nb);

    private:
    unsigned short int dimension;
       /* indique la combinaison de ligne*colonne choisie.
          Cette combinaison est contenue dans les tableaux
             NB_CASES_HAUT_PLATEAU[] =  {4,4,4,4,5,4,6,6,6,7};
          et NB_CASES_LARGE_PLATEAU[]=  {4,5,6,7,6,8,6,7,8,8};
          exemple : si dimension = 2, le plateau aura pour dimensions 4 lignes et 6 colonnes
          indice compris entre 0 et DIMENSION_MAX_PLATEAU  - cf. declarations communes */

    Case casesPlateau[DIMENSION_MAX_PLATEAU][DIMENSION_MAX_PLATEAU];    // lignes, colonnes
       /* le plateau de lignes et colonnes de cases, au d�part il est vide
          dimensions possible du memory (respectivement Hauteur * Largeur) :
          4*4, 4*5, 4*6, 4*7, 5*6, 4*8, ...., 7*8 cases
       */

    unsigned short int nbCasesOccupees;
       // nbre d'�l�ments dans le tableau pr�c�dent = nombre de cases remplies avec une carte

    UnePosition casesSelectionnees [NB_MAX_DE_CARTES_A_RASSEMBLER] ;
       /* tableau des positions du plateau o� se trouvent les cartes s�lectionn�es.
          Exemple : contient  le tableau
                    {(ligne_carte1, col_carte1), (ligne_carte2, col_carte2) }
                    si on doit trouver des PAIRES
       */
    unsigned short int nbCasesSelectionnees ;
       /* nbre de cartes actuellement dans le tableau pr�c�dent.
          Compris entre [0, NB_MAX_CARTES_A_RASSEMBLER]
       */
};
#endif // PLATEAU_H

/*** Pour les futures versions  du logiciel */
/* Concernant les cartes retir�es du plateau une fois qu'elles ont �t�
   appari�es.
    - Soit on les ignore (elles disparaissent).
    - Soit on les range qqpart, pour �ventuellement faire un r�capitulatif
      qqpart.
   Ici, nous avons fait le choix de ranger ces cartes dans le tableau
   cartesRetir�es
*/
