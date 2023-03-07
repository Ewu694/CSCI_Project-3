/*
Name: Eric Wu
Professor: Tizana Ligorio
Description: Creating the LibraryRecord subclass for the project
Course: CSCI 235 Spring 2023
Due Date: 03/10/2023
*/

#include "LibraryRecord.hpp"

bool LibraryRecord::checkIn(const Book &book)
{
    bool add_book = add(book);//adds book to items_ using the arraybag add method to see if it is added or not
    if(add_book)//if book is successfully added, return true
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool LibraryRecord::checkOut(const Book &book)
{
    bool remove_book = remove(book);//removes book using arraybag remove method and obtains whether it is removed or not
    if(remove_book)
    {
        return true;
        checked_out_.push_back(book);//adds the removed book to the list of removed books
    }
    else
    {
        return false;
    }
}

int LibraryRecord::getCheckOutHistory(const Book &book)
{
    int counter = 0;
    for(std::size_t i = 0; i < checked_out_.size(); i++)//loops through list of checked out books
    {
        if(checked_out_[i] == book)//if the book param is found within the list, counter gets incremented every time it is found
        {
            counter++;
        }
    }
    return counter;
}

void LibraryRecord::display() 
{
    for(std::size_t i = 0; i < checked_out_.size(); i++)
    {
        checked_out_[i].display();
        std::cout << "\nIt has been checked out " << getCheckOutHistory(checked_out_[i]) << " times.";//uses book method display to get title, author, page count and digital, and then uses getcheckedouthistory to print the number of times a book has been checked out
    }
}

void LibraryRecord::displayTitles() const
{
    std::string display_titles = "";
    for(std::size_t i = 0; i < checked_out_.size(); i++)
    {
        display_titles + checked_out_[i].getTitle();//adds the name of the title of each book in the checked out list
        display_titles + ", ";//adds a comma to each title
    }
    display_titles + "!";//adds a exclaimation mark once the loop is done to end the string
    std::cout << display_titles;
}

bool LibraryRecord::duplicateStock()
{
    if(item_count_ * 2 > 10)//if duplicating stock is greater than maximum space, return false
    {
        return false;
    }
    int starting_item_count = item_count_;
    for(int i = 0; i < (10 - item_count_); i++)//loop through items
    {
            bool add_item = add(items_[i]);
            if(add_item)
            {
            item_count_++;
            }
    }
    if(item_count_ == (2 * starting_item_count))
    {
        return true;
    }
}

bool LibraryRecord::removeStock(const Book &book)
{
    if(contains(book) == false)
    {
        return false;
    }
    else
    {
    for(int i = 0; i < item_count_; i++)
    {
        if(items_[i] == book)
        {
            remove(items_[i]);
        }
    }
    return true;
    }
}

/**
    @param:   A reference to another LibraryRecord
    @return:  Returns true if the 2 library records have the same contents, regardless of their order. For example, if the current holdings of the LibraryRecord are [book1, book2, book3]
    and those of the referenced LibraryRecord are [book3, book1, book2], it will return true
    */
bool LibraryRecord::equivalentRecords(const LibraryRecord &record)
{
    if(getCurrentSize() != record.getCurrentSize())
    {
        return false;
    }
    else
    {
        int counter = 0;
        int i = 0;
        while(counter != record.getCurrentSize())
        {
            if(contains(record.items_[i]))
            {
                counter++;
                i++;
            }
        }
        if(counter == record.getCurrentSize())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

    /**
        @param:   A reference to another LibraryRecord object
        @post:    Combines the contents from both LibraryRecord objects, including duplicates.
        Example: [book1, book2, book3] += [book1, book4] will produce [book1, book2, book3, book1, book4]

        IMPORTANT: We are carrying over the number of times a book has been checked out. For example, if we have LibraryRecord1 += LibraryRecord2 and
        book4 is in LibraryRecord2 and has been checked out 2 times, then it should still be checked out 2 times in LibraryRecord1 after the += operation
        Hint: use getCheckOutHistory and the checkout history vector
    */
void LibraryRecord::operator+=(const LibraryRecord &record)
{
    for(size_t i = 0; i < record.getCurrentSize(); i++)
    {
        if(item_count_ < 10)
        {
        add(record.items_[i]);
        }
    }
    int times_appeared = 0;
    int num_times_checked_out = 0;
    for(int i = 0; i < item_count_; i++)
    {
        int index_book_location = getIndexOf(record.items_[i]);
        times_appeared = getFrequencyOf(record.items_[i]);
        num_times_checked_out = getCheckOutHistory(checked_out_[index_book_location]);
    }
}

    /** @param:   A reference to another LibraryRecord object
        @post:    Combines the contents from both LibraryRecord objects, EXCLUDING duplicates.
        Example: [book1, book2, book3] /= [book1, book4] will produce [book1, book2, book3, book4]

        IMPORTANT: We are carrying over the nunber of times a book has been checked out. For example, if we have LibraryRecord1 /= LibraryRecord2 and
        book4 is in LibraryRecord2 and has been checked out 2 times, then it should still be checked out 2 times in LibraryRecord1 after the /= operation
        Hint: use getCheckOutHistory and the checkout history vector
    */
void LibraryRecord::operator/=(const LibraryRecord &record)
{
    for(size_t i = 0; i < record.getCurrentSize(); i++)
    {
        if(item_count_ < 10 && !contains(record.items_[i]))
        {
        add(record.items_[i]);
        }
    }
}
