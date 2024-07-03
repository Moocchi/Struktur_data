#include <iostream>
#include <vector>
#include <string>

class Queue {
private:
    std::vector<std::string> queue;

public:
    void push(const std::string& item) {
        queue.push_back(item);
    }

    std::string pop() {
        if (!empty()) {
            std::string item = queue.front();
            queue.erase(queue.begin());
            return item;
        } else {
            return "Queue is empty";
        }
    }

    std::string front() {
        if (!empty()) {
            return queue.front();
        } else {
            return "Queue is empty";
        }
    }

    bool empty() const {
        return queue.empty();
    }

    int size() const {
        return queue.size();
    }

    std::vector<std::string> display() const {
        return queue;
    }
};

void menu() {
    std::cout << "1. Push" << std::endl;
    std::cout << "2. Pop" << std::endl;
    std::cout << "3. Front" << std::endl;
    std::cout << "4. Empty" << std::endl;
    std::cout << "5. Size" << std::endl;
    std::cout << "6. Display Queue" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

int main() {
    Queue queue;

    while (true) {
        menu();
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string item;
            std::cout << "Enter item to push: ";
            std::cin >> item;
            queue.push(item);
        } else if (choice == 2) {
            std::cout << "Popped item: " << queue.pop() << std::endl;
        } else if (choice == 3) {
            std::cout << "Front item: " << queue.front() << std::endl;
        } else if (choice == 4) {
            std::cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << std::endl;
        } else if (choice == 5) {
            std::cout << "Queue size: " << queue.size() << std::endl;
        } else if (choice == 6) {
            std::vector<std::string> contents = queue.display();
            std::cout << "Queue contents: ";
            for (const std::string& item : contents) {
                std::cout << item << " ";
            }
            std::cout << std::endl;
        } else if (choice == 0) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
