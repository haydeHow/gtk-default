cmake_minimum_required(VERSION 3.10)
project(app C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find the necessary packages
find_package(PkgConfig REQUIRED)

# Check for GTK3, GLib, and libcurl using pkg-config
pkg_check_modules(GTK4 REQUIRED gtk4)
pkg_check_modules(GLIB REQUIRED glib-2.0)
pkg_check_modules(CURL REQUIRED libcurl)
pkg_check_modules(SQLITE3 REQUIRED sqlite3)

# Add the executable
add_executable(app main.c)

# Include GTK3 and GLib headers
target_include_directories(app PRIVATE
    ${GTK4_INCLUDE_DIRS}
    ${GLIB_INCLUDE_DIRS}
    ${SQLITE3_INCLUDE_DIRS}
)

# Link libraries for GTK3, GLib, and libcurl
target_link_libraries(app
    ${GTK4_LIBRARIES}
    ${GLIB_LIBRARIES}
    ${CURL_LIBRARIES}
    ${SQLITE3_LIBRARIES}
)

# Handle GTK3 and GLib compile flags
foreach(flag ${GTK3_CFLAGS_OTHER} ${GLIB_CFLAGS_OTHER})
    # Remove any spaces or dashes that might break macro names
    string(REPLACE "-" "_" flag_fixed ${flag})
    string(REPLACE " " ";" flag_fixed ${flag_fixed}) # replace spaces with semicolons (for valid list elements)
    target_compile_definitions(app PRIVATE ${flag_fixed})
endforeach()
