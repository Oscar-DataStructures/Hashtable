/*
Oscar Martinez
CS 271
Dr. Lall
Project 6
*/


template <class KeyType>
class HashTable
{
  public:
    HashTable(int numSlots);
    HashTable(const HashTable<KeyType>& h);
    ~HashTable();

    KeyType get(const KeyType& k) const;
    void insert(KeyType k);
    void remove(const KeyType& k);

    HashTable<KeyType>& operator=(const HashTable<KeyType>& h);
    std::string toString(int slot) const;

  private:
    int slots;
    List<KeyType> *table; // an array of List<KeyType>’s
};
