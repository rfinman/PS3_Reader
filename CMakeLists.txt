cmake_minimum_required(VERSION 2.6.0)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-2.4)

add_subdirectory(src)
