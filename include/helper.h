
/* 
  Helper functions
*/
std::string userInput(std::string prompt) {
  std::string reply = "";  
  std::cout << prompt;   
  std::getline(std::cin, reply);  
  return reply;
}

bool isNumber(std::string str) {
  bool state = true;
  //pattern to check if input string matches numbers
  std::regex regex_pattern(R"([-]?((\d+(\.\d+)?)|(\d+\.)|(\.\d+))(e[-+]?\d+)?*$)");
  if (!std::regex_match(str,regex_pattern)) {
    state = false;
  }  
  return state;
}

float stringToFloat(std::string str, float deflt = -1) {
  float value = deflt;
  if (isNumber(str)) {
    value = stof(str);
  }  
  return value;
}

int stringToInt(std::string str, int deflt = -1) {
  int value = deflt;
  if (isNumber(str)) {
    value = stoi(str);
  }    
  return value;
}

int floatLength(float num) {
  std::string str = std::to_string(num);
  return str.size();
}

float roundTwoDecimal(float num) {  
  int sizeStr = floatLength(num);
  char arrayChar[sizeStr];

  sprintf(arrayChar, "%.2f", num);
  sscanf(arrayChar, "%f", &num);

  return num;
}

float readFloat(std::string prompt) {
  std::string input;  
  do {    
    input = userInput(prompt);
  } while (!isNumber(input));
  return stringToFloat(input);;
}

int readInteger(std::string prompt) {
  std::string input;
  do {   
    input = userInput(prompt);
  } while (!isNumber(input) || (input.find('.') != std::string::npos));
  return stringToInt(input);
}

char readChar(std::string prompt) {
  std::string input;  
  do {       
    input = userInput(prompt);
  } while (input.size() != 1);
  return input[0];
}

std::string readString(std::string prompt) {
  std::string input;
  do {
    input = userInput(prompt);
  } while (input.length() == 0);
  return input;
}

unsigned short int getMatchCount(std::string pattern, std::string password) {
  
  std::regex  const expression(pattern);
  std::string const text(password);

  std::ptrdiff_t const match_count(std::distance(
  std::sregex_iterator(text.begin(), text.end(), expression),
  std::sregex_iterator()));  

  return match_count;
}

std::string readName(std::string prompt) {
  std::string input;
  do {
    input = userInput(prompt);
  } while ((getMatchCount(R"(\d)", input) > 0) || input.length() == 0);
  return input;
}

void printStrElementsVector(std::vector<std::string> &myVector) {  
  for (std::string e : myVector) {
    std::cout << e << "\n";
  }
}
