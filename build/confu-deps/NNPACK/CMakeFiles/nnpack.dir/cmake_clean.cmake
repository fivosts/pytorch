file(REMOVE_RECURSE
  "src/x86_64-fma/2d-fourier-8x8.py.o"
  "src/x86_64-fma/2d-fourier-16x16.py.o"
  "src/x86_64-fma/2d-winograd-8x8-3x3.py.o"
  "src/x86_64-fma/blas/s8gemm.py.o"
  "src/x86_64-fma/blas/c8gemm.py.o"
  "src/x86_64-fma/blas/s4c6gemm.py.o"
  "src/x86_64-fma/blas/conv1x1.py.o"
  "src/x86_64-fma/blas/sgemm.py.o"
  "src/x86_64-fma/max-pooling.py.o"
  "src/x86_64-fma/relu.py.o"
  "src/x86_64-fma/softmax.py.o"
  "src/x86_64-fma/blas/sdotxf.py.o"
  "src/x86_64-fma/blas/shdotxf.py.o"
  "CMakeFiles/nnpack.dir/src/init.c.o"
  "CMakeFiles/nnpack.dir/src/convolution-inference.c.o"
  "CMakeFiles/nnpack.dir/src/fully-connected-inference.c.o"
  "CMakeFiles/nnpack.dir/src/pooling-output.c.o"
  "CMakeFiles/nnpack.dir/src/relu-output.c.o"
  "CMakeFiles/nnpack.dir/src/softmax-output.c.o"
  "CMakeFiles/nnpack.dir/src/fully-connected-output.c.o"
  "CMakeFiles/nnpack.dir/src/relu-input-gradient.c.o"
  "CMakeFiles/nnpack.dir/src/convolution-input-gradient.c.o"
  "CMakeFiles/nnpack.dir/src/convolution-kernel-gradient.c.o"
  "CMakeFiles/nnpack.dir/src/convolution-output.c.o"
  "CMakeFiles/nnpack.dir/src/x86_64-fma/softmax.c.o"
  "../../lib/libnnpack.pdb"
  "../../lib/libnnpack.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/nnpack.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
