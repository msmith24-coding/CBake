#include "../../includes/parser.h"

// +
// | Builds the command based on the
// | operating system to delete the file or
// | files that are provided in arg0.
// +
std::string Parser::makeDelFunc()
{
    this->advance();
    if(this->currentToken.getType() == TokenType::LPAREN) {
        this->advance();
        std::string arg0 = this->makeStringArg(TokenType::RPAREN);
        this->advance();
        if(this->currentToken.getType() == TokenType::END_OF_LINE) {
            this->advance();

            /* Is the OS Windows? */
            #ifdef _WIN32
                return "del " + arg0;
            #endif

            /* Is the OS macOS? */
            #ifdef __APPLE__
                return "rm -f " + arg0;
            #endif

            /* Is the OS a Linux flavor? */
            #ifdef __linux__
                return "rm -f " + arg0;
            #endif

        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return "NULL";
}