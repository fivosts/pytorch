# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# The generator used is:
set(CMAKE_DEPENDS_GENERATOR "Unix Makefiles")

# The top level Makefile was generated from the following files:
set(CMAKE_MAKEFILE_DEPENDS
  "CMakeCache.txt"
  "../CMakeLists.txt"
  "../aten/CMakeLists.txt"
  "../aten/src/ATen/ATenConfig.cmake.in"
  "../aten/src/ATen/CMakeLists.txt"
  "../aten/src/ATen/Config.h.in"
  "../aten/src/ATen/common_with_cwrap.py"
  "../aten/src/ATen/core/CMakeLists.txt"
  "../aten/src/ATen/cuda/CUDAConfig.h.in"
  "../aten/src/ATen/native/cpu/Activation.cpp"
  "../aten/src/ATen/native/cpu/BinaryOpsKernel.cpp"
  "../aten/src/ATen/native/cpu/CopyKernel.cpp"
  "../aten/src/ATen/native/cpu/CrossKernel.cpp"
  "../aten/src/ATen/native/cpu/DistanceOpsKernel.cpp"
  "../aten/src/ATen/native/cpu/FillKernel.cpp"
  "../aten/src/ATen/native/cpu/GridSamplerKernel.cpp"
  "../aten/src/ATen/native/cpu/IndexKernel.cpp"
  "../aten/src/ATen/native/cpu/LerpKernel.cpp"
  "../aten/src/ATen/native/cpu/PointwiseOpsKernel.cpp"
  "../aten/src/ATen/native/cpu/ReduceOpsKernel.cpp"
  "../aten/src/ATen/native/cpu/SoftMaxKernel.cpp"
  "../aten/src/ATen/native/cpu/SortingKernel.cpp"
  "../aten/src/ATen/native/cpu/TensorCompareKernel.cpp"
  "../aten/src/ATen/native/cpu/UnaryOpsKernel.cpp"
  "../aten/src/ATen/native/cpu/layer_norm_kernel.cpp"
  "../aten/src/ATen/quantized/CMakeLists.txt"
  "../aten/src/ATen/test/CMakeLists.txt"
  "../aten/src/TH/CMakeLists.txt"
  "../aten/src/TH/THGeneral.h.in"
  "../aten/src/THNN/CMakeLists.txt"
  "CMakeFiles/3.13.4/CMakeASMCompiler.cmake"
  "CMakeFiles/3.13.4/CMakeCCompiler.cmake"
  "CMakeFiles/3.13.4/CMakeCXXCompiler.cmake"
  "CMakeFiles/3.13.4/CMakeSystem.cmake"
  "CMakeFiles/FindMPI/test_mpi.cpp"
  "../c10/CMakeLists.txt"
  "../c10/macros/cmake_macros.h.in"
  "../c10/test/CMakeLists.txt"
  "../caffe2/CMakeLists.txt"
  "../caffe2/contrib/CMakeLists.txt"
  "../caffe2/contrib/aten/CMakeLists.txt"
  "../caffe2/contrib/gloo/CMakeLists.txt"
  "../caffe2/contrib/nccl/CMakeLists.txt"
  "../caffe2/contrib/opencl/CMakeLists.txt"
  "../caffe2/contrib/prof/CMakeLists.txt"
  "../caffe2/contrib/shm_mutex/CMakeLists.txt"
  "../caffe2/core/CMakeLists.txt"
  "../caffe2/core/macros.h.in"
  "../caffe2/core/nomnigraph/CMakeLists.txt"
  "../caffe2/db/CMakeLists.txt"
  "../caffe2/distributed/CMakeLists.txt"
  "../caffe2/ideep/CMakeLists.txt"
  "../caffe2/image/CMakeLists.txt"
  "../caffe2/mobile/CMakeLists.txt"
  "../caffe2/mobile/contrib/CMakeLists.txt"
  "../caffe2/mobile/contrib/ios/CMakeLists.txt"
  "../caffe2/mpi/CMakeLists.txt"
  "../caffe2/observers/CMakeLists.txt"
  "../caffe2/onnx/CMakeLists.txt"
  "../caffe2/onnx/torch_ops/CMakeLists.txt"
  "../caffe2/operators/CMakeLists.txt"
  "../caffe2/operators/quantized/CMakeLists.txt"
  "../caffe2/operators/rnn/CMakeLists.txt"
  "../caffe2/opt/CMakeLists.txt"
  "../caffe2/perfkernels/CMakeLists.txt"
  "../caffe2/predictor/CMakeLists.txt"
  "../caffe2/predictor/emulator/CMakeLists.txt"
  "../caffe2/proto/CMakeLists.txt"
  "../caffe2/python/CMakeLists.txt"
  "../caffe2/quantization/CMakeLists.txt"
  "../caffe2/quantization/server/CMakeLists.txt"
  "../caffe2/queue/CMakeLists.txt"
  "../caffe2/serialize/CMakeLists.txt"
  "../caffe2/sgd/CMakeLists.txt"
  "../caffe2/share/CMakeLists.txt"
  "../caffe2/share/contrib/CMakeLists.txt"
  "../caffe2/share/contrib/depthwise/CMakeLists.txt"
  "../caffe2/share/contrib/nnpack/CMakeLists.txt"
  "../caffe2/transforms/CMakeLists.txt"
  "../caffe2/utils/CMakeLists.txt"
  "../caffe2/video/CMakeLists.txt"
  "../cmake/BuildVariables.cmake"
  "../cmake/Caffe2Config.cmake.in"
  "../cmake/Caffe2ConfigVersion.cmake.in"
  "../cmake/Codegen.cmake"
  "../cmake/Dependencies.cmake"
  "../cmake/External/nnpack.cmake"
  "../cmake/MiscCheck.cmake"
  "../cmake/Modules/FindARM.cmake"
  "../cmake/Modules/FindAVX.cmake"
  "../cmake/Modules/FindBLAS.cmake"
  "../cmake/Modules/FindLAPACK.cmake"
  "../cmake/Modules/FindMAGMA.cmake"
  "../cmake/Modules/FindMKL.cmake"
  "../cmake/Modules/FindMKLDNN.cmake"
  "../cmake/Modules/FindNumPy.cmake"
  "../cmake/Modules/FindNuma.cmake"
  "../cmake/Modules/FindOpenMP.cmake"
  "../cmake/Modules/Findpybind11.cmake"
  "../cmake/ProtoBuf.cmake"
  "../cmake/Summary.cmake"
  "../cmake/TorchConfig.cmake.in"
  "../cmake/TorchConfigVersion.cmake.in"
  "../cmake/Utils.cmake"
  "../cmake/Whitelist.cmake"
  "../cmake/cmake_uninstall.cmake.in"
  "../cmake/public/mkl.cmake"
  "../cmake/public/mkldnn.cmake"
  "../cmake/public/threads.cmake"
  "../cmake/public/utils.cmake"
  "../modules/CMakeLists.txt"
  "../modules/detectron/CMakeLists.txt"
  "../modules/module_test/CMakeLists.txt"
  "../modules/observers/CMakeLists.txt"
  "../modules/rocksdb/CMakeLists.txt"
  "../test/cpp/api/CMakeLists.txt"
  "../test/cpp/jit/CMakeLists.txt"
  "../third_party/FP16/CMakeLists.txt"
  "../third_party/FXdiv/CMakeLists.txt"
  "../third_party/NNPACK/CMakeLists.txt"
  "../third_party/QNNPACK/CMakeLists.txt"
  "../third_party/QNNPACK/deps/clog/CMakeLists.txt"
  "../third_party/benchmark/CMakeLists.txt"
  "../third_party/benchmark/cmake/AddCXXCompilerFlag.cmake"
  "../third_party/benchmark/cmake/CXXFeatureCheck.cmake"
  "../third_party/benchmark/cmake/Config.cmake.in"
  "../third_party/benchmark/cmake/GetGitVersion.cmake"
  "../third_party/benchmark/cmake/benchmark.pc.in"
  "../third_party/benchmark/cmake/gnu_posix_regex.cpp"
  "../third_party/benchmark/cmake/posix_regex.cpp"
  "../third_party/benchmark/cmake/std_regex.cpp"
  "../third_party/benchmark/cmake/steady_clock.cpp"
  "../third_party/benchmark/src/CMakeLists.txt"
  "../third_party/cpuinfo/CMakeLists.txt"
  "../third_party/fbgemm/CMakeLists.txt"
  "../third_party/fbgemm/third_party/asmjit/CMakeLists.txt"
  "../third_party/foxi/CMakeLists.txt"
  "../third_party/foxi/cmake/summary.cmake"
  "../third_party/gloo/CMakeLists.txt"
  "../third_party/gloo/cmake/Dependencies.cmake"
  "../third_party/gloo/cmake/GlooConfig.cmake.in"
  "../third_party/gloo/cmake/GlooConfigVersion.cmake.in"
  "../third_party/gloo/gloo/CMakeLists.txt"
  "../third_party/gloo/gloo/common/CMakeLists.txt"
  "../third_party/gloo/gloo/config.h.in"
  "../third_party/gloo/gloo/mpi/CMakeLists.txt"
  "../third_party/gloo/gloo/rendezvous/CMakeLists.txt"
  "../third_party/gloo/gloo/transport/CMakeLists.txt"
  "../third_party/gloo/gloo/transport/tcp/CMakeLists.txt"
  "../third_party/googletest/CMakeLists.txt"
  "../third_party/googletest/googlemock/CMakeLists.txt"
  "../third_party/googletest/googletest/CMakeLists.txt"
  "../third_party/googletest/googletest/cmake/internal_utils.cmake"
  "../third_party/ideep/mkl-dnn/CMakeLists.txt"
  "../third_party/ideep/mkl-dnn/cmake/Doxygen.cmake"
  "../third_party/ideep/mkl-dnn/cmake/MKL.cmake"
  "../third_party/ideep/mkl-dnn/cmake/OpenMP.cmake"
  "../third_party/ideep/mkl-dnn/cmake/SDL.cmake"
  "../third_party/ideep/mkl-dnn/cmake/TBB.cmake"
  "../third_party/ideep/mkl-dnn/cmake/Threading.cmake"
  "../third_party/ideep/mkl-dnn/cmake/config.cmake.in"
  "../third_party/ideep/mkl-dnn/cmake/options.cmake"
  "../third_party/ideep/mkl-dnn/cmake/platform.cmake"
  "../third_party/ideep/mkl-dnn/cmake/profiling.cmake"
  "../third_party/ideep/mkl-dnn/cmake/utils.cmake"
  "../third_party/ideep/mkl-dnn/cmake/version.cmake"
  "../third_party/ideep/mkl-dnn/doc/Doxyfile.in"
  "../third_party/ideep/mkl-dnn/doc/header.html.in"
  "../third_party/ideep/mkl-dnn/examples/CMakeLists.txt"
  "../third_party/ideep/mkl-dnn/include/mkldnn_version.h.in"
  "../third_party/ideep/mkl-dnn/src/CMakeLists.txt"
  "../third_party/ideep/mkl-dnn/tests/CMakeLists.txt"
  "../third_party/onnx/CMakeLists.txt"
  "../third_party/onnx/cmake/ONNXConfig.cmake.in"
  "../third_party/onnx/cmake/ONNXConfigVersion.cmake.in"
  "../third_party/onnx/cmake/Utils.cmake"
  "../third_party/onnx/cmake/summary.cmake"
  "../third_party/protobuf/cmake/CMakeLists.txt"
  "../third_party/protobuf/cmake/install.cmake"
  "../third_party/protobuf/cmake/libprotobuf-lite.cmake"
  "../third_party/protobuf/cmake/libprotobuf.cmake"
  "../third_party/protobuf/cmake/libprotoc.cmake"
  "../third_party/protobuf/cmake/protobuf-config-version.cmake.in"
  "../third_party/protobuf/cmake/protobuf-config.cmake.in"
  "../third_party/protobuf/cmake/protobuf-lite.pc.cmake"
  "../third_party/protobuf/cmake/protobuf-module.cmake.in"
  "../third_party/protobuf/cmake/protobuf-options.cmake"
  "../third_party/protobuf/cmake/protobuf.pc.cmake"
  "../third_party/protobuf/cmake/protoc.cmake"
  "../third_party/psimd/CMakeLists.txt"
  "../third_party/pthreadpool/CMakeLists.txt"
  "../third_party/sleef/CMakeLists.txt"
  "../third_party/sleef/Configure.cmake"
  "../third_party/sleef/sleef-config.h.in"
  "../third_party/sleef/src/CMakeLists.txt"
  "../third_party/sleef/src/common/CMakeLists.txt"
  "../third_party/sleef/src/libm/CMakeLists.txt"
  "../torch/CMakeLists.txt"
  "../torch/_utils_internal.py"
  "../torch/lib/c10d/CMakeLists.txt"
  "../torch/lib/c10d/FileStore.hpp"
  "../torch/lib/c10d/PrefixStore.hpp"
  "../torch/lib/c10d/ProcessGroup.hpp"
  "../torch/lib/c10d/ProcessGroupGloo.hpp"
  "../torch/lib/c10d/ProcessGroupMPI.hpp"
  "../torch/lib/c10d/Store.hpp"
  "../torch/lib/c10d/TCPStore.hpp"
  "../torch/lib/c10d/Types.hpp"
  "../torch/lib/c10d/Utils.hpp"
  "../torch/lib/c10d/test/CMakeLists.txt"
  "../torch/lib/libshm/CMakeLists.txt"
  "/usr/share/cmake-3.13/Modules/BasicConfigVersion-SameMajorVersion.cmake.in"
  "/usr/share/cmake-3.13/Modules/CMakeASMInformation.cmake"
  "/usr/share/cmake-3.13/Modules/CMakeCInformation.cmake"
  "/usr/share/cmake-3.13/Modules/CMakeCXXInformation.cmake"
  "/usr/share/cmake-3.13/Modules/CMakeCheckCompilerFlagCommonPatterns.cmake"
  "/usr/share/cmake-3.13/Modules/CMakeCommonLanguageInclude.cmake"
  "/usr/share/cmake-3.13/Modules/CMakeDependentOption.cmake"
  "/usr/share/cmake-3.13/Modules/CMakeFindFrameworks.cmake"
  "/usr/share/cmake-3.13/Modules/CMakeGenericSystem.cmake"
  "/usr/share/cmake-3.13/Modules/CMakeInitializeConfigs.cmake"
  "/usr/share/cmake-3.13/Modules/CMakeLanguageInformation.cmake"
  "/usr/share/cmake-3.13/Modules/CMakePackageConfigHelpers.cmake"
  "/usr/share/cmake-3.13/Modules/CMakeParseImplicitLinkInfo.cmake"
  "/usr/share/cmake-3.13/Modules/CMakePushCheckState.cmake"
  "/usr/share/cmake-3.13/Modules/CMakeSystemSpecificInformation.cmake"
  "/usr/share/cmake-3.13/Modules/CMakeSystemSpecificInitialize.cmake"
  "/usr/share/cmake-3.13/Modules/CheckCCompilerFlag.cmake"
  "/usr/share/cmake-3.13/Modules/CheckCSourceCompiles.cmake"
  "/usr/share/cmake-3.13/Modules/CheckCSourceRuns.cmake"
  "/usr/share/cmake-3.13/Modules/CheckCXXCompilerFlag.cmake"
  "/usr/share/cmake-3.13/Modules/CheckCXXSourceCompiles.cmake"
  "/usr/share/cmake-3.13/Modules/CheckFortranFunctionExists.cmake"
  "/usr/share/cmake-3.13/Modules/CheckFunctionExists.cmake"
  "/usr/share/cmake-3.13/Modules/CheckIncludeFile.cmake"
  "/usr/share/cmake-3.13/Modules/CheckIncludeFileCXX.cmake"
  "/usr/share/cmake-3.13/Modules/CheckLibraryExists.cmake"
  "/usr/share/cmake-3.13/Modules/CheckSymbolExists.cmake"
  "/usr/share/cmake-3.13/Modules/CheckTypeSize.cmake"
  "/usr/share/cmake-3.13/Modules/Compiler/CMakeCommonCompilerMacros.cmake"
  "/usr/share/cmake-3.13/Modules/Compiler/GNU-ASM.cmake"
  "/usr/share/cmake-3.13/Modules/Compiler/GNU-C.cmake"
  "/usr/share/cmake-3.13/Modules/Compiler/GNU-CXX.cmake"
  "/usr/share/cmake-3.13/Modules/Compiler/GNU.cmake"
  "/usr/share/cmake-3.13/Modules/ExternalProject.cmake"
  "/usr/share/cmake-3.13/Modules/FindDoxygen.cmake"
  "/usr/share/cmake-3.13/Modules/FindGit.cmake"
  "/usr/share/cmake-3.13/Modules/FindMPI.cmake"
  "/usr/share/cmake-3.13/Modules/FindMPI/test_mpi.c"
  "/usr/share/cmake-3.13/Modules/FindOpenMP.cmake"
  "/usr/share/cmake-3.13/Modules/FindPackageHandleStandardArgs.cmake"
  "/usr/share/cmake-3.13/Modules/FindPackageMessage.cmake"
  "/usr/share/cmake-3.13/Modules/FindPythonInterp.cmake"
  "/usr/share/cmake-3.13/Modules/FindPythonLibs.cmake"
  "/usr/share/cmake-3.13/Modules/FindThreads.cmake"
  "/usr/share/cmake-3.13/Modules/GNUInstallDirs.cmake"
  "/usr/share/cmake-3.13/Modules/Platform/Linux-GNU-C.cmake"
  "/usr/share/cmake-3.13/Modules/Platform/Linux-GNU-CXX.cmake"
  "/usr/share/cmake-3.13/Modules/Platform/Linux-GNU.cmake"
  "/usr/share/cmake-3.13/Modules/Platform/Linux.cmake"
  "/usr/share/cmake-3.13/Modules/Platform/UnixPaths.cmake"
  "/usr/share/cmake-3.13/Modules/SelectLibraryConfigurations.cmake"
  "/usr/share/cmake-3.13/Modules/WriteBasicConfigVersionFile.cmake"
  )

