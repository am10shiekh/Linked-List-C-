#include <iostream>
using namespace std;
struct nodey
{
	int data;
	nodey* next;
};
class linky
{
private:
	nodey *head;
	nodey *tail;
public:
	linky()
	{
		head = NULL;
		tail = NULL;
	}
	void create(int value)
	{
		nodey *temp = new nodey;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL)
		{
			head = tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	void insertStart(int value)
	{
		nodey *temp = new nodey;
		temp->data = value;
		temp->next = head;
		head = temp;
	}
	void insertEnd(int value)
	{
		nodey *temp = new nodey;
		temp->data = value;
		temp->next = NULL;
		head = tail = temp;
		tail->next = temp;
		tail = temp;
	}
	void insertRand(int value, int pos)
	{
		nodey *temp = new nodey;
		nodey *current = new nodey;
		nodey *previous = new nodey;
		current = head;
		temp->data = value;
		for (int i = 1; i < pos; i++)
		{
			previous = current;
			current = current->next;
		}
		previous->next = temp;
		temp->next = current;
	}
	void deleteStart()
	{
		nodey *temp = head;
		head = temp;
		head = head->next;
		delete temp;
	}
	void deleteEnd()
	{
		nodey *temp = new nodey;
		nodey *cur = new nodey;
		cur = head;

		while (cur->next != NULL)
		{
			temp = cur;
			cur = cur->next;
		}
		temp->next = NULL;
		delete cur;

	}
	void deleteRand(int pos)
	{
		nodey *cur = new nodey;
		nodey *prev = new nodey;
		cur = head;
		for (int i = 0; i < pos; i++)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		delete cur;
	}
	void dispay()
	{
		nodey *temp = new nodey;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}

};

int main()
{
	linky obj;
	obj.create(50);
	obj.create(51);
	obj.create(52);
	obj.create(53);
	obj.create(54);
	cout << "---------Displaying Nodes-----------" << endl;
	obj.dispay();
	obj.insertStart(123);
	cout << "---------INSERTING Nodes at START-----------" << endl;
	obj.dispay();
	obj.create(321);
	cout << "---------INSERTING Nodes at END-----------" << endl;
	obj.dispay();
	obj.insertRand(444, 3);
	cout << "---------INSERTING Nodes at RADNOM-----------" << endl;
	obj.dispay();
	obj.deleteStart();
	cout << "---------DELETING Nodes at START-----------" << endl;
	obj.dispay();
	obj.deleteEnd();
	cout << "---------DELETING Nodes at END-----------" << endl;
	obj.dispay();
	obj.deleteRand(3);
	cout << "---------DELETING Nodes at RANDOM-----------" << endl;
	obj.dispay();

	system("pause");
}
