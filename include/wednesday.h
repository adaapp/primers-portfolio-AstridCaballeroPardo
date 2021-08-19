void phoneDirectory(void) {
	std::string line;
  const char COMMA = ',';
  std::string info;
  std::vector<std::string> match;
  int countLine = 0;

	std::string text = userInput("Please enter a name or number to search: ");  

  //open file
  std::ifstream fileObject;
  fileObject.open("phoneBook.csv");    

  //search in file
  while (getline(fileObject, line)) {
    if (line.find(text) != std::string::npos) {  
      //store matching line in sstream to be able to manipulate the string line    
      std::stringstream sso(line);
      // split the string with a delimiter
      while (std::getline(sso, info, COMMA)) {        
        match.push_back(info);      
      }
    }   
    countLine ++;
  }

  std::cout << "Searching "<< countLine << " records … \n\n";

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
  

//loop
  while (getline(fileObject, line)) {    
    //store line into sstream for string manipulation
    std::stringstream sso(line);
          
    getline(sso, initial, COMMA); 
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
}