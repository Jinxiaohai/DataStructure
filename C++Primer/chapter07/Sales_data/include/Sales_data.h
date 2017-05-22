/**
 * @file   Sales_data.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Mon May 22 12:44:28 2017
 * 
 * @brief  Sales_data class for book.
 * 
 */
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>

namespace xiaohai
{ 
  class Sales_data
  {
    /// friend API
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream &Read(std::isteam&, Sales_data&);
    friend std::ostream &print(std::ostream&, Sales_data&);
    
  public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p):
      bookNo(s), unist_sold(n), revenue(p*n) { }
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(std::istream&);
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data&);
    virtual ~Sales_data();

  private:
    double avg_price() const
    { return units_sold ? revenue/units_sold : 0; }
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.;
  };

  Sales_data add(const Sales_data&, const Sales_data&);
  std::istream &Read(std::istream&, Sales_data&);
  std::ostream &print(std::ostream&, const Sales_data&);
}

#endif /* SALES_DATA_H */
