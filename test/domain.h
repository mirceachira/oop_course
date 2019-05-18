#ifndef DOMAIN
#define DOMAIN
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;


class Document
{
protected:
    string author;
public:

    Document() {}

    Document(string author)
    {
        this->author = author;
    }

    ~Document() {}

    virtual bool
    isAccordingToRequirements() { return true; }

    string
    toString() {
        return this->author;
    }

    string
    getAuthor()
    {
        return this->author;
    }
};

class Manuscript : virtual public Document
{
private:
    int numberOfWords;
    int numberOfPages;
public:

    Manuscript(string author, int numberOfWords, int numberOfPages) : Document(author)
    {
        this->numberOfWords = numberOfWords;
        this->numberOfPages = numberOfPages;
    }

    ~Manuscript() {}

    bool
    isAccordingToRequirements()
    {
        return this->numberOfWords >= 2000 && this->numberOfPages >= 5;
    }

    string
    toString()
    {
        return to_string(this->numberOfWords) + " - " + to_string(this->numberOfPages);
    }
};


class Presentation : public Document
{
private:
    int numberOfSlides;

public:
    string text;

    Presentation(string author, int numberOfSlides, string text) : Document(author)
    {
        this->numberOfSlides = numberOfSlides;
        this->text = text;
    }

    bool
    isAccordingToRequirements()
    {
        return this->text.length() / this->numberOfSlides < 200;
    }

    string
    toString()
    {
        return to_string(this->numberOfSlides) + " - " + this->text;
    }
};

#endif // ifndef DOMAIN
