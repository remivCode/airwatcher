ECHO = @echo
EDL = g++
COMP = g++
CCFLAGS = -ansi -pedantic -Wall -std=c++11
MAP_OPTION =
EXE=analog
BIN = ./bin
EXE_DIR = $(EXE:%=$(BIN)/%)

INT = AirMeasurement.h Attribute.h Cleaner.h CoordGPS.h Date.h GovernmentAgencyEmployee.h Measurement.h PrivateIndividual.h Provider.h Sensor.h User.h Controller.h
SRC = $(INT:.h=.cpp) main.cpp
OBJ = $(INT:.h=.o) main.o


ifdef MAP
	MAP_OPTION = -DMAP
endif

all: $(EXE_DIR)

$(EXE_DIR):$(OBJ)
	$(ECHO) "Edl de $@"
	$(EDL) -o $@ $(OBJ)


$(BIN)/%.o:%.cpp %.h
	$(ECHO) "Compilation de $<"
	$(COMP) -c $< $(CCFLAGS) $(MAP_OPTION)

clean:
	$(ECHO) "Nettoyage des fichiers objets et de l'executable"
	rm -f $(OBJ) $(EXE_DIR)
