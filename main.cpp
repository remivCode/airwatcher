#include "Controller.h"
#include "View.h"
#include "Traitement.h"

int main()
{
    Traitement::chargerDonnees();
    View::MenuConnexion();
    Traitement::clean();
    Controller::clean();
    return 0;
}