#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"
using namespace std; 

Book::Book(const string& name, double price, int qty,
           const string& isbn, const string& author)
    : Product("book", name, price, qty), isbn_(isbn), author_(author) {}

Book::~Book() {}

set<string> Book::keywords() const{
  set<string> a = parseStringToWords(getName());
  set<string> b = parseStringToWords(author_); 
  set<string> k = setUnion(a,b);
  k.insert(isbn_);
  return k; 
}
string Book::displayString() const{
  ostringstream oss; 
  oss << getName() << "\n" <<"Author: " << author_ << " ISBN: " << isbn_ << "\n"
    << fixed << setprecision(2) << getPrice() << " " << getQty() << " left."; 
  return oss.str(); 
}

void Book::dump(ostream& os) const{
  Product::dump(os); 
  os << isbn_ << "\n" << author_ << endl; 
}
