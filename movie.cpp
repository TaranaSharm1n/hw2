#include <sstream>
#include <iomanip>
#include "movie.h"
#include "util.h"
using namespace std; 

Movie::Movie::Movie(const string& name, double price, int qty,
             const string& genre, const string& rating)
    : Product("movie", name, price, qty), genre_(genre), rating_(rating) {}

Movie::~Movie() {}

set<string> Movie::keywords() const{
  set<string> k = parseStringToWords(getName());
  k.insert(convToLower(genre_));   
  return k;
}
string Movie::displayString() const{
  ostringstream oss; 
  oss << getName() << "\n"
        << "Genre: " << genre_ << " Rating: " << rating_ << "\n"
        << fixed << setprecision(2) << getPrice() << " " << getQty() << " left.";
  return oss.str();
}

void Movie::dump(ostream& os) const{
  Product::dump(os); 
  os << genre_ << "\n" << rating_ << endl; 
}
