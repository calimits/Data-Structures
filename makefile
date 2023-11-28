#Template makefile for any C++ project

#Qué modificaciones hacer según el proyecto:
#1-Agregar los archivos .cpp que deben compilarse a la variable SRC
#2-Agregar los paths de las carpetas necesarias para la compilación en 
#la variable FLAI y en vpath
#3-Agregar el nombre del .exe que se va a generar y de la carpeta
#**************EL RESTO ESTÄ HECHO*********************************

#Creación de una variable para guardar el nombre del ejecutable
EXE = example

#Creación de una variable para guardar el nombre de la carpeta 
#donde se guardará el ejecutable
FOLDER = bin

#Se define una variable SRC que incluirá todos los archivos .cpp a compilar
SRC = main.cpp 
#Luego se crea una carpeta donde se incluirán todos los archivos .cpp que deben compilarse, con
#la extensión .o
OBJ = $(patsubst %.cpp, %.o, $(SRC))

#Se define las flags de include en caso de que haya archivos de inclusión en otras carpetas
FLAI = -I include -Wall 
#nota: si hay más carpetas incluirlas igual, seguido -I carpeta -I carpeta2 etc etc

#Si el proyecto tiene más de una carpeta dentro de la raíz agregarlas
#mediante VPATH=carpeta o vpath %.cpp carpeta
vpath %.cpp src
vpath %.h include


#En la regla all se define la creación de la carpeta
all: $(EXE)
	mkdir $(FOLDER) || echo "[i] bin directory was already created"
	mv $(EXE) ./$(FOLDER)/$(EXE)

#Luego se preocede a lo más importante de make, los procesos de compilación 
$(EXE): $(OBJ)
	g++ $(OBJ) -o $(EXE)

%.o: %.cpp
	g++ -c $(FLAI) $< -o $@