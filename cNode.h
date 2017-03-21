#pragma once
#include <vector>

class cNode
{
private:
	char symbol;
	unsigned int frequency;
	bool mMarker;
	std::vector<cNode*> mChildren;

public:
	cNode();
	~cNode();

#pragma region Symbol Get/Set
	char GetSymbol() { return symbol; }
	void SetSymbol(char c) { symbol = c; }
#pragma endregion

#pragma region Frequency Get/Set
	void SetFrequency(unsigned int frequency) { this->frequency = frequency; }
	unsigned int GetFrequency() { return frequency; }
#pragma endregion 

#pragma region WordMarker Get/Set
	bool WordMarker() { return mMarker; }
	void SetWordMarker() { mMarker = true; }
#pragma endregion 

	cNode* FindChild(char c);
	void AddChild(cNode* child);
	std::vector<cNode*> Children() const { return mChildren; }
};

inline void cNode::AddChild(cNode* child)
{
	mChildren.push_back(child);
}

inline cNode* cNode::FindChild(char c)
{
	for (auto i = 0; i < mChildren.size(); i++)
	{
		cNode* tmp = mChildren.at(i);
		if (tmp->GetSymbol() == c)
		{
			return tmp;
		}
	}

	return nullptr;
}

