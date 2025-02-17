# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# compile C with /usr/bin/cc
# compile CXX with /usr/bin/c++
C_FLAGS =  -fopenmp -O3  -fPIC   -DCAFFE2_USE_GLOO -DHAVE_GCC_GET_CPUID -DUSE_AVX -DUSE_AVX2 -DTH_HAVE_THREAD -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -Wno-write-strings -Wno-unknown-pragmas -Wno-missing-braces -Wno-maybe-uninitialized -fvisibility=hidden -DCAFFE2_BUILD_MAIN_LIB -O2 -pthread -DASMJIT_STATIC -std=gnu99

C_DEFINES = -DAT_PARALLEL_OPENMP=1 -DCAFFE2_BUILD_MAIN_LIB -DCPUINFO_SUPPORTED_PLATFORM=1 -DHAVE_MALLOC_USABLE_SIZE=1 -DHAVE_MMAP=1 -DHAVE_SHM_OPEN=1 -DHAVE_SHM_UNLINK=1 -DNNP_CONVOLUTION_ONLY=0 -DNNP_INFERENCE_ONLY=0 -DONNX_ML=1 -DONNX_NAMESPACE=onnx_torch -D_FILE_OFFSET_BITS=64 -D_THP_CORE -Dtorch_EXPORTS

C_INCLUDES = -I/home/fivosts/Repos/pytorch/build/aten/src -I/home/fivosts/Repos/pytorch/aten/src -I/home/fivosts/Repos/pytorch/build -I/home/fivosts/Repos/pytorch -I/home/fivosts/Repos/pytorch/cmake/../third_party/benchmark/include -I/home/fivosts/Repos/pytorch/build/caffe2/contrib/aten -I/home/fivosts/Repos/pytorch/third_party/onnx -I/home/fivosts/Repos/pytorch/build/third_party/onnx -I/home/fivosts/Repos/pytorch/third_party/foxi -I/home/fivosts/Repos/pytorch/build/third_party/foxi -I/home/fivosts/Repos/pytorch/caffe2/../torch/csrc/api -I/home/fivosts/Repos/pytorch/caffe2/../torch/csrc/api/include -I/home/fivosts/Repos/pytorch/caffe2/aten/src/TH -I/home/fivosts/Repos/pytorch/build/caffe2/aten/src/TH -I/home/fivosts/Repos/pytorch/caffe2/../torch/../aten/src -I/home/fivosts/Repos/pytorch/build/caffe2/aten/src -I/home/fivosts/Repos/pytorch/build/caffe2/../aten/src -I/home/fivosts/Repos/pytorch/build/caffe2/../aten/src/ATen -I/home/fivosts/Repos/pytorch/caffe2/../torch/csrc -I/home/fivosts/Repos/pytorch/caffe2/../torch/../third_party/miniz-2.0.8 -I/home/fivosts/Repos/pytorch/aten/src/TH -I/home/fivosts/Repos/pytorch/aten/../third_party/catch/single_include -I/home/fivosts/Repos/pytorch/aten/src/ATen/.. -I/home/fivosts/Repos/pytorch/build/caffe2/aten/src/ATen -I/home/fivosts/Repos/pytorch/third_party/miniz-2.0.8 -I/home/fivosts/Repos/pytorch/caffe2/core/nomnigraph/include -I/home/fivosts/Repos/pytorch/c10/.. -I/home/fivosts/Repos/pytorch/build/third_party/ideep/mkl-dnn/include -I/home/fivosts/Repos/pytorch/third_party/ideep/mkl-dnn/src/../include -I/home/fivosts/Repos/pytorch/third_party/QNNPACK/include -I/home/fivosts/Repos/pytorch/third_party/pthreadpool/include -I/home/fivosts/Repos/pytorch/third_party/NNPACK/include -I/home/fivosts/Repos/pytorch/third_party/cpuinfo/include -I/home/fivosts/Repos/pytorch/third_party/fbgemm/include -I/home/fivosts/Repos/pytorch/third_party/fbgemm -I/home/fivosts/Repos/pytorch/third_party/fbgemm/third_party/asmjit/src -I/home/fivosts/Repos/pytorch/third_party/FP16/include -isystem /home/fivosts/Repos/pytorch/build/third_party/gloo -isystem /home/fivosts/Repos/pytorch/cmake/../third_party/gloo -isystem /home/fivosts/Repos/pytorch/cmake/../third_party/googletest/googlemock/include -isystem /home/fivosts/Repos/pytorch/cmake/../third_party/googletest/googletest/include -isystem /home/fivosts/Repos/pytorch/third_party/protobuf/src -isystem /home/fivosts/Repos/pytorch/third_party/gemmlowp -isystem /home/fivosts/Repos/pytorch/third_party/neon2sse -isystem /home/fivosts/Repos/pytorch/third_party -isystem /home/fivosts/Repos/pytorch/cmake/../third_party/eigen -isystem /usr/include/python3.7m -isystem /usr/lib/python3/dist-packages/numpy/core/include -isystem /home/fivosts/Repos/pytorch/cmake/../third_party/pybind11/include -isystem /usr/lib/x86_64-linux-gnu/openmpi/include/openmpi -isystem /usr/lib/x86_64-linux-gnu/openmpi/include -isystem /home/fivosts/Repos/pytorch/third_party/ideep/mkl-dnn/include -isystem /home/fivosts/Repos/pytorch/third_party/ideep/include -isystem /home/fivosts/Repos/pytorch/third_party/ideep/mkl-dnn/external/mklml_lnx_2019.0.3.20190220/include -isystem /home/fivosts/Repos/pytorch/build/include 

