#pragma once
#include <tuple>
#include <iostream>

// Используем tuple для хранения IP-адреса (4 байта)
using IpAddress = std::tuple<int, int, int, int>;

// Функция для создания IP из 4 чисел
IpAddress make_ip(int b1, int b2, int b3, int b4);

// Функция для вывода IP-адреса
void print_ip(const IpAddress& ip);

// Перегрузка оператора < для сортировки
bool operator<(const IpAddress& left, const IpAddress& right);

// Перегрузка оператора > для обратной сортировки
bool operator>(const IpAddress& left, const IpAddress& right);