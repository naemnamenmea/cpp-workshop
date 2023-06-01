add_executable(EntryPoint)

file(GLOB SOURCE_FILES *.cpp *.hpp)

target_sources(EntryPoint PUBLIC ${SOURCE_FILES})

target_link_libraries(EntryPoint PUBLIC misc)
