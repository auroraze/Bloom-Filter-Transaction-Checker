#include "BloomFilter.h"
#include <iostream>
#include <functional>

BloomFilter::BloomFilter(std::size_t size) : bits(size == 0 ? 16 : size, false) {}

std::size_t BloomFilter::hash1(const std::string& value) const {
    return std::hash<std::string>{}(value) % bits.size();
}

std::size_t BloomFilter::hash2(const std::string& value) const {
    // A second simple hash-like calculation 
    std::size_t result = 5381;
    for (unsigned char ch : value) {
        result = ((result << 5) + result) + ch;
    }
    return result % bits.size();
}

void BloomFilter::add(const std::string& id) {
    bits[hash1(id)] = true;
    bits[hash2(id)] = true;
}

bool BloomFilter::mightContain(const std::string& id) const {
    return bits[hash1(id)] && bits[hash2(id)];
}

void BloomFilter::display() const {
    std::cout << "\nBloom Filter bit array (0 = off, 1 = on):\n";
    for (bool bit : bits) {
        std::cout << (bit ? '1' : '0') << ' ';
    }
    std::cout << "\n\n";
}
