#pragma once

#include <memory>
#include <stdexcept>

template <typename T>
class Pila {
private:
    struct Node {
        T data;
        std::shared_ptr<Node> next;

        explicit Node(const T& data) : data(data), next(nullptr) {}
    };

    std::shared_ptr<Node> top_;
    int size_;

public:
    Pila() : top_(nullptr), size_(0) {}

    ~Pila() = default;

    void push(const T& data) {
        auto newNode = std::make_shared<Node>(data);
        newNode->next = top_;
        top_ = newNode;
        size_++;
    }

    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Pila is empty");
        }

        top_ = top_->next;
        size_--;
    }

    T& top() {
        if (isEmpty()) {
            throw std::underflow_error("Pila is empty");
        }

        return top_->data;
    }

    const T& top() const {
        if (isEmpty()) {
            throw std::underflow_error("Pila is empty");
        }

        return top_->data;
    }

    bool isEmpty() {
        return top_ == nullptr;
    }

    int size() const {
        return size_;
    }

    void clear() {
        top_ = nullptr;
        size_ = 0;
    }
};