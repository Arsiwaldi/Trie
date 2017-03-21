#pragma once
#include "cNode.h"
#include <string>

using namespace std;
class cTrie
{
public:
	cTrie();
	~cTrie();
	void addWord(char * term, unsigned int length) const;
	bool searchWord(char * term, unsigned int length) const;
	void deleteWord(std::string s);
private:
	cNode* root;
};


inline void cTrie::addWord(char * term, unsigned int length) const
{
	cNode* current = root;

	for (int i = 0; i < length; i++)
	{
		cNode* child = current->FindChild(term[i]);
		if (child != nullptr)
		{
			current = child;
		}
		else
		{
			cNode* tmp = new cNode();
			tmp->SetSymbol(term[i]);
			if (i == length - 1)
			{
				unsigned int frequency = tmp->GetFrequency();
				tmp->SetFrequency(++frequency);
			}
			current->AddChild(tmp);
			current = tmp;
		}
	}
}

inline bool cTrie::searchWord(char * term, unsigned int length) const
{
	cNode* current = root;

	while (current != nullptr)
	{
		for (int i = 0; i < length; i++)
		{
			cNode* tmp = current->FindChild(term[i]);
			if (tmp == nullptr)
				return false;
			current = tmp;
			if (i == length - 1 && current->GetFrequency() > 0)
				return true;
		}
	}

	return false;
}


