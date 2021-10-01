# PID Controller
[![Build Status](https://app.travis-ci.com/SamPusegaonkar/Test-Driven-PID.svg?branch=main)](https://app.travis-ci.com/SamPusegaonkar/Test-Driven-PID)
[![Coverage Status](https://coveralls.io/repos/github/SamPusegaonkar/Test-Driven-PID/badge.svg?branch=main)](https://coveralls.io/github/SamPusegaonkar/Test-Driven-PID?branch=main)
---

## Overview

A Repo for the PID class done using test driven development & pair programming

- Sameer Pusegaonkar: Driver
- Kavyashree Devadiga: Navigator


## Instructions to run the program.

## 1st Method to Run: Standard install via command-line
```
cd Test-Driven-PID
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## To run cpplint for the entire directory:
```
Go outside the directory & run cpplint ~/Test-Driven-PID/*.* ~/Test-Driven-PID/*/*.*
Or we can run cpplint on the 3 individual files:
cd Test-Driven-PID
cpplint ./app/main.cpp
cpplint ./app/PID.cpp
cpplint ./include/PID.h


```

## To run cppcheck 
```
cd Test-Driven-PID
cd app
cppcheck ./app/main.cpp
cppcheck ./app/PID.cpp
cppcheck ./include/PID.h
```

## 2nd Method to Run: Using Eclipse IDE (Outdated)
## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
Paste the all the problem folders in ~/workspace
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
cd boilerplate-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../<directory>/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "boilerplate-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold boilerplate-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)


## Debug


1. Set breakpoint in source file (i.e. double click in the left margin on the line you want 
the program to break).

2. In Eclipse, right click on the boilerplate-eclipse in Project Explorer, select Debug As -> 
Local C/C++ Application, choose the binaries to run (e.g. shell-app).

3. If prompt to "Confirm Perspective Switch", select yes.

4. Program will break at the breakpoint you set.

5. Press Step Into (F5), Step Over (F6), Step Return (F7) to step/debug your program.

6. Right click on the variable in editor to add watch expression to watch the variable in 
debugger window.

7. Press Terminate icon to terminate debugging and press C/C++ icon to switch back to C/C++ 
perspetive view (or Windows->Perspective->Open Perspective->C/C++).


## Plugins

- CppChEclipse

    To install and run cppcheck in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> cppcheclipse.
    Set cppcheck binary path to "/usr/bin/cppcheck".

    2. To run CPPCheck on a project, right click on the project name in the Project Explorer 
    and choose cppcheck -> Run cppcheck.


- Google C++ Sytle

    To include and use Google C++ Style formatter in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> Code Style -> Formatter. 
    Import [eclipse-cpp-google-style][reference-id-for-eclipse-cpp-google-style] and apply.

    2. To use Google C++ style formatter, right click on the source code or folder in 
    Project Explorer and choose Source -> Format

[reference-id-for-eclipse-cpp-google-style]: https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-cpp-google-style.xml

- Git

    It is possible to manage version control through Eclipse and the git plugin, but it typically requires creating another project. If you're interested in this, try it out yourself and contact me on Canvas.
