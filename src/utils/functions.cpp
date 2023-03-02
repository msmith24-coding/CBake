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

#include "../../includes/functions.h"

// +
// | Vector to store the function names.
// +
std::vector<std::string> functions;

// +
// | Function used to add all the function names to the functions vector.
// +
void setupFunctions()
{
    functions.push_back("call");
    functions.push_back("del");
    functions.push_back("run");
    functions.push_back("print");
    functions.push_back("simple_compile");
    functions.push_back("simple_archive");
    functions.push_back("compile");
    functions.push_back("unit_test");
}
