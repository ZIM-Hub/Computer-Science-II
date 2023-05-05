#include "Encyclopedia.h"
#include <iostream>

void Encyclopedia::SetEdition(string userEdition) {
    edition = userEdition;
}

string Encyclopedia::GetEdition() {
    return edition;
}

void Encyclopedia::SetNumVolumes(int userNumVolumes) {
    numVolumes = userNumVolumes;
}

int Encyclopedia::GetNumVolumes() {
    return numVolumes;
}

void Encyclopedia::PrintInfo() {
    cout << "Book Information: " << endl;
    cout << "   Book Title: " << GetTitle() << endl;
    cout << "   Author: " << GetAuthor() << endl;
    cout << "   Publisher: " << GetPublisher() << endl;
    cout << "   Publication Date: " << GetPublicationDate() << endl;
    cout << "   Edition: " << edition << endl;
    cout << "   Number of Volumes: " << numVolumes << endl;
}
