add_executable(day_1 ./main.cpp)
target_compile_features(day_1 PUBLIC cxx_std_17)
target_link_libraries(day_1 -static-libgcc -static-libstdc++ common)
target_include_directories(day_1 PUBLIC ../common)
