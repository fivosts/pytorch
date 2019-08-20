file(REMOVE_RECURSE
  "../lib/libcaffe2_protos.pdb"
  "../lib/libcaffe2_protos.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/caffe2_protos.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
