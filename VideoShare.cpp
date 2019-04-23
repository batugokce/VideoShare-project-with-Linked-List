#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "VideoShare.hpp"
#include "User.hpp"

using namespace std;

void VideoShare::printAllVideos() {
    videos.print();
}

void VideoShare::printAllUsers() {
    users.print();
}

/* TO-DO: method implementations below */

VideoShare::VideoShare(){
	users = LinkedList<User>();	
	videos = LinkedList<Video>();	
}

VideoShare::~VideoShare(){
	users.~LinkedList();
	videos.~LinkedList();
}

void VideoShare::createUser(const string & userName, const string & name, const string & surname ){
	User person = User(userName,name,surname);
	users.insertNode(users.getHead(),person);
}

void VideoShare::loadUsers(const string & fileName){
	
}

void VideoShare::createVideo(const string & title, const string & genre){
	Video video = Video(title, genre);
	videos.insertNode(videos.getHead(),video);
}

void VideoShare::loadVideos(const string & fileName){
	
}

void VideoShare::addFriendship(const string & userName1, const string & userName2){
	Node<User>* tmp = findUserPtr(userName1);
	Node<User>* tmp2 = findUserPtr(userName2);
	
	if (tmp != users.getHead() and tmp2 != users.getHead() and tmp and tmp2){
		tmp->getData().addFriend(tmp2->getDataPtr());
		tmp2->getData().addFriend(tmp->getDataPtr());
	}
	
}

void VideoShare::removeFriendship(const string & userName1, const string & userName2){
	Node<User>* tmp  = findUserPtr(userName1);
	Node<User>* tmp2 = findUserPtr(userName2);
	
	if (tmp == NULL or tmp2 == NULL) {
		return;
	}
	
	tmp->getData().removeFriend(tmp2->getDataPtr());
	tmp2->getData().removeFriend(tmp->getDataPtr());
	
}

void VideoShare::updateUserStatus(const string & userName, Status newStatus){
	Node<User>* tmp = findUserPtr(userName);

	if (tmp == NULL) {
		return;
	}
	
	tmp->getData().updateStatus(newStatus);
	
}

void VideoShare::subscribe(const string & userName, const string & videoTitle){
	Node<User>* tmp = findUserPtr(userName);
	Node<Video>* tmp2 = findVideoPtr(videoTitle);
	
	tmp->getData().subscribe(tmp2->getDataPtr());
}

void VideoShare::deleteUser(const string & userName){
	Node<User>* tmp = users.getHead();
	
	while (tmp->getNext()){
		if(tmp->getNext()->getData().getUsername() == userName){
			break;
		}
		tmp = tmp -> getNext();
	}
	
	users.deleteNode(tmp);
	
}

void VideoShare::sortUserSubscriptions(const string & userName){

	
}

void VideoShare::printUserSubscriptions(const string & userName){
	Node<User>* tmp = findUserPtr(userName);
	sortUserSubscriptions(userName);
	tmp->getData().getSubscriptions()->print();
	
}

void VideoShare::printFriendsOfUser(const string & userName){
	Node<User>* tmp = findUserPtr(userName);
	tmp->getData().getFriends()->print();
}

void VideoShare::printCommonSubscriptions(const string & userName1, const string & userName2){
	
	
}

void VideoShare::printFriendSubscriptions(const string & userName){
	
	
}

bool VideoShare::isConnected(const string & userName1, const string & userName2){
	
	
}
