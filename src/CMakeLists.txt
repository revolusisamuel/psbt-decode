add_library(wallet STATIC wallet.cpp)
target_include_directories(wallet PUBLIC ${CMAKE_SOURCE_DIR}/include)
add_executable(psbt-decode main.cpp)
target_link_libraries(psbt-decode PRIVATE wallet)
