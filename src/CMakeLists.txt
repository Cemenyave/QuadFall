add_executable(
  quadfall
  main.cpp
  block.cpp
  well.cpp
  game.cpp
  renderer.cpp
)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules/" ${CMAKE_MODULE_PATH})

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)

  # add SFML dependencies
  if (MSVC)
    target_link_libraries(quadfall opengl32.lib winmm.lib gdi32.lib)
  ENDIF (MSVC)

  target_link_libraries(quadfall ${JPEG_LIBRARY})

  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(quadfall ${SFML_LIBRARIES})
endif()

IF( MSVC )
  #Tell Visual Studio that this is windows application
  #set_target_properties(quadfall PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS")
  #set_target_properties(quadfall PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
ENDIF( MSVC )
