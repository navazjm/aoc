#include <bits/stdc++.h>
#include <openssl/md5.h>

std::string hash(const std::string &s) {
  MD5_CTX md5Context;
  MD5_Init(&md5Context);

  MD5_Update(&md5Context, s.c_str(), s.size());

  unsigned char hash[MD5_DIGEST_LENGTH];
  MD5_Final(hash, &md5Context);

  std::stringstream ss;
  for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
    ss << std::hex << std::setw(2) << std::setfill('0')
       << static_cast<int>(hash[i]);
  }
  return ss.str();
}

void partOne(const std::vector<std::string> &input) {
  std::string s = input[0];
  int i = 0;
  while (i < 100000000) {
    std::string sI = std::to_string(i);
    std::string s2 = s + sI;
    std::string md5Hash = hash(s2);
    if (md5Hash.substr(0, 5) == "00000") {
      std::cout << i << "\n";
      break;
    }
    i++;
  }
}

void partTwo(const std::vector<std::string> &input) {
  std::string s = input[0];
  int i = 0;
  while (i < 100000000) {
    std::string sI = std::to_string(i);
    std::string s2 = s + sI;
    std::string md5Hash = hash(s2);
    if (md5Hash.substr(0, 6) == "000000") {
      std::cout << i << "\n";
      break;
    }
    i++;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <filename.txt>" << std::endl;
    return 1;
  }
  std::string filename = argv[1];

  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Failed to open the file: " << filename << std::endl;
    return 1;
  }

  std::vector<std::string> fileContents;
  std::string line;

  while (std::getline(file, line)) {
    fileContents.push_back(line);
  }

  // Close the file
  file.close();

  partOne(fileContents);
  partTwo(fileContents);

  return 0;
}