# The corresponding makefile is:
set(CMAKE_MAKEFILE_OUTPUTS
  "Makefile"
  "CMakeFiles/cmake.check_cache"
  )

# Byproducts of CMake generate step:
set(CMAKE_MAKEFILE_PRODUCTS
  "CMakeFiles/FindMPI/test_mpi.cpp"
  "CMakeFiles/FindMPI/test_mpi.cpp"
  "cmake_uninstall.cmake"
  "Caffe2ConfigVersion.cmake"
  "Caffe2Config.cmake"
  "CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/protobuf/cmake/CMakeFiles/CMakeDirectoryInformation.cmake"
  "confu-deps/QNNPACK/CMakeFiles/CMakeDirectoryInformation.cmake"
  "confu-deps/clog/CMakeFiles/CMakeDirectoryInformation.cmake"
  "confu-deps/cpuinfo/CMakeFiles/CMakeDirectoryInformation.cmake"
  "confu-deps/pthreadpool/CMakeFiles/CMakeDirectoryInformation.cmake"
  "confu-deps/fxdiv/CMakeFiles/CMakeDirectoryInformation.cmake"
  "confu-deps/psimd/CMakeFiles/CMakeDirectoryInformation.cmake"
  "confu-deps/fp16/CMakeFiles/CMakeDirectoryInformation.cmake"
  "confu-deps/NNPACK/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/googletest/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/googletest/googlemock/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/googletest/googlemock/gtest/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/benchmark/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/benchmark/src/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/fbgemm/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/fbgemm/asmjit/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/gloo/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/gloo/gloo/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/gloo/gloo/common/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/gloo/gloo/mpi/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/gloo/gloo/rendezvous/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/gloo/gloo/transport/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/gloo/gloo/transport/tcp/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/onnx/torch_ops/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/onnx/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/foxi/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/ideep/mkl-dnn/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/ideep/mkl-dnn/src/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/ideep/mkl-dnn/examples/CMakeFiles/CMakeDirectoryInformation.cmake"
  "third_party/ideep/mkl-dnn/tests/CMakeFiles/CMakeDirectoryInformation.cmake"
  "c10/CMakeFiles/CMakeDirectoryInformation.cmake"
  "c10/test/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/aten/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/aten/src/TH/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/aten/src/THNN/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/aten/src/ATen/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/aten/src/ATen/core/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/aten/src/ATen/quantized/CMakeFiles/CMakeDirectoryInformation.cmake"
  "sleef/CMakeFiles/CMakeDirectoryInformation.cmake"
  "sleef/src/CMakeFiles/CMakeDirectoryInformation.cmake"
  "sleef/src/libm/CMakeFiles/CMakeDirectoryInformation.cmake"
  "sleef/src/common/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/aten/src/ATen/test/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/core/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/proto/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/serialize/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/utils/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/perfkernels/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/contrib/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/contrib/aten/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/contrib/gloo/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/contrib/nccl/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/contrib/opencl/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/contrib/prof/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/contrib/shm_mutex/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/predictor/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/predictor/emulator/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/core/nomnigraph/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/db/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/distributed/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/ideep/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/image/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/video/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/mobile/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/mobile/contrib/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/mobile/contrib/ios/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/mpi/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/observers/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/onnx/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/operators/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/operators/rnn/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/quantization/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/quantization/server/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/operators/quantized/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/opt/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/python/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/queue/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/sgd/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/share/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/share/contrib/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/share/contrib/nnpack/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/share/contrib/depthwise/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/transforms/CMakeFiles/CMakeDirectoryInformation.cmake"
  "test_jit/CMakeFiles/CMakeDirectoryInformation.cmake"
  "test_api/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/lib_c10d/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/lib_c10d/test/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/torch/CMakeFiles/CMakeDirectoryInformation.cmake"
  "caffe2/torch/lib/libshm/CMakeFiles/CMakeDirectoryInformation.cmake"
  "modules/CMakeFiles/CMakeDirectoryInformation.cmake"
  "modules/detectron/CMakeFiles/CMakeDirectoryInformation.cmake"
  "modules/module_test/CMakeFiles/CMakeDirectoryInformation.cmake"
  "modules/observers/CMakeFiles/CMakeDirectoryInformation.cmake"
  "modules/rocksdb/CMakeFiles/CMakeDirectoryInformation.cmake"
  )

