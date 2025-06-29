#include <iostream>
#include <future>
 
int asyncTask() {
    return 58;
}
 
int main() {
    std::packaged_task<int()> task(asyncTask);//std::packaged_task可移动但不可复制
    std::future<int> result = task.get_future();
    std::thread t(std::move(task));//可移动但不可复制，用移动语义move
    t.join();
    std::cout << "The result is: " << result.get() << std::endl;
    return 0;
}