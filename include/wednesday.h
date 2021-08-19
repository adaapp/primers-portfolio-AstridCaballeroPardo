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
  int maxLenLast = 0;
  int maxLenSalary = 0;
  std::string line;
  std::string initial;
  std::string last;
  std::string salary;

	//open file
  std::ifstream fileObject;
  fileObject.open("employee.csv");   

  while (fileObject.good()) {
    getline(fileObject, line);
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
    //std::cout << last.size() << "\n";   
    
  } 

  //std::cout << "\nMax len last: "<< maxLenLast << "\n";
  //std::cout << "\nMax len salary: "<< maxLenSalary << "\n";

  //TODO Ongoing
  std::cout << "\nInital  \t"<<  "Last      \t" << "Salary  \n";
  std::cout << std::string(8, '-') << "\t" <<  std::string(maxLenLast, '-') << "\t" << std::string(maxLenSalary, '-') << "\n";

  //TODO cout the data
  // manipulate the sstream
  //print column and count its length to subtract from the max len and add the remaining spaces
}