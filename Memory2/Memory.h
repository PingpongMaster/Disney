#ifndef MEMORY_H
#define MEMORY_H

// Header central de wxWidgets incluant les widgets les plus utilisés
/* par exemple :
#include "wx/event.h"
#include "wx/app.h"
#include "wx/utils.h"
#include "wx/stream.h"
#include "wx/memory.h"
#include "wx/math.h"
#include "wx/stopwatch.h"
#include "wx/module.h"

#if wxUSE_GUI
#include "wx/window.h"
#include "wx/containr.h"
#include "wx/panel.h"
#include "wx/toplevel.h"
#include "wx/frame.h"
#include "wx/gdicmn.h"
#include "wx/gdiobj.h"
#include "wx/region.h"
#include "wx/bitmap.h"
#include "wx/image.h"
#include "wx/colour.h"
#include "wx/font.h"
#include "wx/dc.h"
#include "wx/dcclient.h"
#include "wx/dcmemory.h"
#include "wx/dcprint.h"
#include "wx/dcscreen.h"
#include "wx/button.h"
#include "wx/menuitem.h"
#include "wx/menu.h"
#include "wx/pen.h"
#include "wx/brush.h"
#include "wx/palette.h"
#include "wx/icon.h"
#include "wx/cursor.h"
#include "wx/dialog.h"
#include "wx/timer.h"
#include "wx/settings.h"
#include "wx/msgdlg.h"
#include "wx/cmndata.h"
#include "wx/dataobj.h"

#include "wx/control.h"
#include "wx/checkbox.h"
#include "wx/checklst.h"
#include "wx/scrolbar.h"
#include "wx/stattext.h"
#include "wx/statbox.h"
#include "wx/listbox.h"
#include "wx/radiobox.h"
#include "wx/radiobut.h"
#include "wx/textctrl.h"
#include "wx/slider.h"
#include "wx/scrolwin.h"
#include "wx/toolbar.h"
#include "wx/combobox.h"
#include "wx/layout.h"
#include "wx/sizer.h"
#include "wx/mdi.h"
#include "wx/statusbr.h"
....
*/
#include <wx/wx.h>
#include "plateau.h"
#include "case.h"
#include "carte.h"

enum
{
    monID_BoutonDemarrer = wxID_HIGHEST + 1,
    monID_BoutonAbandon
};

// Définition de la classe Memory
class Memory
{

private:

    enum UnEtatMemory
    {
        initialise,
        enCours,
        perdu,
        gagne,
        abandonne
    };

    struct UnScore
    {
        unsigned short int nbPaires;
        int uninbCoups;
        int tempsEcoule;
    };

    UnEtatMemory etat;
    UnScore score;
    wxButton *bouton;

//Cette classe gère des événements, déclaration d'une table statique
    DECLARE_EVENT_TABLE()

public:
    // Le constructeur
    Memory(const wxString& title);


    UnEtatMemory getEtatMemory();
    UnEtatMemory getEtatmemory();
    int getTempsMax();
    int TempsRestant();
    void getTempsMaxAlloue();
    void setEtatUnEtatMemory();
    void setTempsMaxAlloue(int a);
    void setTempsRestant();
    void getNbCasesOccupees();
    void setNbCaseOccupees();
    void getNbPairesObtenues();
    void setNbPairesObtenues();


    // Le destructeur
    virtual ~Memory();
};
#endif // PRINCIPALE_H
