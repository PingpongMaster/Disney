#include "Memory.h"


BEGIN_EVENT_TABLE(Memory, wxFrame)


END_EVENT_TABLE()

Memory::Memory(const wxString& title) : wxFrame (NULL,
                                                wxID_ANY, // identifiant de l'objet qui sera cr��, par d�faut : wxID_ANY,
                                                title)  // titre de la fen�tre
{

// Nous ajouterons ici la cr�ation des contr�les que contiendra notre fen�tre}




}

    UnEtatMemory Memory::getEtatMemory()
    {

    }

    UnEtatMemory Memory::getEtatmemory()
    {

    }

    int Memory::getTempsMax()
    {

    }

    int Memory::TempsRestant()
    {

    }

    void Memory::getTempsMaxAlloue()
    {

    }

    void Memory::setEtatUnEtatMemory()
    {

    }
    -
    void Memory::setTempsMaxAlloue(int a)
    {

    }

    void Memory::setTempsRestant()
    {

    }

    void Memory::getNbCasesOccupees()
    {

    }

    void Memory::setNbCaseOccupees()
    {

    }

    void Memory::getNbPairesObtenues()
    {

    }

    void Memory::setNbPairesObtenues()
    {

    }


    // Le destructeur
Memory::~Memory()
{
    // Destructeur
}
