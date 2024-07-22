# Bloom Filter

## Running the Project
### Required!
The project was built on a Linux operating system and used the "make" functionality for compiling and running the project.  
Therefore, it is necessary to have the "make" functionality to run the tests and the main program.

#### Compiler Version
    g++ (GCC) 14.1.1

#### Standard Version Used for Compilation
    std=c++17

### Running
    Usage: make [target] [options]
    Targets:
        run            Compiles and runs the main file
        run-exp        Compiles and runs the experimentation file
        run-all-exp    Compiles and runs for various values of M and k
        clean          Cleans up generated files
        help           Help message
    Options:
        save=1          Save the results of the experimentation

### Running Task Experimentation
To execute all the experiments for the task, simply run:

    make run-exp

This will execute the search algorithms for values of $N\in\{2^{10}, 2^{12}, 2^{14}, 2^{16}\}$ and for values of $p\in\{0, 1/4, 1/2, 3/4\}$, using M = 1,000,000 and k = 7.

If you run "make run-exp save=1", the results will be saved in a "results.csv" file, from which information will later be retrieved to generate comparative graphs.

#### Running with More Values
You can also run the following command to experiment with various values of M and k:

    make run-all-exp

Optionally, you can run:

    ./build/experimentation -- <M value> <k value>

## Project Structure

     .
    ├──  build                             ## Executables
    │   ├──  experimentation
    │   ├──  experimentation.o
    │   ├──  main
    │   └──  main.o
    ├──  db                                ## Files with names, to simulate a database.
    │   ├──  names.csv
    │   ├──  otherNames.csv
    │   └──  primes.csv
    ├──  headers                           ## Project headers
    │   ├──  db
    │   │   ├──  BloomFilterDataBase.hpp
    │   │   ├──  DataBase.hpp
    │   │   └──  NoFilterDataBase.hpp
    │   └──  filter
    │       └──  BloomFilter.hpp
    ├──  Makefile                          
    ├──  README.md
    ├──  results                           ## Experimentation results
    │   ├── 󰌠 requirements.txt
    │   ├──  results.csv
    │   ├──  results.html
    │   └── 󱧼 src
    │       ├──  clean.ipynb
    │       └──  results.ipynb
    └── 󱧼 src                               ## Task codes
        ├──  db
        │   ├──  BloomFilterDataBase.cpp
        │   └──  NoFilterDataBase.cpp
        ├──  experimentation.cpp
        ├──  filter
        │   └──  BloomFilter.cpp
        └──  main.cpp

## Results

The results of the experimentation are available in the results/ folder.