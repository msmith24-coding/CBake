#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>

class Token
{
    private:
        std::string type;
        std::string value;
    public:
        /* Contructors */
        Token();
        Token(std::string type);
        Token(std::string type, std::string value);

        /* Functions */
        std::string asString();

        /* Getters */
        std::string getType();
        std::string getValue();

        /* Destructors */
        ~Token();
};

#endif