# Primer Portfolio

## Section 1 - Primer Challenges
### Primer 1 - Fahrenheit / Centigrade Conversion
This challenge requires us to allow a user to enter a value before selecting whether to convert it from:

Fahrenheit to Centigrade
Centigrade to Fahrenheit
Kelvin to Centigrade
Centigrade to Kelvin
Fahrenheit to Kelvin
Kelvin to Fahrenheit

As part of the initial design six functions that implement the formulas of each conversion were needed.
 

To help complete this challenge I needed to break the overall problem down into the following main tasks: 
* Get data from the user
* Verify the data is in a suitable format
* Create a method to convert F->C represented by 'C'
* Create a method to convert C->F represented by 'F'
* Create a method to convert C->K represented by 'K'
* Create a method to convert K->C represented by 'G'
* Create a method to convert F->K represented by 'D'
* Create a method to convert K->F represented by 'H'
* Display conversion

 
#### Reflection (as well as issues, challenges & resolutions)
To solve the primer I started by getting the input and testing it, then displaying the options and testing it, then writing the fucntions to perform the conversions for C->F and F->C and testing it, followed by displaying the resulted conversion. Finally, I added the 'Additional revisions' requirements to the code(i.e Kelvin, etc).

Once I had a working version that met the overall requirements I went into working on validation, such as making sure the user entered a valid temperature value (isNumber()) or a valid conversion choice (readChar()). My next step was improving readability, an example of that was creating a variable called 'msg' that will hold the message to be display to the user. 

One particular case where I couldn't use the message variable was when printing the result, because in order to create the message I used 'std::to_string' to covert the temperature values to string - in order to concatenate them to the final message - and 'std::to_string' by default has the precision of 6 decimals so instead of printing '60.1' it was printing:

![image info](./screenshots/Primer1_DisplayToString.png)

I then played with  'std::cout.precision(3)' but this approach will also affect the converted temperature to have only two decimals (in that case I needed all the decimals):

![image info](./screenshots/Primer1_DisplayPrecision.png)

The other solutions was to explicitly define the precision to each temperature value (original and converted) making the message a longer line than just writing directly to 'std::cout'. I decided to not create a message and leave it as:

![image info](./screenshots/Primer1_DisplayConversion.png)

Another challenge was implementing the helper function isNumber() as I used regex to do the validation.I have used regex in the past with SQL (working as a Data officer) and also during Ada's Lunchpad but not on a regular basis, so getting the pattern right still takes me good time of trial and error.

The other challenge was to spot parts of the code that can be taken out and become a function on their own in order to improve usability, readability and design. Examples of that were the userInput() and readFloat(). Creating those those functions made fahrenheitCentigradeConversion() shorter and easy to read and I was able to reuse some of those functions in other primers such as primer2.

### Primer 2 - Self-service Checkout
This challenge requires us to create a selfservice checkout program where the user inputs the quantity of a specific item and its cost (this can be done 0 or many times). The result is the calculation of the total purchase including tax.

As part of the initial design two functions that implemented the accumulative calculation of the cost of the items and the calculation of the tax.

To help complete this challenge I needed to break the overall problem down into the following main tasks: 
* Get data from the user
* Verify the data is in a suitable format
* Create the methods to implement the basic calculations (subtotal and tax)
* Display the purchase details (subtotal, tax and total)

#### Reflection (as well as issues, challenges & resolutions)
To solve the primer I started by getting the input of the item's quantyties and testing it, followed by getting the input of the cost of the item and testing it. then I worked on creating the brances to check the conditions (0 to finish the purchases, else to keep purchasing) and test it. Lastly, I implemented the calculation of the subtotal, tax and total and their display.

After the primer met the overall requirements then I moved to add the 'Additional revisions' requirements to the code (rounding to two decimal places). 

This primer brought a similar challenge that I faced on primer1, I used 'std::cout.precision()' but the result didn't always result in two decimal places. So I implemented a helper function called roundTwoDecimal() which only two decimals if the original value has more than two decimals.

As I had already implemented userInput() I was able to reuse that function to get the input for the user with few lines of code. I was also able to reuse readFloat() making easy the input validation.

