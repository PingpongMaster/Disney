#ifndef CARTE_H
#define CARTE_H

#include <string>
#include <iostream>
#include <wx/msgdlg.h> // pour les wxMessageBx()

using namespace std;

/**  ==================  CARTE.H  ==============
     -------------------------------------------
    Les fichiers images représentant les figures des cartes sont nommés de la manière suivante :
    nomCollection_0.type,
    nomCollection_1.type,
    nomCollection_2.type, .....,
    et l'image contenant le dos de la carte se nomme nomCollection_0.type
Exple : Disney_1.gif, Disney_2.gif, .... Disney_53.gif, et Disney_0.gif.
Ici :
- nomCollection. Exemple "Disney"
- nomFace = nom du fichier image contenant le côté face de la carte. Exemple "Disney_14.gif"
  calculé par concaténation d'attrbuts :
  Carte::setNomFace(nomCol + "_i." + Carte::getTypeImage()) ;
  où i est un nombre compris entre 1 et nbrImages
  - typeImage = Extention. Exemple "gif"
- nomDos = nom du fichier image représentant le dos de chaque carte de la collection.
  calculé par concaténation d'éléments décrits précédemment :
  Carte::setNomDos(nomCol + "_0." + Carte::getTypeImage()) ;
  Exemple : "Disney_0.gif"
- nbrImages = NB  (NB-1 images pour les cartes et 1 image pour le dos)
Pour la Collection Disney, nbreCartes = 54 (1 image pour dos et 53 pour les faces).

Lien avec les constantes du programme (fichier constantesCommmunes.h :
----------------------------------------------------------------------
L'attribut nbrImages doit être < NB_MAX_IMAGES_COLLECTION
*/

class Carte
{
    public:
        enum UnEtatCarte {indetermine, faceVisible, faceNonVisible};
        /// valeurs posssibles :
         /* - sur le Plateau : faceVisible, faceNonVisible
            - hors plateau : indetermine
            */
       ///* Constructeurs  et destructeur */
        Carte(std::string nFace); // avec nom de carte
        Carte();
        virtual ~Carte();

        /// GETTERS - Méthodes d'instances
        string getNomFace(); // retourne le nom de la face
        UnEtatCarte getEtat(); // retourne l'état de la carte

        /// SETTERS - Méthodes d'instance
        void retourner();
            // bascule l'attribut etatCarte entre faceVisible et faceNonVisible
        void setEtat (UnEtatCarte etat);
            // affecte l'attribut etatCarte de la valeur du paramètre etat
        void setNomFace (string nFace);
            // affecte l'attribut nomFace de la valeur du paramètre nFace

        /// Getteurs COMMUNS à TOUTS les CARTES = Méthodes de classe = Méthodes statiques
        static string getNomCollection();
            // retourne l'attribut nomCollection
        static unsigned short int getNbCartesCollection();
            // retourne l'attribut nbCartesCollection
        static string getTypeImage();
            // retourne l'attribut typeImage
        static string getNomDos();
            // retourne l'attribut nomDos

        /// Setteurs COMMUNS à TOUTS les CARTES = Méthodes de classe = Méthodes statiques
        static void setNomCollection (string nomCol);
        static void setTypeImage (string typeIm);
        static void setNbCartesCollection (unsigned short int nbCa);
          // Post-condition: nbCartesCollection <= NB_MAX_IMAGES_COLLECTION
        static void setNomDos(string nDos);

    private:
        UnEtatCarte etatCarte;

        string nomFace;
          // nom du fichier image de la face

        ///* COMMUN à TOUTES LES CARTES = ATTRIBUTS DE CLASSE = Attributs statiques */
        static string nomCollection;
          // racine du nom de fichier. Exemple : "Disney"
        static string typeImage;
          // Exemple : "gif", "png", ...
        static unsigned short int nbCartesCollection;
          // nbre de cartes de la collection.
        static string nomDos;
          /* nom de l'image utilisée pour le dos de toutes les cartes
             L'image utilisée pour le dos est celle numérotée 0
             Exemple : "Disney_0.gif" pour l'image de dos de la collection Disney
             */
};
#endif // CARTE_H
