# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/raray/OneDrive/Escritorio/Makers/VERSA/Aries-main/Aries-main/Proyecto/esp-idf/components/bootloader/subproject"
  "C:/Users/raray/OneDrive/Escritorio/Makers/VERSA/Aries-main/Aries-main/Proyecto/Versa_Sample/build/bootloader"
  "C:/Users/raray/OneDrive/Escritorio/Makers/VERSA/Aries-main/Aries-main/Proyecto/Versa_Sample/build/bootloader-prefix"
  "C:/Users/raray/OneDrive/Escritorio/Makers/VERSA/Aries-main/Aries-main/Proyecto/Versa_Sample/build/bootloader-prefix/tmp"
  "C:/Users/raray/OneDrive/Escritorio/Makers/VERSA/Aries-main/Aries-main/Proyecto/Versa_Sample/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Users/raray/OneDrive/Escritorio/Makers/VERSA/Aries-main/Aries-main/Proyecto/Versa_Sample/build/bootloader-prefix/src"
  "C:/Users/raray/OneDrive/Escritorio/Makers/VERSA/Aries-main/Aries-main/Proyecto/Versa_Sample/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/raray/OneDrive/Escritorio/Makers/VERSA/Aries-main/Aries-main/Proyecto/Versa_Sample/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
