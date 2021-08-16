float ftoc(float f) {
  return ((f - 32) * 5 / 9); //Fahrenheit to Centigrade.
}

float ctof(float c) {
  return ((c * 9 / 5) + 32); //Centigrade to Fahrenheit.
}

void fahrenheitCentigradeConversion(void) {
	std::string temp;
  std::string label;
  float ot = 0.0;
  float t = 0.0;

  std::cout << "\nPlease enter the starting temperature: ";
  std::getline(std::cin, temp);
  ot = stof(temp);

  std::cout << "\nPress ‘C’ to convert from Fahrenheit to Centigrade";
  std::cout << "\nPress ‘F’ to convert from Centigrade to Fahrenheit.\n\n";

  std::cout << "\nYour choice: ";
  std::getline(std::cin, temp);

  if(temp == "C" || temp == "c") {
    t = ftoc(ot);
    label = "Fahrenheit";
  }

  if(temp == "F" || temp == "f") {
    t = ctof(ot);
    label = "Centigrade";
  }

  std::cout << ot << " degrees " << label << " is = " << t << "\n";
}


void selfServiceCheckout(void) {
	std::cout << " - selfServiceCheckout: not yet implemented\n\n";
}

