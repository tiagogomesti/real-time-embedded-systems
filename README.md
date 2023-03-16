https://www.coursera.org/specializations/real-time-embedded-systems

# Important Links
* Download raspiberry cross compile tools: https://sysprogs.com/getfile/1742/raspberry-gcc10.2.1.exe
* How to configure eclipse: https://www.96boards.org/documentation/guides/crosscompile/eclipseide.html
* Ninja-build: https://ninja-build.org/

# How to compile

## Requirements
*  arm-linux-gnueabihf toolchain installed and added to path
*  Ninja-build installed and added to path

## CMakeLists.txt example
```CMake
ccmake_minimum_required(VERSION 3.0.0)
set(PROJECT_NAME <YOUR_PROJECT_NAME>)

project(
    ${PROJECT_NAME}
        LANGUAGES
            C
            CXX
)

add_executable( 
    ${PROJECT_NAME}
        file_1.c
        file_2.c
)

target_link_libraries(
    ${PROJECT_NAME}
        pthread     # Necessary to use Posix Threads
)
```

## How to compile
```shell
mkdir build && cd build
cmake <PATH_TO_CMAKE_LISTS> -DCMAKE_TOOLCHAIN_FILE=<PATH_TO_TOOL_CHAIN_FOLDER>/Toolchain-RaspberryPi.cmake -G"Eclipse CDT4 - Ninja" -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=Debug
```

# Stuffes
* Clang-format on vscode "clang-format.assumeFilename": "C:/Users/tigomes/Workspace/Courses/RealTimeEmbeddedSystemsCourse/Tools/.clang-format"
