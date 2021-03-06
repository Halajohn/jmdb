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

#ifndef KdwpCmd_ReferenceType_GetValues_hpp
#define KdwpCmd_ReferenceType_GetValues_hpp

#include <string>
#include <vector>

#include "KdwpCmd_ReferenceType.hpp"
#include "Value.hpp"

namespace jmdb
{
  typedef class KdwpCmd_ReferenceType_GetValues KdwpCmd_ReferenceType_GetValues;
  class KdwpCmd_ReferenceType_GetValues : public KdwpCmd_ReferenceType
  {
  private:
    
    // Out data
    
    uint32_t m_reference_id;
    uint32_t m_wanted_count;
    
    std::vector<uint64_t> m_wanted_fields;
    
    static uint32_t const EXTRA_HEADER_SIZE = (sizeof(get_size(&KdwpCmd_ReferenceType_GetValues::m_reference_id)) +
                                               sizeof(get_size(&KdwpCmd_ReferenceType_GetValues::m_wanted_count)));
    
    // Reply data
    
    uint32_t m_return_count;
    
    std::vector<ValueBase *> m_return_fields;
    
  public:
    
    // Life cycle
    
    KdwpCmd_ReferenceType_GetValues(uint32_t const reference_id)
      : KdwpCmd_ReferenceType(FLAG_NONE, GET_VALUES, EXTRA_HEADER_SIZE),
        m_reference_id(reference_id),
        m_wanted_count(0)
    { }
    
    ~KdwpCmd_ReferenceType_GetValues();
    
    // Operation
    
    void
    add_wanted_field(uint32_t const field_id)
    {
      uint64_t real_id = ((static_cast<uint64_t>(m_reference_id) << 32) | field_id);
      
      m_wanted_fields.push_back(real_id);
      
      ++m_wanted_count;
      
      add_extra_packet_size(sizeof(uint64_t));
    }
    
    uint64_t
    get_field_value(uint32_t const index)
    {
      return (m_return_fields[index])->get_value();
    }
    
    // Friend
    
    friend ClientSocket const &operator<<(ClientSocket const &socket, KdwpCmd_ReferenceType_GetValues &cmd);
  };
}

#endif
