add_executable(psbt-decode_tests test_core.cpp)
target_link_libraries(psbt-decode_tests PRIVATE wallet)
target_include_directories(psbt-decode_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME core COMMAND psbt-decode_tests)
