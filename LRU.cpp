class LRUCache
{
public:
    class Node
    {
    
    public:
        // class for the doubly linked list
        int key;
        int value;
        Node *next;
        Node *prev;

        Node(int _key, int _value)
        {
            key = _key;
            value = _value;
        }
    };

    // creating a head and tail for doubly list
    Node *head = new Node(-1, -1); // as soon as object is created, constructor will be called
    Node *tail = new Node(-1, -1);
    // we will create a hashmap for taking entires of the data
    unordered_map<int, Node*> mp;
    int cap; // will store the capacity

    LRUCache(int capacity)
    {
        cap = capacity;
        // create a doubly list with head and tail
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node)
    {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    void deleteNode(Node* node)
    {
        Node* delPrev = node->prev;
        Node* delNext = node->next;
        delPrev->prev = delNext;
        delNext->next = delPrev;

    }

    int get(int key)
    {
        // to get an item you will first have to check if its entry is in the map
        // if not return -1 and if there is an entry then return its value and
        // remember to rearrange its position into the doubly list and move it
        // to just next of head
        if (mp.find(key) != mp.end())
        {
            // means there exist a key
            Node *temp = mp[key];
            // before returning the value..adjust the position of the key, value pair in list
            mp.erase(key);
            deleteNode(temp); // will delete any node
            addNode(temp);    // will add a node to the immediate next of head
            mp[key] = head->next;
            return temp->value;
        }
        return -1;
            
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            // means there exit an key value pair already...so remove it because we will
            // create a new entry anyway
            Node* temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if (mp.size() == cap)
        {
            // remove the least recently used node
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        // now add the element
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};