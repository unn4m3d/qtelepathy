# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/qtelepathy_static_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/qtelepathy_static_autogen.dir/ParseCache.txt"
  "CMakeFiles/test1_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/test1_autogen.dir/ParseCache.txt"
  "qtelepathy_static_autogen"
  "test1_autogen"
  )
endif()
