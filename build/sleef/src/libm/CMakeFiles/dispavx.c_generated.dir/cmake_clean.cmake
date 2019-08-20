file(REMOVE_RECURSE
  "dispavx.c"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/dispavx.c_generated.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
