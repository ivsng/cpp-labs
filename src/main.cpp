#include "ip_filter.h"
#include <iostream>

int main() {
    try {
        // Читаем IP-адреса из stdin
        auto ip_pool = read_ip_pool(std::cin);
        
        // Сортируем в обратном лексикографическом порядке
        sort_ip_pool_reverse(ip_pool);
        
        // 1. Печатаем весь отсортированный список
        print_ip_pool(ip_pool);
        
        // 2. Печатаем IP с первым байтом = 1
        auto filtered_1 = filter_by_first_byte(ip_pool, 1);
        print_ip_pool(filtered_1);
        
        // 3. Печатаем IP с первым байтом = 46 и вторым = 70
        auto filtered_46_70 = filter_by_two_bytes(ip_pool, 46, 70);
        print_ip_pool(filtered_46_70);
        
        // 4. Печатаем IP, где любой байт = 46
        auto filtered_any_46 = filter_by_any_byte(ip_pool, 46);
        print_ip_pool(filtered_any_46);
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}