class SpecialQueue {

  public:
    queue<int> q;
    deque<int> minDeque;
    deque<int> maxDeque;
    void enqueue(int x) {
        q.push(x);

        // Maintain maxDeque: remove smaller elements from back
        while (!maxDeque.empty() && maxDeque.back() < x)
            maxDeque.pop_back();
        maxDeque.push_back(x);

        // Maintain minDeque: remove larger elements from back
        while (!minDeque.empty() && minDeque.back() > x)
            minDeque.pop_back();
        minDeque.push_back(x);
    }

    void dequeue() {
        if (q.empty()) return;

        int front = q.front();
        q.pop();

        if (!maxDeque.empty() && maxDeque.front() == front)
            maxDeque.pop_front();
        if (!minDeque.empty() && minDeque.front() == front)
            minDeque.pop_front();
    }

    int getFront() {
        return q.empty() ? -1 : q.front();
    }

    int getMin() {
        return minDeque.empty() ? -1 : minDeque.front();
    }

    int getMax() {
        return maxDeque.empty() ? -1 : maxDeque.front();
    }
};