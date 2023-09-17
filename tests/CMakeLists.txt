add_executable(tests)

file(GLOB SOURCE_FILES *.cpp *.hpp *.h)

target_sources(tests PUBLIC ${SOURCE_FILES})

target_link_libraries(tests PUBLIC misc)
target_link_libraries(tests PUBLIC my_testing_tools)
