# Install script for directory: /home/fivosts/Repos/pytorch/third_party/ideep/mkl-dnn/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY MESSAGE_NEVER FILES "/home/fivosts/Repos/pytorch/build/lib/libmkldnn.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE MESSAGE_NEVER FILES
    "/home/fivosts/Repos/pytorch/build/third_party/ideep/mkl-dnn/include/mkldnn_version.h"
    "/home/fivosts/Repos/pytorch/third_party/ideep/mkl-dnn/src/../include/mkldnn.h"
    "/home/fivosts/Repos/pytorch/third_party/ideep/mkl-dnn/src/../include/mkldnn.hpp"
    "/home/fivosts/Repos/pytorch/third_party/ideep/mkl-dnn/src/../include/mkldnn_debug.h"
    "/home/fivosts/Repos/pytorch/third_party/ideep/mkl-dnn/src/../include/mkldnn_types.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/mkldnn" TYPE FILE MESSAGE_NEVER FILES
    "/home/fivosts/Repos/pytorch/build/third_party/ideep/mkl-dnn/src/generated/mkldnn-config.cmake"
    "/home/fivosts/Repos/pytorch/build/third_party/ideep/mkl-dnn/src/generated/mkldnn-config-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/mkldnn/mkldnn-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/mkldnn/mkldnn-targets.cmake"
         "/home/fivosts/Repos/pytorch/build/third_party/ideep/mkl-dnn/src/CMakeFiles/Export/lib/cmake/mkldnn/mkldnn-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/mkldnn/mkldnn-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/mkldnn/mkldnn-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/mkldnn" TYPE FILE MESSAGE_NEVER FILES "/home/fivosts/Repos/pytorch/build/third_party/ideep/mkl-dnn/src/CMakeFiles/Export/lib/cmake/mkldnn/mkldnn-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/mkldnn" TYPE FILE MESSAGE_NEVER FILES "/home/fivosts/Repos/pytorch/build/third_party/ideep/mkl-dnn/src/CMakeFiles/Export/lib/cmake/mkldnn/mkldnn-targets-release.cmake")
  endif()
endif()

