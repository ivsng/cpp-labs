#pragma once
#include "ip_address.h"
#include <vector>
#include <string>

// Чтение IP-адресов из потока (stdin или файл)
std::vector<IpAddress> read_ip_pool(std::istream& input);

// Парсинг одной строки с IP-адресом
IpAddress parse_ip_line(const std::string& line);

// Сортировка в обратном лексикографическом порядке
void sort_ip_pool_reverse(std::vector<IpAddress>& pool);

// Фильтр: первый байт равен заданному значению
std::vector<IpAddress> filter_by_first_byte(
    const std::vector<IpAddress>& pool, 
    int first_byte
);

// Фильтр: первый байт = b1 И второй байт = b2
std::vector<IpAddress> filter_by_two_bytes(
    const std::vector<IpAddress>& pool,
    int first_byte,
    int second_byte
);

// Фильтр: любой байт равен заданному значению
std::vector<IpAddress> filter_by_any_byte(
    const std::vector<IpAddress>& pool,
    int byte_value
);

// Вывод списка IP-адресов
void print_ip_pool(const std::vector<IpAddress>& pool);