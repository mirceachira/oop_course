#ifndef UTILS
#define UTILS

#include <fstream>
#include <vector>

#include "domain.h"


class CsvHandler
{
public:
    std::string const&
    operator [] (std::size_t index) const;
    std::size_t
    size() const;
    void
    readNextRow(std::istream& str);
    void
    writeToFile(std::vector<Dog> dogVector);
    void
    writeToHTML(std::vector<Dog> dogVector);
private:
    std::vector<std::string> m_data;
};

#endif // ifndef UTILS
