#include "../../includes/parser.h"

std::vector<std::string> Parser::makeCompileFunc()
{
    std::vector<std::string> result;
    this->advance();
    if(this->currentToken.getType() == TokenType::LPAREN) {

        this->advance();
        std::string compiler = this->makeStringArg(TokenType::COMMA);
        if(compiler.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string objs = this->makeStringArg(TokenType::COMMA);
        if(objs.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string includes = this->makeStringArg(TokenType::COMMA);
        if(includes.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string libraries = this->makeStringArg(TokenType::COMMA);
        if(libraries.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string compilerFlags = this->makeStringArg(TokenType::COMMA);
        if(compilerFlags.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string linkerFlags = this->makeStringArg(TokenType::COMMA);
        if(linkerFlags.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string out = this->makeStringArg(TokenType::RPAREN);
        if(out.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        if(this->currentToken.getType() == TokenType::END_OF_LINE) {
            this->advance();
            result.push_back(compiler + " " + compilerFlags + " "  + objs + " " + includes + " " + libraries + " " + linkerFlags + " -o " + out);
            return result;
        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return result;
}