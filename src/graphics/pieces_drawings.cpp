#include "headers/pieces_drawings.hpp"

const unordered_map<std::string, Box> Drawing::piece_drawing = {
  {
    "bishop",
    {{
       "█████████",
       "███(/)███",
       "███▙ ▟███",
       "███▀ ▀███",
       "█████████",
     }}
  },
  {
    "king",
    {{
       "██▁ ✜ ▁██",
       "█( ╲|╱ )█",
       "██╲▁▁▁╱██",
       "█[▁▁▁▁▁]█",
       "█████████",
     }}
  },
  {
    "knight",
    {{
       "█████████",
       "████ █ ██",
       "███    ██",
       "████   ██",
       "█████████",
     }}
  },
  {
    "pawn",
    {{
       "█████████",
       "███( )███",
       "███▛ ▜███",
       "██▛   ▜██",
       "█████████",
     }}
  },
  {
    "queen",
    {{
       "█████████",
       "██ █ █ ██",
       "██     ██",
       "██     ██",
       "█████████",
     }}
  },
  {
    "rook",
    {{
       "█████████",
       "██▀█▀█▀██",
       "██▙   ▟██",
       "██▀   ▀██",
       "█████████",
     }}
  },
  {
    "BaseWhiteSquare",
    {{
       "█████████",
       "█████████",
       "█████████",
       "█████████",
       "█████████",
     }}
  },
  {
    "BaseBlackSquare",
    {{
       "         ",
       "         ",
       "         ",
       "         ",
       "         ",
     }}
  }
};
