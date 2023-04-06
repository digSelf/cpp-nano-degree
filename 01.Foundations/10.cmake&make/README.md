CMakeLists.txt:

* ```
        cmake_minimum_required(VERSION 3.5.1)
        set(CMAKE_CXX_STANDARD 14)
    ```

* These lines set the minimum cmake version required to 3.5.1 and set the environment variable CMAKE_CXX_STANDARD so CMake uses C++ 14. On your own computer, if you have a recent g++ compiler, you could use C++ 17 instead.

* CMake requires that we name the project, so you should choose a name for the project and then add the following line to CMakeLists.txt:

  * `project(<your_project_name>)`

* Next, we want to add an executable to this project. You can do that with the add_executable command by specifying the executable name, along with the locations of all the source files that you will need. CMake has the ability to automatically find source files in a directory, but for now, you can just specify each file needed:

  * `add_executable(your_executable_name  path_to_file_1  path_to_file_2 ...)`

* A typical CMake project will have a build directory in the same place as the top-level CMakeLists.txt. Make a build directory in the /home/workspace/cmake_example folder:

* ```bash
    root@abc123defg:/home/workspace/cmake_example# mkdir build
    root@abc123defg:/home/workspace/cmake_example# cd build
    root@abc123defg:/home/workspace/cmake_example/build# cmake ..
    root@abc123defg:/home/workspace/cmake_example/build# make
    root@abc123defg:/home/workspace/cmake_example/build# ./your_executable_name
    ```

  * The first line directs the cmake command at the top-level CMakeLists.txt file with ... This command uses the CMakeLists.txt to configure the project and create a Makefile in the build directory.

  * In the second line, make finds the Makefile and uses the instructions in the Makefile to build the project.

  * Now that your project builds correctly, try modifying one of the files. When you are ready to run the project again, you'll only need to run the make command from the build folder, and only that file will be compiled again. Try it now!

  * In general, CMake only needs to be run once for a project, unless you are changing build options (e.g. using different build flags or changing where you store your files).

  * Make will be able to keep track of which files have changed and compile only those that need to be compiled before building.