CXX_FLAGS =  -Wno-deprecated -fvisibility-inlines-hidden -fopenmp -DUSE_FBGEMM -DUSE_QNNPACK -O2 -fPIC -Wno-narrowing -Wall -Wextra -Wno-missing-field-initializers -Wno-type-limits -Wno-array-bounds -Wno-unknown-pragmas -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-result -Wno-strict-overflow -Wno-strict-aliasing -Wno-error=deprecated-declarations -Wno-stringop-overflow -Wno-error=pedantic -Wno-error=redundant-decls -Wno-error=old-style-cast -fdiagnostics-color=always -faligned-new -Wno-unused-but-set-variable -Wno-maybe-uninitialized -fno-math-errno -fno-trapping-math -Wno-stringop-overflow -DHAVE_AVX_CPU_DEFINITION -DHAVE_AVX2_CPU_DEFINITION -O3  -fPIC   -DCAFFE2_USE_GLOO -DHAVE_GCC_GET_CPUID -DUSE_AVX -DUSE_AVX2 -DTH_HAVE_THREAD -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -Wno-write-strings -Wno-unknown-pragmas -Wno-missing-braces -Wno-maybe-uninitialized -fvisibility=hidden -DCAFFE2_BUILD_MAIN_LIB -O2 -pthread -DASMJIT_STATIC -std=gnu++11

CXX_DEFINES = -DAT_PARALLEL_OPENMP=1 -DCAFFE2_BUILD_MAIN_LIB -DCPUINFO_SUPPORTED_PLATFORM=1 -DHAVE_MALLOC_USABLE_SIZE=1 -DHAVE_MMAP=1 -DHAVE_SHM_OPEN=1 -DHAVE_SHM_UNLINK=1 -DNNP_CONVOLUTION_ONLY=0 -DNNP_INFERENCE_ONLY=0 -DONNX_ML=1 -DONNX_NAMESPACE=onnx_torch -D_FILE_OFFSET_BITS=64 -D_THP_CORE -Dtorch_EXPORTS

