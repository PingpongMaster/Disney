#ifndef CONSTANTESCOMMUNES_H
#define CONSTANTESCOMMUNES_H
#include <wx/string.h>
#include <string>
using namespace std;


/*----VALEURS MODIFIABLES AVANT COMPILATION -------------------------------*/
const unsigned short int DIM_PLATEAU = 0;
  // on fixe 'en dur' la dimension du plateau. Enre 0 et 9 (cf. DIMENSION_MAX_PLATEAU ci-dessous)
  /* Remarque : Si l'on veut que DIM_PLATEAU soit paramétrable, il faut que la hauteur/largeur
     proposées soient telles que :
      - largeur*hauteur multiples de NB_CARTES_A_RASSEMBLER
      - ET largeur*hauteur <= nbImagesDisponiblesDeLaCollection.
     Les dimensions du plateau devraient alors être calculées,
     en vérifiant qu'elle aient bien les propriétés énoncées ci-dessus.
      --> non implémenté dans la version actuelle.
*/

///----VALEURS MODIFIABLES -------------------------------
const unsigned short int TEMPS_MAX_ALLOUE = 60;
  // temps maximum en SECONDES dont dispose le joueur pour rassembler ses cartes
const unsigned short int UNITE_TEMPS_PAUSE = 100;
const unsigned int NB_UNITES_TEMPS_PAUSE = 8;
  ///ATTENTION en MILLISECONDES : le temps de pase alloué au joueur sera calculé :
  //                              = UNITE_TEMPS_PAUSE * NB_UNITES_TEMPS_PAUSE

const string NOM_COLLECTION = "Disney";
const string CHEMIN_COLLECTION = "cartesDisney/"; // par rapport au fichier .exe
const unsigned short int NB_IMAGES_COLLECTION = 54;
const string IMAGE_CASE_VIDE = "Disney_tapis.gif"  ;

///----VALEURS NON MODIFIABLES -------------------------------
const unsigned short int NB_MAX_IMAGES_COLLECTION = 60;
  //  images 'utiles', cad sans compter l'image de dos commune à toutes les cartes.
const unsigned short int  NB_MINIMUM_DE_CARTES_A_RASSEMBLER = 2;
  // ...mais on pourrait rassembler des TRIOS et des QUADRUPLETS....
const unsigned short int NB_MAX_DE_CARTES_A_RASSEMBLER = 4;
// --> NON fait ici : on ne rassemble QUE des PAIRES.
const unsigned short int NB_CARTES_A_RASSEMBLER = 2;
// le nombre de cartes à assembler dans le présent jeu
// dans une prochane version cettte valeur pourra être choisie par l'utilisateur
const unsigned short int NB_MAX_IMAGES_FACE_A_CHARGER =
                    NB_MAX_IMAGES_COLLECTION / NB_MINIMUM_DE_CARTES_A_RASSEMBLER ;
  // Pour définir une taille max des tableaux du programme
const unsigned short int DIMENSION_MAX_PLATEAU = 10;
// nbre maximum de combinaisons Hauteur*Largeur du plateau
const unsigned int NB_CASES_HAUT_PLATEAU[DIMENSION_MAX_PLATEAU] =   {4,4,4,4,5,4,6,6,6,7};
  // hauteurs possibles plateau = nbre de colonnes
const unsigned int NB_CASES_LARGE_PLATEAU[DIMENSION_MAX_PLATEAU] =  {4,5,6,7,6,8,6,7,8,8};
  // largeurs possibles du plateau = nbre de lignes


#endif // CONSTANTESCOMMUNES_H
