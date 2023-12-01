// Common helper functions needed to solve AOC problems

#ifndef AOC_H
#define AOC_H

#include <bits/stdc++.h>

namespace AOC {

/* Split
 * @param str - string value to split
 * @param delimiter - char to split on
 * @return a vector of substrings
 */
std::vector<std::string> Split(const std::string &str, const char delimiter);

/* Get File Contents
 * @param filename - path to the file
 * @returns the content of the file where each index matches to the
 * corresponding line
 */
std::vector<std::string> *Get_File_Contents(const std::string &filename);

} // namespace AOC

#endif // AOC_H
