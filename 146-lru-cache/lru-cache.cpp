struct Node {
    int key;
    int value;
    shared_ptr<Node> prev;
    shared_ptr<Node> next;
    Node(int key, int value) : key(key), value(value) {}
};
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) { join(head, tail); }

    int get(int key) {
        const auto i = keyToNode.find(key);
        if (i == keyToNode.cend())
            return -1;
        shared_ptr<Node> node = i->second;
        remove(node);
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (const auto i = keyToNode.find(key); i != keyToNode.cend()) {
            shared_ptr<Node> node = i->second;
            node->value = value;
            remove(node);
            moveToHead(node);
            return;
        }

        if (keyToNode.size() == capacity) {
            shared_ptr<Node> lastNode = tail->prev;
            keyToNode.erase(lastNode->key);
            remove(lastNode);
        }

        moveToHead(make_shared<Node>(key, value));
        keyToNode[key] = head->next;
    }

private:
    const int capacity;
    unordered_map<int, shared_ptr<Node>> keyToNode;
    shared_ptr<Node> head = make_shared<Node>(-1, -1);
    shared_ptr<Node> tail = make_shared<Node>(-1, -1);
    void join(shared_ptr<Node> node1, shared_ptr<Node> node2) {
        node1->next = node2;
        node2->prev = node1;
    }

    void moveToHead(shared_ptr<Node> node) {
        join(node, head->next);
        join(head, node);
    }

    void remove(shared_ptr<Node> node) { join(node->prev, node->next); }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */