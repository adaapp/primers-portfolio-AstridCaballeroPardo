
/* 
  Helper functions
*/
std::string userInput(std::string prompt1, int iter = -1, std::string prompt2 = " ") {
  std::string reply = "";
  if (prompt2 != " " && iter > 0) {
    std::cout << prompt1 << iter << prompt2; 
  } 
  else if((prompt2 != " " && iter == -1)) {
    std::cout << prompt1 << prompt2; 
  }
  else if((prompt2 == " " && iter > 0)){
    std::cout << prompt1 << iter; 
  }
  else {
    std::cout << prompt1; 
  }   
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
  float v = deflt;
  if (isNumber(str)) {
    v = stof(str);
  }  
  return v;
}

int stringToInt(std::string str, int deflt = -1) {
  int v = deflt;
  if (isNumber(str)) {
    v = stoi(str);
  }    
  return v;
}

/*
  functions used by fahrenheitCentigradeConversion()
*/
float ftoc(float f) {
  return ((f - 32) * 5 / 9); //Fahrenheit to Centigrade.
}

float ctof(float c) {
  return ((c * 9 / 5) + 32); //Centigrade to Fahrenheit.
}

float ctok(float c) {
  return (c + 273.15); //Centigrade to Kelvin.
}

float ktoc(float k) {
  return (k - 273.15); // Kelvin to Centigrade.
}

float ftok(float f) {
  return ((f + 459.67) * 5 / 9); //Fahrenheit to Centigrade.
}

float ktof(float k) {
  return ((k * 9 / 5) - 459.67); //Centigrade to Fahrenheit.  
}

void fahrenheitCentigradeConversion(void) {
	std::string temp;
  std::string label;
  std::string c = "";
  char choice;
  float ot = 0.0;
  float t = 0.0;

  //ot = stringToFloat(userInput("\nPlease enter the starting temperature: "));
  do {
    ot = stringToFloat(userInput("\nPlease enter the starting temperature: "));
  } while (ot == -1);
  
  c = userInput("\nPress ‘C’ to convert from Fahrenheit to Centigrade.\nPress ‘F’ to convert from Centigrade to Fahrenheit.\nPress ‘K’ to convert from Centigrade to Kelvin.\nPress ‘G’ to convert from Kelvin to Centigrade.\nPress ‘D’ to convert from Fahrenheit to Kelvin.\nPress ‘H’ to convert from Kelvin to Fahrenheit.\n\nYour choice: ");
 
  choice = c[0];

  switch(tolower(choice)) {
    case 'c': 
      t = ftoc(ot);
      label = "Fahrenheit";
      break;
    
    case 'f':
      t = ctof(ot);
      label = "Centigrade";
      break;
    
    case 'k':
      t = ctok(ot);
      label = "Centigrade";
      break;

    case 'g':
      t = ktoc(ot);
      label = "Kelvin";
      break;

    case 'd':
      t = ftok(ot);
      label = "Fahrenheit";
      break;

    case 'h':
      t = ktof(ot);
      label = "Kelvin";
      break;

    default:
      std::cout << "Not a valid input, unable to make conversion\n";
      return;
  }  

  std::cout << ot << " degrees " << label << " is = " << t << "\n";
}

/*
  functions used by selfServiceCheckout()
*/

//Function that calculates the cost of a number of same items
float costItems(int numberItems, float valueItem, float subtotal) {
  return (numberItems * valueItem) + subtotal;
}

//Function that calculates the tax based on the subtotal
float taxCal(float subtotal, float tax) {  
  return (subtotal * tax) / 100;
}

void selfServiceCheckout(void) {
	int i = 1;
  int numberItems = 1;
  float valueItem = 0.0;
  float subtotal = 0.0;
  std::string tempStr = "";
  const float tax = 5.5;

  while (numberItems > 0){
    do {
      tempStr = userInput("Please enter a quantity for item ", i, "(or 0 to finish): \n");
    } while (!isNumber(tempStr) || (tempStr.find('.') != std::string::npos));

    numberItems = stringToInt(tempStr);    

    if (numberItems == 0) {
      std::cout << "Thank you.\n\n";
      std::cout << "Subtotal: £" << subtotal << "\n";    
    }
    else {
      do {
        tempStr = userInput("Please enter item ", i, "’s cost: ");
      } while (!isNumber(tempStr));

      valueItem = stringToFloat(tempStr);     
      subtotal = costItems(numberItems, valueItem, subtotal);
      i++;
      std::cout << "\n\n";
    }
  }
  //TODO revisit lines with std::cout.precision()
  std::cout.precision(2);
  std::cout << "Shopping Tax: £" << taxCal(subtotal, tax) << "\n\n";
  std::cout.precision(3);
  std::cout << "Total: £" << taxCal(subtotal, tax) + subtotal << "\n";
	
}

