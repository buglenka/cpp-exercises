add_subdirectory(${PROJECT_NAME})

# Add executable called "helloDemo" that is built from the source file
# "main.cpp". The extensions are automatically found.
add_executable (main main.cpp)

# Link the executable to the Solution library. Since the Solution library has
# public include directories we will use those link directories when building
# main
target_link_libraries (main LINK_PUBLIC Solution)