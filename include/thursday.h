/*
  functions used by sleepTimer()
*/

void sleepnow(int seconds = 10) {
  std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));
}

void sleepTimer(void) {
	std::cout << "start\n";
	sleepnow();
  std::cout << "end\n";
}


void joinDetachThreads(void) {
	std::cout << " - joinDetachThreads: not yet implemented\n\n";
}