#include "day_07.h"
#include "aoc.h"
#include <bits/stdc++.h>

struct Hand_Card {
  char c;
  int value;
  Hand_Card(const char &temp_c, int card_value)
      : c(temp_c), value(card_value) {}
};

enum Hand_Type {
  HIGH_CARD,  // 0
  ONE_PAIR,   // 1
  TWO_PAIR,   // 2
  THREE_KIND, // 3
  FULL_HOUSE, // 4
  FOUR_KIND,  // 5
  FIVE_KIND   // 6
};

Hand_Type get_hand_type(std::string cards, bool is_part_two) {
  std::unordered_map<char, int> card_count;
  for (const char c : cards) {
    if (card_count.find(c) == card_count.end()) {
      card_count.insert({c, 1});
    } else {
      card_count[c]++;
    }
  }

  if (card_count.size() == 1) {
    return Hand_Type::FIVE_KIND;
  }

  // hand contains a J, add J value to the highest value
  if (is_part_two && card_count.find('J') != card_count.end()) {
    int j_count = card_count['J'];
    int max_value = 0;
    char max_key;
    for (std::pair<char, int> card : card_count) {
      if (card.second >= max_value && card.first != 'J') {
        max_key = card.first;
        max_value = card.second;
      }
    }
    card_count[max_key] = card_count[max_key] + j_count;
    card_count.erase('J');

    // need to recheck for cards like 'JAAAA'
    if (card_count.size() == 1) {
      return Hand_Type::FIVE_KIND;
    }
  }

  for (std::pair<char, int> card : card_count) {
    if (card.second == 4)
      return Hand_Type::FOUR_KIND;
    if (card.second == 3 && card_count.size() == 2)
      return Hand_Type::FULL_HOUSE;
    if (card.second == 3)
      return Hand_Type::THREE_KIND;
    if (card.second == 2 && card_count.size() == 3)
      return Hand_Type::TWO_PAIR;
    if (card.second == 2 && card_count.size() == 4)
      return Hand_Type::ONE_PAIR;
  }

  return Hand_Type::HIGH_CARD;
}

struct Hand {
  std::vector<Hand_Card> cards;
  Hand_Type type;
  int bid;

  Hand(const std::string &temp_cards, int hand_bid, bool is_part_two) {
    for (const char &c : temp_cards) {
      int value = 0;
      if (std::isdigit(c))
        value = c - '0';
      if (c == 'A')
        value = 14;
      if (c == 'K')
        value = 13;
      if (c == 'Q')
        value = 12;
      // if part two, J value will be zero instead of 11
      if (c == 'J' && !is_part_two)
        value = 11;
      if (c == 'T')
        value = 10;
      cards.push_back({c, value});
    }

    type = get_hand_type(temp_cards, is_part_two);
    bid = hand_bid;
  }
};

void Day_07::Solution_01(const std::vector<std::string> *input) {
  std::vector<Hand> hands;

  for (const std::string line : (*input)) {
    std::vector<std::string> line_parts = AOC::Split(line, ' ');
    int hand_bid = std::stoi(line_parts[1]);
    Hand current_hand = {line_parts[0], hand_bid, false};
    hands.push_back(current_hand);
  }

  std::sort(hands.begin(), hands.end(), [](Hand a, Hand b) {
    if (a.type == b.type) {
      for (int i = 0; i < a.cards.size(); i++) {
        if (a.cards[i].value == b.cards[i].value)
          continue;
        return a.cards[i].value < b.cards[i].value;
      }
    }
    return a.type < b.type;
  });

  int total = 0;
  for (int i = 0; i < hands.size(); i++) {
    total += hands[i].bid * (i + 1);
  }
  std::cout << total << "\n";
}

void Day_07::Solution_02(const std::vector<std::string> *input) {
  std::vector<Hand> hands;

  for (const std::string line : (*input)) {
    std::vector<std::string> line_parts = AOC::Split(line, ' ');
    int hand_bid = std::stoi(line_parts[1]);
    Hand current_hand = {line_parts[0], hand_bid, true};
    hands.push_back(current_hand);
  }

  std::sort(hands.begin(), hands.end(), [](Hand a, Hand b) {
    if (a.type == b.type) {
      for (int i = 0; i < a.cards.size(); i++) {
        if (a.cards[i].value == b.cards[i].value)
          continue;
        return a.cards[i].value < b.cards[i].value;
      }
    }
    return a.type < b.type;
  });

  int total = 0;
  for (int i = 0; i < hands.size(); i++) {
    total += hands[i].bid * (i + 1);
  }
  std::cout << total << "\n";
}
