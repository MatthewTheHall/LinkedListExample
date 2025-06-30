#include <iostream>
#include <string>
using namespace std;

class ContactNode {
public:
	ContactNode(const string& name, const string& phone, ContactNode* next = nullptr);
	const string& GetName() const { return contactName; }
	const string& GetPhoneNumber() const { return contactPhoneNumber; }
	ContactNode* GetNext() const { return nextNodePtr; } 
	void InsertAfter(ContactNode* nodeLoc); //insert nodeLoc immediately after *this*
	void PrintContactNode() const;

private:
	string contactName;
	string contactPhoneNumber;
	ContactNode* nextNodePtr;
};


//constructor initializer 
ContactNode::ContactNode(const string& name, const string& phone, ContactNode* next)
{
	this->contactName = name; //sets passed info
	this->contactPhoneNumber = phone;
	this->nextNodePtr = next; //sets nextNodePtr to next memory location
}
void ContactNode::InsertAfter(ContactNode* nodeLoc)
{
	nodeLoc->nextNodePtr = nextNodePtr; //new node points where *this used to
	nextNodePtr = nodeLoc; //*this now points to new node
}
void ContactNode::PrintContactNode() const //prints both data for the current node
{
	std::cout << "Name: " << this->contactName << '\n';
	std::cout << "Phone number: " << this->contactPhoneNumber << '\n';
}

int main() {
	ContactNode* head = nullptr; //first node in list (null while empty)
	ContactNode* last = nullptr; //last node/tail pointer for appending
	string name, phone;
	for (int i = 1; i <= 3; ++i) //input loop
	{
		getline(cin, name);
		getline(cin, phone);
		cout << "Person " << i << ": " << name << ", " << phone << '\n';
		ContactNode* node = new ContactNode(name, phone);
		if (!head) //if list is still empty
		{
			head = last = node; //head and last both point to node
		} else //list has at least one node
		{
			last->InsertAfter(node); //stitch new node after last
			last = node; //update last pointer/tail
		}
	}
	cout << "\nCONTACT LIST\n"; //output loop
	for (ContactNode* cur = head; cur; cur = cur->GetNext())
	{
		cur->PrintContactNode();
		if (cur->GetNext())
		{
			cout << '\n';
		}
	}
	cout << '\n';
	//free memory
	ContactNode* cur = head;
	while (cur)
	{
		ContactNode* next = cur->GetNext();
		delete cur;
		cur = next;
	}
	return 0;
}
