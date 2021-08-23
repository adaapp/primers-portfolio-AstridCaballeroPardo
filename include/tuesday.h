/*
  functions used by passwordComplexityChecker()
*/

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
  std::string msg = "";
  unsigned short int  passValue = 0;

  //General instructions
  std::cout << "\nFor a very strong password consider:\n - At least 8 characters\n - at least 2 numbers\n - at least 4 letters\n - At least 1 special character\n\n";

  //get user input    
  msg = "Create a password: ";  
  password = readString(msg);  

  // calculate the count of each type of element of the string
  unsigned short int numberCount = getMatchCount(R"(\d)", password);
  unsigned short int charCount = getMatchCount(R"([a-zA-Z])", password);
  unsigned short int specialCharCount = getMatchCount(R"([^a-zA-Z\d])", password);

  //Calculate the length of the string
  unsigned short int passwordLength = password.length();

  //assign a value to the stored password
  passValue = getValuePassword(password, numberCount, charCount, specialCharCount, passwordLength);   

  //Display result
  msg = "The password ‘" + password  + "’ is "; 

  switch (passValue) {
    case 1:
      std::cout << msg << "Weak\n\n";
      break;

    case 2:
      std::cout << msg << "Moderate\n\n";
      break;

    case 3:
      std::cout << msg << "Strong\n\n";
      break;

    case 4:
      std::cout << msg << "Very Strong\n\n";
      break;
  }
}

/*
  functions used by employeeListRemoval()
*/

//accessing the vector by reference '&' to be able to acces it and manipulate it
int findEmpName(std::vector<std::string> &employeeList, std::string nameToDel) {
  int index = -1;
  std::vector<std::string>::iterator iter = std::find_if(employeeList.begin(), employeeList.end(),
  //[&] capture clause for lambda expressions, as '&' is not accompanied by a specific variable it means that the lambda will get all the variables by their reference, It could have been used the value instead of the reference with [=] instead of [&]. By reference only takes the address, in this case the address of the beginning of the string so it takes less memory than passing the value.
  [&](std::string &str) { 
      // if the size of the Nth element of the vector is not the same than the size of the string inputed by the user then we can easily know they don't match
      if ( str.size() != nameToDel.size() )
        return false;
    
    // if the size of the strings are the same then iterate over their characters and compare
      for (size_t i = 0; i < str.size(); ++i)
        if (std::tolower(str[i]) == std::tolower(nameToDel[i]))
          return true;
      return false;
    }
  );

  if (iter != employeeList.end()){
    index = std::distance(employeeList.begin(), iter);    
    return index;
  } 
  return index;
}

//accessing the vector by reference '&' to be able to acces it and manipulate it
void deleteEmployee(int index, std::vector<std::string> &myVector) {
   if (index >= 0) {
    myVector.erase(myVector.begin() + index);
  } else {
    std::cout << "\nEmployee name doesn't exist.\n";
  }
}

void employeeListRemoval(void) {
	//unsorted vector
  std::vector<std::string> employeeList;   
  std::string nameToDel = ""; 
  std::string msg = ""; 
  int index = 0;

  employeeList.push_back("John Smith");
  employeeList.push_back("Jaelynn Stuart");
  employeeList.push_back("Kaley Barajas");
  employeeList.push_back("Walter Collier");  
  employeeList.push_back("Cale Myers");

  
  //display list of employees
  msg = "\nThere are " + std::to_string(employeeList.size()) + " employees: \n";
  std::cout << msg;
  printStrElementsVector(employeeList);

  //Delete name from list
  msg = "\nPlease enter employee name to be deleted: ";
  nameToDel = readName(msg);
  // nameToDel = userInput("\nPlease enter employee name to be deleted: ");

  //find if inputed name matches an element of the vector, return positive integer if found (represents the index of the element inside the vector)
  index = findEmpName(employeeList, nameToDel);

  //delete employee if there is a match
  deleteEmployee(index, employeeList);
  
  //display list of employees
  msg = "\nThere are " + std::to_string(employeeList.size()) + " employees: \n";
  std::cout << msg;
  printStrElementsVector(employeeList);
}
