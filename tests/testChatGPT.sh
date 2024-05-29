# Chemin vers le programme à tester
PROGRAM=./run

# Fichiers d'entrée et de sortie standard
INPUT_FILE=./std.in
EXPECTED_OUTPUT_FILE=./std.out

# Fichier de sortie temporaire généré par le programme
OUTPUT_FILE=output.tmp

# Exécuter le programme avec le fichier d'entrée
$PROGRAM < $INPUT_FILE > $OUTPUT_FILE

# Comparer la sortie générée avec la sortie attendue
if diff -q $OUTPUT_FILE $EXPECTED_OUTPUT_FILE > /dev/null; then
    echo "Test réussi: la sortie du programme correspond à la sortie attendue."
    # Supprimer le fichier de sortie temporaire
    rm $OUTPUT_FILE
else
    echo "Échec du test: la sortie du programme ne correspond pas à la sortie attendue."
    echo "Différences (output vs expected):"
    diff $OUTPUT_FILE $EXPECTED_OUTPUT_FILE
    # Conserver le fichier de sortie temporaire pour inspection
    echo "Le fichier de sortie est disponible ici: $OUTPUT_FILE"
fi