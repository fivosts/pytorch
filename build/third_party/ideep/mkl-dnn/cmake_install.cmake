# Install script for directory: /home/fivosts/Repos/pytorch/third_party/ideep/mkl-dnn

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE PROGRAM MESSAGE_NEVER FILES
    "/home/fivosts/Repos/pytorch/third_party/ideep/mkl-dnn/external/mklml_lnx_2019.0.3.20190220/lib/libmklml_intel.so"
    "/home/fivosts/Repos/pytorch/third_party/ideep/mkl-dnn/external/mklml_lnx_2019.0.3.20190220/lib/libiomp5.so"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/mkldnn" TYPE DIRECTORY OPTIONAL MESSAGE_NEVER FILES "/home/fivosts/Repos/pytorch/build/third_party/ideep/mkl-dnn/reference")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/mkldnn" TYPE FILE MESSAGE_NEVER FILES "/home/fivosts/Repos/pytorch/third_party/ideep/mkl-dnn/LICENSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/fivosts/Repos/pytorch/build/third_party/ideep/mkl-dnn/src/cmake_install.cmake")
  include("/home/fivosts/Repos/pytorch/build/third_party/ideep/mkl-dnn/examples/cmake_install.cmake")
  include("/home/fivosts/Repos/pytorch/build/third_party/ideep/mkl-dnn/tests/cmake_install.cmake")

endif()

