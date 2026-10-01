# Install script for directory: /run/media/zack/Sandisk USB/repositories/nitrogen/deps/miniaudio-0.11.25

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/llvm-objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/miniaudio" TYPE FILE FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/deps/miniaudio-0.11.25/miniaudio.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/miniaudio/extras/decoders/libvorbis" TYPE FILE FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/deps/miniaudio-0.11.25/extras/decoders/libvorbis/miniaudio_libvorbis.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/miniaudio/extras/decoders/libopus" TYPE FILE FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/deps/miniaudio-0.11.25/extras/decoders/libopus/miniaudio_libopus.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/miniaudio/extras/nodes/ma_channel_combiner_node" TYPE FILE FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/deps/miniaudio-0.11.25/extras/nodes/ma_channel_combiner_node/ma_channel_combiner_node.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/miniaudio/extras/nodes/ma_channel_separator_node" TYPE FILE FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/deps/miniaudio-0.11.25/extras/nodes/ma_channel_separator_node/ma_channel_separator_node.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/miniaudio/extras/nodes/ma_ltrim_node" TYPE FILE FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/deps/miniaudio-0.11.25/extras/nodes/ma_ltrim_node/ma_ltrim_node.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/miniaudio/extras/nodes/ma_reverb_node" TYPE FILE FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/deps/miniaudio-0.11.25/extras/nodes/ma_reverb_node/ma_reverb_node.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/miniaudio/extras/nodes/ma_vocoder_node" TYPE FILE FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/deps/miniaudio-0.11.25/extras/nodes/ma_vocoder_node/ma_vocoder_node.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/linux-build/deps/miniaudio-0.11.25/miniaudio.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/linux-build/deps/miniaudio-0.11.25/libminiaudio.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/linux-build/deps/miniaudio-0.11.25/libminiaudio_libvorbis.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/linux-build/deps/miniaudio-0.11.25/libminiaudio_libopus.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/linux-build/deps/miniaudio-0.11.25/libminiaudio_channel_combiner_node.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/linux-build/deps/miniaudio-0.11.25/libminiaudio_channel_separator_node.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/linux-build/deps/miniaudio-0.11.25/libminiaudio_ltrim_node.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/linux-build/deps/miniaudio-0.11.25/libminiaudio_reverb_node.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/run/media/zack/Sandisk USB/repositories/nitrogen/linux-build/deps/miniaudio-0.11.25/libminiaudio_vocoder_node.a")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/run/media/zack/Sandisk USB/repositories/nitrogen/linux-build/deps/miniaudio-0.11.25/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
