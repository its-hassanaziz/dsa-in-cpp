#ifndef JOBINFO_H
#define JOBINFO_H

#include<string>
#include<iostream>

using namespace std;

class JobInfo {
private:
	int JID;
	int noP;
	string jName;
	JobInfo* nextAdd;
public:
	JobInfo() {
		JID = 0;
		noP = 0;
		jName = "";
		nextAdd = nullptr;
	}
	JobInfo(int id, int p, string n) {
		JID = id;
		noP = p;
		jName = n;
		nextAdd = nullptr;
	}
	void setJID(int id) {
		JID = id;
	}
	void setnoP(int n) {
		noP = n;
	}
	void setName(string n) {
		jName = n;
	}
	void setNextAdd(JobInfo* next) {
		nextAdd = next;
	}

	int getJID() {
		return JID;
	}
	int getnoP() {
		return noP;
	}
	string getjName() {
		return jName;
	}
	JobInfo* getNextAdd() {
		return nextAdd;
	}
};
#endif