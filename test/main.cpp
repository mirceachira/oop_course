#include <iostream>
#include <string>

#include "domain.h"
#include "controller.h"

using namespace std;

int
main()
{
    Controller myController{};

    Manuscript myManuscriptA{ "author 1", 1, 2 };
    Manuscript myManuscriptB{ "author 2", 10000, 20000 };
    Presentation myPresentationA{ "author 3", 100, "Some text" };
    Presentation myPresentationB{ "author 4", 100, "Some text asdasdasdasdasdasd" };

    myController.addDocument(myManuscriptA);
    myController.addDocument(myManuscriptB);
    myController.addDocument(myPresentationA);
    myController.addDocument(myPresentationB);



    int w;

    cout << "What do you want to add? 1 - presentation, 0 - manuscript";
        cin >> w;
    if (w) {
        string author2, text;
        int numberOfSlides;

        cout << "Enter Presentation author: ";
        cin >> author2;

        cout << "Enter Presentation number slides: ";
        cin >> numberOfSlides;

        cout << "Enter Presentation text: ";
        cin >> text;

        Presentation myPresentation{ author2, numberOfSlides, text };
        myController.addDocument(myPresentation);

    } else {
        string author;
        int words, pages;

        cout << "Enter manuscript author: ";
        cin >> author;

        cout << "Enter manuscript number of words: ";
        cin >> words;

        cout << "Enter manuscript number of pages: ";
        cin >> pages;

        Manuscript myManuscript{ author, words, pages };
        myController.addDocument(myManuscript);
    }

    cout << "Displaying all docs";
    for (auto i: myController.getAllDocuments()) {
        cout << "\n" << i.toString();
    }

    cout << "Displaying all docs that fit requirements";
    for (auto i: myController.getAllDocumentsAccordingToRequirements()) {
        cout << "\n" << i.toString();
    }
    // cout << myManuscript.toString();

    return 0;
} // main
