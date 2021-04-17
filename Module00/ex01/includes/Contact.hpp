//
// Created by Aaron Berry on 4/14/21.
//

#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact{
  int                          index_;
  std::string                  first_name_;
  std::string                  last_name_;
  std::string                  nickname_;
  std::string                  login_;
  std::string                  postal_address_;
  std::string                  email_address_;
  std::string                  phone_number_;
  std::string                  birthday_date_;
  std::string                  favorite_;
  std::string                  meal_;
  std::string                  underwear_color_;
  std::string                  darkest_secret_;

 public:
  Contact();

  explicit Contact(int index);

  Contact& operator=(const Contact &other);

  Contact(const Contact &other);

  ~Contact();

  void setIndex(int index);

  int getIndex() const;

  const std::string &getLastName() const;

  void setLastName(const std::string &lastName);

  const std::string &getFirstName() const;

  void setFirstName(const std::string &firstName);

  const std::string &getNickname() const;

  void setNickname(const std::string &nickname);

  const std::string &getLogin() const;

  void setLogin(const std::string &login);

  const std::string &getPostalAddress() const;

  void setPostalAddress(const std::string &postalAddress);

  const std::string &getEmailAddress() const;

  void setEmailAddress(const std::string &emailAddress);

  const std::string &getPhoneNumber() const;

  void setPhoneNumber(const std::string &phoneNumber);

  const std::string &getBirthdayDate() const;

  void setBirthdayDate(const std::string &birthdayDate);

  const std::string &getFavorite() const;

  void setFavorite(const std::string &favorite);

  const std::string &getMeal() const;

  void setMeal(const std::string &meal);

  const std::string &getUnderwearColor() const;

  void setUnderwearColor(const std::string &underwearColor);

  const std::string &getDarkestSecret() const;

  void setDarkestSecret(const std::string &darkestSecret);
};

#endif  // CONTACT_HPP
