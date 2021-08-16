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

float tempInput(){
  std::string temp;
  std::getline(std::cin, temp);
  return stof(temp);
}

void fahrenheitCentigradeConversion(void) {
	std::string temp;
  std::string label;
  char choice;
  float ot = 0.0;
  float t = 0.0;

  std::cout << "\nPlease enter the starting temperature: ";
  try {
    ot = tempInput();
  }
  catch(...) {
    std::cout << "You must enter a number.\n";
    return;
  } 

  std::cout << "\nPress ‘C’ to convert from Fahrenheit to Centigrade.";
  std::cout << "\nPress ‘F’ to convert from Centigrade to Fahrenheit.";
  std::cout << "\nPress ‘K’ to convert from Centigrade to Kelvin.";
  std::cout << "\nPress ‘G’ to convert from Kelvin to Centigrade.";
  std::cout << "\nPress ‘D’ to convert from Fahrenheit to Kelvin";
  std::cout << "\nPress ‘H’ to convert from Kelvin to Fahrenheit.\n\n";

  std::cout << "\nYour choice: ";
  std::cin >> choice;

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
float costItems(int numberItems, float valueItem) {
  return numberItems * valueItem;
}

float taxCal(float subtotal) {
  const float tax = 5.5;
  return (subtotal * tax) / 100;
}

void selfServiceCheckout(void) {
	bool buying = true;
  int i = 1;
  int numberItems = 0;
  float valueItem = 0.0;
  float subtotal = 0.0;

  while (buying){
    std::cout << "Please enter a quantity for item "<< i << "(or 0 to finish): \n";
    std::cin >> numberItems;

    if (numberItems == 0) {
      std::cout << "Thank you.\n\n";
      std::cout << "Subtotal: £" << subtotal << "\n";    buying = false;
    }
    else {
      std::cout << "Please enter item " << i << "’s cost: ";
      std::cin >> valueItem;
      subtotal += costItems(numberItems, valueItem);
      i++;
      std::cout << "\n\n";
    }
  }
  //TODO revisit lines with std::cout.precision()
  std::cout.precision(2);
  std::cout << "Shopping Tax: £" << taxCal(subtotal) << "\n\n";
  std::cout.precision(3);
  std::cout << "Total: £" << taxCal(subtotal) + subtotal << "\n";
}

