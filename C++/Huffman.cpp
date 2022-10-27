//huffman code
#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node* left, *right;
};

Node* getNode(char ch, int freq, Node* left, Node* right){
    Node* node= new Node();
    node->ch=ch;
    node->freq=freq;
    node->left=left;
    node->right=right;
    return node;
}


//comparison to order the heap
struct comp{
    bool operator()(Node* l, Node* r){
        return l->freq > r->freq;
    }
};

void encode(Node* root, string str, unordered_map<char, string> &huffmanCode){
    if(root==nullptr){
        return;
    }
    
    //found a leaf node
    if(!root->left && !root->right){
        huffmanCode[root->ch]=str;
    }

    encode(root->left, str+"0", huffmanCode);
    encode(root->right, str+"1", huffmanCode);
}


void decode(Node* root, int &topIdx, string str){
    if(root==nullptr){
        return;
    }

    //found a leaf node
    if(!root->right && !root->left){
        cout<<root->ch;
        return;
    }
    topIdx++;

    if(str[topIdx]=='0'){
        decode(root->left, topIdx, str);
    }
    else{
        decode(root->right, topIdx, str);
    }

}

void buildHuffmanTree(string text){
    unordered_map<char, int> freq;
    for(char ch:text){
        freq[ch]++;
    }

    //to store the leaf nodes of the huffman tree
    priority_queue<Node*, vector<Node*>, comp> pq;

    for(auto pair: freq){
        //make leaf node of each character and push to the priority queue
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    //do the following till there is only one node in the priority queue
    while(pq.size()!=1){
        //remove two nodes and from queue
        Node* left=pq.top(); pq.pop();
        Node* right=pq.top(); pq.pop();

        //create an internal node with frequency equal to the sum of the frequency of these two popped nodes
        int sum=left->freq+right->freq;
        pq.push(getNode('\0', sum, left, right)); 
    }

    //root of the huffman tree
    Node* root=pq.top();

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout<<"The Huffman codes are:\n";
    for(auto pair: huffmanCode){
        cout<<pair.first<<" "<<pair.second<<"\n";
    }

    cout<<"original string was "<<text<<endl;
    string str="";
    for(char ch: text){
        str+=huffmanCode[ch];
    }

    cout<<"The encoded string is "<<str<<endl;
int index = -1;
	cout << "\nDecoded string is: \n";
    
	while (index < (int)str.size() - 2) {
		decode(root, index, str);
	}

}

int main(){
    string text;
    cout<<"Enter a text: ";
    getline(cin, text);
    buildHuffmanTree(text);
    return 0;
}