#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>

#include "domain.h"
#include "utils.h"


std::string const
& TextFileHandler::operator [] (std::size_t index) const
{
    return m_data[index];
}

std::size_t
TextFileHandler::size() const
{
    return m_data.size();
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
CsvHandler::writeToFile(std::vector<Dog> dogVector)
{
    ofstream myfile;

    myfile.open("result.csv", std::ios_base::out);

    for (auto d: dogVector) {
        myfile << d.getBreed() << ',' << d.getName() << ',' << d.getAge() << ',' << d.getPhoto() << '\n';
    }

    myfile.close();
}

void
HtmlHandler::writeToFile(std::vector<Dog> dogVector)
{
    string htmlStart = "<!DOCTYPE html><html><head><style>table {font-family: arial, sans-serif;border-collapse: collapse;width: 100%;}td, th {border: 1px solid #dddddd;text-align: left;padding: 8px;}tr:nth-child(even) {background-color: #dddddd;}</style></head><body><h2>Pets available</h2><table><tr><th>Bree</th><th>Name</th><th>Age</th><th>Photo</th></tr>";
    string htmlEnd = "</table></body></html>";
    ofstream myfile;

    myfile.open("result.html", std::ios_base::out);

    myfile << htmlStart;

    for (auto d: dogVector) {
        myfile << "<tr>";
        myfile << "<td>" << d.getBreed() << "</td>";
        myfile << "<td>" << d.getName() << "</td>";
        myfile << "<td>" << d.getAge() << "</td>";
        myfile << "<td>" << d.getPhoto() << "</td>";
        myfile << "</tr>";
    }

    myfile << htmlEnd;

    myfile.close();
}
