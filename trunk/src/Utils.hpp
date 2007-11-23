// Jmdb - A J2ME debugger with Emacs interface
// Copyright (C) <2007>  Wei Hu <wei.hu.tw@gmail.com>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef Utils_hpp
#define Utils_hpp

#include "Type.hpp"

namespace jmdb
{
  enum NumberType
  {
    DEC,
    HEX
  };
  typedef enum NumberType NumberType;
  
  NumberType number_type(std::string const &number_string);
  uint32_t convert_to_integer(std::string const &number_string);
}

#endif
