# Turn on symbol export to make the shared library.
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
# Make the shared 'complex' library.
add_library(complex SHARED complex.hpp complex.cpp)

install(FILES ${CMAKE_CURRENT_LIST_DIR}/complex.cpp ${CMAKE_CURRENT_LIST_DIR}/complex.hpp DESTINATION "include/complex/")
