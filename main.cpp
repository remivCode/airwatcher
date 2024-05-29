#include "Controller.h"
#include "View.h"
#include "Traitement.h"

int main()
{
    Traitement::chargerDonnees();
    View::MenuConnexion();
    return 0;
}