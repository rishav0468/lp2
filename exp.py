class LibraryExpertSystem:
    def __init__(self):
        self.books = {}
        self.users = {}

    def add_book(self, title, category):
        if title in self.books:
            print(f"'{title}' already exists in the library.")
        else:
            self.books[title] = {"category": category}
            print(f"'{title}' has been added to the library.")

    def remove_book(self, title):
        if title in self.books:
            del self.books[title]
            print(f"'{title}' has been removed from the library.")
        else:
            print("Book not found in the library.")

    def borrow_book(self, title, username):
        if title in self.books:
            if username not in self.users:
                self.users[username] = []
            self.users[username].append(title)
            print(f"'{title}' has been borrowed by {username}.")
        else:
            print("Book not available for borrowing.")

    def return_book(self, title, username):
        if username in self.users and title in self.users[username] and title in self.books:
            self.users[username].remove(title)
            print(f"'{title}' has been returned by {username}.")
        else:
            print("Invalid book or user.")

    def recommend_books(self, category=None):
        recommended_books = []

        if category:
            for title, info in self.books.items():
                if info["category"] == category:
                    recommended_books.append(title)
        else:
            for title in self.books:
                recommended_books.append(title)

        if recommended_books:
            print("Recommended books:")
            for title in recommended_books:
                print(f"- {title} ({self.books[title]['category']})")
        else:
            print("No books available in the specified category.")

# Example usage with user input
expert_system = LibraryExpertSystem()

print("Welcome to the Library Management Expert System!")

while True:
    print("\n1. Add Book\n2. Remove Book\n3. Borrow Book\n4. Return Book\n5. Recommend Books\n6. Exit")
    choice = input("Enter your choice: ")

    if choice == '1':
        title = input("Enter title of the book: ")
        category = input("Enter category of the book: ")
        expert_system.add_book(title, category)
    elif choice == '2':
        title = input("Enter title of the book to remove: ")
        expert_system.remove_book(title)
    elif choice == '3':
        title = input("Enter title of the book to borrow: ")
        username = input("Enter your username: ")
        expert_system.borrow_book(title, username)
    elif choice == '4':
        title = input("Enter title of the book to return: ")
        username = input("Enter your username: ")
        expert_system.return_book(title, username)
    elif choice == '5':
        category = input("Enter category of books to recommend (leave empty for all): ")
        expert_system.recommend_books(category)
    elif choice == '6':
        print("Exiting...")
        break
    else:
        print("Invalid choice. Please try again.")
