file(REMOVE_RECURSE
  "CMakeFiles/ATEN_CPU_FILES_GEN_TARGET"
  "../aten/src/ATen/CPUType.cpp"
  "../aten/src/ATen/CPUType.h"
  "../aten/src/ATen/Declarations.yaml"
  "../aten/src/ATen/Functions.h"
  "../aten/src/ATen/LegacyTHFunctionsCPU.cpp"
  "../aten/src/ATen/LegacyTHFunctionsCPU.h"
  "../aten/src/ATen/MkldnnCPUType.cpp"
  "../aten/src/ATen/MkldnnCPUType.h"
  "../aten/src/ATen/NativeFunctions.h"
  "../aten/src/ATen/QuantizedCPUType.cpp"
  "../aten/src/ATen/QuantizedCPUType.h"
  "../aten/src/ATen/RegistrationDeclarations.h"
  "../aten/src/ATen/SparseCPUType.cpp"
  "../aten/src/ATen/SparseCPUType.h"
  "../aten/src/ATen/TypeDefault.cpp"
  "../aten/src/ATen/TypeDefault.h"
  "../aten/src/ATen/CUDAType.cpp"
  "../aten/src/ATen/CUDAType.h"
  "../aten/src/ATen/LegacyTHFunctionsCUDA.cpp"
  "../aten/src/ATen/LegacyTHFunctionsCUDA.h"
  "../aten/src/ATen/SparseCUDAType.cpp"
  "../aten/src/ATen/SparseCUDAType.h"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/ATEN_CPU_FILES_GEN_TARGET.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
