
class Node {
public:
    int freq;
    Node* prev;
    Node* next;
    unordered_set<string> keys;

    Node(int freq) : freq(freq), prev(nullptr), next(nullptr) {}
};

class AllOne {
public:

    Node *head, *tail;
    unordered_map<string, Node*> map;

    void deleteNode(Node *target) {
        target->prev->next = target->next;
        target->next->prev = target->prev;

        delete target;
    }

    AllOne() {
        head = new Node(0);
        tail = new Node(0);

        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if (!map[key]) {

            // target freq ke 1
            if (head->next->freq != 1) {
                Node *one = new Node(1);
                Node *temp = head->next;

                head->next = one;
                one->prev = head;
                one->next = temp;
                temp->prev = one;
            }

            head->next->keys.insert(key);
            map[key] = head->next;
        } else {
            // Berarti mau increment key nya naek node sebelah
            Node *curr = map[key];

            curr->keys.erase(key);

            if (curr->next->freq != curr->freq + 1) {
                Node *newNext = new Node(curr->freq + 1);

                Node *next = curr->next;

                curr->next = newNext;
                newNext->prev = curr;
                newNext->next = next;
                next->prev = newNext;
            }

            curr->next->keys.insert(key);
            map[key] = curr->next;

            if (curr->keys.empty()) {
                deleteNode(curr);
            }
        }
    }
    
    void dec(string key) {
        if (!map[key]) return;

        Node *target = map[key];
        target->keys.erase(key);

        if (target->freq > 1) {
            // Berarti harus dipass ke freq belakangnya
            if (target->prev->freq != target->freq - 1) {
                Node *newPrev = new Node(target->freq - 1);

                target->prev->next = newPrev;
                newPrev->prev = target->prev;
                newPrev->next = target;
                target->prev = newPrev;
            }

            target->prev->keys.insert(key);
            map[key] = target->prev;
        } else {
            map.erase(key);
        }

        // Misal udah kosong berarti harus apus nodenya biar min max nanti tetep konsisten
        if (target->keys.empty()) {
            deleteNode(target);
        }
    }
    
    string getMaxKey() {
        if (tail->prev == head) return "";
        return *(tail->prev->keys.begin());
    }
    
    string getMinKey() {
        if (head->next == tail) return "";
        return *(head->next->keys.begin());
    }
};