//
// Created by Aaron Berry on 4/14/21.
//

#include <iostream>
#include <iomanip>
#include <string>

#include "../includes/PhoneBook.hpp"

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

void PhoneBook::AddContact() {
  ++size_;
  if (size_ > MAX_COUNT_CONTACT) {
    std::cout << "Phonebook is full" << std::endl;
    return;
  }
  std::string	input_data;
  for (int i = 0; i < 12; ++i) {
    if(!getline(std::cin, input_data))
      return;
    CallContactAddField(size_ - 1, i, input_data);
  }
}

void PhoneBook::CallContactAddField(int contact_index, int field_index,
                                    const std::string &data) {
  std::cout << message[field_index];
  (contacts_[contact_index].*setter_func[field_index])(data);
}

PhoneBook::PhoneBook() {
  size_ = 0;
  for (int i = 0; i < 8; ++i) {
    contacts_[i].setIndex(i + 1);
  }
}

PhoneBook::~PhoneBook() {}

PhoneBook::PhoneBook(const PhoneBook &other)
: size_(other.size_){
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

void PhoneBook::PrintInfoAboutContact(int index) const {
  for (int i = 0; i < 12; ++i) {
    std::cout << message[index]
                      << (contacts_[index].*getter_func[index])() << std::endl;
  }
}

void PrintHeaderListContact() {
  std::cout << std::setw(11);
  std::cout << "index|";
  std::cout << std::setw(11);
  std::cout << "first name|";
  std::cout << std::setw(11);
  std::cout << "last name|";
  std::cout << std::setw(11);
  std::cout << "nickname|";
}

void PrintInfoListContact(const std::string &data) {
  std::string out_string(data);
  if (out_string.length() > 10) {
    out_string.resize(10);
    out_string[10] = '.';
  }
  out_string.insert(10, 1, '|');
  std::cout << std::setw(11);
  std::cout << out_string;
}

bool IsNumber(const std::string& str)
{
  for (char const &c : str) {
    if (std::isdigit(c) == 0)
      return false;
  }
  return true;
}

void PhoneBook::SearchContact() const {
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
  if(!getline(std::cin, input_data))
    return;
  if (IsNumber(input_data))
  {
    int index = (int)strtol(input_data.data(), (char **)nullptr, 10);
    if(index > 0 && index <= size_)
      PrintInfoAboutContact(index);
  }
}

