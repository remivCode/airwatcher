Programme de tests automatiques - mode d'emploi

Tout d'abord, afin d'effectuer tous les tests, il faut se donner les droits.
Il faut executer les deux commandes suivantes dans le fichier Tests:
chmod +x test.sh
chmod +x mktest.sh

Afin d'exécuter l'ensemble des tests, il faut exécuter la commande suivante:
./mktest.sh

-------------------------------------------------------------------------------
test.sh [ repertoire [ fichier.csv ] ]

- repertoire indique le répertoire dans lequel se trouvent les fichiers de 
configuration du test
- fichier.csv indique un fichier dans lequel les résultats du tests seront 
ajoutés

En l'absence d'arguments, le script traitera le répertoire courant

Fichiers de configuration :
- run : fichier texte indiquant la ligne de commande à éxécuter
- std.in : fichier texte indiquant une entrée clavier à simuler
- std.out : fichier texte indiquant la sortie devant être produite 
- description : fichier texte donnant la description du test

-------------------------------------------------------------------------------
mktest.sh
