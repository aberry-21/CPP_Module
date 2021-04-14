//
// Created by Aaron Berry on 4/14/21.
//

#include "../includes/Contact.hpp"

Contact::Contact()
: index_(), first_name_(), last_name_(), nickname_(),
login_(), postal_address_(), email_address_(), phone_number_(),
birthday_date_(), favorite_(), meal_(), underwear_color_(), darkest_secret_() {}

Contact::~Contact() {}

Contact &Contact::operator=(const Contact &other){
  if (this == &other)
    return (*this);
  this->index_ = other.index_;
  this->first_name_ = other.first_name_;
  this->last_name_ = other.last_name_;
  this->nickname_ = other.nickname_;
  this->login_ = other.login_;
  this->postal_address_ = other.postal_address_;
  this->email_address_ = other.email_address_;
  this->phone_number_ = other.phone_number_;
  this->birthday_date_ = other.birthday_date_;
  this->favorite_ = other.favorite_;
  this->meal_ = other.meal_;
  this->underwear_color_ = other.underwear_color_;
  this->darkest_secret_ = other.darkest_secret_;
  return *this;
}

Contact::Contact(const Contact &other)
:index_(other.index_), first_name_(other.first_name_),
last_name_(other.last_name_), nickname_(other.nickname_),
login_(other.login_), postal_address_(other.postal_address_),
email_address_(other.email_address_), phone_number_(other.phone_number_),
birthday_date_(other.birthday_date_), favorite_(other.favorite_),
meal_(other.meal_), underwear_color_(other.underwear_color_),
darkest_secret_(other.darkest_secret_){}

Contact::Contact(int index)
:first_name_(), last_name_(), nickname_(),
login_(), postal_address_(), email_address_(), phone_number_(),
birthday_date_(), favorite_(), meal_(), underwear_color_(), darkest_secret_() {
  setIndex(index);
}

int Contact::getIndex() const {
  return index_;
}

void Contact::setIndex(int index) {
  index_ = index;
}

const std::string &Contact::getLastName() const {
  return last_name_;
}

void Contact::setLastName(const std::string &lastName) {
  last_name_ = lastName;
}

const std::string &Contact::getFirstName() const {
  return first_name_;
}

void Contact::setFirstName(const std::string &firstName) {
  first_name_ = firstName;
}

const std::string &Contact::getNickname() const {
  return nickname_;
}

void Contact::setNickname(const std::string &nickname) {
  nickname_ = nickname;
}

const std::string &Contact::getLogin() const {
  return login_;
}

void Contact::setLogin(const std::string &login) {
  login_ = login;
}

const std::string &Contact::getPostalAddress() const {
  return postal_address_;
}

void Contact::setPostalAddress(const std::string &postalAddress) {
  postal_address_ = postalAddress;
}

const std::string &Contact::getEmailAddress() const {
  return email_address_;
}

void Contact::setEmailAddress(const std::string &emailAddress) {
  email_address_ = emailAddress;
}

const std::string &Contact::getPhoneNumber() const {
  return phone_number_;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
  phone_number_ = phoneNumber;
}

const std::string &Contact::getBirthdayDate() const {
  return birthday_date_;
}

void Contact::setBirthdayDate(const std::string &birthdayDate) {
  birthday_date_ = birthdayDate;
}

const std::string &Contact::getFavorite() const {
  return favorite_;
}

void Contact::setFavorite(const std::string &favorite) {
  favorite_ = favorite;
}

const std::string &Contact::getMeal() const {
  return meal_;
}

void Contact::setMeal(const std::string &meal) {
  meal_ = meal;
}

const std::string &Contact::getUnderwearColor() const {
  return underwear_color_;
}

void Contact::setUnderwearColor(const std::string &underwearColor) {
  underwear_color_ = underwearColor;
}

const std::string &Contact::getDarkestSecret() const {
  return darkest_secret_;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
  darkest_secret_ = darkestSecret;
}
