cmake_minimum_required(VERSION 3.19)

project(C++Workshop)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

list(APPEND CMAKE_MODULE_PATH
    "C:/Users/Andrew/source/repos/cmake-tutorial/dev/cmake")
include(common)

add_external_lib(my_testing_tools)
add_external_lib(math)
add_external_lib(misc)
add_external_lib(data_structures)

add_subdirectory(sample)
add_subdirectory(draft)
add_subdirectory(EntryPoint)
