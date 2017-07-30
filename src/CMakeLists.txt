

set(SOURCES
  main.cpp
  game.cpp
  atlas.cpp
  score.cpp
  gameScene.cpp
  gameOverScene.cpp
  pauseScene.cpp
  renderer.cpp
  quadfallController.cpp
  quadfallControls.cpp
)

add_subdirectory( data )

add_executable(
  quadfall
  ${SOURCES}
)

#set up SFML configuration
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2 REQUIRED system window graphics network audio)
# add SFML dependencies
if (MSVC)
  target_link_libraries(quadfall opengl32.lib winmm.lib gdi32.lib)
ENDIF (MSVC)

include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(quadfall
  ${JPEG_LIBRARY}
  ${FREETYPE_LIBRARY}
  ${SFML_LIBRARIES}
  jsoncpp
)


install( TARGETS quadfall DESTINATION ${QUADFALL_BINARY_DIR} )

