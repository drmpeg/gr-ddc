INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_DDC ddc)

FIND_PATH(
    DDC_INCLUDE_DIRS
    NAMES ddc/api.h
    HINTS $ENV{DDC_DIR}/include
        ${PC_DDC_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    DDC_LIBRARIES
    NAMES gnuradio-ddc
    HINTS $ENV{DDC_DIR}/lib
        ${PC_DDC_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(DDC DEFAULT_MSG DDC_LIBRARIES DDC_INCLUDE_DIRS)
MARK_AS_ADVANCED(DDC_LIBRARIES DDC_INCLUDE_DIRS)

