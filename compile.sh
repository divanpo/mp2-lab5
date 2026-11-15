g++ -Wall -Iinclude -g samples/main.cpp -o build/prog
g++ -Wall -Iinclude -Igtest -g test/test_forwardlist.cpp gtest/gtest-all.cc -o build/test_forwardlist
