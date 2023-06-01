add_executable(draft)

file(GLOB SOURCE_FILES *.cpp *.hpp)

target_sources(draft PUBLIC ${SOURCE_FILES})

target_link_libraries(draft PUBLIC misc)
target_link_libraries(draft PUBLIC my_testing_tools)
