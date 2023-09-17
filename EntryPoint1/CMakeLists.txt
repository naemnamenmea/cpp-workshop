add_executable(EntryPoint1)

file(GLOB SOURCE_FILES *.cpp *.hpp)

target_sources(EntryPoint1 PUBLIC ${SOURCE_FILES})

target_link_libraries(EntryPoint1 PUBLIC misc)
