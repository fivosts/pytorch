# Install script for directory: /home/fivosts/Repos/pytorch/aten/src/TH

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/TH" TYPE FILE MESSAGE_NEVER FILES
    "/home/fivosts/Repos/pytorch/aten/src/TH/TH.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THAllocator.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THMath.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THBlas.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THDiskFile.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THFile.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THFilePrivate.h"
    "/home/fivosts/Repos/pytorch/build/caffe2/aten/src/TH/THGeneral.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateAllTypes.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateBFloat16Type.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateBoolType.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateDoubleType.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateFloatType.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateHalfType.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateLongType.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateIntType.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateShortType.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateCharType.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateByteType.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateFloatTypes.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateIntTypes.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateQUInt8Type.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateQInt8Type.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateQInt32Type.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerateQTypes.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THLapack.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THLogAdd.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THMemoryFile.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THSize.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THStorage.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THStorageFunctions.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THTensor.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THTensorApply.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THTensorDimApply.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THVector.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THHalf.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THTensor.hpp"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THStorageFunctions.hpp"
    "/home/fivosts/Repos/pytorch/aten/src/TH/THGenerator.hpp"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/TH/vector" TYPE FILE MESSAGE_NEVER FILES
    "/home/fivosts/Repos/pytorch/aten/src/TH/vector/AVX.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/vector/AVX2.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/../ATen/native/cpu/avx_mathfun.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/TH/generic" TYPE FILE MESSAGE_NEVER FILES
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THBlas.cpp"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THBlas.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THLapack.cpp"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THLapack.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THStorage.cpp"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THStorage.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THStorageCopy.cpp"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THStorageCopy.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THTensor.cpp"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THTensor.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THTensor.hpp"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THTensorConv.cpp"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THTensorConv.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THTensorFill.cpp"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THTensorFill.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THTensorLapack.cpp"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THTensorLapack.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THTensorMath.cpp"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THTensorMath.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THTensorRandom.cpp"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THTensorRandom.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THVectorDispatch.cpp"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THVector.h"
    "/home/fivosts/Repos/pytorch/aten/src/TH/generic/THTensorFastGetSet.hpp"
    )
endif()

