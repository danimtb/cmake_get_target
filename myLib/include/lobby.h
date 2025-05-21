#pragma once
#include INCLUDE_PATH_TO_GAME_OPTION

// We could use a templated class here but then we have to move all the
// definitions from lobby.cxx into lobby.hxx.

struct Lobby {
  //   lots of lobby code
  GameOption gameOption{};
};
