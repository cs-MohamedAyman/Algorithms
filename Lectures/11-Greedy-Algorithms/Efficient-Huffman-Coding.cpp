#include <bits/stdc++.h>
using namespace std;

struct node {
    int freq;
    string symbol;
    node* left;
    node* right;
    string huff;

    node(int freq=0, string symbol="", node* left=NULL, node* right=NULL, string huff="") {
        this->freq = freq;
        this->symbol = symbol;
        this->left = left;
        this->right = right;
        this->huff = huff;
    }
};

void print_nodes(node* curr, string val = "") {
    string new_val = val + curr->huff;
    if (curr->left)
        print_nodes(curr->left, new_val);
    if (curr->right)
        print_nodes(curr->right, new_val);
    if (!curr->left && !curr->right)
        cout << curr->symbol << " -> " << new_val << '\n';
}

int main() {
    int n = 6;
	string chars[] = {"a", "b", "c", "d", "e", "f"};
	int freq[]     = { 5,   9,   12,  13,  16, 45 };
	auto comp = [](auto& x, auto& y){return x->freq > y->freq;};
	priority_queue<node*, vector<node*>, decltype(comp)> nodes(comp);
	for (int i = 0; i < n; i++) {
        node* curr = new node(freq[i], chars[i]);
		nodes.push(curr);
    }
	while (nodes.size() > 1) {
		node* left = nodes.top();
		nodes.pop();
		node* right = nodes.top();
		nodes.pop();
		left->huff = "0";
		right->huff = "1";
		node* new_node = new node(left->freq+right->freq, left->symbol+right->symbol, left, right);
		nodes.push(new_node);
	}
	print_nodes(nodes.top());
}
