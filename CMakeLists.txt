# Copyright (c) 2012-2013 Hadron Industries, Inc.
#
# This is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required (VERSION 2.8.8)

project (madgwick-ahrs)
include (GNUInstallDirs)

include_directories (src)

set(BLACKMAGIC_SRCS Linux/include/DeckLinkAPIDispatch.cpp)
set(BLACKMAGIC_HDRS 
Linux/include/DeckLinkAPIConfiguration.h
Linux/include/DeckLinkAPIConfiguration_v10_2.h
Linux/include/DeckLinkAPIDeckControl.h
Linux/include/DeckLinkAPIDiscovery.h
Linux/include/DeckLinkAPI.h
Linux/include/DeckLinkAPIModes.h
Linux/include/DeckLinkAPITypes.h
Linux/include/DeckLinkAPI_v10_2.h
Linux/include/DeckLinkAPI_v7_1.h
Linux/include/DeckLinkAPI_v7_3.h
Linux/include/DeckLinkAPI_v7_6.h
Linux/include/DeckLinkAPI_v7_9.h
Linux/include/DeckLinkAPI_v8_0.h
Linux/include/DeckLinkAPI_v8_1.h
Linux/include/DeckLinkAPI_v9_2.h
Linux/include/DeckLinkAPI_v9_9.h
Linux/include/DeckLinkAPIVersion.h
Linux/include/LinuxCOM.h)

add_library(blackmagic-ahrs-shared SHARED ${BLACKMAGIC_SRCS} ${BLACKMAGIC_HDRS})
add_library(blackmagic-ahrs-static STATIC ${BLACKMAGIC_SRCS} ${BLACKMAGIC_HDRS})

set_target_properties(blackmagic-ahrs-shared PROPERTIES SOVERSION 10)
set_target_properties(blackmagic-ahrs-shared PROPERTIES OUTPUT_NAME DeckLinkAPI)
set_target_properties(blackmagic-ahrs-static PROPERTIES OUTPUT_NAME DeckLinkAPI)

target_link_libraries(blackmagic-ahrs-shared)

install (TARGETS blackmagic-ahrs-shared
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install (TARGETS blackmagic-ahrs-static
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install (FILES ${BLACKMAGIC_HDRS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/decklink)
