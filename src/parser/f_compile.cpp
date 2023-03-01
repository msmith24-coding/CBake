#include "../../includes/parser.h"

std::vector<std::string> Parser::makeCompileFunc()
{
    std::vector<std::string> result;
    this->advance();
    if(this->currentToken.getType() == TT_LPAREN) {

        this->advance();
        std::string compiler = this->makeStringArg(TT_COMMA);
        if(compiler.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string objs = this->makeStringArg(TT_COMMA);
        if(objs.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string includes = this->makeStringArg(TT_COMMA);
        if(includes.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string libraries = this->makeStringArg(TT_COMMA);
        if(libraries.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string compilerFlags = this->makeStringArg(TT_COMMA);
        if(compilerFlags.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string linkerFlags = this->makeStringArg(TT_COMMA);
        if(linkerFlags.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string out = this->makeStringArg(TT_RPAREN);
        if(out.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        if(this->currentToken.getType() == TT_EOL) {
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