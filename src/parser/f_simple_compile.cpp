#include "../../includes/parser.h"

std::vector<std::string> Parser::makeSimpleCompileFunc()
{
    std::vector<std::string> result;
    this->advance();
    if(this->currentToken.getType() == TT_LPAREN) {

        this->advance();
        std::string compiler = this->makeStringArg(TT_COMMA);
        if(compiler.empty()) {
            this->throwError("simple_compile -> (compiler, objs, compiler_flags, out).");
        }

        this->advance();
        std::string objs = this->makeStringArg(TT_COMMA);

        if(objs.empty()) {
            this->throwError("simple_compile -> (compiler, objs, compiler_flags, out).");
        }

        this->advance();
        std::string cFlags = this->makeStringArg(TT_COMMA);

        if(cFlags.empty()) {
            this->throwError("simple_compile -> (compiler, objs, compiler_flags, out).");
        }

        this->advance();
        std::string out = this->makeStringArg(TT_RPAREN);

        if(out.empty()) {
           this->throwError("simple_compile -> (compiler, objs, compiler_flags, out).");
        }

        this->advance();
        if(this->currentToken.getType() == TT_EOL) {
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