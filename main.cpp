#include "Controller.h"
#include "View.h"
#include "Traitement.h"

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        int argument = atoi(argv[1]); // Convertir l'argument en entier

        cout << "Execution with argument: " << argument << endl;

        switch (argument)
        {
        case 1:
            Traitement::chargerDonneesTest();
            break;
        default:
            cout << "Argument non valide" << endl;
            Traitement::chargerDonnees();
        }
    }
    else
    {
        // Si aucun argument n'est passé, exécuter Traitement::chargerDonnees()
        Traitement::chargerDonnees();
    }
    View::MenuConnexion();
    Traitement::clean();
    Controller::clean();
    return 0;
}