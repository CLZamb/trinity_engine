#include "input/headers/keyboard_input_player.h"

const string KeyboardInputPlayer::key_not_supported = "key not supported\n";

KeyboardInputPlayer::KeyboardInputPlayer(KeyboardBase &k) : m_k_input(k) {}

void KeyboardInputPlayer::setup(BoardView &v) { m_view = &v; }

void KeyboardInputPlayer::update_turn(const PlayerInfo &p) {
  m_turn = p;
  update_view_select_next_square(last_position[p.turn]);
}

string KeyboardInputPlayer::get_player_string_move(PlayerPosition &player) {
  completed = false;
  has_been_selected = false;

  string next_move{""};
  size_t next_pos = player.get_to_position();

  while (!completed) {
    switch (InputKeys::Key key = m_k_input.read_key(); key) {
      case InputKeys::ARROW_KEY:
        handle_arrow_keys(m_k_input.read_arrow_key(), next_pos);
        break;
      case InputKeys::W:
      case InputKeys::A:
      case InputKeys::S:
      case InputKeys::D:
        handle_arrow_keys(key, next_pos);
        break;
      case InputKeys::ENTER:
        next_move += select_position(player, next_pos);
        update_view_selected_square(next_pos);
        selected_positions.push_back(next_pos);
        break;
      default:
        std::cout << key_not_supported << std::endl;
        break;
    }

    update_view_select_next_square(next_pos);
    m_view->print();
  }

  deselect_all_previous_selected_squares();
  update_last_position(next_pos);
  return next_move;
}

void KeyboardInputPlayer::deselect_all_previous_selected_squares() {
  for (const size_t &pos : selected_positions)
    update_view_deselected_square(pos);
  selected_positions.clear();
}

void KeyboardInputPlayer::update_last_position(const size_t &pos) {
  last_position[m_turn.turn] = pos;
}

void KeyboardInputPlayer::handle_arrow_keys(const InputKeys::Key &k, size_t &pos) {
  size_t prev = pos;
  int _pos = static_cast<int>(pos);

  if (_pos >= 0)
    _pos += m_direction_value[k];

  pos = static_cast<size_t>(_pos);

  if (pos < A1 || pos > H8)
    pos = prev;
}

string KeyboardInputPlayer::select_position(PlayerPosition &p, const size_t &pos) {
  if (has_been_selected) {
    select_to(p, pos);
  } else {
    select_from(p, pos);
  }

  has_been_selected = !has_been_selected;
  return string_utils::squareindex_to_str(SquareIndices(pos));
}

void KeyboardInputPlayer::select_from(PlayerPosition &p, const size_t pos) {
  p.set_from_position(pos);
}

void KeyboardInputPlayer::select_to(PlayerPosition &p, const size_t pos) {
  completed = true;
  p.set_to_position(pos);
}

void KeyboardInputPlayer::update_view_select_next_square(const size_t &next) {
  m_view->select_next_square(next);
}

void KeyboardInputPlayer::update_view_selected_square(const size_t &p) {
  m_view->selected_square(p);
}

void KeyboardInputPlayer::update_view_deselected_square(const size_t &p) {
  m_view->deselect_square(p);
}
