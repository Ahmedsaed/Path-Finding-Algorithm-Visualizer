# Path-Finding-Algorithm-Visualizer


## Table of Contents

- [Introduction](#introduction)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Makefile Usage](#makefile-usage)
- [Usage](#usage)
- [Features](#features)
- [Algorithms](#algorithms)
- [Contributing](#contributing)

## Introduction

The Path Finding Algorithm Visualizer is implemented in C++ using the Qt framework. It provides a user-friendly interface where users can define a start point and an end point. They can then choose a path finding algorithm to visualize its execution on the graph. The visualization includes the exploration of nodes, the generation of the path, and the highlighting of the shortest path.

[Screencast from 2023-05-31 00-25-42.webm](https://github.com/Ahmedsaed/Path-Finding-Algorithm-Visualizer/assets/37080003/34d5b4eb-1742-4443-a634-6e5c94c69fcc)


## Project Structure
```
Path-Finding-Algorithm-Visualizer
├── build                           # build directory
├── sources                         # source files (.cpp)
|   ├── queue.cpp                   # source files for data structures
|   ├── stack.cpp
|   ├── set.cpp
|   ├── ...
|   ├── bfs.cpp                     # source files for algorithms
|   ├── dfs.cpp
|   ├── ...
|   └── main.cpp                    # main - entry point
├── include                         # header files (.h)
|   ├── queue.h                     # header files for data structures
|   ├── stack.h
|   ├── set.h
|   ├── ...
|   ├── bfs.h                       # header files for algorithms
|   ├── dfs.h
|   ├── ...
|   └── main.h                      # main header file
├── tests                           # test files
|   ├── unit                        # unit tests
|   |   └── queue.cpp
|   └── integration                 # integration tests
|       └── bfs.py
└── Makefile                        # Automation scripts to build, run and test the program
```

## Installation

    Note: The main branch contains the main logic warped in a command line interface. switch to the gui branch for the graphical user interface

1. Clone the repository from GitHub to your local machine:

```bash
git clone https://github.com/Ahmedsaed/Path-Finding-Algorithm-Visualizer.git
```

2. Install the necessary dependencies, including Qt framework and any additional libraries required by the project.

3. Build and run the project using the build system. We have wrote a build system using gnu make. read the next section for more details on how to use it.

## Makefile Usage

We have wrote a Makefile that can be used to automate various tasks such as compiling the executable, running tests, and more.

To use the Makefile, open a terminal and navigate to the project directory. Then, type `make` followed by the recipe you want to run. Here's a list of the available recipes:

- `build`: This recipe compiles the source files. It generates an executable file called `shortest_path`.

- `run_tests`: This recipe runs unit and integration tests on the executable. The integration tests requires `python 3` to be installed

- `check_memory`: This recipe checks for memory leaks and errors using Valgrind. It requires the `Valgrind` program to be installed.

- `all`: This is a special recipe that gets called when no arguments are being passed to `make`. This recipe will run `clear_screen build run_tests check_memory`. This means that typing `make` in the terminal will run these recipes in order.

- `run`: This recipe runs the compiled executable (`./build/shortest_path`).

Note that some of the recipes require specific programs to be installed, such as `valgrind` and `python3`. If you encounter any errors when running the Makefile, make sure that these programs are installed on your system.

To run a recipe, type `make` followed by the recipe name. For example, to compile the executable, type:

```bash
make build
```

This will generate an executable file called `shortest_path` in `build` directory. To run the executable, type:
```bash
make run
```

## Features

The Path Finding Algorithm Visualizer offers the following features:

- Interactive graph-based interface for defining start and end nodes.
- Visualization of various path finding algorithms.
- Display of explored nodes and generated path.

## Algorithms

We have implemented the following path finding algorithms:

- Breath First Search (BFS)
- Depth First Search (DFS)
- Depth Limited Search (DLS)
- Iterative Deepening Depth First Search (IDDFS)
- Uniform Cost Search (UCS)
- Bidirectional Search
- A* Search
- Greedy Best-First Search

## Data Structures

We have implemented the following data structures:

- Queue
- Stack
- Priority Queue
- Vector
- Pair

## Contributing

We welcome contributions to the Path Finding Algorithm Visualizer. If you find a bug or have an idea for an improvement, please submit an issue on GitHub. If you would like to implement the feature or fix the bug yourself, please make a pull request.
