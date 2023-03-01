#include "../../includes/parser.h"

std::vector<std::string> Parser::makeSimpleCompileFunc()
{
    std::vector<std::string> result;
    this->advance();
    if(this->currentToken.getType() == TokenType::LPAREN) {

        this->advance();
        std::string compiler = this->makeStringArg(TokenType::COMMA);
        if(compiler.empty()) {
            this->throwError("simple_compile -> (compiler, objs, compiler_flags, out).");
        }

        this->advance();
        std::string objs = this->makeStringArg(TokenType::COMMA);

        if(objs.empty()) {
            this->throwError("simple_compile -> (compiler, objs, compiler_flags, out).");
        }

        this->advance();
        std::string cFlags = this->makeStringArg(TokenType::COMMA);

        if(cFlags.empty()) {
            this->throwError("simple_compile -> (compiler, objs, compiler_flags, out).");
        }

        this->advance();
        std::string out = this->makeStringArg(TokenType::RPAREN);

        if(out.empty()) {
           this->throwError("simple_compile -> (compiler, objs, compiler_flags, out).");
        }

        this->advance();
        if(this->currentToken.getType() == TokenType::END_OF_LINE) {
            this->advance();
            result.push_back(compiler + " " + objs + " " + cFlags + " -o " + out);
            return result;
        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return result;
}