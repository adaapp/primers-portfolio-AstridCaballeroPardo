
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
  std::string msg = "";
  std::string c = "";
  char choice;
  float originalTemp = 0.0;
  float convertedTemp = 0.0;

  msg = "\nPlease enter the starting temperature: ";
  originalTemp = readFloat(msg);
  
  msg = "\nPress ‘C’ to convert from Fahrenheit to Centigrade.\nPress ‘F’ to convert from Centigrade to Fahrenheit.\nPress ‘K’ to convert from Centigrade to Kelvin.\nPress ‘G’ to convert from Kelvin to Centigrade.\nPress ‘D’ to convert from Fahrenheit to Kelvin.\nPress ‘H’ to convert from Kelvin to Fahrenheit.\n\nYour choice: ";
  choice = readChar(msg);

  switch(tolower(choice)) {
    case 'c': 
      convertedTemp = ftoc(originalTemp);
      label = "Fahrenheit";
      break;
    
    case 'f':
      convertedTemp = ctof(originalTemp);
      label = "Centigrade";
      break;
    
    case 'k':
      convertedTemp = ctok(originalTemp);
      label = "Centigrade";
      break;

    case 'g':
      convertedTemp = ktoc(originalTemp);
      label = "Kelvin";
      break;

    case 'd':
      convertedTemp = ftok(originalTemp);
      label = "Fahrenheit";
      break;

    case 'h':
      convertedTemp = ktof(originalTemp);
      label = "Kelvin";
      break;

    default:
      std::cout << "Not a valid input, unable to make conversion\n";
      return;
  }  

  std::cout << originalTemp << " degrees " << label << " is " << convertedTemp << "\n";
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
  std::string msg = "";
  float valueItem = 0.0;
  float subtotal = 0.0;
  float subTax = 0.0;
  const float TAX = 5.5;

  while (numberItems > 0){
    msg = msg = "Please enter a quantity for item " + std::to_string(i) + " (or 0 to finish): ";
    numberItems = readInteger(msg);    

    if (numberItems == 0) {
      break;   
    }
    else {      
      msg = "Please enter item " + std::to_string(i) + "’s cost: ";
      valueItem = readFloat(msg);     
      subtotal = costItems(numberItems, valueItem, subtotal);
      i++;
      std::cout << "\n\n";
    }
  }

  subTax = taxCal(subtotal, TAX);

  std::cout << "Thank you.\n\n"; 
  std::cout << "Subtotal: £" << roundTwoDecimal(subtotal) << "\n";  
  std::cout << "Shopping Tax: £" << roundTwoDecimal(subTax) << "\n\n";  
  std::cout << "Total: £" << roundTwoDecimal(subTax + subtotal) << "\n";	
}

