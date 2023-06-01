add_executable(sample)

file(GLOB SOURCE_FILES *.cpp *.hpp)

target_sources(sample PUBLIC ${SOURCE_FILES})

# if(MSVC)
#   target_compile_options(sample PRIVATE /W4 /WX)
# else()
#   target_compile_options(sample PRIVATE -Wall -Wextra -Wpedantic -Werror)
# endif()

target_link_libraries(sample PUBLIC misc)
target_link_libraries(sample PUBLIC data_structures)
