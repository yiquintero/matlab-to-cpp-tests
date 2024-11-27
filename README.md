A repository to validate the correctness of matrix operations translated from MATLAB to C++ using the Eigen library. It includes example matrix computations and GoogleTest-based tests to ensure equivalence between MATLAB and C++ implementations. 

## Requirements 
- C++ compiler
- [CMake version](cmake.org) (> 3.14)
- [GNU Make](https://www.gnu.org/software/make/) (Linux and MacOS only)
- [Visual Studio](https://visualstudio.microsoft.com) (Windows only)

The [GoogleTest framework](https://google.github.io/googletest/) and the [Eigen library](https://eigen.tuxfamily.org/index.php?title=Main_Page) are also required, but these are installed automatically by CMake when building the project.  

## Build and run the tests
This project uses CMake to build the tests according to your operating system. By default, CMake will use:
- Makefiles & GNU compilers (gcc, g++) on Linux-based systems (e.g. Ubuntu)
- Makefiles & Clang compilers on MacOS
- Visual Studio solution & compilers on Windows  

### Linux and MacOS
```bash
# Download the project
git clone https://github.com/yiquintero/matlab-to-cpp-tests.git
cd matlab-to-cpp-tests

# Configure CMake project
mkdir build
cd build
cmake .. # this command generates the Makefile & downloads Eigen and GoogleTest

# Compile the tests
make

# Run the tests
ctest
```

### Windows
Launch Visual Studio and open the built-in Terminal using the Menu at the top of the screen (View -> Terminal). Type the following commands in the newly opened Terminal:

```shell
# Download the project
git clone https://github.com/yiquintero/matlab-to-cpp-tests.git
cd matlab-to-cpp-tests

# Configure CMake project
mkdir build
cd build
cmake .. # this command generates the Visual Studio Solution & downloads Eigen and GoogleTest

# Compile the tests
msbuild testcppvsmatlab.vcxproj

# Run the tests
ctest
```
