#ifndef IBOARD_SIDE_PANE_H
#define IBOARD_SIDE_PANE_H

#include "ui_components/pane.h"
#include "utils/move.hpp"

class IBoardSidePane : public Pane {
 public:
  IBoardSidePane() : Pane(Kboard_pane_size) {}
  virtual ~IBoardSidePane() = default;
  virtual void make_move(const Move &mv) = 0;
  virtual void update() = 0;

 private:
  static const size_t Kboard_pane_size{44};
};

#endif /* IBOARD_SIDE_PANE_H */
