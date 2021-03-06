#ifndef UTILS
#define UTILS

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

#include "domain.h"

using namespace std;

class TextFileHandler
{
public:
    std::string const&
    operator [] (std::size_t index) const;

    std::size_t
    size() const;

    void
    readNextRow(std::istream& str);

    void
    writeToFile(std::vector<Item> itemVector);
private:
    std::vector<std::string> m_data;
};

std::string const
& TextFileHandler::operator [] (std::size_t index) const
{
    return m_data[index];
}

void
TextFileHandler::readNextRow(std::istream& str)
{
    std::string line;

    std::getline(str, line);

    std::stringstream lineStream(line);
    std::string cell;

    m_data.clear();
    while (std::getline(lineStream, cell, ',')) {
        m_data.push_back(cell);
    }

    if (!lineStream && cell.empty()) {
        m_data.push_back("");
    }
}

void
TextFileHandler::writeToFile(std::vector<Item> itemVector)
{
    ofstream myfile;

    myfile.open("result.csv", std::ios_base::out);

    // for (auto d: itemVector) {
    //     myfile << d.value << '\n';
    // }

    myfile.close();
}

#endif // ifndef UTILS
