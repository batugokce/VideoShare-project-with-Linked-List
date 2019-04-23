#include <iostream>
#include "User.hpp"
#include "Video.hpp"

void User::printSubscriptions() {
    Node< Video*> * first = subscriptions.first();
    while (first) {
        cout << *(first->getData());
        first = first->getNext();
    }
    cout << std::endl;
}

void User::printFriends() {
    Node< User*> * first = friends.first();
    while (first) {
        cout << *(first->getData());
        first = first->getNext();
    }
    cout << std::endl;
}

ostream& operator<<(ostream& out, const User & user) {
    string st = (user.status == ACTIVE) ? "active" : "suspended";
    out << "username:" << user.username << ",name:" << user.name << ",surname:" << user.surname << ",Status:" << st << endl;
    return out;
}

/* TO-DO: method implementations below */

User::User(){
	this->username= "";
	this->name="";
	this->surname ="";
	this->status = ACTIVE;
	subscriptions = LinkedList< Video* >();
	friends = LinkedList< User* >();
}

User::User(string username, string name , string surname ){
	this->username = username;
	this->name = name;
	this->surname = surname;
	this->status = ACTIVE;
	subscriptions = LinkedList< Video* >();
	friends = LinkedList< User* >();
}



User::~User(){
	subscriptions.~LinkedList();
	friends.~LinkedList();
}

const string& User::getUsername() const{
	return username;
}

const string& User::getName() const{
	return name;
}

const string& User::getSurname() const{
	return surname;
}

Status User::getStatus() const{
	return status;
}

void User::updateStatus(Status st){
	status = st;
}

void User::subscribe(Video * video){
	subscriptions.insertNode(subscriptions.getHead(), video);
}

void User::unSubscribe(Video * video){
	Node<Video*>* tmp = subscriptions.getHead();
	while (tmp){
		if (tmp->getNext()->getData() == video){
			break;
		}
		tmp = tmp->getNext();
	}
	subscriptions.deleteNode(tmp);
}

void User::addFriend(User * user){
	friends.insertNode(friends.getHead(), user);
}

void User::removeFriend(User * user){
	Node<User*>* tmp = friends.getHead();
	while (tmp){
		if (tmp->getNext()->getData() == user){
			break;
		}
		tmp = tmp->getNext();
	}
	friends.deleteNode(tmp);
}

LinkedList<Video* > * User::getSubscriptions(){
	subscriptions.getHead();
}

LinkedList<User* > * User::getFriends(){
	friends.getHead();
}

bool User::operator==(const User& rhs) const{
	if(username == rhs.username){
		return 1;
	}
	else {
		return 0;
	}
}



