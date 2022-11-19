#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
#include<cmath>
using namespace std;

//Класс узла для создания дерева
class Node {
public:
    char c;
    int freq;
    Node* left, * right;
};

//Функция для создания нового узла дерева
Node* getNode(char c, int freq, Node* left, Node* right) {
    Node* t = new Node();
    t->c = c;
    t->freq = freq;
    t->left = left;
    t->right = right;
    return t;
}

//Объект сравнения, чтобы упорядочить кучу
class comp {
public:
    bool operator()(Node* left, Node* right) {
        //Highest priority or top most item in pq must have highest freq
        return left->freq > right->freq;
    }
};

//Пройдите по Хаффману и сохраните строки на map для кодов Хаффмана
void encode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    //Если root равен NULL, ничего нельзя сделать!
    if (!root)
        return;

    //Нашел лист
    if (!root->left && !root->right)
        huffmanCode[root->c] = str;

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}


//Создание Хаффмана и, наконец, его расшифровка
void buildHuffman(string text) {

    ///Counts and stores frequency of every occuring character
    unordered_map<char, int> freq;

    for (auto c : text) {
        ///Updating frequency
        freq[c]++;
    }

    ///Создание приоритетной очереди для хранения листьев дерева Хаффмана
    priority_queue<Node*, vector<Node*>, comp> tree;

    ///Создание конечного узла каждого символа, сохраненного на map, и вставка в root;
    cout << "\nFrequency of each character in input string:\n";
    for (auto p : freq) {
        cout << p.first << " : " << p.second << endl;
        tree.push(getNode(p.first, p.second, NULL, NULL));
    }

    ///Creating tree
    while (tree.size() != 1) {
        ///Remove two nodes with highest priority ie lowest frequency from tree
        Node* left = tree.top(); tree.pop();
        Node* right = tree.top(); tree.pop();

        ///Create new node with these two as its children and push a new node with freq = sum of both children
        int sum = left->freq + right->freq;
        tree.push(getNode(NULL, sum, left, right));
    }

    ///Root stores pointer to root of huffman tree
    Node* root = tree.top();

    ///CREATED!

    ///Traverse the whole huffman tree and store huffman codes in map
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "\nHUFFMAN CODES ARE:\n" << endl;

    ///Printing codes for each character
    for (auto p : huffmanCode)
        cout << p.first << " : " << p.second << endl;

    cout << endl;

    cout << "\nOriginal string was: \n" << text << endl;
    cout << endl;

    ///Appending code
    string res = "";
    for (char c : text)
        res += huffmanCode[c];

    ///Printing huffman coded string for the given text;
    cout << "\nEncoded string is: \n" << res << endl;


}

///Huffman coding begins
int main()
{
    string str;
    getline(cin, str);

    buildHuffman(str);

    return 0;
}