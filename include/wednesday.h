/*
  functions used by phoneDirectory()
*/

std::string readPhoneBookInput(std::string prompt) {
  std::string input;
  do {
    input = userInput(prompt);
  } while (input.length() == 0 || ((getMatchCount(R"(\d)", input) > 0) && (getMatchCount(R"([a-zA-Z])", input) > 0)));
  return input; 
}

void stringToLower(std::string &str) { 
  for (size_t i = 0; i < str.size(); i++) {
    str[i] = std::tolower(str[i]);     
    } 
}

int countLine(std::ifstream &inputFile) {
  std::string line;
  int countLine = 0.0;

  while (getline(inputFile, line)){
    countLine++;
  }
  return countLine;
}

void storeMatchInput(std::vector<std::string> &myVector, std::ifstream &inputFile, std::string inputStr) {
  std::string line;
  std::string lowerLine;
  std::string info;
  const char COMMA = ',';  

  while (getline(inputFile, line)) {
      //make a copy of line
      lowerLine = line; 
      //convert copy to lower case   
      stringToLower(lowerLine);
      //match substring of the copy with user input    
      if (lowerLine.find(inputStr) != std::string::npos) {  
        //store matching line in sstream to be able to manipulate the string line   

        //get information from the original 'line' that is not lower case 
        std::stringstream sso(line);
        // split the string with a delimiter
        while (std::getline(sso, info, COMMA)) {  
          //sotre name and phone in vector  
          myVector.push_back(info);     
        }
      }    
    }
}


void phoneDirectory(void) {
	std::string msg;
  std::string text;
  std::vector<std::string> match;  
  int countLn = 0;

	msg = "Please enter a name or number to search: "; 
  text = readPhoneBookInput(msg);  

  //convert user input to lower case
  stringToLower(text);

  //open file
  std::ifstream fileObject;
  fileObject.open("phoneBook.csv");    

  //check if the file opened succesfully
  if (!fileObject.fail()) { 
    //calculate the number of records in the file
    countLn = countLine(fileObject);
    std::cout << "Searching "<< countLn << " records … \n\n";

    //Read file again
    //https://stackoverflow.com/a/28903431
    fileObject.clear();
    fileObject.seekg(0);
    
    //search in file
    storeMatchInput(match, fileObject, text);
 
    //check if vector has information stored
    if (match.empty()) {
      std::cout << "Sorry, no contact details found" << "\n";
    } else {
      //print contact details 
      std::cout << "Contact details:" << "\n";
      for (int i = 0; i < (match.size()- 1); i += 2) {  
        std::cout << match.at(i) << ", T: " << match.at(i + 1) << "\n";
      }
    }    
    //close file
    fileObject.close();
  } else {
    std::cerr << "Opening file failed\n";
  }
}


void dataFileParser(void) {
	  const char COMMA = ',';    
  const int INITIAL = 8;
  const int LAST = 5;
  const int SALARY = 7;

  int maxLenLast = 0;
  int maxLenSalary = 0;
  std::string line;
  std::string initial;
  std::string last;
  std::string salary;

	//open file
  std::ifstream fileObject;
  fileObject.open("employee.csv");   

  //check if the file opened succesfully
  if (!fileObject.fail()) { 
    // calculate the max lengths of 2nd and 3rd columns
    while (getline(fileObject, line)) {
      //store line into sstream for string manipulation
      std::stringstream sso(line);
          
      getline(sso, initial, COMMA);
      getline(sso, last, COMMA);
      //Calculate the max length of second column
      if (maxLenLast < last.size()) {
        maxLenLast = last.size();
      }
      getline(sso, salary, COMMA);
      //Calculate the max length of third column
      if (maxLenSalary < salary.size()) {
        maxLenSalary = salary.size();
      }      
      
    } 
  
    //display headers
    std::cout << "\n";
    std::cout << std::left << std::setw(INITIAL) << "Initial" << "\t";
    if (maxLenLast < LAST) {
      std::cout << std::left << std::setw(LAST) << "Last"  << "\t";
    } else {
      std::cout << std::left << std::setw(maxLenLast + 1) << "Last" << "\t";
    }
    if (maxLenSalary < SALARY) {
      std::cout << std::left << std::setw(SALARY) << "Salary" << "\n";
    } else {
      std::cout << std::left << std::setw(maxLenSalary + 1) << "Salary" << "\n";
    }

    //display '-' under headers
    std::cout << std::setfill('-') << std::setw(INITIAL) << "-" << "\t";
    if (maxLenLast < LAST) {
      std::cout << std::setw(LAST) << "-" << "\t";
    } else {
      std::cout << std::setw(maxLenLast + 1) << "-" << "\t";
    }
    if (maxLenSalary < SALARY) {
      std::cout << std::setw(SALARY) << "-" << "\n";
    } else {
      std::cout << std::setw(maxLenSalary + 1) << "-" << "\n";
    }

    //Read file again
    //https://stackoverflow.com/a/28903431
    fileObject.clear();
    fileObject.seekg(0);
    

    //Display each record
    while (getline(fileObject, line)) {    
      //store line into sstream for string manipulation
      std::stringstream sso(line);
            
      getline(sso, initial, COMMA); 
      //get first letter of initial
      initial = initial.front();
      getline(sso, last, COMMA);
      getline(sso, salary, COMMA);

      std::cout << std::setfill(' ') << std::left << std::setw(INITIAL) << initial + "."  << "\t";
      if (maxLenLast < LAST) {
        std::cout << std::left << std::setw(LAST) << last  << "\t";
      } else {
        std::cout << std::left << std::setw(maxLenLast + 1) << last << "\t";
      }
      if (maxLenSalary < SALARY) {
        std::cout << std::left << std::setw(SALARY) << salary << "\n";
      } else {
        std::cout << std::left << std::setw(maxLenSalary + 1) <<salary << "\n";
      }
    }
    //close file
    fileObject.close();
  } else {
    std::cerr << "Opening file failed\n";
  }
}