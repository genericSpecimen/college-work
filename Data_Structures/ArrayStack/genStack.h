#ifndef STACK
#define STACK

#include<vector>
template<typename T, int capacity>
class Stack {
private:
	std::vector<T> pool;
public:
	Stack() {
		pool.reserve(capacity);
	}
	void clear() {
		pool.clear();
	}
	bool isEmpty() const {
		return pool.empty();
	}
	T& top_element() {
		return pool.back();
	}
	T pop() {
		T element = pool.back();
		pool.pop_back();
		return element;
	}
	void push(const T& element) {
		pool.push_back(element);
	}
};

#endif
