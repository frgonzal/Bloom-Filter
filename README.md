# Filtro de Bloom

## Ejecutar Proyecto
### Necesario!
El proyecto se construyo en un sistema operativo con linux y se utilizo
la funcionalidad "make" para la compilación y ejecución del proyecto.    
Por lo anterior, es necesario tener la funcionalidad "make" para ejecutar los test y el main.

#### Versión del compilador
    g++ (GCC) 14.1.1

#### Versión estándar con la que se compilo
    std=c++17


### Ejecutar
	Uso: make [target] [options]
	Targets:
	    run            Compila y ejecuta archivo main
	    run-exp        Compila y ejecuta archivo experimentation
	    clean          Limpia los archivos generados
	    help           Mensaje de ayuda
	Options:
	    test=1          Ejecutar test que comprueben resultados de la experimentación
	    save=1	        Guardar resultados de la experimentación
	    test-and-save=1 Ejecutar test y guardar resultados


### Ejecutar experimentación de la Tarea
Para ejectuar todos los experimentos de la tarea basta con ejecutar:

    make run-exp

... rellenar con informacion de la experimentacion ...

Si se ejecuta "make run-exp save=1" entonces se guardaran los resultados de lo anterior en un archivo "results.csv", del cual luego se recupera la información para generar graficos comparativos.


## Estructura del proyecto

     .
    ├──  bdd
    │   ├──  Film-Names.csv
    │   └──  Popular-Baby-Names-Final.csv
    ├──  build
    ├──  headers
    ├──  Makefile
    ├──  README.md
    ├──  results
    └── 󱧼 src


## Resultados

Los resultados de la experimentación se encuentran disponibles en el archivo results.ipynb,
el cual lee los archivos generados por "experimentation" para generar gráficos y figuras con la información
obtenida.    
Para poder ejecutar el .ipynb, se cuenta con un archivo requirements.txt al interior de la carpeta ./resultados con todos los módulos necesarios.