### Primer 3 - passwordComplexityChecker
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque ac elit in magna porttitor convallis. Ut eu justo rutrum, luctus lorem a, pretium quam. Sed ut commodo lectus. Vestibulum ut ligula lorem. Nulla mattis varius ex ac luctus. Aenean nec laoreet enim. Sed lorem erat, vestibulum ut faucibus vel, pellentesque nec felis. Vivamus metus tellus, pretium eu sodales interdum, fringilla ut mauris. ....

#### Reflection (as well as issues, challenges & resolutions)
The biggest issue was related to testing the areas my solution failed, originally, I tested to see if it worked - however, it wasn’t until I tried to break it that I found some of the more serious issues with my design and implementation.  For example, ...

### Primer 4 - employeeListRemoval
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque ac elit in magna porttitor convallis. Ut eu justo rutrum, luctus lorem a, pretium quam. Sed ut commodo lectus. Vestibulum ut ligula lorem. Nulla mattis varius ex ac luctus. Aenean nec laoreet enim. Sed lorem erat, vestibulum ut faucibus vel, pellentesque nec felis. Vivamus metus tellus, pretium eu sodales interdum, fringilla ut mauris. ....

#### Reflection (as well as issues, challenges & resolutions)
The biggest issue was related to testing the areas my solution failed, originally, I tested to see if it worked - however, it wasn’t until I tried to break it that I found some of the more serious issues with my design and implementation.  For example, ...

### Primer 5 - phoneDirectory
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque ac elit in magna porttitor convallis. Ut eu justo rutrum, luctus lorem a, pretium quam. Sed ut commodo lectus. Vestibulum ut ligula lorem. Nulla mattis varius ex ac luctus. Aenean nec laoreet enim. Sed lorem erat, vestibulum ut faucibus vel, pellentesque nec felis. Vivamus metus tellus, pretium eu sodales interdum, fringilla ut mauris. ....

#### Reflection (as well as issues, challenges & resolutions)
The biggest issue was related to testing the areas my solution failed, originally, I tested to see if it worked - however, it wasn’t until I tried to break it that I found some of the more serious issues with my design and implementation.  For example, ...

### Primer 6 - dataFileParser
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque ac elit in magna porttitor convallis. Ut eu justo rutrum, luctus lorem a, pretium quam. Sed ut commodo lectus. Vestibulum ut ligula lorem. Nulla mattis varius ex ac luctus. Aenean nec laoreet enim. Sed lorem erat, vestibulum ut faucibus vel, pellentesque nec felis. Vivamus metus tellus, pretium eu sodales interdum, fringilla ut mauris. ....

#### Reflection (as well as issues, challenges & resolutions)
The biggest issue was related to testing the areas my solution failed, originally, I tested to see if it worked - however, it wasn’t until I tried to break it that I found some of the more serious issues with my design and implementation.  For example, ...

..  

---
## Section 2 - Programming Paradigms
### Programming Paradigms
Simply put, a programming paradigm, for example, procedural, object-oriented, functional, structured, declarative, imperative and event driven can be described as a specific approach used when trying to solve a problem.  Although many programming languages can (and do) support multiple paradigms this discussion will focus more specifically on the possible benefits with examples of the potential differences and similarities of five from the above list. These are ...

---
## Section 3 - Continued Professional Development
### Benefits of becoming a Polyglot Programmer
Vestibulum vitae semper sem. Duis leo leo, suscipit at felis non, pellentesque varius massa. Sed sit amet orci nibh. Morbi scelerisque faucibus elit, vitae mollis turpis finibus eget. In convallis euismod nunc non imperdiet. Duis ultricies pulvinar lorem, sed molestie nunc porta at. Aenean arcu ante, efficitur nec felis sed, feugiat iaculis turpis. Vestibulum eu elementum diam. Quisque nec tortor auctor, scelerisque ante vitae, fringilla tellus.

Quisque ligula lectus, efficitur quis malesuada sit amet, malesuada sed nibh. In lorem erat, elementum quis tempus nec, rhoncus ac ante. Mauris suscipit massa tempor, pulvinar neque vel, gravida nulla. Donec massa diam, molestie in diam nec, vulputate faucibus ligula. Aliquam erat volutpat. Aliquam sit amet dui ligula. Nullam euismod eros ultrices magna convallis lobortis. Proin convallis placerat tincidunt. Quisque interdum, nisi id egestas luctus, augue libero lacinia urna, sit amet tempus nisl sem nec quam. Vestibulum interdum urna mauris, vel dignissim nisi dignissim egestas. Donec volutpat dictum dui, at egestas sem tristique nec.
