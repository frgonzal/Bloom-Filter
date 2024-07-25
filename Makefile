PROJECT = BloomFilter
CC = g++

## agregar flags? como -g o -Wall
CFLAGS = -std=c++17 -g -Wall

## agregar librerias extra
LDLIBS=

TARGET=./build/main
TEST=./build/experimentation

## AQUI INCLUIR LOS ARCHIVOS .C 
## excepto main y test
## agregar un "\" al final de cada nombre
SRC = \
	src/filter/BloomFilter.cpp \
	src/filter/NullFilter.cpp \
	src/db/DataBase.cpp \


## nombre de los headers (automatico)
HDRS = $(wildcard headers/*.hpp)
## nombre de los .o (automatico)
OBJS = $(SRC:./src/%.cpp=./build/%.o)


all:
	@echo " Bloom Filter implementation"
	@echo ""
	@echo " use \"make help\" to get more info"

## Compila un .o a partir del src
./build/%.o: ./src/*/%.cpp $(HDRS)
	@ $(CC) $(CFLAGS)  -c $< -o $@

## Compila un .o a partir del src
./build/%.o: ./src/%.cpp $(HDRS)
	@ $(CC) $(CFLAGS)  -c $< -o $@

## Compila el ejecutable del main y ejecuta
.PHONY: run
run: $(OBJS) $(TARGET).o
	@ $(CC) $(CFLAGS) $^ -o $(TARGET) $(LDLIBS) && $(TARGET)

## Compila el ejecutable de los test y ejecuta
.PHONY: run-exp
run-exp: $(OBJS) $(TEST).o
	@ $(CC) $(CFLAGS) $^ -o $(TEST) $(LDLIBS)
ifeq ($(save), 1) 
	@ $(TEST) --save
else
	@ $(TEST)
endif

.PHONY: run-all-exp
run-all-exp: $(OBJS) $(TEST).o
	@ $(CC) $(CFLAGS) $^ -o $(TEST) $(LDLIBS)
	@ $(TEST) --save  100000 1
	@ $(TEST) --save  250000 2
	@ $(TEST) --save  500000 4
	@ $(TEST) --save  750000 6
	@ $(TEST) --save 1000000 7
	@ $(TEST) --save 2000000 15

.PHONY: zip
zip:
	zip -r Tarea3.zip 				\
		../$(PROJECT)/build/ 		\
		../$(PROJECT)/db/			\
		../$(PROJECT)/headers/ 		\
		../$(PROJECT)/results/		\
		../$(PROJECT)/src/	 		\
		../$(PROJECT)/Makefile 		\
		../$(PROJECT)/README.md  	\
		./Informe.pdf	\

## borra todo lo que se compilo
.PHONY: clean
clean: $(wildcard build/*.o)
	@ rm -f $(TARGET)
	@ rm -f $(TEST)
	@ rm -f $^

.PHONY: help
help:
	@echo "Usage: make [target] [options]"
	@echo "Targets:"
	@echo "  run            Build and run the main program"
	@echo "  run-exp        Build and run the experimentation program"
	@echo "  run-all-exp    Compila y ejecuta para varios valores de M y k"
	@echo "  clean          Clean the build files"
	@echo "  help           Display this help message"
	@echo "Options:"
	@echo "  save=1	  	Save the time results"