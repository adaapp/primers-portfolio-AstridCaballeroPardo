//Global variables to be used in detachFunction()
int TIME1 = 5;
int TIME2 = 10;

void sleepTimer(int seconds = 10) {
	std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));	
}

/*
  functions used by joinDetachThreads()
*/ 
void timer1(int seconds) {  
  std::cout << "timer1 started \n";
  std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));	
  std::cout << "timer1 end \n";
}

void timer2(int seconds) {  
  std::cout << "timer2 started \n";
  std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));	
  std::cout << "timer2 end \n";
}

void thread_function1() {
  std::cout << "thread 1: " << std::this_thread::get_id() << " started\n";
  timer1(TIME1);
  std::cout <<  "thread 1: " << std::this_thread::get_id() << " ended\n";  
}

void thread_function2() {
  std::cout << "thread 2: " << std::this_thread::get_id() << " started\n";
  timer2(TIME2);
  std::cout <<  "thread 2: " << std::this_thread::get_id() << " ended\n";
}

void joinFunction() {
  std::cout << "Main thread: " << std::this_thread::get_id() << " started\n";
  std::thread thread1(&thread_function1);  
  std::thread thread2(&thread_function2);

  thread1.join();
  thread2.join();

  std::cout << "Main thread: " << std::this_thread::get_id() << " ended\n";
}


void detachFunction() {
  std::cout << "Main thread: " << std::this_thread::get_id() << " started\n";
  std::thread thread1(&thread_function1);  
  std::thread thread2(&thread_function2);

  thread1.detach();
  thread2.detach();

  std::cout << "Main thread: " << std::this_thread::get_id() << " ended\n";
}

void joinDetachThreads(void) {
  std::cout << "Part A:\n";
	//TODO add comment explaining the output and a short summary  about what happened.
  joinFunction();

  std::cout << "\n\n";

  std::cout << "Part B:\n";
  //TODO add comment explaining why the output (in this challenge) is  different to that of the previous (above).
  detachFunction();
}