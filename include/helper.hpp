#ifndef HELPER_HPP_
#define HELPER_HPP_

#include <string>

namespace CBake
{

    class Helper
    {

    public: // Constructors
        Helper();
        ~Helper();

    public: // Static Methods
        static bool doesFileExist(std::string fileName);
        
    };

} 


#endif