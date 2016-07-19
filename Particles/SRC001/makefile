#
#	This is the make file for the parxel program.
#
#
#	Headers for this project will be stored in the daughter folder HDR001	
#	Objects created by this project will be stored in the daughter folder OBJ001
#
#
vpath %.cpp ../SRC001
CC = g++
#PARXPACK = main.cpp parx.cpp cell.cpp exforce.cpp inforce.cpp simbox.cpp
PARXPACK = main.cpp parxy.cpp simBox.cpp
#OBJECTS = main.o parx.o cell.o exforce.o inforce.o simbox.o
OBJECTS = main.o parxy.o simBox.h
CFLAGS = -I.
#HEADS = main.h parx.h cell.h exforoce.h inforce.h simbox.h
HEADS = parxy.h
IDIR = HDR001
ODIR = OBJ001



_DEPS = $(HEADS)
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJS = $(PARXPACK) 
OBJS = $(patsubst %.cpp,$(ODIR)/%.o,$(_OBJS))

$(OBJS): | OBJ001

OBJ001:
	@mkdir -p $@

OBJ001/%.o : %.cpp $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

parxy : $(OBJS) $(DEPS)
	g++ -o $@ $^ $(CFLAGS)

.PHONY: clean

	
clean :
	rm -f $(ODIR)/*.o 
