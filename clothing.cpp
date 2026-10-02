#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"
using namespace std; 

Clothing::Clothing(const string& name, double price, int qty,
                   const string& size, const string& brand)
    : Product("clothing", name, price, qty), size_(size), brand_(brand) {}

Clothing::~Clothing() {}

set<string> Clothing::keywords() const
{
  set<string> a = parseStringToWords(getName());
  set<string> b = parseStringToWords(brand_);
  return setUnion(a, b);
}

string Clothing::displayString() const{
  ostringstream oss;
  oss << getName() << "\n" << "Size: " << size_ << " Brand: " << brand_ << "\n" << fixed << setprecision(2) << getPrice() << " " << getQty() << " left.";
  return oss.str();
}

void Clothing::dump(ostream& os) const
{
  Product::dump(os);
  os << size_ << "\n" << brand_ << endl;
}
