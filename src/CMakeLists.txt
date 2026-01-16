# Библиотека с логикой фильтрации
add_library(ip_filter_lib
    ip_address.cpp
    ip_filter.cpp
)

target_include_directories(ip_filter_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Исполняемый файл
add_executable(ip_filter main.cpp)

target_link_libraries(ip_filter PRIVATE ip_filter_lib)

# Установка (для CPack)
install(TARGETS ip_filter RUNTIME DESTINATION bin)