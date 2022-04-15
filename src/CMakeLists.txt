aux_source_directory(. sub_dir)

add_library(lib ${sub_dir})

target_include_directories(lib PUBLIC ${CMAKE_SOURCE_DIR}/include)