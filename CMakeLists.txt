cmake_minimum_required (VERSION 3.1)

project( quadfall_game )

set( QUADFALL_BINARY_DIR ${PROJECT_SOURCE_DIR}/game )
#set( QUADFALL_INTERMEDIATE_DIR ${PROJECT_SOURCE_DIR}/game )


if( MSVC )
  set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${QUADFALL_BINARY_DIR} )
  set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${QUADFALL_BINARY_DIR} )
  set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${QUADFALL_BINARY_DIR} )

  foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${QUADFALL_BINARY_DIR} )
    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${QUADFALL_BINARY_DIR} )
    set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${QUADFALL_BINARY_DIR} )
  endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

  SET(CMAKE_CXX_FLAGS "/EHsc")

  # define an option for choosing between static and dynamic C runtime (Windows only)
  # for VC++, we can apply it globally by modifying the compiler flags
  foreach(flag
          CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG
          CMAKE_CXX_FLAGS_RELEASE
          CMAKE_CXX_FLAGS_MINSIZEREL
          CMAKE_CXX_FLAGS_RELWITHDEBINFO)
      if(${flag} MATCHES "/MD")
          string(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
      endif()
  endforeach()

endif( MSVC )

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules/" ${CMAKE_MODULE_PATH})

add_subdirectory( thirdPartyLibs/jsoncpp )
add_subdirectory( src )
