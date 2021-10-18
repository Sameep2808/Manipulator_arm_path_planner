[![Build Status](https://app.travis-ci.com/Sameep2808/Manipulator_arm_path_planner.svg?branch=main)](https://app.travis-ci.com/Sameep2808/Manipulator_arm_path_planner) 
[![Coverage Status](https://coveralls.io/repos/github/Sameep2808/Manipulator_arm_path_planner/badge.svg?branch=iteration_development_branch_1)](https://coveralls.io/github/Sameep2808/Manipulator_arm_path_planner?branch=iteration_development_branch_1)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Personnel
- Sameep Pote - M.Eng. Robotics Student at University of Maryland College Park. 
- Yash Kulkarni - M.Eng. Robotics Student at University of Maryland College Park. 

## License
MIT License

Copyright (c) 2021 Sameep Pote, Yash Kulkarni

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## Overview
Our objective is to create a IK solver and a path planning software for a 4DOF robotic arm. Today at every scale of manufacturing from minutely detailed VLSI board assembly to heavy industry such as automobile production as well as in warehouses for pick and place application, robotic arms are being used. Similarly Acme robotics can use a robotic arm for various activities once they have a software which can navigate their arm to desired location efficiently.

# Objective
Our project focuses on the software for optimal implementation of robotic arm, with 4DOF robotic arm equipped with an IK solver and custom designed path planner to simulate its actions and movement in capabilities similar to a human arm for a pick and place application. This software will be developed keeping in mind the inverse  kinematics and the path planning, taking into account the obstacles and complexities faced by robotic arm with any dimensions. 

# Approach
Inverse Kinematic Solver: Inverse kinematics uses kinematics equation to get the joint parameters which then can be used to calculate the desired position and rotation of our robotic arm end-effectors. We use this method as it is much faster compared to the forward kinematics. There are three methods to solve inverse kinematics:
	Algebraic: Basically solving using matrices
	Geometric:Using robotic arm’s geometry with trigonometric equations
	Numeric:Take random movements and look how close we are to the target then move one or 			more segments to locally minimize the error. Repeat the same process till you 			reach the final point
In this project we will be using the geometric method as it is comparatively less complex and efficient.

# Importance
Industry creates a lot of jobs which are repetitive, mundane and tedious. A human can work efficiently for 8 hours and more if trained properly but  still lacks efficiency when compared to a robot. Industry has realised this and is replacing humans with robotic arms for  these highly mundane jobs to increase productivity. Today at every scale of manufacturing from minutely detailed VLSI board assembly to heavy industry such as automobile production as well as in warehouses for pick and place application, robotic arms are being used. In each of these cases selection of the right robotic arm with the right inverse kinematics and path planning algorithm should be used. The software designed by us is a dynamic IK solver and path planner for a 5 DOF robotic arm with variable arm length as per the users requirements.

# Technologies Used
Programming language : C++.
Build system : Ubuntu 18.04, 20.04 .
Softwares used : Eclipse, OpenGL.
Libraries: Math library, Standard C++ Libraries.

# Risk and Mitigation
Mechanical failures may result in unexpected behaviour of the arm and such failures can cause potential damage to the system. To avoid this regular maintenance of the robot should be performed. Human errors can cause a wide range of mistakes like faulty interfacing or incorrect activation of software. To avoid these we can use exceptions while programming so that such mistakes are ignored and rectified and the program doesn't crash while running.

## Development Process
The design and development process will be followed by the AIP (Agile Iterative process) model. Here programmers Yash and Sameep will write the initial code using TDD (Test driven development) format where Sameep will be the driver and Yash will be the Navigator for the initial phase of code development. In the phase 2 of the process the driver and navigator roles will be swapped. The role of process manager will be observed by the person  in the role of navigator. Iteration meetings will be conducted and parallel code changes will be made. The product backlog will be created and it will be iterated as the project progresses. This will also ensure the quality of the project.
https://docs.google.com/spreadsheets/d/1PYU4KbmbUpj8JzwZs5e4I8T3UgeqICPrl9gqWq-t9LE/edit?usp=sharing

## Standard install via command-line
```
git clone --recursive https://github.com/Sameep2808/Manipulator_arm_path_planner
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/dpiet/Manipulator_arm_path_planner
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p boilerplate-eclipse
cd boilerplate-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../Manipulator_arm_path_planner/
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
