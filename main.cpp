#include <iostream>
#include "Book.hpp"
#include "LibraryRecord.hpp"

int main() {
    Book my_book;

    // Test parameterized constructor
    Book my_book1("Harry Potter and the Chamber of Secrets", "J.K Rowling", 253, 1);
    Book my_book2("Moby Dick", "Herman Melville", 378);

    Book my_book3("Moby Dick", "Herman Melville", 378);
    my_book3.setTitle("50 shades of gray");
    my_book3.setAuthor("E. L. James");
    my_book3.setPageCount(514);
    my_book3.setPageCount(-10);
    my_book3.setDigital();

    LibraryRecord record1;
    record1.checkIn(my_book1);
    record1.checkIn(my_book2);
    record1.checkIn(my_book3);
    record1.checkOut(my_book1);
    record1.checkIn(my_book1);
    record1.checkOut(my_book1);
    record1.removeStock(my_book2);
    std::cout << record1.duplicateStock() << "\n" << std::endl;
    record1.display();
}
