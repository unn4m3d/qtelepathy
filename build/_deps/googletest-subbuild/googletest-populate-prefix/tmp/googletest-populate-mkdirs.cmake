# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/unn4m3d/Projects/qtelepathy/build/_deps/googletest-src"
  "/home/unn4m3d/Projects/qtelepathy/build/_deps/googletest-build"
  "/home/unn4m3d/Projects/qtelepathy/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/home/unn4m3d/Projects/qtelepathy/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/home/unn4m3d/Projects/qtelepathy/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/home/unn4m3d/Projects/qtelepathy/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/home/unn4m3d/Projects/qtelepathy/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/unn4m3d/Projects/qtelepathy/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
