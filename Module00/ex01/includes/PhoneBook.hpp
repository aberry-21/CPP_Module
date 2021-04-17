//
// Created by Aaron Berry on 4/14/21.
//

#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

#define MAX_COUNT_CONTACT 8

class PhoneBook {
  int                             size_;
  Contact                         contacts_[MAX_COUNT_CONTACT];
  static const char               message[12][32];

  typedef void (Contact::*setterContactField)(const std::string &data);
  static const setterContactField setter_func[12];

  typedef const std::string &(Contact::*getterContactField)() const;
  static const getterContactField getter_func[12];

  void CallContactAddField(int contact_index, int field_index,
                                                      const std::string &data);

  void PrintInfoAboutContact(int index) const;

 public:
  PhoneBook& operator=(const PhoneBook &other);

  PhoneBook(const PhoneBook &other);

  PhoneBook();

  ~PhoneBook();

  int  AddContact();

  int  SearchContact() const;
};

#endif  // PHONEBOOK_HPP
