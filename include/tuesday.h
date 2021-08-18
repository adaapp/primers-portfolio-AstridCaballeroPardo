/*
  functions used by passwordComplexityChecker()
*/

unsigned short int getMatchCount(std::string pattern, std::string password) {
  
  std::regex  const expression(pattern);
  std::string const text(password);

  std::ptrdiff_t const match_count(std::distance(
  std::sregex_iterator(text.begin(), text.end(), expression),
  std::sregex_iterator()));  

  return match_count;
}

unsigned short int getValuePassword(std::string password, unsigned short int numberCount, unsigned short int charCount, unsigned short int specialCharCount, unsigned short int passwordLength) {
  unsigned short int value = 0;
  const unsigned short int min_char = 4;
  const unsigned short int min_schar = 1;
  const unsigned short int min_num = 2;
  const unsigned short int min_len = 8;

  if (numberCount == passwordLength || charCount == passwordLength || specialCharCount == passwordLength || passwordLength < min_char) {
    value = 1;
  }
  else if (passwordLength >= min_len  && numberCount >= min_num && charCount >= min_char && specialCharCount < min_schar ) {
    value = 3;
  }
  else if (passwordLength >= min_len  && numberCount >= min_num && charCount >= min_char && specialCharCount >= min_schar ) {
    value = 4;
  }
  else {
    value = 2;
  }

  return value;
}
void passwordComplexityChecker(void) {
  std::string password = "";
    unsigned short int  passValue = 0;

    //General instructions
    std::cout << "\nFor a very strong password consider:\n - At least 8 characters\n - at least 2 numbers\n - at least 4 letters\n - At least 1 special character\n\n";

    //get user input
    do {
      password = userInput("Create a password: ");
    } while (password.length() == 0);
    

  // calculate the count of each type of element of the string
    unsigned short int numberCount = getMatchCount(R"(\d)", password);
    unsigned short int charCount = getMatchCount(R"([a-zA-Z])", password);
    unsigned short int specialCharCount = getMatchCount(R"([^a-zA-Z\d])", password);

    //Calculate the length of the string
    unsigned short int passwordLength = password.length();

    //assign a value to the stored password
    passValue = getValuePassword(password, numberCount, charCount, specialCharCount, passwordLength);    

    switch (passValue) {
      case 1:
        std::cout << "The password ‘" << password <<"’ is Weak\n\n";
        break;

      case 2:
        std::cout << "The password ‘" << password <<"’ is Moderate\n\n";
        break;

      case 3:
        std::cout << "The password ‘" << password <<"’ is Strong\n\n";
        break;

      case 4:
        std::cout << "The password ‘" << password <<"’ is Very Strong\n\n";
        break;
    }
  }


void employeeListRemoval(void) {
	//unsorted vector
  std::vector<std::string> employeeList;   
  std::string nameToDel = ""; 
  int index = 0;

  // //user inputs employees to the list
  // for (int i = 0; i < 5; i++) {
  //   employeeList.push_back(userInput("Please enter employee Name: "));    
  // }

  employeeList.push_back("John Smith");
  employeeList.push_back("Jaelynn Stuart");
  employeeList.push_back("Kaley Barajas");
  employeeList.push_back("Walter Collier");  
  employeeList.push_back("Cale Myers");

  
  //display list of employees
  std::cout << "\nThere are " << employeeList.size() << " employees: \n";
  for (auto e : employeeList) {
    std::cout << e << "\n";
  }

  //Delete name from list
  nameToDel = userInput("\nPlease enter employee name to be deleted: ");

  //TODO take into account lower case

  std::vector<std::string>::iterator iter = std::find(employeeList.begin(), employeeList.end(), nameToDel);

  if (iter != employeeList.end()){
    index = std::distance(employeeList.begin(), iter);    
    employeeList.erase(employeeList.begin() + index);
  } else {
    std::cout << "\nEmployee name doesn't exist.\n";
  }
  
  //display list of employees
  std::cout << "\nThere are " << employeeList.size() << " employees: \n";
  for (auto e : employeeList) {
    std::cout << e << "\n";
  }
}
