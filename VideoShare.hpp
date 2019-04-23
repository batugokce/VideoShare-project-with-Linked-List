#ifndef VIDEOSHARE_HPP
#define	VIDEOSHARE_HPP

#include <string>
#include <iostream>
#include "User.hpp"
#include "Video.hpp"
#include "LinkedList.hpp"

using namespace std;

class VideoShare {
private:
    LinkedList<User> users;
    LinkedList<Video> videos;
    /* TO-DO: you can  private members(functions/variables) below */

	Node<User>* findUserPtr(const string & userName){
		Node<User>* tmp = users.getHead();
		
		while (tmp){
		if (tmp->getData().getUsername() == userName){
			return tmp;
		}
		tmp = tmp->getNext();
		}
		return tmp;
	}
	
	Node<Video>* findVideoPtr(const string & p_title){
		Node<Video>* tmp = videos.getHead();
		
		while (tmp){
		if (tmp->getData().getTitle() == p_title){
			return tmp;
		}
		tmp = tmp->getNext();
		}
	}

    /* end of private member declaration */
public:
    /*....DO NOT EDIT BELOW....*/
    VideoShare();
    ~VideoShare();
    void createUser(const string & userName, const string & name = "", const string & surname = "");
    void loadUsers(const string & fileName);
    void createVideo(const string & title, const string & genre);
    void loadVideos(const string & fileName);
    void addFriendship(const string & userName1, const string & userName2);
    void removeFriendship(const string & userName1, const string & userName2);
    void updateUserStatus(const string & userName, Status newStatus);
    void subscribe(const string & userName, const string & videoTitle);
    void unSubscribe(const string & userName, const string & videoTitle);
    void deleteUser(const string & userName);
    void sortUserSubscriptions(const string & userName);
    void printAllUsers();
    void printAllVideos();
    void printUserSubscriptions(const string & userName);
    void printFriendsOfUser(const string & userName);
    void printCommonSubscriptions(const string & userName1, const string & userName2);
    void printFriendSubscriptions(const string & userName);
    bool isConnected(const string & userName1, const string & userName2);
};


#endif	/* VIDEOSHARE_HPP */


