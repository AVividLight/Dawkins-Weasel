file(REMOVE_RECURSE
  "liblibpugixml.pdb"
  "liblibpugixml.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/libpugixml.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
