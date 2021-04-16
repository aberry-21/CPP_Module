//
// Created by Aaron Berry on 4/14/21.
//

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_COUNT_CONTACT 8

class PhoneBook {
  int                             size_;
  Contact                         contacts_[MAX_COUNT_CONTACT];
  static const char               message[12][32];
  typedef void (Contact::*setterContactField)(const std::string &data);
  static const setterContactField setter_func[12];
 public:

  PhoneBook& operator=(const PhoneBook &other);

  PhoneBook(const PhoneBook &other);

  PhoneBook();

  ~PhoneBook();

  void CallContactAddField(int contact_index, int field_index, const std::string &data);

  void AddContact();

};


#endif //PHONEBOOK_HPP
