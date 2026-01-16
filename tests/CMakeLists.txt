# Скачиваем Google Test автоматически
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
# Для Windows: предотвращаем перезапись флагов компилятора родителя
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Создаем исполняемый файл тестов
add_executable(test_ip_filter test_ip_filter.cpp)

# Линкуем с библиотекой и Google Test
target_link_libraries(test_ip_filter 
    PRIVATE 
    ip_filter_lib
    gtest_main
)

target_include_directories(test_ip_filter PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)