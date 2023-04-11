#ifndef BOARD_INPUT_SELECTION
#define BOARD_INPUT_SELECTION

#include "utils/defs.h"
class KeyboardBoardInputSelection {
 public:
  virtual ~KeyboardBoardInputSelection() {}
  virtual void select_next_square(const SquareIndices& sq) = 0;
  virtual void selected_square(const SquareIndices& sq) = 0;
  virtual void deselect_square(const SquareIndices& sq) = 0;
};

#endif // !BOARD_MAIN_PANE_H
