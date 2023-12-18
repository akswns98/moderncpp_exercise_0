#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>


int main() {
	

	std::atomic<int> x1 = 0;

	auto t1 = std::chrono::steady_clock::now();

	std::thread th1([&]() {
		for (int i = 0; i < 100'000'000; ++i)
			x1.fetch_add(1);
		});
	std::thread th2([&]() {
		for (int i = 0; i < 100'000'000; ++i)
			x1.fetch_add(1);
		});
	// do something


	if (th1.joinable()) {
		th1.join();
	}

	if (th2.joinable()) {
		th2.join();
	}

	auto t2 = std::chrono::steady_clock::now();

	std::cout << x1 << '\n';
	auto dt= std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	std::cout << "Took "<<dt.count() <<" ms"<< std::endl;

	int x2 = 0;
	std::mutex m;     //atomic 대비 느리지만 어떤 영역이든 원자성 

	auto t3 = std::chrono::steady_clock::now();

	std::thread th3([&]() {
		for (int i = 0; i < 100'000'000; ++i) {
			std::lock_guard<std::mutex> lck(m);
			x2 += 1;
		}
		});
	std::thread th4([&]() {
		for (int i = 0; i < 100'000'000; ++i) {
			std::lock_guard<std::mutex> lck(m);
			x2 += 1;
		}
		});
	// do something


	if (th3.joinable()) {
		th3.join();
	}

	if (th4.joinable()) {
		th4.join();
	}

	auto t4 = std::chrono::steady_clock::now();

	std::cout << x2 << '\n';
	auto dt2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
	std::cout << "Took " << dt2.count() << " ms" << std::endl;

	return 0;
}