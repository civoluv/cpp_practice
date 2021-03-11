#ifndef HEAP_H_
#define HEAP_H_

#include <vector>
#include <functional>

template <typename T>
struct HeapComparer {
  bool(*Comparer)(T, T);
};

template <typename T>
class Heap {
public :
  
  Heap() {}
  /*Heap(HeapComparer<T>* comparer) {*/
  Heap(std::function<bool (T,T)>& fn) 
    : comparer_(fn)
  {
    //comparer_ = fn;
  }
  bool Contains(T t) {
    return std::find(heap_.begin(), heap_.end(), t) != heap_.end();
  }
  bool Empty() { return 0 == heap_.size(); }
  T Pop() {
    T top = heap_.front();
    std::pop_heap(heap_.begin(), heap_.end());
    heap_.pop_back();
    return top;
  }
  void Push(T t) {
    heap_.push_back(t);
    std::push_heap(heap_.begin(), heap_.end());
  }
  void ReSort() {
    std::make_heap(heap_.begin(), heap_.end());
  }
private:
  std::function<bool (T, T)>& comparer_;// bool (*comparer_)(T);
  std::vector<T> heap_;
};

#endif