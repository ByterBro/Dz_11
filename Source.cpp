#include <iostream>
#include <string>
using namespace std;

const int ASIZE = 26;

struct TrieNode
{
	struct TrieNode* children[ASIZE];

	bool isEndOfWord;
};

struct TrieNode* getNode(void)
{
	struct TrieNode* pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ASIZE; i++)
		pNode->children[i] = nullptr;

	return pNode;
}
void insert(struct TrieNode* root, string key)
{
	struct TrieNode* Search = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!Search->children[index])
			Search->children[index] = getNode();

		Search = Search->children[index];
	}
	Search->isEndOfWord = true;
}
bool search(struct TrieNode* root, string key)
{
	struct TrieNode* Search = root;

	for (int i = 0; i < key.length(); i++)
	{
		int j = key[i] - 'a';
		if (!Search->children[j])
			return false;

		Search = Search->children[j];
	}

	return (Search->isEndOfWord);
}
void seek(struct TrieNode* root,string word)
{
	if (search(root, word) == 1)
	{
		cout <<word<< " = Yes, it is in vocab" << endl;
	}
	else
	{
		cout <<word<< " = No, it isn`t in vocab" << endl;
	}
}
int main()
{
	string keys[] = { "the", "ananas", "there","happy", "lover", "exist", "by",
					"bye", "their","car","banana","happiness","love","existance"};
	int n = sizeof(keys) / sizeof(keys[0]);

	struct TrieNode* root = getNode();

	for (int i = 0; i < n; i++)
		insert(root, keys[i]);
	seek(root, "love");
	seek(root, "happier");
	seek(root, "anamas");
	seek(root, "byi");
	
}