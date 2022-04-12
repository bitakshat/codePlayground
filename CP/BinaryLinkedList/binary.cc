#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public: 
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);
            
            if(!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode *node, string sep, ofstream& fout) {
    while (node) {
        fout << node -> data;
        node = node->next;

        if(node) {
            fout << sep;
        }
    }
}

long getNumber(SinglyLinkedListNode *binary) {
    std::vector<int> binary_array;
    while(binary != nullptr) {
        binary_array.push_back(binary->data);
        binary = binary->next;
    }

    std::vector<int>::iterator it;
    int dec_num = 0;
    int power = binary_array.size() - 1;
    for (it = binary_array.begin(); it != binary_array.end(); it++) {
        dec_num += (*it) * pow(2, power);
        power -= 1;
    }
    return dec_num;
}

int main(void) {

    ofstream fout(getenv("OUTPUT_PATH"));
    SinglyLinkedList *binary = new SinglyLinkedList();

    string binary_count_temp;
    getline(cin, binary_count_temp);
    int binary_count = stoi(ltrim(rtrim(binary_count_temp)));

    for (int i = 0; i < binary_count; i++) {
        string binary_item_temp;
        getline(cin, binary_item_temp);

        int binary_item = stoi(ltrim(rtrim(binary_item_temp)));
        binary->insert_node(binary_item);
    }

    long result = getNumber(binary->head);
    fout << result << "\n";
    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
