g++ -o motus.out src/main.cpp src/motus.cpp src/algo.cpp -I./include/ -std=c++2a
./motus.out dictionary/dictionary.txt
rm motus.out
