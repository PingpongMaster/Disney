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
Chaque case est située à une position (ligne, colonne) de la grille.
Sa dimension est un indice permettant de définir :
   - la hauteur du plateau = nombre de lignes de cases = NB_CASES_HAUT_PLATEAU[dimension]
   - la largeur du plateau = nombre de colonnes de cases = NB_CASES_LARGE_PLATEAU[dimension]

A tout moment, une case peut être libre ou bien occupée par un élément (par exemple une carte).

Le plateau maintient la liste des cases sélectionnés par l'utilisateur.
(Pour les cartes du Memory, les cartes sélectionnées sont les cartes posées sur le plateau
  avec face tournée vers le haut.)
Le plateau mémorise aussi le nombre de cases occupées à tout moment.

Lien avec les autres éléments du programme
(fichier constantesCommmunes.h, autres classes... :
---------------------------------------------------
- Dans version actuelle, la dimension est initialisée avec la constante DIM_PLATEAU.

Relations à prendre en compte dans une future version du programme où la dimension du plateau et
le jeu de cartes utilisé dseront paramétrables :
- dimension < DIMENSION_MAX_PLATEAU
- largeur*hauteur multiples de NB_CARTES_A_RASSEMBLER
- ET largeur*hauteur <= Memory::nbCartesUtilisées

DESCRIPTION DES ELEMENTS DU PLATEAU
    // ELEMENTS DU PLATEAU
        Le plateau est composé des éléments suivants :

    0.- DIMENSION DU PLATEAU
      unsigned short int dimension;

    1.- LES CASES DU TABLEAU SUR LESQUELLES SONT POSéES les CARTES
      Case casesPlateau[NB_MAX_DIMENSIONS][NB_MAX_DIMENSIONS];
      un tableau = une matrice (ligne * colonne) composé de cases.
      Elle est définie par l'élément dimension ci-dessus


    2.- LE NBRE DE CARTES SUR LE PLATEAU
      unsigned short int nbCasesOccupees;
      Le nombre de cases du plateau occupées par des cartes.
      En effet, les cases du plateau se vident de cartes au fur et à mesure
      que le joueur trouve des paires/triplet...

    3.- LES POSITIONS DES CARTES SELECTIONNEES
      UnePosition casesSelectionnees [NB_MAX_CARTES_A_RASSEMBLER] ;
      Tableau des positions (ligne, colonne) des cases (et donc cartes) du plateau
      qui sont sélectionnées.
      Dans la version actuelle du memory, ce tableau peut contenir 0, 1 ou 2 cases, vu que
      dans la version actuelle, NB_MAX_CARTES_A_RASSEMBLER = 2, c'est à dire que le joueur
      doit trouver des PAIRES de cartes.

    - unsigned short int nbCasesSelectionnees ;
      Le nombre d'éléments du tableau précédent
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
           occupées par des éléments (cartes)
           */

        Carte* getElementPlateau (unsigned short int lig,
                                  unsigned short int col);
        /* Si la case est occupée :
                - retourne un pointeur sur l'élément placé en position
                  (lig, col) du tableau casesPlateau
           Sinon retourne NULL
           */

        Carte* supprimerElementPlateau (unsigned short int lig,
                                        unsigned short int col);
        /* But : élimine l'élément du plateau.
                 Si la case située en position (lig, col est occupée :
                  - elle ne pointera plus vers un élément du jeu
                  - la méthode retourne le pointeur vers l'élement supprimé.
                  - et rend la case libre.
                 Si la case indiquée est vide, retourne NULL
           */

        Case::UnEtatCase getEtatCase(unsigned short int lig,
                                     unsigned short int col);
        /* retourne l'état de la case située en position (lig, col)
           du plateau casesPlateau, c'est à dire la valeur : libre ou occupee
           */

        void placerElementDansCasePlateau (Carte * elt,
                                           unsigned short int lig,
                                           unsigned short int col);
        /* place dans la case (lig, col) du plateau casesPlateau
           l'élément pointé par le paramètre elt,
           Incrémente l'attribut nbCartesPlacées
           */

        void remplirCasesPlateau(Carte* tabElements[], Carte::UnEtatCarte etat);
        /* Initialise toutes les cases du tableau casesPlateau
           à partir des nbElts elements contenus dans le tableau tabElements
           Les éléments du plateau sont tous initialisé avec la valeur du paramètre etat

           Pré-condition : tableau tabElements a assez d'éléments pour remplir le
           plateau : getLargeur() * getHauteur() * <= Carte::nbCartesUtilisées.
        */

        void ajouterCaseASelection (unsigned short int lig,
                                    unsigned short int col);
        /* Ajoute les coordonnées de la case (et donc carte) sélectionée au tableau
           cartesSelectionnees et incrémente le nbre nbreCartesSelectionnees qui
           représente le nbre de cartes dans ce tableau
           Attention, les tableaux démarrent à 0 :
           Ainsi, lorsque nbreCartesSelectionnees = 1, la valeur est rangée à
           l'indice nbreCartesSelectionnees-1 et la prochaine carte sera rangée à
           l'indice nbreCartesSelectionnees
           */

       /* Retourne la ligne (respectivement colonne) de l'élément situé à l'indice
          ind du tableau casesSelectionnees
          */
        unsigned short int getLigneCaseSelectionnee(unsigned short int ind);
        unsigned short int getColonneCaseSelectionnee(unsigned short int ind);

        bool caseDejaSelectionnee(unsigned short int lig,
                                   unsigned short int col);
        /* retourne true si la case du PLateau situe en (lig, col) a déjà été
           sélectionnée retourne false sinon
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
       /* le plateau de lignes et colonnes de cases, au départ il est vide
          dimensions possible du memory (respectivement Hauteur * Largeur) :
          4*4, 4*5, 4*6, 4*7, 5*6, 4*8, ...., 7*8 cases
       */

    unsigned short int nbCasesOccupees;
       // nbre d'éléments dans le tableau précédent = nombre de cases remplies avec une carte

    UnePosition casesSelectionnees [NB_MAX_DE_CARTES_A_RASSEMBLER] ;
       /* tableau des positions du plateau où se trouvent les cartes sélectionnées.
          Exemple : contient  le tableau
                    {(ligne_carte1, col_carte1), (ligne_carte2, col_carte2) }
                    si on doit trouver des PAIRES
       */
    unsigned short int nbCasesSelectionnees ;
       /* nbre de cartes actuellement dans le tableau précédent.
          Compris entre [0, NB_MAX_CARTES_A_RASSEMBLER]
       */
};
#endif // PLATEAU_H

/*** Pour les futures versions  du logiciel */
/* Concernant les cartes retirées du plateau une fois qu'elles ont été
   appariées.
    - Soit on les ignore (elles disparaissent).
    - Soit on les range qqpart, pour éventuellement faire un récapitulatif
      qqpart.
   Ici, nous avons fait le choix de ranger ces cartes dans le tableau
   cartesRetirées
*/
