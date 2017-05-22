/**
 * @file   Sales_data.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Mon May 22 12:55:03 2017
 * 
 * @brief  class definition of Sales_data.
 * 
 * 
 */
#include "../include/Sales_data.h"

namespace xiaohai
{
  Sales_data::Sales_data(std::istream &is)
  {
    read(is, *this);
  }

  Sales_data::Sales_data& Sales_data::combine(const Sales_data &rhs)
  {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
  }

  Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
  {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
  }

  std::istream &Read(std::istream &is, Sales_data &item)
  {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
  }

  std::ostream &print(std::ostream &os, const Sales_data &item)
  {
    os << item.isbn() << "  " << item.units_sold << "  "
       << item.revenue << "  " << item.avg_price();
  }
}

