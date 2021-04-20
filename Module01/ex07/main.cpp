//
// Created by Aaron Berry on 4/18/21.
//

#include <iostream>
#include <fstream>
#include <string>

static std::string CreateFilename(char *input_file) {
  size_t len = strlen(input_file);
  for (size_t i = 0; i < len; ++i) {
    input_file[i] = static_cast<char>(toupper(input_file[i]));
  }
  std::string out_file(input_file);
  return (out_file + ".replace");
}

static void ExitWithMessage() {
  std::cout << "Error !" << std::endl;
  exit(1);
}

static void ReplaceAndWriteInFile(char *argv[]) {
  std::string line;
  std::string filename(argv[1]);
  std::ifstream out_file("../" + filename);
  if (!out_file.is_open())
    ExitWithMessage();
  std::ofstream in_file("../" + CreateFilename(argv[1]));
  if (!in_file.is_open())
    ExitWithMessage();
  int64_t index, offset;
  while (getline(out_file, line)) {
    offset = 0;
    while ((index = static_cast<int64_t>(line.find(argv[2], offset)))
            != static_cast<int64_t>(std::string::npos)) {
      offset += static_cast<int64_t>(strlen(argv[3])),
      line.replace(index, strlen(argv[2]), argv[3]);
    }
    if (out_file.eof() == 0)
      in_file << line.data() << std::endl;
    else
      in_file << line.data();
  }
  filename.close();
  out_file.close();
}

int main(int argc, char *argv[]) {
  if (argc != 4)
    ExitWithMessage();
  ReplaceAndWriteInFile(argv);
  return 0;
}
