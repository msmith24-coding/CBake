/**
 * CBake is an open source project used as a build tool for C/C++ projects.
 * Copyright (C) 2023  CBake Foundation
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "../../includes/parser.h"

std::vector<std::string> Parser::makeUnitTestFunc()
{
    std::vector<std::string> result;
    this->advance();
    if(this->currentToken.getType() == TokenType::LPAREN) {
        this->advance();
        std::string exe = this->makeStringArg(TokenType::COMMA);
        if(exe.empty()) {
            this->throwError("unit_test -> (exe, test_file).");
        }

        this->advance();
        std::string testFile = this->makeStringArg(TokenType::RPAREN);
        if(testFile.empty()) {
            this->throwError("unit_test -> (exe, test_file).");
        }

        this->advance();
        if(this->currentToken.getType() == TokenType::END_OF_LINE) {
            this->advance();
            std::string outFile = "temp.test";
            /* Is the OS Windows? */
            #ifdef _WIN32
                //TODO
            #endif

            /* Is the OS macOS? */
            #ifdef __APPLE__
                result.push_back("./" + exe + " > " + outFile);
                result.push_back("diff " + outFile + " " + testFile + " > /dev/null 2>&1; error=$?; if [ $error -eq 0 ]; then echo \"[" + testFile + "] Test passed!\"; else echo \"[" + testFile + "] Test failed.\"; fi;");
                result.push_back("rm -f " + outFile);
            #endif

            /* Is the OS a Linux flavor? */
            #ifdef __linux__
                result.push_back("./" + exe + " > " + outFile);
                result.push_back("diff " + outFile + " " + testFile + " > /dev/null 2>&1; error=$?; if [ $error -eq 0 ]; then echo \"[" + testFile + "] Test passed!\"; else echo \"[" + testFile + "] Test failed.\"; fi;");
                result.push_back("rm -f " + outFile);
            #endif

            return result;

        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return  result;
}