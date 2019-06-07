#include <vector>
#include <fstream>
#include <iostream>

#include "domain.h"
#include "utils.h"

std::istream&
operator >> (std::istream& str, TextFileHandler& data)
{
    data.readNextRow(str);
    return str;
}

int
main(void)
{
    std::vector<Item> v;

    std::ifstream file("/home/mirceachira/Desktop/oop_course/test2/test2");

    TextFileHandler row;

    while (file >> row) {
        v.push_back(Item{ row[0], row[1], std::stoi(row[2]) });
    
    }

    cout << v[0].name;
    return 0;
}
