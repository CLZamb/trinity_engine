#include "headers/game.h"
#include <algorithm>

Game::Game() : m_board_with_info() {
  m_messages_gui.add_pane_at_pos(&m_messages, GuiController::Left_pane);
  attach(m_board_with_info.get_board());
  attach(m_board_with_info.get_info());
  attach(&m_board_with_info);
}

Game::~Game() {}

void Game::start() {
  if (get_start_or_quit_selection() == Quit) {
    print_message(m_messages.get_game_over());
    return;
  }

  set_players_on_board(get_players_selection());
  play();
}

int Game::get_start_or_quit_selection() {
  print_message(m_messages.get_start_or_quit());
  return get_selected_option({Start, Quit});
}

void Game::_init() {
  m_board_with_info._init();
  m_ipc_search._init();

  Board* board = m_board_with_info.get_board();
  Info* info = m_board_with_info.get_info();

  m_main_gui.add_pane_at_pos(board, GuiController::Middle_pane);
  m_main_gui.add_pane_at_pos(info, GuiController::Right_pane);

  info->save_game_info(
      "Is player " +
      board->get_turn()->get_str_color_pieces() +
      " turn");
  cout << m_main_gui;
}

void Game::play() {
  _init();
  Board* board = m_board_with_info.get_board();
  Info* info = m_board_with_info.get_info();

  string player_input = "";
  while (!board->is_checkmate()) {
    current_player = board->get_turn();
    current_player->get_input(player_input);

    if (has_player_quit(player_input))
      break;

    if (!MoveUtils::is_valid_str_move_format(player_input)) {
      info->save_game_info(
          "Move { " +
          player_input +
          " } - is an not in a recognizable format, please try again ");
      cout << m_main_gui;
      continue;
    }

    player_move = MoveUtils::str_convert_to_move(player_input);

    if (!board->is_legal_move(player_move)) {
      info->save_game_info(
          "Move { " +
          player_input +
          " } is an ilegal move");
      cout << m_main_gui;
      continue;
    }

    m_board_with_info.make_move(player_move);
    change_turn();

    cout << m_main_gui;
  }
}

bool Game::has_player_quit(const string& str) {
  return str == "quit" || str == "close" || str == "exit";
}

pair<Player::Type, Player::Type> Game::get_players_selection() {
  print_message(m_messages.get_players_options());

  int opt =
    get_selected_option(m_players_selections.get_configurations_options());

  return m_players_selections.get_pair_players_type(
      static_cast<PlayersSelections::Players_configuration>(opt));
}

int Game::get_selected_option(vector<int> opts) {
  std::cout << "\t\tchoose one of the options ("
    << opts.front() << "-"
    << opts.back() << "): ";

  int input = -1;
  bool valid_option = false;

  while (!valid_option) {
    std::cin >> input;

    valid_option = check_valid_option(input, opts);

    if (!valid_option)
      cout << "invalid option try again!" << endl;
  }

  std::cin.clear();
  std::cin.ignore();
  return input;
}

bool Game::check_valid_option(int i, const vector<int>& opts) {
  return std::find(opts.begin(), opts.end(), i) != opts.end();
}

void Game::
set_players_on_board(const std::pair<Player::Type, Player::Type>& p_type) {
  player_1 = create_new_player(p_type.first, WHITE);
  player_2 = create_new_player(p_type.second, BLACK);
  m_board_with_info.get_board()->set_players(player_1, player_2);
}

std::unique_ptr<Player>
Game::create_new_player(Player::Type type, Color color) {
  if (type == Player::Human)
    return std::make_unique<Player>(Player(color));
  // else Playyer::CPU
  return std::make_unique<Player>(Player(color));
}

void Game::print_message(MessageState* message) {
  m_messages.set_message(message);
  cout << m_messages_gui << endl;
}

void Game::change_turn() {
  current_player = current_player->get_opponent();;

  if (current_player == player_1)
    m_turn = GameTurn::player_1;
  else  // current_player == player_2
    m_turn = GameTurn::player_2;

  cout << "change turn " << endl;


  notify();
}

void Game::notify() {
  for (auto observer : *_observers) {
    observer->update_turn(m_turn);
  }
}
