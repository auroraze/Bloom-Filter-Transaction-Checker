FAST TRANSACTION / MEMBER ID CHECKER — SIMPLE BLOOM FILTER DEMO

Files
- BloomFilter.h: class declaration
- BloomFilter.cpp: Bloom Filter implementation
- main.cpp: menu and input validation

Compile (g++ with C++11 or later)
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp BloomFilter.cpp -o bloom_checker

Run on Windows: bloom_checker.exe
Run on Linux/macOS: ./bloom_checker

Suggested test
1. Add TX101.
2. Check TX101: it should say "MIGHT exist".
3. Check an ID not added, such as TX999: it will usually say "DEFINITELY NOT"
   (a Bloom Filter can have false positives).
4. Choose option 3 to view the bit array.
5. Enter 9 at the menu to test invalid menu-choice handling.

Important note
A Bloom Filter is a quick screening structure. "Definitely not" means absent from
the filter; "Might exist" is not proof that the ID is real. A real application would
verify possible matches against its authoritative database. This classroom demo uses
two simple hash calculations and is not intended for security-sensitive or production use.
