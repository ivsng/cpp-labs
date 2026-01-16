#include "ip_address.h"

IpAddress make_ip(int b1, int b2, int b3, int b4) {
    return std::make_tuple(b1, b2, b3, b4);
}

void print_ip(const IpAddress& ip) {
    std::cout << std::get<0>(ip) << "."
              << std::get<1>(ip) << "."
              << std::get<2>(ip) << "."
              << std::get<3>(ip) << std::endl;
}

// ИСПРАВЛЕНО: правильное сравнение для обратной сортировки
bool operator<(const IpAddress& left, const IpAddress& right) {
    // Сравниваем по каждому байту
    if (std::get<0>(left) != std::get<0>(right))
        return std::get<0>(left) < std::get<0>(right);
    if (std::get<1>(left) != std::get<1>(right))
        return std::get<1>(left) < std::get<1>(right);
    if (std::get<2>(left) != std::get<2>(right))
        return std::get<2>(left) < std::get<2>(right);
    return std::get<3>(left) < std::get<3>(right);
}

bool operator>(const IpAddress& left, const IpAddress& right) {
    // Обратное сравнение
    if (std::get<0>(left) != std::get<0>(right))
        return std::get<0>(left) > std::get<0>(right);
    if (std::get<1>(left) != std::get<1>(right))
        return std::get<1>(left) > std::get<1>(right);
    if (std::get<2>(left) != std::get<2>(right))
        return std::get<2>(left) > std::get<2>(right);
    return std::get<3>(left) > std::get<3>(right);
}