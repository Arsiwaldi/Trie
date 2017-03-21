#include "stdafx.h"
#include "cTrie.h"
#include "cNode.h"
#include <iostream>

using namespace std;
int main()
{
	cTrie* trie = new cTrie();
	trie->addWord("Hello",5);
	trie->addWord("Hellos", 6);
	cout << trie->searchWord("H", 1);
	cout << "";

	delete trie;

}

