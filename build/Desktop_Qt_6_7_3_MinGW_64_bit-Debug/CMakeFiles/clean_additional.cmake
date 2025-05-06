# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ProjetCC_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ProjetCC_autogen.dir\\ParseCache.txt"
  "ProjetCC_autogen"
  )
endif()
