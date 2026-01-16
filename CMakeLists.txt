cmake_minimum_required(VERSION 3.12)

# Версионирование как в Lab1
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(ip_filter VERSION ${PROJECT_VERSION})

# Стандарт C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем подпроекты
add_subdirectory(src)
add_subdirectory(tests)

# Включаем тестирование
enable_testing()
add_test(NAME test_ip_filter COMMAND test_ip_filter)

# CPack для создания пакетов
set(CPACK_GENERATOR ZIP)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)