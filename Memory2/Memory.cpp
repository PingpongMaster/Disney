#include "Memory.h"


BEGIN_EVENT_TABLE(Memory, wxFrame)


END_EVENT_TABLE()

Memory::Memory(const wxString& title) : wxFrame (NULL,
                                                wxID_ANY, // identifiant de l'objet qui sera créé, par défaut : wxID_ANY,
                                                title)  // titre de la fenêtre
{

// Nous ajouterons ici la création des contrôles que contiendra notre fenêtre}




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