# Dependency information for all targets:
set(CMAKE_DEPEND_INFO_FILES
  "CMakeFiles/caffe2_uninstall.dir/DependInfo.cmake"
  "third_party/protobuf/cmake/CMakeFiles/libprotobuf-lite.dir/DependInfo.cmake"
  "third_party/protobuf/cmake/CMakeFiles/libprotoc.dir/DependInfo.cmake"
  "third_party/protobuf/cmake/CMakeFiles/protoc.dir/DependInfo.cmake"
  "third_party/protobuf/cmake/CMakeFiles/libprotobuf.dir/DependInfo.cmake"
  "confu-deps/QNNPACK/CMakeFiles/qnnpack.dir/DependInfo.cmake"
  "confu-deps/clog/CMakeFiles/clog.dir/DependInfo.cmake"
  "confu-deps/cpuinfo/CMakeFiles/cpuinfo_internals.dir/DependInfo.cmake"
  "confu-deps/cpuinfo/CMakeFiles/cpuinfo.dir/DependInfo.cmake"
  "confu-deps/pthreadpool/CMakeFiles/pthreadpool.dir/DependInfo.cmake"
  "confu-deps/NNPACK/CMakeFiles/nnpack.dir/DependInfo.cmake"
  "confu-deps/NNPACK/CMakeFiles/nnpack_reference_layers.dir/DependInfo.cmake"
  "third_party/googletest/googlemock/CMakeFiles/gmock_main.dir/DependInfo.cmake"
  "third_party/googletest/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake"
  "third_party/googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/DependInfo.cmake"
  "third_party/googletest/googlemock/gtest/CMakeFiles/gtest.dir/DependInfo.cmake"
  "third_party/benchmark/src/CMakeFiles/benchmark_main.dir/DependInfo.cmake"
  "third_party/benchmark/src/CMakeFiles/benchmark.dir/DependInfo.cmake"
  "third_party/fbgemm/CMakeFiles/fbgemm_avx2.dir/DependInfo.cmake"
  "third_party/fbgemm/CMakeFiles/fbgemm_generic.dir/DependInfo.cmake"
  "third_party/fbgemm/CMakeFiles/fbgemm_avx512.dir/DependInfo.cmake"
  "third_party/fbgemm/CMakeFiles/fbgemm.dir/DependInfo.cmake"
  "third_party/fbgemm/asmjit/CMakeFiles/asmjit.dir/DependInfo.cmake"
  "third_party/gloo/gloo/CMakeFiles/gloo.dir/DependInfo.cmake"
  "third_party/onnx/CMakeFiles/onnx.dir/DependInfo.cmake"
  "third_party/onnx/CMakeFiles/onnxifi_loader.dir/DependInfo.cmake"
  "third_party/onnx/CMakeFiles/gen_onnx_operators_proto.dir/DependInfo.cmake"
  "third_party/onnx/CMakeFiles/gen_onnx_proto.dir/DependInfo.cmake"
  "third_party/onnx/CMakeFiles/onnx_proto.dir/DependInfo.cmake"
  "third_party/onnx/CMakeFiles/onnxifi_wrapper.dir/DependInfo.cmake"
  "third_party/onnx/CMakeFiles/onnxifi_dummy.dir/DependInfo.cmake"
  "third_party/foxi/CMakeFiles/foxi_loader.dir/DependInfo.cmake"
  "third_party/foxi/CMakeFiles/foxi_wrapper.dir/DependInfo.cmake"
  "third_party/foxi/CMakeFiles/foxi_dummy.dir/DependInfo.cmake"
  "third_party/ideep/mkl-dnn/CMakeFiles/doc.dir/DependInfo.cmake"
  "third_party/ideep/mkl-dnn/src/CMakeFiles/mkldnn.dir/DependInfo.cmake"
  "c10/CMakeFiles/c10.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_TypeList_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_TensorTypeId_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_flags_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_LeftRight_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_registry_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_Half_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_Array_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_tempfile_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_StreamGuard_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_TypeTraits_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_Metaprogramming_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_DeviceGuard_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_InlineDeviceGuard_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_InlineStreamGuard_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_bfloat16_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_intrusive_ptr_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_either_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_logging_test.dir/DependInfo.cmake"
  "c10/test/CMakeFiles/c10_typeid_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/python_copy_files.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/pattern_net_transform_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/conv_to_nnpack_transform_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/depthwise3x3_conv_op_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/nnpack_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/mobile_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/device_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/dead_code_elim_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/converter_nomigraph_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/bound_shape_inference_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/graph_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/net_async_tracing_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/kernel_stackbased_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/kernel_functor_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/caffe2_pybind11_state.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/fatal_signal_asan_no_sig_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/List_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/TensorImpl_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/dlconvertor_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/wrapdim_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/common_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/inline_container_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/NeuralNetTest.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/xla_tensor_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/weakref_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/common_subexpression_elimination_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/NamedTensor_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/thread_init_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/kernel_function_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/tensor_interop_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/tensor_iterator_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/native_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/scalar_tensor_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/torch.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/BinaryMatchImplTest.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/net_dag_utils_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/Dimname_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/verify_api_visibility.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/kernel_lambda_legacy_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/context_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/caffe2_protos.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/smart_tensor_printer_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/scalar_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/Dict_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/generate-torch-sources.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/ssa_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/operator_schema_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/boolean_unmask_ops_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/extension_backend_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/half_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/apply_utils_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/kernel_function_legacy_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/atest.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/int8_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/math_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/cpu_generator_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/batch_matmul_op_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/undefined_tensor_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/test_parallel.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/basic.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/event_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/int8_roi_align_op_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/init_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/transform_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/module_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/net_simple_refcount_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/TarjansImplTest.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/ATEN_CUDA_FILES_GEN_TARGET.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/net_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/GraphTest.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/elementwise_op_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/observer_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/mpi_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/operator_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/parallel_net_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/stats_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/timer_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/TopoSortTest.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/workspace_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/generate_proposals_op_util_boxes_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/fixed_divisor_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/op_registration_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/simple_queue_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/text_file_reader_utils_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/proto_utils_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/MatchTest.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/distributed_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/cpuid_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/backend_cutting_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/broadcast_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/predictor_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/kernel_lambda_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/string_ops_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/quantized_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/cast_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/data_filler_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/__aten_op_header_gen.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/AlgorithmsTest.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/SubgraphMatcherTest.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/generate_proposals_op_util_nms_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/ATEN_CPU_FILES_GEN_TARGET.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/time_observer_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/conv_transpose_op_mobile_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/generate_proposals_op_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/half_float_ops_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/blob_test.dir/DependInfo.cmake"
  "caffe2/CMakeFiles/utility_ops_test.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/renamedsp256.h_generated.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/dispavx.c_generated.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/headers.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/sleef.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/mkrename_gnuabi.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/renameSSE4.h_generated.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/sleefavx.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/sleefavx512f.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/dispsse_obj.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/mkrename.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/dispavx_obj.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/sleefsse2.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/renameAVX512F.h_generated.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/renameAVX2.h_generated.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/mkdisp.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/sleeffma4.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/renameAVX2128.h_generated.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/renameFMA4.h_generated.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/mkalias.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/alias_avx512f.h_generated.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/sleefavx2.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/renameSSE2.h_generated.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/sleefavx2128.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/sleefsse4.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/renamedsp128.h_generated.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/renameAVX.h_generated.dir/DependInfo.cmake"
  "sleef/src/libm/CMakeFiles/dispsse.c_generated.dir/DependInfo.cmake"
  "sleef/src/common/CMakeFiles/arraymap.dir/DependInfo.cmake"
  "sleef/src/common/CMakeFiles/common.dir/DependInfo.cmake"
  "caffe2/proto/CMakeFiles/Caffe2_PROTO.dir/DependInfo.cmake"
  "caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx512.dir/DependInfo.cmake"
  "caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx.dir/DependInfo.cmake"
  "caffe2/perfkernels/CMakeFiles/Caffe2_perfkernels_avx2.dir/DependInfo.cmake"
  "caffe2/quantization/server/CMakeFiles/caffe2_dnnlowp_avx2_ops.dir/DependInfo.cmake"
  "test_jit/CMakeFiles/test_jit.dir/DependInfo.cmake"
  "test_api/CMakeFiles/test_api.dir/DependInfo.cmake"
  "caffe2/lib_c10d/CMakeFiles/c10d.dir/DependInfo.cmake"
  "caffe2/lib_c10d/test/CMakeFiles/FileStoreTest.dir/DependInfo.cmake"
  "caffe2/lib_c10d/test/CMakeFiles/TCPStoreTest.dir/DependInfo.cmake"
  "caffe2/lib_c10d/test/CMakeFiles/ProcessGroupGlooTest.dir/DependInfo.cmake"
  "caffe2/lib_c10d/test/CMakeFiles/ProcessGroupMPITest.dir/DependInfo.cmake"
  "caffe2/torch/CMakeFiles/torch_python.dir/DependInfo.cmake"
  "caffe2/torch/CMakeFiles/torch_python_stubs.dir/DependInfo.cmake"
  "caffe2/torch/lib/libshm/CMakeFiles/torch_shm_manager.dir/DependInfo.cmake"
  "caffe2/torch/lib/libshm/CMakeFiles/shm.dir/DependInfo.cmake"
  "modules/detectron/CMakeFiles/caffe2_detectron_ops.dir/DependInfo.cmake"
  "modules/module_test/CMakeFiles/caffe2_module_test_dynamic.dir/DependInfo.cmake"
  "modules/observers/CMakeFiles/caffe2_observers.dir/DependInfo.cmake"
  )
