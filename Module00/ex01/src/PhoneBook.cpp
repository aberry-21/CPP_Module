//
// Created by Aaron Berry on 4/14/21.
//

#include <iostream>
#include <string>

#include "../includes/PhoneBook.hpp"

char const  PhoneBook::message[12][32] =
{"Your first_name: ",
 "Your last_name: ", "Your nickname: ", "Your login: ", "Your postal_address: ",
 "Your email_address: ", "Your phone_number: ", "Your birthday_date: ",
 "Your favorite: ", "Your meal: ", "Your underwear_color: ",
 "Your darkest_secret: " };

PhoneBook::setterContactField const PhoneBook::setter_func[12] =
{&Contact::setFirstName, &Contact::setLastName, &Contact::setNickname,
  &Contact::setLogin, &Contact::setPostalAddress, &Contact::setEmailAddress,
  &Contact::setPhoneNumber, &Contact::setBirthdayDate, &Contact::setFavorite,
  &Contact::setMeal, &Contact::setUnderwearColor, &Contact::setDarkestSecret};

void PhoneBook::AddContact() {
  ++size_;
  if (size_ > MAX_COUNT_CONTACT) {
    std::cout << "Phonebook is full" << std::endl;
    return;
  }
  std::string	input_data;
  for (int i = 0; i < 12; ++i) {
    getline(std::cin, input_data);
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
