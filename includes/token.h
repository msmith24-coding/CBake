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
        Token(std::string type_);
        Token(std::string type_, std::string value_);

        /* Functions */
        std::string asString();

        /* Getters */
        std::string getType();
        std::string getValue();

        /* Destructors */
        ~Token();
};

#endif