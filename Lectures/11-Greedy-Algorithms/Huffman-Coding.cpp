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
	vector<node*> nodes;
	for (int i = 0; i < n; i++) {
        node* curr = new node(freq[i], chars[i]);
		nodes.push_back(curr);
    }
	while (nodes.size() > 1) {
        sort(nodes.begin(), nodes.end(), [](auto& x, auto& y){return x->freq < y->freq;});
		node* left = nodes[0];
		node* right = nodes[1];
		left->huff = "0";
		right->huff = "1";
		node* new_node = new node(left->freq+right->freq, left->symbol+right->symbol, left, right);
		nodes.erase(nodes.begin());
		nodes.erase(nodes.begin());
		nodes.push_back(new_node);
	}
	print_nodes(nodes[0]);
}
