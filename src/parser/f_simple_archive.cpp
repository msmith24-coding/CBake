#include "../../includes/parser.h"

std::vector<std::string> Parser::makeSimpleArchiveFunc()
{
    std::vector<std::string> result;
    this->advance();
    if(this->currentToken.getType() == TT_LPAREN) {

        this->advance();
        std::string compiler = this->makeStringArg(TT_COMMA);
        if(compiler.empty()) {
            this->throwError("archive -> (compiler, objs, out).");
        }

        this->advance();
        std::string objs = this->makeStringArg(TT_COMMA);
        if(objs.empty()) {
            this->throwError("archive -> (compiler, objs, out).");
        }

        this->advance();
        std::string out = this->makeStringArg(TT_RPAREN);
        if(out.empty()) {
            this->throwError("archive -> (compiler, objs, out).");
        }

        if(this->currentToken.getType() == TT_EOL) {
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