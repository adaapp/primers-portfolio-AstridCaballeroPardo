void sleepTimer(int seconds = 10) {
	std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));	
}

void joinDetachThreads(void) {
	std::cout << " - joinDetachThreads: not yet implemented\n\n";
}