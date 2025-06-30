#include <iostream>
#include <string>
using namespace std;

class ContactNode {
public:
	/* Declare member functions here */
	ContactNode(const string& name, const string& phone, ContactNode* next = nullptr);
	const string& GetName() const { return contactName; }
	const string& GetPhoneNumber() const { return contactPhoneNumber; }
	ContactNode* GetNext() const { return nextNodePtr; } 
	void InsertAfter(ContactNode* nodeLoc); 
	void PrintContactNode() const;

private:
	/* Declare data members here */
	string contactName;
	string contactPhoneNumber;
	ContactNode* nextNodePtr;
};

/* Define member functions here */
ContactNode::ContactNode(const string& name, const string& phone, ContactNode* next)
{
	this->contactName = name; //sets passed info
	this->contactPhoneNumber = phone;
	this->nextNodePtr = next; //sets nextNodePtr to next memory location
}
void ContactNode::InsertAfter(ContactNode* nodeLoc)
{
	nodeLoc->nextNodePtr = nextNodePtr; //set sub object ptr to next
	nextNodePtr = nodeLoc; //update next
}
void ContactNode::PrintContactNode() const //prints both data for the current node
{
	std::cout << "Name: " << this->contactName << '\n';
	std::cout << "Phone number: " << this->contactPhoneNumber << '\n';
}

int main() {
	/* Type your code here. */
	ContactNode* head = nullptr; //first node
	ContactNode* last = nullptr; //last node
	string name, phone;
	for (int i = 1; i <= 3; ++i) //input loop
	{
		getline(cin, name);
		getline(cin, phone);
		cout << "Person " << i << ": " << name << ", " << phone << '\n';
		ContactNode* node = new ContactNode(name, phone);
		if (!head) //if not first node
		{
			head = last = node; //? head = last = the new node input
		} else //if head? so first append
		{
			last->InsertAfter(node); //inserting node into last
			//this will update node sub object with nextNodePtr address
			//then update nextNodePtr with node's info?
			last = node;
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
