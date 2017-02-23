# Create a library called "Solution" which includes the source file "Solution.cpp".
# The extension is already found. Any number of sources could be listed here.
add_library (Solution Solution.cpp)

# Make sure the compiler can find include files for our Solution library
# when other libraries or executables link to Hello
target_include_directories (Solution PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})