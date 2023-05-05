#ifndef ENCYCLOPEDIAH
#define ENCYCLOPEDIAH

#include "Book.h"

class Encyclopedia : public Book {
public:
    void SetEdition(string userEdition);
    string GetEdition();
    void SetNumVolumes(int userNumVolumes);
    int GetNumVolumes();
    void PrintInfo();

private:
    string edition;
    int numVolumes;
};

#endif
