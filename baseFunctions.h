#ifndef BASEFUNCTIONS_H
#define BASEFUNCTIONS_H
#include <string>
class baseFunctions
{
    public:
        baseFunctions();
        void prompt();
        void cls();
        int input(std::string iPrompt, int i);
        bool fileExists(const char *fileName);
    protected:
    private:
};

#endif