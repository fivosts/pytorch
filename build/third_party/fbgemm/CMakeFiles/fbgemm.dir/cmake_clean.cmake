file(REMOVE_RECURSE
  "../../lib/libfbgemm.pdb"
  "../../lib/libfbgemm.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/fbgemm.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
