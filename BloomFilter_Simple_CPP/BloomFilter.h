#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <string>
#include <vector>
#include <cstddef>

class BloomFilter {
private:
    std::vector<bool> bits;
    std::size_t hash1(const std::string& value) const;
    std::size_t hash2(const std::string& value) const;

public:
    explicit BloomFilter(std::size_t size = 16);
    void add(const std::string& id);
    bool mightContain(const std::string& id) const;
    void display() const;
};

#endif
