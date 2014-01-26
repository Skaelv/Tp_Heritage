RM = rm
ECHO = echo
COMP = g++
EDL = g++
EXE = B3428
CPPFLAGS = -Wall
EDLFLAGS = 
LIBS = 
LIBPATH = 
INCPATH = 
CLEAN = efface
RMFLAGS = -f

INT = AjouterCercleCommand.h AjouterLigneCommand.h AjouterObjetAgregeCommand.h AjouterPolyligneCommand.h AjouterRectangleCommand.h Cercle.h ChargerCommand.h ClearCommand.h Command.h Controller.h DeleteCommand.h EltGeo.h Ligne.h Modele.h ObjetAgrege.h Point.h Polyligne.h Rectangle.h TranslaterCommand.h main.h
REAL = $(INT: .h = .cpp)
OBJ = $(INT:.h=.o)

.PHONY : $(CLEAN)

$(EXE) : $(OBJ)
	$(ECHO) EDL de $(EXE)
	$(EDL) -o $(EXE) $(OBJ)
	
%.o : %.cpp
	$(ECHO) compilation $<
	$(COMP) $(CPPFLAGS) -c $<

efface :
	$(ECHO) Nettoyage
	rm -f *.o $(EXE) core