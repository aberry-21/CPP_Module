//
// Created by Aaron Berry on 4/14/21.
//

#include <iostream>
#include <iomanip>
#include <string>

#include "../includes/PhoneBook.hpp"

//==========================  Static Field  ====================================

char const  PhoneBook::message[12][32] =
{"first_name: ",
 "last_name: ", "nickname: ", "login: ", "postal_address: ",
 "email_address: ", "phone_number: ", "birthday_date: ",
 "favorite: ", "meal: ", "underwear_color: ",
 "darkest_secret: " };

PhoneBook::setterContactField const PhoneBook::setter_func[12] =
{ &Contact::setFirstName, &Contact::setLastName, &Contact::setNickname,
  &Contact::setLogin, &Contact::setPostalAddress, &Contact::setEmailAddress,
  &Contact::setPhoneNumber, &Contact::setBirthdayDate, &Contact::setFavorite,
  &Contact::setMeal, &Contact::setUnderwearColor, &Contact::setDarkestSecret};

PhoneBook::getterContactField const PhoneBook::getter_func[12] =
{ &Contact::getFirstName, &Contact::getLastName, &Contact::getNickname,
  &Contact::getLogin, &Contact::getPostalAddress, &Contact::getEmailAddress,
  &Contact::getPhoneNumber, &Contact::getBirthdayDate, &Contact::getFavorite,
  &Contact::getMeal, &Contact::getUnderwearColor, &Contact::getDarkestSecret};

//==============================================================================

PhoneBook::PhoneBook() {
  size_ = 0;
  for (int i = 0; i < 8; ++i) {
    contacts_[i].setIndex(i + 1);
  }
}

PhoneBook::~PhoneBook() {}

PhoneBook::PhoneBook(const PhoneBook &other)
: size_(other.size_) {
  for (int i = 0; i < other.size_; ++i) {
    contacts_[i] = other.contacts_[i];
  }
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other) {
  if (this == &other)
    return *this;
  this->size_ = other.size_;
  for (int i = 0; i < other.size_; ++i) {
    this->contacts_[i] = other.contacts_[i];
  }
  return *this;
}

//===========================  AddContact  =====================================

void PhoneBook::CallContactAddField(int contact_index, int field_index,
                                    const std::string &data) {
  (contacts_[contact_index].*setter_func[field_index])(data);
}

int PhoneBook::AddContact() {
  if (size_ >= MAX_COUNT_CONTACT) {
    std::cout << "Phonebook is full" << std::endl;
    return 0;
  }
  ++size_;
  std::string input_data;
  for (int i = 0; i < 12; ++i) {
    std::cout << message[i];
    if (!getline(std::cin, input_data))
      return 1;
    CallContactAddField(size_ - 1, i, input_data);
  }
  return 0;
}

//==============================================================================

//==========================  SearchContact  ===================================

void PhoneBook::PrintInfoAboutContact(int index) const {
  for (int i = 0; i < 12; ++i) {
    std::cout << message[i]
                      << (contacts_[index].*getter_func[i])() << std::endl;
  }
}

void PrintHeaderListContact() {
  std::cout << std::setw(11);
  std::cout << "index|";
  std::cout << std::setw(11);
  std::cout << "first name|";
  std::cout << std::setw(11);
  std::cout << "last name|";
  std::cout << std::setw(12);
  std::cout << "nickname|\n";
}

void PrintInfoListContact(const std::string &data) {
  std::string out_string(data);
  if (out_string.length() > 10) {
    out_string.resize(10);
    out_string[9] = '.';
  }
  out_string.insert(out_string.length(), 1, '|');
  std::cout << std::setw(11);
  std::cout << out_string;
}

bool IsNumber(const std::string& str) {
  size_t len = str.length();
  for (size_t i = 0; i < len; ++i) {
    if (std::isdigit(str[i]) == 0)
      return false;
  }
  return true;
}

int PhoneBook::SearchContact() const {
  PrintHeaderListContact();
  for (int i = 0; i < size_; ++i) {
    PrintInfoListContact(std::to_string(contacts_[i].getIndex()));
    PrintInfoListContact(contacts_[i].getFirstName());
    PrintInfoListContact(contacts_[i].getLastName());
    PrintInfoListContact(contacts_[i].getNickname());
    std::cout << std::endl;
  }
  std::string input_data;
  std::cout << "Write index contact: ";
  if (!getline(std::cin, input_data))
    return 1;
  if (IsNumber(input_data)) {
    int index = static_cast<int>(strtol(input_data.data() ,
                                        static_cast<char **>(nullptr), 10));
    if (index > 0 && index <= size_)
      PrintInfoAboutContact(index - 1);
  }
  return 0;
}

//==============================================================================
