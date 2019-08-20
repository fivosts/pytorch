file(REMOVE_RECURSE
  "dispsse.c"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/dispsse.c_generated.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
