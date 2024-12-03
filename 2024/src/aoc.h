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
std::optional<std::vector<std::string>> Get_File_Contents(const std::string &file_name);

/* Get Solution Test Case File Path
 * @param day - advent calendar day
 * @param useSampleTxtFile - Any non zero value is True. Defaults to 0 for input
 * txt file
 * @returns the file path to the test cases for the given day
 */
std::string Get_Solution_Test_Case_File_Path(int day, bool use_sample_txt_file);

/* Calculate Least Common Multiple of a vector
 * @param nums - vector of numbers
 * @returns LCM of the vector
 */
template <typename T> T LCM(const std::vector<T> &nums) {
    if (nums.empty()) {
        return 0;
    }

    T res = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        res = (res * nums[i]) / std::gcd(res, nums[i]);
    }

    return res;
}

} // namespace AOC

#endif // AOC_H
