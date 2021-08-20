/*
  code that feeds carClass()
*/

class car {
  private:
    std::string colour;
    std::string make;
    bool isEngineOn = false;    
    bool isLocked = false;

  public:
    //constructor
    car() {
      colour = "Blue"; 
      make = "Honda"; 
      }
    //overloading the constructor
    car(std::string colour, std::string make) {
      set_colour(colour);
      set_make(make);
    }

    //destructor
    ~car() { }

    //Class Methods
    //Setters
    void set_colour(std::string colour) {
      colour = colour;
    }

    void set_make(std::string make) {
      make = make;
    }

    //Getters
    std::string get_colour(void) {
      return colour;
    }

    std::string get_make(void) {
      return make;
    }

    std::string get_engine_on(void) {
      if (isEngineOn) {
        return "On";
      } else {
        return "Off";
      }      
    }

    std::string get_locked(void) {
      if (isLocked) {
        return "Locked";
      } else {
        return "Unlocked";
      }
    }

    //other Methods
    void engine_on(void) {
      if (!isEngineOn) {
        isEngineOn = true;        
      }      
    }

    //find this function redundant but I made it as the instrunctions say it is a MUST
    void engine_off(void) {
      if (isEngineOn) {
        isEngineOn = false;        
      }      
    }

    void locked(bool) {
      if (isLocked) {
        isLocked = false;
      } else {
        isLocked = true;
      }
    }

    void status (void) {
      std::cout << "Car Status: colour: " << get_colour() << ", make: " << get_make() << ", engine: " << get_engine_on() << ", " << get_locked() << "\n";
    }
    
};


void menuCar(car myCar) {  
  int choiceNum = -1;
  std::string choiceStr;  

  //Make Menu iterable until user chooses 0 (exit)
  do {
    std::cout << "\n";
    //print status of the instance
    myCar.status();
    //print menu options
    std::cout << "1. Turn Engine On\n";
    std::cout << "2. Turn Engine Off\n";
    std::cout << "3. Lock Car\n";
    std::cout << "4. Unlock Car\n";
    //keep asking until valid input from user
    do {
      std::cout << "Please select an option (or 0 to finish): ";      
      std::getline(std::cin, choiceStr);
    } while (!std::regex_match(choiceStr, std::regex(R"([0-4])") )); 
    //convert string to int
    choiceNum = stoi(choiceStr);

    //Run actions to deliver user's choice
    switch(choiceNum) {
      case 1:
        if (myCar.get_engine_on() == "Off") {
          myCar.engine_on();
          std::cout << "Turning the engine on\n";
        } else {
          std::cout << "Sorry, the engine is already on\n";
        }        
        break;
      
      case 2:
        if (myCar.get_engine_on() == "On") {
          myCar.engine_off();
          std::cout << "Turning the engine off\n";
        } else {
          std::cout << "Sorry, the engine is already off\n";
        }         
        break;

      case 3:
        if (myCar.get_locked() == "Unlocked") {
          myCar.locked(true);
          std::cout << "Locking the car\n";
        } else {
          std::cout << "Sorry, the car is already locked\n";
        }        
        break;

      case 4:
      if (myCar.get_locked() == "Locked") {
          myCar.locked(false);
          std::cout << "Unlocking the car\n";
        } else {
          std::cout << "Sorry, the car is already unlocked\n";
        }         
        break;

      case 0:
        std::cout << "Exiting\n";
        break;      
    }
    // give some time for the user to read output and reuse primer 7
    sleepTimer(3);

  } while (choiceNum != 0);
}


void carClass(void) {
  //create instance object
  car car1 = car();    

  //call menu 
  menuCar(car1);   
}


void areaOf(void) {
		std::cout << " - areaOf: not yet implemented\n\n";
}