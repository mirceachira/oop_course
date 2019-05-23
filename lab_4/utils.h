#ifndef UTILS
#define UTILS

#include <fstream>
#include <vector>

#include "domain.h"


class TextFileHandler
{
public:
    std::string const&
    operator [] (std::size_t index) const;
    std::size_t
    size() const;
    void
    readNextRow(std::istream& str);
    virtual void
    writeToFile(std::vector<Dog> dogVector)=0;
private:
    std::vector<std::string> m_data;
};

class CsvHandler : public TextFileHandler
{
public:
    void
    writeToFile(std::vector<Dog> dogVector);
};

class HtmlHandler : public TextFileHandler
{
public:
    void
    writeToFile(std::vector<Dog> dogVector);
};

#endif // ifndef UTILS
