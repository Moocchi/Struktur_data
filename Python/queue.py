class Queue:
    def __init__(self):
        self.queue = []

    def push(self, item):
        self.queue.append(item)

    def pop(self):
        if not self.empty():
            return self.queue.pop(0)
        else:
            return "Queue is empty"

    def front(self):
        if not self.empty():
            return self.queue[0]
        else:
            return "Queue is empty"

    def empty(self):
        return len(self.queue) == 0

    def size(self):
        return len(self.queue)

    def display(self):
        return self.queue


def menu():
    print("1. Push")
    print("2. Pop")
    print("3. Front")
    print("4. Empty")
    print("5. Size")
    print("6. Display Queue")
    print("0. Exit")


queue = Queue()

while True:
    menu()
    choice = int(input("Enter your choice: "))

    if choice == 1:
        item = input("Enter item to push: ")
        queue.push(item)
    elif choice == 2:
        print("Popped item:", queue.pop())
    elif choice == 3:
        print("Front item:", queue.front())
    elif choice == 4:
        print("Is queue empty?", queue.empty())
    elif choice == 5:
        print("Queue size:", queue.size())
    elif choice == 6:
        print("Queue contents:", queue.display())
    elif choice == 0:
        break
    else:
        print("Invalid choice. Please try again.")
