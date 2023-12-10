#include "day_05.h"
#include "aoc.h"
#include <bits/stdc++.h>

#define ll long long

void Day_05::Solution_01(const std::vector<std::string> *input) {
  std::string seed_line = (*input)[0];
  size_t colon_idx = seed_line.find(":");
  std::vector<std::string> seed_strs =
      AOC::Split(seed_line.substr(colon_idx + 2), ' ');

  std::unordered_map<ll, ll> seed_map; // <seed, destination_after_each_mapping>
  for (const std::string seed_str : seed_strs) {
    ll seed = std::stoll(seed_str);
    seed_map.insert({seed, seed});
  }

  std::vector<std::vector<ll>> curr_sub_map;
  for (int i = 3; i < (*input).size(); i++) {
    std::string line = (*input)[i];

    // ignore sub mapping headers (i.e., seed-to-soil map:, etc.)
    if (line != "" && !std::isdigit(line[0]))
      continue;

    // line -> destination #, source #, range #
    if (line != "" && std::isdigit(line[0])) {
      std::vector<std::string> line_strs = AOC::Split(line, ' ');
      ll destination = std::stoll(line_strs[0]);
      ll source = std::stoll(line_strs[1]);
      ll range = std::stoll(line_strs[2]);
      curr_sub_map.push_back({destination, source, range});
      // continue to next line if we are not at the last line of the input
      if (i != (*input).size() - 1)
        continue;
    }

    // reached end of sub map (aka line == "") or reached last line of the input
    for (std::pair<ll, ll> seed : seed_map) {
      ll seed_source = seed.second;
      for (const std::vector<ll> line_mapping : curr_sub_map) {
        ll range = line_mapping[2];
        ll start_source = line_mapping[1];
        ll end_source = start_source + range - 1;
        ll dest = line_mapping[0];

        if (seed_source >= start_source && seed_source <= end_source) {
          ll mapping_offset = seed_source - start_source;
          seed_map[seed.first] = dest + mapping_offset;
          break;
        }
      }
    }
    curr_sub_map = {};
  }

  ll lowest_location = std::numeric_limits<ll>::max();
  for (std::pair<ll, ll> seed : seed_map) {
    if (seed.second < lowest_location) {
      lowest_location = seed.second;
    }
  }
  std::cout << lowest_location << "\n";
}

void Day_05::Solution_02(const std::vector<std::string> *input) {
  std::cout << "Running day_05, part 2 solution\n";
}
