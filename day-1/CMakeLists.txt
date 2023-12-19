add_executable(day_1_part_1 ./part_1.cpp)
target_compile_features(day_1_part_1 PUBLIC cxx_std_17)
target_link_libraries(day_1_part_1 -static-libgcc -static-libstdc++ common)
target_include_directories(day_1_part_1 PUBLIC ../common)

add_executable(day_1_part_2 ./part_2.cpp)
target_compile_features(day_1_part_2 PUBLIC cxx_std_17)
target_link_libraries(day_1_part_2 -static-libgcc -static-libstdc++ common)
target_include_directories(day_1_part_2 PUBLIC ../common)
