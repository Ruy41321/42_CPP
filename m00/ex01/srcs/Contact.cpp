#include "../includes/Contact.hpp"


void Contact::setFirstName(std::string str) {
    this->firstName = str;
}

void Contact::setLastName(std::string str) {
    this->lastName = str;
}

void Contact::setNickname(std::string str) {
    this->nickname = str;
}

void Contact::setNumber(std::string str) {
    this->number = str;
}

void Contact::setDarkestSecret(std::string str) {
    this->darkestSecret = str;
}

const std::string& Contact::getFirstName(void) const {
    return this->firstName;
}

const std::string& Contact::getLastName(void) const {
    return this->lastName;
}

const std::string& Contact::getNickname(void) const {
    return this->nickname;
}

const std::string& Contact::getNumber(void) const {
    return this->number;
}

const std::string& Contact::getDarkestSecret(void) const {
    return this->darkestSecret;
}