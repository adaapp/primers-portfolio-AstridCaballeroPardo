/*
  code that feeds carClass()
*/

class Car {
  private:
    std::string colour;
    std::string make;
    bool isEngineOn;    
    bool isLocked;

  public:
    //constructor
    Car() {
      colour = "Blue"; 
      make = "Honda"; 
      isEngineOn = false;    
      isLocked = false;
      }
    //overloading the constructor
    Car(std::string colour, std::string make, bool isEngineOn, bool isLocked) {
      setColour(colour);
      setMake(make);
      setIsEngineOn(isEngineOn);
      setIsLocked(isLocked);
    }

    //destructor
    ~Car() { }

    //Class Methods
    //Setters
    void setColour(std::string colour) {
      this->colour = colour;
    }

    void setMake(std::string make) {
      this->make = make;
    }

    void setIsEngineOn(bool isEngineOn) {
      this->isEngineOn = isEngineOn;
    }

    void setIsLocked(bool isLocked) {
      this->isLocked = isLocked;
    }

    //Getters
    std::string getColour(void) {
      return colour;
    }

    std::string getMake(void) {
      return make;
    }

    std::string getEngineOn(void) {
      if (isEngineOn) {
        return "Running";
      } else {
        return "Off";
      }      
    }

    std::string getLocked(void) {
      if (isLocked) {
        return "Locked";
      } else {
        return "Unlocked";
      }
    }

    //other Methods
    void engineOn(void) {
      if (!isEngineOn) {
        isEngineOn = true;        
      }      
    }

    //find this function redundant but I made it as the instrunctions say it is a MUST
    void engineOff(void) {
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
      std::cout << "Car Status: colour: " << getColour() << ", make: " << getMake() << ", engine: " << getEngineOn() << ", " << getLocked() << "\n";
    }
    
};


void menuCar(Car myCar) {  
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
        if (myCar.getEngineOn() == "Off") {
          myCar.engineOn();
          std::cout << "Turning the engine on\n";
        } else {
          std::cout << "Sorry, the engine is already on\n";
        }        
        break;
      
      case 2:
        if (myCar.getEngineOn() == "Running") {
          myCar.engineOff();
          std::cout << "Turning the engine off\n";
        } else {
          std::cout << "Sorry, the engine is already off\n";
        }         
        break;

      case 3:
        if (myCar.getLocked() == "Unlocked") {
          myCar.locked(true);
          std::cout << "Locking the car\n";
        } else {
          std::cout << "Sorry, the car is already locked\n";
        }        
        break;

      case 4:
      if (myCar.getLocked() == "Locked") {
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
    sleepTimer(2);

  } while (choiceNum != 0);
}


void carClass(void) {
  //create instance object
  Car car1 = Car();    

  //call menu 
  menuCar(car1);   
}


/*
  code that feeds areaOf()
*/

//Abstract class
class Shape {
  protected:  
    float side = 0;
    float radious = 0;    
    float height = 0;
    float base = 0;

  public:
  //pure virtual function - interface
    virtual float size() = 0;    

    //setters
    void setRadious(float radious) {
      this->radious = radious;    
    }

    void setSide(float side) {
      this->side = side;    
    }

    void setHeight(float height) {
      this->height = height;    
    }

    void setBase(float base) {
      this->base = base;    
    } 

    //getters
    float getRadious(void){
      return radious;
    }

    float getSide(void){
      return side;
    }

    float getHeight(void){
      return height;
    }

    float getBase(void){
      return base;
    }
};

//using inheritance
class Circle: public Shape {
  public:
    //constructor
    Circle() {       
      }
    //overloading the constructor
    Circle(float radious) {
      setRadious(radious);      
    }

    //destructor
    ~Circle() { }

    //implement size() specifically for Circle
    float size() {
      return  M_PIl * std::pow(radious, 2.0);
    }
};

class Square: public Shape {
  public:
    //constructor
    Square() {       
      }
    //overloading the constructor
    Square(float side) {
      setSide(side);      
    }

    //destructor
    ~Square() { }

    //implement size() specifically for Square
    float size() {
      return std::pow(side, 2.0);
    }
};

class Rectangle: public Shape {
  public:
    //constructor
    Rectangle() {       
      }
    //overloading the constructor
    Rectangle(float side, float height) {
      setSide(side);    
      setHeight(height);    
    }

    //destructor
    ~Rectangle() { }

    //implement size() specifically for Rectangle
    float size() {
      return (side * height);
    }
};

class Triangle: public Shape {
  public:
    //constructor
    Triangle() {       
      }
    //overloading the constructor
    Triangle(float side, float height) {
      setSide(side);    
      setHeight(height);    
    }

    //destructor
    ~Triangle() { }

    //implement size() specifically for Triangle
    float size() {
      return ((side * height) / 2.0);
    }
};

class Trapezoid: public Shape {
  public:
    //constructor
    Trapezoid() {       
      }
    //overloading the constructor
    Trapezoid(float base, float height, float side) {
      setSide(side);    
      setHeight(height);    
      setBase(base);
    }

    //destructor
    ~Trapezoid() { }

    //implement size() specifically for Trapezoid
    float size() {
      return (((base + side) / 2) * height);
    }
};

void areaOf(void) {
  //using the default Circle's constructor
	Circle myCircle = Circle();
  myCircle.setRadious(4.5);
  std::cout << "\nArea of Circle (r = "<< myCircle.getRadious() << "): "<< myCircle.size() << "\n";

  //using the default Square's constructor
  Square mySquare = Square();
  mySquare.setSide(6.1);
  std::cout << "Area of Square (a = "<< mySquare.getSide() << "): "<< mySquare.size() << "\n";

  //using the overloaded Reactangle's constructor
  Rectangle myRectangle(4, 5.9);  
  std::cout << "Area of Rectangle (w = "<< myRectangle.getSide() << ", l = " << myRectangle.getHeight() << "): "<< myRectangle.size() << "\n";

  //using the overloaded Triangle's constructor
  Triangle myTriangle(8,12);
  std::cout << "Area of Triangle (b = "<< myTriangle.getSide() << ", h = " << myTriangle.getHeight() << "): "<< myTriangle.size() << "\n";

  //using the overloaded Trapezoid's constructor
  Trapezoid myTrapezoid(14, 7.5, 6);
  std::cout << "Area of Trapezoid (b = "<< myTrapezoid.getBase() << ", h = " << myTrapezoid.getHeight() << ", a = " << myTrapezoid.getSide() << "): "<< myTrapezoid.size() << "\n";
}