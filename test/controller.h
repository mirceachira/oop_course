#ifndef CONTROLLER
#define CONTROLLER

#include <vector>
#include <fstream>

#include "domain.h"

using namespace std;

class Controller
{
private:
    std::vector<Document> docs;

public:
    void
    addDocument(Document d)
    {
        this->docs.push_back(d);
    }

    std::vector<Document>
    getAllDocuments() {
        return this->docs;
    }

    std::vector<Document>
    getAllDocumentsAccordingToRequirements(){
        std::vector<Document> res;

        for (auto i: this->docs) {
            if (i.isAccordingToRequirements())
                res.push_back(i);
        }

        return res;
    }

    void
    writeToFile(string filename){
    // {
    //     ofstream myfile;

    // myfile.open(filename, std::ios_base::out);

    // for (auto d: this->docs) {
    //     myfile << d.toString() << '\n';
    // }

    // myfile.close();

    }
};


#endif // ifndef CONTROLLER
