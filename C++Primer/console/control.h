/**
 * @file   Iostream.h
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Thu Jun  1 12:57:32 2017
 * 
 * @brief  The classes are used to generate
 *         a pretty console output and are created by xiaohai.
 */

#include <iostream>
#include <string>

using namespace std;

/** 
 * This class is used to generate a promption.
 * 
 * @param Prompt 
 * @param Term 
 */
template <typename T>
class Prompt
{
public:
  /// 
 Prompt(const T &Prompt = "\033[4;3;32m", const T &Term = "\033[0m")
   : prompt(Prompt), term(Term) { }
  virtual ~Prompt(){}

  /** 
   * output
   * @return os
   */
  ostream& operator()(ostream& os)
    {
      os << prompt;
      return os;
    }
  
  /** 
   * end the control console
   * @return term
   */
  inline const T& end() const
  {
    return term;
  }

private:
  T prompt;
  T term;
}; /// template class

/** 
 * This class is used to generate a warning.
 * 
 * @param Warning 
 * @param Term 
 */
template <typename T>
class Warning
{
public:
 Warning(const T &Warning = "\033[4;3;33m", const T &Term = "\033[0m")
   : warning(Warning), term(Term) { }
  virtual ~Warning(){}
  
  ostream& operator()(ostream& os)
    {
      os << warning;
      return os;
    }
  /// end the control console
  inline const T& end() const
  {
    return term;
  }
  
private:
  T warning;
  T term;
}; /// template class


/** 
 * This class is used to generate a error.
 * 
 * @param Error 
 * @param Term 
 */
template <typename T>
class Error
{
public:
 Error(const T &Error = "\033[4;3;31m", const T &Term = "\033[0m")
   : error(Error), term(Term) { }
  virtual ~Error(){}
  
  ostream& operator()(ostream& os)
    {
      os << error;
      return os;
    }
  /// end the control console
  inline const T& end() const
  {
    return term;
  }
  
private:
  T error;
  T term;
}; /// template class
