add_library(common STATIC
    common.cpp
    common.h
)
target_include_directories(common PUBLIC common)