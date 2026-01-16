#include "ip_filter.h"
#include <sstream>
#include <algorithm>

IpAddress parse_ip_line(const std::string& line) {
    // Используем auto для типа потока
    std::istringstream iss(line);
    std::string ip_string;
    
    // Берем только первое поле до табуляции
    std::getline(iss, ip_string, '\t');
    
    // Парсим IP вида "n1.n2.n3.n4"
    std::istringstream ip_stream(ip_string);
    int b1, b2, b3, b4;
    char dot;
    
    ip_stream >> b1 >> dot >> b2 >> dot >> b3 >> dot >> b4;
    
    // Возвращаем tuple
    return make_ip(b1, b2, b3, b4);
}

std::vector<IpAddress> read_ip_pool(std::istream& input) {
    // auto для типа вектора
    std::vector<IpAddress> pool;
    std::string line;
    
    while (std::getline(input, line)) {
        if (line.empty()) continue;
        
        // Используем auto для результата парсинга
        auto ip = parse_ip_line(line);
        pool.push_back(ip);
    }
    
    return pool;
}

void sort_ip_pool_reverse(std::vector<IpAddress>& pool) {
    // Используем lambda для обратной сортировки
    std::sort(pool.begin(), pool.end(), 
        [](const auto& left, const auto& right) {
            // Обратная лексикографическая сортировка
            return left > right;
        }
    );
}

std::vector<IpAddress> filter_by_first_byte(
    const std::vector<IpAddress>& pool,
    int first_byte
) {
    std::vector<IpAddress> result;
    
    // Lambda для фильтрации
    auto filter_func = [first_byte](const auto& ip) {
        return std::get<0>(ip) == first_byte;
    };
    
    // Используем std::copy_if с lambda
    std::copy_if(pool.begin(), pool.end(), 
                 std::back_inserter(result), 
                 filter_func);
    
    return result;
}

std::vector<IpAddress> filter_by_two_bytes(
    const std::vector<IpAddress>& pool,
    int first_byte,
    int second_byte
) {
    std::vector<IpAddress> result;
    
    // Lambda с захватом двух переменных
    std::copy_if(pool.begin(), pool.end(),
                 std::back_inserter(result),
                 [first_byte, second_byte](const auto& ip) {
                     return std::get<0>(ip) == first_byte && 
                            std::get<1>(ip) == second_byte;
                 });
    
    return result;
}

std::vector<IpAddress> filter_by_any_byte(
    const std::vector<IpAddress>& pool,
    int byte_value
) {
    std::vector<IpAddress> result;
    
    // Lambda проверяет все 4 байта
    std::copy_if(pool.begin(), pool.end(),
                 std::back_inserter(result),
                 [byte_value](const auto& ip) {
                     return std::get<0>(ip) == byte_value ||
                            std::get<1>(ip) == byte_value ||
                            std::get<2>(ip) == byte_value ||
                            std::get<3>(ip) == byte_value;
                 });
    
    return result;
}

void print_ip_pool(const std::vector<IpAddress>& pool) {
    // Используем auto в range-based for
    for (const auto& ip : pool) {
        print_ip(ip);
    }
}