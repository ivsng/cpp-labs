# CMake generated Testfile for 
# Source directory: C:/Users/Kris/Desktop/Study/TPU/3sem/programming/cpp-labs
# Build directory: C:/Users/Kris/Desktop/Study/TPU/3sem/programming/cpp-labs/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_ip_filter "C:/Users/Kris/Desktop/Study/TPU/3sem/programming/cpp-labs/build/tests/test_ip_filter.exe")
set_tests_properties(test_ip_filter PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Kris/Desktop/Study/TPU/3sem/programming/cpp-labs/CMakeLists.txt;19;add_test;C:/Users/Kris/Desktop/Study/TPU/3sem/programming/cpp-labs/CMakeLists.txt;0;")
subdirs("src")
subdirs("tests")
