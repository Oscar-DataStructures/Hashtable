/*
Oscar Martinez
CS 271
Dr. Lall
Project 6
*/


#include <sstream>
#include <string>


using namespace std;

// ============================= First Node Constructor ========================
template <class T>
Node<T>::Node()
{
	next = NULL;
}

// ============================ Second Node Constructor ========================
template <class T>
Node<T>::Node(T d)
{
	data = d;
	next = NULL;
}


// ============================= Third Node Constructor ========================
template <class T>
Node<T>::Node(Node* p, T d)
{
	data = d;
}


// ============================= List Constructor ==============================
template <class T>
List<T>::List()
{
	head = NULL;
	size = 0;
}


// copy constructor
template <class T>
List<T>::List(const List<T>& src)
{
  head = NULL;
  size = 0;
  deepCopy(src);
}


// ============================== List Destructor ==============================
template <class T>
List<T>::~List()
{
  Node<T>* current = head;

  for(int i=0; i < size; i++) //goes through all nodes and deletes them
  {
    Node<T>* temp = current;
    current = current-> next;
    delete temp;
  }
}


// =============================== Append Method ===============================
template <class T>
void List<T>::append(T item)
{
	Node<T>* node = new Node<T>(item);
	if (head == NULL)
	{
		head = node;
		tail = node;
	}

	else
	{
		tail->next = node;
		tail = node;
	}

	size++;

}


// ================================ Count Method ===============================
template <class T>
int List<T>::count(T item) const
{
	int number = 0;
	Node<T>* current = head;
	for(int i=0; i < size; i++)
	{
		if (current->data == item)
			number++;
		current = current-> next;

	}
	return number;
}


// =============================== Remove Method ===============================
template <class T>
void List<T>::remove(T item)
{
	Node<T>* current = head;
	Node<T>* tmp = head;

	if (size == 0)
	{
		delete current;
		return;
	}

	while (current->next != NULL && current->next->data != item)
	{
		tmp = current;
		current = current->next;

		if (current->next == NULL && current->next->data == item)
			{
				tmp = current->next;
				current->next = current->next->next;
				delete tmp;
				return;
			}
	}
	size--;
}


// =============================== Insert Method ===============================
template <class T>
void List<T>::insert(int index, T item)
{
	Node<T>* temp = new Node<T>(item);
	Node<T>* node = head;

	if(index > size || index < 0)
    throw IndexError();

	if(index == size)
	{
		append(item);
	}

	else if (index == 0)
	{
		head = temp;
		head->next= node;
		size++;
	}
	else
	{
		for(int i=0; i<index-1; i++)
		{
			node=node->next;
		}
		Node<T>* nxt = node->next;
		node->next = temp;
		temp->next =nxt;

		size++;
 	}
 }


 // ================================ Pop Method ================================
 template <class T>
 void List<T>::pop(int index)
 {
 	Node<T>* current = head;
 	Node<T>* nxt = head;

 	if(index > size || index < 0)
     throw IndexError();

 	 else if (index == 0)
 	 {
 	 	if(head != NULL && size >1 )
 	 	{
 			head = current->next;
 			delete current;
 	 	}
 	 }

 	 else if(index == size-1)
 	 {
 	 	for(int i = 0; i < index - 1; i++)
 	 	{
 	 		current = current->next;
 	 	}
 	 	delete current->next;
 	 }

 	 size--;
 }


 // =============================== Length Method ==============================
 template <class T>
 int List<T>::length() const
 {
   return size;
 }


//================================ Index  Method ===============================
 template <class T>
 int List<T>::index(T item) const
 {

   Node<T>* current = head;
   for(int i = 0; i < size; i++)  //goes through all nodes until index and gets data at index
   {
     if (item == current-> data)
       return i;
     else
       current = current-> next;

   }

   return -1;
 }


//============================ Index Operator Method ============================
template <class T>
T& List<T>::operator[](int index) const
{
  Node<T>* current = head;
  if(index >= size || index < 0)  //if invalid index, return "Index out of Range"
    throw IndexError();

  for(int i=0; i < index; i++)
  {
		current = current->next;
  }

	return current->data;
}


// ======================== Assignment Operator Method =========================
template <class T>
List<T>& List<T>::operator=(const List<T>& src)
{
  Node<T>* current = src.head;
  if (&src != this)
  {
		Node<T>* t = head;

		for(int i=0; i < size; i++) //goes through all nodes and deletes them
		{
			Node<T>* temp = t;
			t = t-> next;
			delete temp;
		}
		deepCopy(src);
	}

  return *this;
}


// ===================== Stream Insertion Operator Method ======================
// template <class T>
// ostream &operator << (ostream &out, List<t> &list)
// {
// 	out <<list.toString();
// 	return out;
// }



// ============================= To String Method ==============================
template <class T>
std::string List<T>::toString() const
{
  std::stringstream ss;
  Node<T>* current= head;
  ss << "[";
  ss << current->data;
  for (int i = 1; i < size; i++)
  {
    ss << ", ";
    current= current->next;
    ss << current->data;
  }
  ss << "]";
    return ss.str();
}


// ============================= Deep Copy Method =============================
template <class T>
 List<T>& List<T>::deepCopy(const List<T>& src)
 {
	 Node<T>* current = src.head;
		 for(int i=0; i < src.size; i++)  //sets each node equal to desired node data
		 {
			 append(current-> data);
			 if(i < src.size-1)
			 {
				 current = current-> next;
		 	 }
		 }


	 return *this;
 }