CXX_INCLUDES = -I/home/fivosts/Repos/pytorch/build/aten/src -I/home/fivosts/Repos/pytorch/aten/src -I/home/fivosts/Repos/pytorch/build -I/home/fivosts/Repos/pytorch -I/home/fivosts/Repos/pytorch/cmake/../third_party/benchmark/include -I/home/fivosts/Repos/pytorch/build/caffe2/contrib/aten -I/home/fivosts/Repos/pytorch/third_party/onnx -I/home/fivosts/Repos/pytorch/build/third_party/onnx -I/home/fivosts/Repos/pytorch/third_party/foxi -I/home/fivosts/Repos/pytorch/build/third_party/foxi -I/home/fivosts/Repos/pytorch/caffe2/../torch/csrc/api -I/home/fivosts/Repos/pytorch/caffe2/../torch/csrc/api/include -I/home/fivosts/Repos/pytorch/caffe2/aten/src/TH -I/home/fivosts/Repos/pytorch/build/caffe2/aten/src/TH -I/home/fivosts/Repos/pytorch/caffe2/../torch/../aten/src -I/home/fivosts/Repos/pytorch/build/caffe2/aten/src -I/home/fivosts/Repos/pytorch/build/caffe2/../aten/src -I/home/fivosts/Repos/pytorch/build/caffe2/../aten/src/ATen -I/home/fivosts/Repos/pytorch/caffe2/../torch/csrc -I/home/fivosts/Repos/pytorch/caffe2/../torch/../third_party/miniz-2.0.8 -I/home/fivosts/Repos/pytorch/aten/src/TH -I/home/fivosts/Repos/pytorch/aten/../third_party/catch/single_include -I/home/fivosts/Repos/pytorch/aten/src/ATen/.. -I/home/fivosts/Repos/pytorch/build/caffe2/aten/src/ATen -I/home/fivosts/Repos/pytorch/third_party/miniz-2.0.8 -I/home/fivosts/Repos/pytorch/caffe2/core/nomnigraph/include -I/home/fivosts/Repos/pytorch/c10/.. -I/home/fivosts/Repos/pytorch/build/third_party/ideep/mkl-dnn/include -I/home/fivosts/Repos/pytorch/third_party/ideep/mkl-dnn/src/../include -I/home/fivosts/Repos/pytorch/third_party/QNNPACK/include -I/home/fivosts/Repos/pytorch/third_party/pthreadpool/include -I/home/fivosts/Repos/pytorch/third_party/NNPACK/include -I/home/fivosts/Repos/pytorch/third_party/cpuinfo/include -I/home/fivosts/Repos/pytorch/third_party/fbgemm/include -I/home/fivosts/Repos/pytorch/third_party/fbgemm -I/home/fivosts/Repos/pytorch/third_party/fbgemm/third_party/asmjit/src -I/home/fivosts/Repos/pytorch/third_party/FP16/include -isystem /home/fivosts/Repos/pytorch/build/third_party/gloo -isystem /home/fivosts/Repos/pytorch/cmake/../third_party/gloo -isystem /home/fivosts/Repos/pytorch/cmake/../third_party/googletest/googlemock/include -isystem /home/fivosts/Repos/pytorch/cmake/../third_party/googletest/googletest/include -isystem /home/fivosts/Repos/pytorch/third_party/protobuf/src -isystem /home/fivosts/Repos/pytorch/third_party/gemmlowp -isystem /home/fivosts/Repos/pytorch/third_party/neon2sse -isystem /home/fivosts/Repos/pytorch/third_party -isystem /home/fivosts/Repos/pytorch/cmake/../third_party/eigen -isystem /usr/include/python3.7m -isystem /usr/lib/python3/dist-packages/numpy/core/include -isystem /home/fivosts/Repos/pytorch/cmake/../third_party/pybind11/include -isystem /usr/lib/x86_64-linux-gnu/openmpi/include/openmpi -isystem /usr/lib/x86_64-linux-gnu/openmpi/include -isystem /home/fivosts/Repos/pytorch/third_party/ideep/mkl-dnn/include -isystem /home/fivosts/Repos/pytorch/third_party/ideep/include -isystem /home/fivosts/Repos/pytorch/third_party/ideep/mkl-dnn/external/mklml_lnx_2019.0.3.20190220/include -isystem /home/fivosts/Repos/pytorch/build/include 

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/TH/THAllocator.cpp.o_FLAGS = -fno-openmp

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/TH/vector/AVX.cpp.o_FLAGS = -O3  -mavx

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/TH/vector/AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/layer_norm_kernel.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/UnaryOpsKernel.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/TensorCompareKernel.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/SortingKernel.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/SoftMaxKernel.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/ReduceOpsKernel.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/PointwiseOpsKernel.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/LerpKernel.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/IndexKernel.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/GridSamplerKernel.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/FillKernel.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/DistanceOpsKernel.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/CrossKernel.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/CopyKernel.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/BinaryOpsKernel.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/Activation.cpp.AVX2.cpp.o_FLAGS = -O3  -mavx2 -mfma -mno-avx256-split-unaligned-load -mno-avx256-split-unaligned-store -DCPU_CAPABILITY=AVX2 -DCPU_CAPABILITY_AVX2

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/layer_norm_kernel.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/UnaryOpsKernel.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/TensorCompareKernel.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/SortingKernel.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/SoftMaxKernel.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/ReduceOpsKernel.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/PointwiseOpsKernel.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/LerpKernel.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/IndexKernel.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/GridSamplerKernel.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/FillKernel.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/DistanceOpsKernel.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/CrossKernel.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/CopyKernel.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/BinaryOpsKernel.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/Activation.cpp.AVX.cpp.o_FLAGS = -O3  -mavx -DCPU_CAPABILITY=AVX -DCPU_CAPABILITY_AVX

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/layer_norm_kernel.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/UnaryOpsKernel.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/TensorCompareKernel.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/SortingKernel.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/SoftMaxKernel.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/ReduceOpsKernel.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/PointwiseOpsKernel.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/LerpKernel.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/IndexKernel.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/GridSamplerKernel.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/FillKernel.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/DistanceOpsKernel.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/CrossKernel.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/CopyKernel.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/BinaryOpsKernel.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

# Custom flags: caffe2/CMakeFiles/torch.dir/__/aten/src/ATen/native/cpu/Activation.cpp.DEFAULT.cpp.o_FLAGS = -O3  -DCPU_CAPABILITY=DEFAULT -DCPU_CAPABILITY_DEFAULT

