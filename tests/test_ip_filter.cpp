#include <gtest/gtest.h>
#include "ip_filter.h"
#include <sstream>

// ТЕСТ 1: Парсинг IP-адресов
TEST(IpFilterTest, ParseIpLine) {
    std::string line = "192.168.1.1\t100\t200";
    
    auto ip = parse_ip_line(line);
    
    EXPECT_EQ(std::get<0>(ip), 192);
    EXPECT_EQ(std::get<1>(ip), 168);
    EXPECT_EQ(std::get<2>(ip), 1);
    EXPECT_EQ(std::get<3>(ip), 1);
}

// ТЕСТ 2: Обратная лексикографическая сортировка
TEST(IpFilterTest, ReverseSorting) {
    std::vector<IpAddress> pool;
    pool.push_back(make_ip(1, 1, 1, 1));
    pool.push_back(make_ip(1, 10, 1, 1));
    pool.push_back(make_ip(1, 2, 1, 1));
    
    sort_ip_pool_reverse(pool);
    
    // После обратной сортировки: 1.10.1.1, 1.2.1.1, 1.1.1.1
    EXPECT_EQ(std::get<1>(pool[0]), 10);
    EXPECT_EQ(std::get<1>(pool[1]), 2);
    EXPECT_EQ(std::get<1>(pool[2]), 1);
}

// ТЕСТ 3: Фильтр по первому байту
TEST(IpFilterTest, FilterByFirstByte) {
    std::vector<IpAddress> pool;
    pool.push_back(make_ip(1, 2, 3, 4));
    pool.push_back(make_ip(2, 3, 4, 5));
    pool.push_back(make_ip(1, 10, 20, 30));
    
    auto filtered = filter_by_first_byte(pool, 1);
    
    EXPECT_EQ(filtered.size(), 2);
    EXPECT_EQ(std::get<0>(filtered[0]), 1);
    EXPECT_EQ(std::get<0>(filtered[1]), 1);
}

// ТЕСТ 4: Фильтр по двум байтам
TEST(IpFilterTest, FilterByTwoBytes) {
    std::vector<IpAddress> pool;
    pool.push_back(make_ip(46, 70, 1, 1));
    pool.push_back(make_ip(46, 80, 2, 2));
    pool.push_back(make_ip(46, 70, 3, 3));
    
    auto filtered = filter_by_two_bytes(pool, 46, 70);
    
    EXPECT_EQ(filtered.size(), 2);
    EXPECT_EQ(std::get<0>(filtered[0]), 46);
    EXPECT_EQ(std::get<1>(filtered[0]), 70);
}

// ТЕСТ 5: Фильтр по любому байту
TEST(IpFilterTest, FilterByAnyByte) {
    std::vector<IpAddress> pool;
    pool.push_back(make_ip(46, 1, 2, 3));   // 46 в первом
    pool.push_back(make_ip(1, 46, 2, 3));   // 46 во втором
    pool.push_back(make_ip(1, 2, 46, 3));   // 46 в третьем
    pool.push_back(make_ip(1, 2, 3, 46));   // 46 в четвертом
    pool.push_back(make_ip(1, 2, 3, 4));    // нет 46
    
    auto filtered = filter_by_any_byte(pool, 46);
    
    EXPECT_EQ(filtered.size(), 4);
}

// ТЕСТ 6: Чтение из потока
TEST(IpFilterTest, ReadIpPool) {
    std::string input_data = 
        "192.168.1.1\t100\t200\n"
        "10.0.0.1\t50\t60\n";
    
    std::istringstream input_stream(input_data);
    auto pool = read_ip_pool(input_stream);
    
    EXPECT_EQ(pool.size(), 2);
    EXPECT_EQ(std::get<0>(pool[0]), 192);
    EXPECT_EQ(std::get<0>(pool[1]), 10);
}