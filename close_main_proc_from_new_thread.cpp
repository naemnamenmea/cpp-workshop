#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>

class ThreadAggregator
{
public:
  void ThreadFunc() {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(3s);
    CloseMainProcess();
  }

  void CloseMainProcess()
  {
    std::exit(1);
  }
};

int main()
{
  ThreadAggregator ta;
  std::thread thread(&ThreadAggregator::ThreadFunc, std::ref(ta));
  thread.detach();
  for (int i = 0; i < 10; ++i)
  {
    std::cout << "String from main proc" << std::endl;
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);
  }

  return 0;
}