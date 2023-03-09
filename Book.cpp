/*
Name: Eric Wu
Professor: Tizana Ligorio
Description: Added Operator Overloading to Book
Course: CSCI 235 Spring 2023
Due Date: 03/10/2023
*/

#include "Book.hpp"



/**
  Parameterized constructor.
  @param      : The title of the book (a string)
  @param      : The author of the book (a string)
  @param      : The number of pages in the book (a positive int)
  @param      : A flag indicating whether the book is in digital form (a Boolean),
                with default value False
  @post       : The private members are set to the values of the corresponding parameters.
*/
Book::Book(std::string title, std::string author, int page_count, bool is_digital):
						title_{title}, author_{author}, page_count_{page_count}, is_digital_{is_digital}{}

/**
   @return : the title of the Book
*/
std::string Book::getTitle() const{
	return title_;
}

/**
  @return : the author of the Book
*/
std::string Book::getAuthor() const{
	return author_;
}

/**
  @return : the page count
*/
int Book::getPageCount() const{
  return page_count_;
}

/**
  @return : true if the book is available in digital form, false otherwise

  Note: this is an accessor function and must follow the same convention as all accessor functions even if it is not called getDigital
*/
bool Book::isDigital() const{
	return is_digital_;
}

/**
  @param  : a reference to title of the Book
  @post   : sets the Book's title to the value of the parameter
*/
void Book::setTitle(const std::string &title){
	title_ = title;
}

/**
  @param  : a reference to the name of the author of the Book
  @post   : sets the Book's author to the value of the parameter
*/
void Book::setAuthor(const std::string &author){
	author_ = author;
}

/**
  @param  : a reference to a positive integer page count
  @pre    : page count > 0 - books cannot have a negative number of pages
  @post   : sets the page count to the value of the parameter
*/
void Book::setPageCount(const int &page_count){
  if (page_count > 0)
  {
    page_count_ = page_count;
  }
}

/**
  @post   : sets the digital flag to true
*/
void Book::setDigital(){
  is_digital_ = true;
}

bool Book::operator==(const Book &book) const //allows the == operator to be used on book objects to test for equality.
{
  if((book.getTitle() == title_) && (book.getAuthor() == author_) && (book.getPageCount() == page_count_) && (book.isDigital() == is_digital_))//tests to see if the object contains the same private variables
  {
    return true;//if correct, then they are equal
  }
  return false;
}

bool Book::operator!=(const Book &book) const//allows the != operator to be used on book objects to test for inequality.
{
  if((book.getTitle() != title_) || (book.getAuthor() != author_) || (book.getPageCount() != page_count_) || (book.isDigital() != is_digital_))//tests to see if any of the private members are differnet
  {
    return true;//if they are different, return false
  }
  return false;
}

void Book::display() const
{
  std::string digital_true_false = "";//used later in the string sentence
  if(is_digital_ == true)
  {
    digital_true_false = "It is ";//If the book is digital, empty string gets set to "It is"
  }
  else
  {
    digital_true_false = "It is not ";//If not, it is set to "It is not"
  }
  std::cout <<  title_ << " is written by " << author_ << ". " << "Page Count: " << page_count_ << ". " << digital_true_false << "available digitally.\n";
}
