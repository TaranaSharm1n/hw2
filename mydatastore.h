#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <map>
#include <set>
#include <deque> 
#include <vector> 
#include <string> 
#include "datastore.h"

class MyDataStore : public DataStore {
  public:
    MyDataStore(); 
    virtual ~MyDataStore(); 
    void addProduct(Product* p); 
    void addUser(User* u); 
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& ofile);

    void addToCart(const std::string& username, int hitIndex, const std::vector<Product*>& hits);
    void viewCart(const std::string& username);
    void buyCart(const std::string& username);

  private: 
    std::vector<Product*> products_;
    std::map<std::string, User*> users_;                       
    std::map<std::string, std::deque<Product*> > carts_;       
    std::map<std::string, std::set<Product*> > index_; 
};
#endif
