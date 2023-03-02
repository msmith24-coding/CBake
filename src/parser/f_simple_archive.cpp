#include "../../includes/parser.h"

std::vector<std::string> Parser::makeSimpleArchiveFunc()
{
    std::vector<std::string> result;
    this->advance();
    if(this->currentToken.getType() == TokenType::LPAREN) {

        this->advance();
        std::string compiler = this->makeStringArg(TokenType::COMMA);
        if(compiler.empty()) {
            this->throwError("archive -> (compiler, objs, out).");
        }

        this->advance();
        std::string objs = this->makeStringArg(TokenType::COMMA);
        if(objs.empty()) {
            this->throwError("archive -> (compiler, objs, out).");
        }

        this->advance();
        std::string out = this->makeStringArg(TokenType::RPAREN);
        if(out.empty()) {
            this->throwError("archive -> (compiler, objs, out).");
        }

        if(this->currentToken.getType() == TokenType::END_OF_LINE) {
            this->advance();
            result.push_back(compiler + " -c "  + objs);
            result.push_back("ar rcs " + out + " *.o");
            return result;
        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return result;
}