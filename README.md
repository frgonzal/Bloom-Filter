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
        run-all-exp    Compila y ejecuta para varios valores de M y k
	    clean          Limpia los archivos generados
	    help           Mensaje de ayuda
	Options:
	    save=1	        Guardar resultados de la experimentación


### Ejecutar experimentación de la Tarea
Para ejectuar todos los experimentos de la tarea basta con ejecutar:

    make run-exp

Esto ejecutara los algoritmos de búsqueda para los valores de $N\in\{2^{10}, 2^{12}, 2^{14}, 2^{16}\}$ y para los valores de $p\in\{0, 1/4, 1/2, 3/4\}$, utilizando el valor M = 1.000.000 y k = 7.

Si se ejecuta "make run-exp save=1" entonces se guardaran los resultados de lo anterior en un archivo "results.csv", del cual luego se recupera la información para generar graficos comparativos.

#### Ejecutar más valores
También se puede ejecutar el siguiente comando para experimentar con varios valores de M y k:

    make run-all-exp

Opcionalmente, se puede ejecutar:

    ./build/experimentation -- <valor de M> <valor de k>



## Estructura del proyecto

     .
    ├──  build                             ## Ejecutables
    │   ├──  experimentation
    │   ├──  experimentation.o
    │   ├──  main
    │   └──  main.o
    ├──  db                                ## Archivos con los nombres, para simular base de datos.
    │   ├──  names.csv
    │   ├──  otherNames.csv
    │   └──  primes.csv
    ├──  headers                           ## Headers del proyecto
    │   ├──  db
    │   │   ├──  BloomFilterDataBase.hpp
    │   │   ├──  DataBase.hpp
    │   │   └──  NoFilterDataBase.hpp
    │   └──  filter
    │       └──  BloomFilter.hpp
    ├──  Makefile                          
    ├──  README.md
    ├──  results                           ## Resultados de la experimentación
    │   ├── 󰌠 requirements.txt
    │   ├──  results.csv
    │   ├──  results.html
    │   └── 󱧼 src
    │       ├──  clean.ipynb
    │       └──  results.ipynb
    └── 󱧼 src                               ## Códigos de la tarea
        ├──  db
        │   ├──  BloomFilterDataBase.cpp
        │   └──  NoFilterDataBase.cpp
        ├──  experimentation.cpp
        ├──  filter
        │   └──  BloomFilter.cpp
        └──  main.cpp


## Resultados

Los resultados de la experimentación se encuentran disponibles en el archivo results.ipynb,
el cual lee los archivos generados por "experimentation" para generar gráficos y figuras con la información
obtenida.    
Para poder ejecutar el .ipynb, se cuenta con un archivo requirements.txt al interior de la carpeta ./resultados con todos los módulos necesarios.

