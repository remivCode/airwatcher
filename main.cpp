#include "Controller.h"
#include "View.h"
#include "Traitement.h"

int main()
{
    Traitement::chargerDonnees();
    View::MenuConnexion();
    cout << "retour main" << endl;
    Traitement::clean();
    Controller::clean();
    return 0;
}