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
	std::cout << " - dataFileParser: not yet implemented\n\n";
}